//----------------------------------------------------------------------------------------------
//
//  newmenuconfig.h
//
//  Tab/page configuration for the split newmenu implementation. This file owns the visible
//  tab labels, descText strings, tab counts, derived tab/page rects, shared hide helpers
//  for page selector bars and page bodies, and the menu chrome every tab shares.
//
//  Usage notes:
//  - Include newmenuext.h first. The width/height calculations in this file depend on base
//    constants from newmenuext.h.
//  - Each tab is its own menu file (newmenu_tabN.menu) loaded from jampingame.txt, and only holds
//    its own pages. Page switches hide just that tab's bodies with HIDE_OPTIONS_TAB_n_PAGE_BODIES.
//  - Use TAB#_PAGE# aliases as the page argument for ROW_* declarations.
//  - Adding a page to tab n: raise OPTIONS_TAB_n_PAGE_COUNT, then add the page's _TEXT,
//    _DESC_TEXT, _X and _RECT defines, a TABn_PAGEm alias, a line in
//    HIDE_OPTIONS_TAB_n_PAGE_BODIES and a NEWMENU_PAGE_BUTTON(n, m) in NEWMENU_PAGE_BUTTONS_n.
//  - Adding tab n: raise HEADER_OPTIONS_TAB_COUNT, add its HEADER_OPTIONS_TAB_n_* defines and the
//    page set above, and a NEWMENU_TAB_ROW_n. Every tab row lists every tab: NEWMENU_TAB_ACTIVE(n)
//    for its own tab and NEWMENU_TAB_INACTIVE(n, i) for the others.
//  - Do not nest $evalint. Keep reusable math in *_EXPR macros and use $evalint only at the final
//    value/rect-component layer.
//
//----------------------------------------------------------------------------------------------
#ifndef NEWMENU_CONFIG_H
#define NEWMENU_CONFIG_H

// Top-level option tabs.
#define HEADER_OPTIONS_TAB_COUNT 1
#define HEADER_OPTIONS_TAB_1_TEXT "CONTROLS"
#define HEADER_OPTIONS_TAB_1_DESC_TEXT "Key bindings"
#define HEADER_OPTIONS_TAB_WIDTH_EXPR (MENU_WIDTH / HEADER_OPTIONS_TAB_COUNT)
#define HEADER_OPTIONS_TAB_HALF_WIDTH_EXPR (HEADER_OPTIONS_TAB_WIDTH_EXPR / 2)
#define HEADER_OPTIONS_TAB_WIDTH $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR)
#define HEADER_OPTIONS_TAB_HALF_WIDTH $evalint(HEADER_OPTIONS_TAB_HALF_WIDTH_EXPR)
#define HEADER_OPTIONS_TAB_1_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 0)
#define HEADER_OPTIONS_TAB_1_RECT HEADER_OPTIONS_TAB_1_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF

// Tab 1 pages.
#define OPTIONS_TAB_1_PAGE_COUNT 3
#define OPTIONS_TAB_1_PAGE_1_TEXT "Weapons"
#define OPTIONS_TAB_1_PAGE_2_TEXT "Movement"
#define OPTIONS_TAB_1_PAGE_3_TEXT "Actions"
#define OPTIONS_TAB_1_PAGE_1_DESC_TEXT "Weapon and firing keys"
#define OPTIONS_TAB_1_PAGE_2_DESC_TEXT "Movement keys"
#define OPTIONS_TAB_1_PAGE_3_DESC_TEXT "Pack and other action keys"
#define OPTIONS_TAB_1_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_1_PAGE_COUNT)
#define OPTIONS_TAB_1_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_1_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_1_PAGE_WIDTH $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_1_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_1_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_1_PAGE_1_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_1_PAGE_2_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_1_PAGE_3_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_1_PAGE_1_RECT OPTIONS_TAB_1_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_2_RECT OPTIONS_TAB_1_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_3_RECT OPTIONS_TAB_1_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Page aliases for ROW_* declarations.
#define TAB1_PAGE1 newmenu_options_tab_1_page_1
#define TAB1_PAGE2 newmenu_options_tab_1_page_2
#define TAB1_PAGE3 newmenu_options_tab_1_page_3

// Per-tab page body hide helpers.
#define HIDE_OPTIONS_TAB_1_PAGE_BODIES \
    hide        newmenu_options_tab_1_page_1 ; \
    hide        newmenu_options_tab_1_page_2 ; \
    hide        newmenu_options_tab_1_page_3 ;

//----------------------------------------------------------------------------------------------
//
//  Shared tab menu chrome.
//
//  Every newmenu_tab* menu is the same apart from its number and its body rows, so a tab file is:
//
//      menuDef
//      {
//          name newmenu_tabN
//          NEWMENU_MENU_PROPS
//          NEWMENU_TAB_LIFECYCLE(N)
//          NEWMENU_TAB_CHROME(N)
//          // ROW_* declarations...
//      }
//
//  - Only the exit and tab buttons show the unapplied-video prompt. In game, ESC closes every
//    menu without running onESC (UI_KeyEvent calls Menus_CloseAll unless a fullScreen menu is
//    visible), and outOfBoundsClick closes the tab through onClose only, so both drop unapplied
//    changes silently. onESC stays so the prompt works if that changes. The fix is a small UI
//    module change: an opt-in menuDef keyword that makes UI_KeyEvent pass ESC to Menu_HandleKey
//    and makes Menus_HandleOOBClick run onESC for that menu.
//  - Menu sounds belong to the action that closes a tab (onESC, the exit button, tab buttons).
//    Tabs have no onClose: onOpen resets everything they show.
//  - NEWMENU_TAB_LIFECYCLE_EX(n, extraOnOpen) adds a fragment to the start of onOpen. The
//    fragment can't contain commas. NEWMENU_TAB_LIFECYCLE fills it with a lone ";", which
//    menu scripts skip.
//
//----------------------------------------------------------------------------------------------

#define NEWMENU_MENU_PROPS \
    rect                    MENU_X 0 MENU_WIDTH SCREEN_HEIGHT \
    outOfBoundsClick \
    focusColor              COL_WHITE \
    descX                   DESC_TEXT_X \
    descY                   DESC_TEXT_Y \
    descScale               DESC_TEXT_SCALE \
    descColor               COL_DESC_TEXT \
    descAlignment           ITEM_ALIGN_LEFT

#define NEWMENU_TAB_LIFECYCLE_EX(n, extraOnOpen) \
    onOpen \
    { \
        uiScript            getvideosetup ; \
        extraOnOpen \
        HIDE_OPTIONS_TAB_##n##_PAGE_BODIES \
        RESET_HOVER \
        show                MENU_CHROME_GROUP ; \
        show                options_tab_##n##_pages ; \
        show                newmenu_options_tab_##n##_page_1 ; \
        setitemrect         newmenu_selected_tab_highlight HEADER_OPTIONS_TAB_##n##_RECT ; \
        setitemrect         newmenu_selected_page_highlight OPTIONS_TAB_##n##_PAGE_1_RECT ; \
    } \
    onESC \
    { \
        play                "sound/interface/button1" ; \
        defer               VideoSetup NEWMENU_VIDEO_WARNING ; \
        close               newmenu_tab##n ; \
    }

#define NEWMENU_TAB_LIFECYCLE(n) \
    NEWMENU_TAB_LIFECYCLE_EX(n, ;)

// The current tab's cell resets it to page 1; the others switch to their own menu.
#define NEWMENU_TAB_ACTIVE(i) \
    ITEM_TAB_BUTTON(options_tab_##i##_button, MENU_CHROME_GROUP, HEADER_OPTIONS_TAB_##i##_TEXT, HEADER_OPTIONS_TAB_##i##_RECT, HEADER_OPTIONS_TAB_HALF_WIDTH, HEADER_OPTIONS_TAB_##i##_DESC_TEXT, HIDE_OPTIONS_TAB_##i##_PAGE_BODIES, newmenu_options_tab_##i##_page_1, OPTIONS_TAB_##i##_PAGE_1_RECT, VISIBLE)

#define NEWMENU_TAB_INACTIVE(n, i) \
    ITEM_TAB_NAV(options_tab_##i##_button, MENU_CHROME_GROUP, HEADER_OPTIONS_TAB_##i##_TEXT, HEADER_OPTIONS_TAB_##i##_RECT, HEADER_OPTIONS_TAB_HALF_WIDTH, HEADER_OPTIONS_TAB_##i##_DESC_TEXT, newmenu_tab##n, newmenu_tab##i, VISIBLE)

// Tab row for each tab.
#define NEWMENU_TAB_ROW_1 \
    NEWMENU_TAB_ACTIVE(1)

#define NEWMENU_PAGE_BUTTON(n, p) \
    ITEM_PAGE_BUTTON(options_tab_##n##_page_##p##_button, options_tab_##n##_pages, OPTIONS_TAB_##n##_PAGE_##p##_TEXT, OPTIONS_TAB_##n##_PAGE_##p##_RECT, OPTIONS_TAB_##n##_PAGE_HALF_WIDTH, OPTIONS_TAB_##n##_PAGE_##p##_DESC_TEXT, HIDE_OPTIONS_TAB_##n##_PAGE_BODIES, newmenu_options_tab_##n##_page_##p)

// Page buttons for each tab.
#define NEWMENU_PAGE_BUTTONS_1 \
    NEWMENU_PAGE_BUTTON(1, 1) \
    NEWMENU_PAGE_BUTTON(1, 2) \
    NEWMENU_PAGE_BUTTON(1, 3)

// Backgrounds, the shared highlight helpers, header title, exit and apply buttons, the tab row
// and this tab's page buttons. Draw order matters: backgrounds, then highlights, then the rest.
#define NEWMENU_TAB_CHROME(n) \
    ITEM_BACKGROUND(background_header,      MENU_CHROME_GROUP, 0 0 MENU_WIDTH HEADER_HEIGHT,                       COL_MENU_HEADER_BACK) \
    ITEM_BACKGROUND(background_main_panel,  MENU_CHROME_GROUP, 0 HEADER_HEIGHT MENU_WIDTH HEADER_HEIGHT_REMAINING, COL_MENU_PANEL_BACK) \
    SELECTEDHIGHLIGHT(newmenu_selected_tab_highlight) \
    SELECTEDHIGHLIGHT(newmenu_selected_page_highlight) \
    HIGHLIGHT \
    DUMMYHIGHLIGHT \
    TEXT_BOX_HEADER(header_title, MENU_CHROME_GROUP, 0 0 HEADER_TITLE_WIDTH HEADER_HEIGHT_HALF, VISIBLE, HEADER_TITLE) \
    ITEM_EXIT(header_exit_button, MENU_CHROME_GROUP, HEADER_EXIT_ICON_X HEADER_PADDING HEADER_EXIT_ICON_SIZE HEADER_EXIT_ICON_SIZE, COL_WHITE, HEADER_EXIT_ICON_SHADER, newmenu_tab##n) \
    ITEM_APPLY_CHANGES \
    NEWMENU_TAB_ROW_##n \
    NEWMENU_PAGE_BUTTONS_##n

#endif
