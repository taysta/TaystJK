//----------------------------------------------------------------------------------------------
//
//  newmenuconfig.h
//
//  Tab/page configuration for the split newmenu implementation. This file owns the visible
//  tab labels, descText strings, tab counts, derived tab/page rects, and shared hide helpers
//  for page selector bars and page bodies.
//
//  Usage notes:
//  - Include newmenuext.h first. The width/height calculations in this file depend on base
//    constants from newmenuext.h.
//  - The menu supports up to five top-level tabs and five pages per tab. Menus can use fewer
//    by omitting page buttons/page bodies, but keep the configured counts in sync with the
//    buttons rendered.
//  - Use TAB#_PAGE# aliases as the page argument for ROW_* declarations.
//  - Do not nest $evalint. Keep reusable math in *_EXPR macros and use $evalint only at the final
//    value/rect-component layer.
//  - HIDE_PAGE_BARS and HIDE_PAGE_BODIES are used by newmenuext.h helper macros after both
//    headers have been included, so avoid moving them into menu-local scope.
//
//----------------------------------------------------------------------------------------------
#ifndef NEWMENU_CONFIG_H
#define NEWMENU_CONFIG_H

// Top-level option tabs.
#define HEADER_OPTIONS_TAB_COUNT 5
#define HEADER_OPTIONS_TAB_1_TEXT "TAB1"
#define HEADER_OPTIONS_TAB_2_TEXT "TAB2"
#define HEADER_OPTIONS_TAB_3_TEXT "TAB3"
#define HEADER_OPTIONS_TAB_4_TEXT "TAB4"
#define HEADER_OPTIONS_TAB_5_TEXT "TAB5"
#define HEADER_OPTIONS_TAB_1_DESC_TEXT "Tab 1 Settings"
#define HEADER_OPTIONS_TAB_2_DESC_TEXT "Tab 2 Settings"
#define HEADER_OPTIONS_TAB_3_DESC_TEXT "Tab 3 Settings"
#define HEADER_OPTIONS_TAB_4_DESC_TEXT "Tab 4 Settings"
#define HEADER_OPTIONS_TAB_5_DESC_TEXT "Tab 5 Settings"
#define HEADER_OPTIONS_TAB_WIDTH_EXPR (MENU_WIDTH / HEADER_OPTIONS_TAB_COUNT)
#define HEADER_OPTIONS_TAB_HALF_WIDTH_EXPR (HEADER_OPTIONS_TAB_WIDTH_EXPR / 2)
#define HEADER_OPTIONS_TAB_WIDTH $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR)
#define HEADER_OPTIONS_TAB_HALF_WIDTH $evalint(HEADER_OPTIONS_TAB_HALF_WIDTH_EXPR)
#define HEADER_OPTIONS_TAB_1_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 0)
#define HEADER_OPTIONS_TAB_2_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 1)
#define HEADER_OPTIONS_TAB_3_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 2)
#define HEADER_OPTIONS_TAB_4_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 3)
#define HEADER_OPTIONS_TAB_5_X $evalint(HEADER_OPTIONS_TAB_WIDTH_EXPR * 4)
#define HEADER_OPTIONS_TAB_1_RECT HEADER_OPTIONS_TAB_1_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF
#define HEADER_OPTIONS_TAB_2_RECT HEADER_OPTIONS_TAB_2_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF
#define HEADER_OPTIONS_TAB_3_RECT HEADER_OPTIONS_TAB_3_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF
#define HEADER_OPTIONS_TAB_4_RECT HEADER_OPTIONS_TAB_4_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF
#define HEADER_OPTIONS_TAB_5_RECT HEADER_OPTIONS_TAB_5_X HEADER_HEIGHT_HALF HEADER_OPTIONS_TAB_WIDTH HEADER_HEIGHT_HALF

// Tab 1 pages.
#define OPTIONS_TAB_1_PAGE_COUNT 5
#define OPTIONS_TAB_1_PAGE_1_TEXT "T1 Page 1"
#define OPTIONS_TAB_1_PAGE_2_TEXT "T1 Page 2"
#define OPTIONS_TAB_1_PAGE_3_TEXT "T1 Page 3"
#define OPTIONS_TAB_1_PAGE_4_TEXT "T1 Page 4"
#define OPTIONS_TAB_1_PAGE_5_TEXT "T1 Page 5"
#define OPTIONS_TAB_1_PAGE_1_DESC_TEXT "Tab 1 Page 1 Settings"
#define OPTIONS_TAB_1_PAGE_2_DESC_TEXT "Tab 1 Page 2 Settings"
#define OPTIONS_TAB_1_PAGE_3_DESC_TEXT "Tab 1 Page 3 Settings"
#define OPTIONS_TAB_1_PAGE_4_DESC_TEXT "Tab 1 Page 4 Settings"
#define OPTIONS_TAB_1_PAGE_5_DESC_TEXT "Tab 1 Page 5 Settings"
#define OPTIONS_TAB_1_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_1_PAGE_COUNT)
#define OPTIONS_TAB_1_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_1_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_1_PAGE_WIDTH $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_1_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_1_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_1_PAGE_1_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_1_PAGE_2_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_1_PAGE_3_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_1_PAGE_4_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 3)
#define OPTIONS_TAB_1_PAGE_5_X $evalint(OPTIONS_TAB_1_PAGE_WIDTH_EXPR * 4)
#define OPTIONS_TAB_1_PAGE_1_RECT OPTIONS_TAB_1_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_2_RECT OPTIONS_TAB_1_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_3_RECT OPTIONS_TAB_1_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_4_RECT OPTIONS_TAB_1_PAGE_4_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_1_PAGE_5_RECT OPTIONS_TAB_1_PAGE_5_X HEADER_HEIGHT OPTIONS_TAB_1_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Tab 2 pages.
#define OPTIONS_TAB_2_PAGE_COUNT 5
#define OPTIONS_TAB_2_PAGE_1_TEXT "T2 Page 1"
#define OPTIONS_TAB_2_PAGE_2_TEXT "T2 Page 2"
#define OPTIONS_TAB_2_PAGE_3_TEXT "T2 Page 3"
#define OPTIONS_TAB_2_PAGE_4_TEXT "T2 Page 4"
#define OPTIONS_TAB_2_PAGE_5_TEXT "T2 Page 5"
#define OPTIONS_TAB_2_PAGE_1_DESC_TEXT "Tab 2 Page 1 Settings"
#define OPTIONS_TAB_2_PAGE_2_DESC_TEXT "Tab 2 Page 2 Settings"
#define OPTIONS_TAB_2_PAGE_3_DESC_TEXT "Tab 2 Page 3 Settings"
#define OPTIONS_TAB_2_PAGE_4_DESC_TEXT "Tab 2 Page 4 Settings"
#define OPTIONS_TAB_2_PAGE_5_DESC_TEXT "Tab 2 Page 5 Settings"
#define OPTIONS_TAB_2_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_2_PAGE_COUNT)
#define OPTIONS_TAB_2_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_2_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_2_PAGE_WIDTH $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_2_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_2_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_2_PAGE_1_X $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_2_PAGE_2_X $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_2_PAGE_3_X $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_2_PAGE_4_X $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR * 3)
#define OPTIONS_TAB_2_PAGE_5_X $evalint(OPTIONS_TAB_2_PAGE_WIDTH_EXPR * 4)
#define OPTIONS_TAB_2_PAGE_1_RECT OPTIONS_TAB_2_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_2_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_2_PAGE_2_RECT OPTIONS_TAB_2_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_2_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_2_PAGE_3_RECT OPTIONS_TAB_2_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_2_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_2_PAGE_4_RECT OPTIONS_TAB_2_PAGE_4_X HEADER_HEIGHT OPTIONS_TAB_2_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_2_PAGE_5_RECT OPTIONS_TAB_2_PAGE_5_X HEADER_HEIGHT OPTIONS_TAB_2_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Tab 3 pages.
#define OPTIONS_TAB_3_PAGE_COUNT 5
#define OPTIONS_TAB_3_PAGE_1_TEXT "T3 Page 1"
#define OPTIONS_TAB_3_PAGE_2_TEXT "T3 Page 2"
#define OPTIONS_TAB_3_PAGE_3_TEXT "T3 Page 3"
#define OPTIONS_TAB_3_PAGE_4_TEXT "T3 Page 4"
#define OPTIONS_TAB_3_PAGE_5_TEXT "T3 Page 5"
#define OPTIONS_TAB_3_PAGE_1_DESC_TEXT "Tab 3 Page 1 Settings"
#define OPTIONS_TAB_3_PAGE_2_DESC_TEXT "Tab 3 Page 2 Settings"
#define OPTIONS_TAB_3_PAGE_3_DESC_TEXT "Tab 3 Page 3 Settings"
#define OPTIONS_TAB_3_PAGE_4_DESC_TEXT "Tab 3 Page 4 Settings"
#define OPTIONS_TAB_3_PAGE_5_DESC_TEXT "Tab 3 Page 5 Settings"
#define OPTIONS_TAB_3_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_3_PAGE_COUNT)
#define OPTIONS_TAB_3_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_3_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_3_PAGE_WIDTH $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_3_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_3_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_3_PAGE_1_X $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_3_PAGE_2_X $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_3_PAGE_3_X $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_3_PAGE_4_X $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR * 3)
#define OPTIONS_TAB_3_PAGE_5_X $evalint(OPTIONS_TAB_3_PAGE_WIDTH_EXPR * 4)
#define OPTIONS_TAB_3_PAGE_1_RECT OPTIONS_TAB_3_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_3_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_3_PAGE_2_RECT OPTIONS_TAB_3_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_3_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_3_PAGE_3_RECT OPTIONS_TAB_3_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_3_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_3_PAGE_4_RECT OPTIONS_TAB_3_PAGE_4_X HEADER_HEIGHT OPTIONS_TAB_3_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_3_PAGE_5_RECT OPTIONS_TAB_3_PAGE_5_X HEADER_HEIGHT OPTIONS_TAB_3_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Tab 4 pages.
#define OPTIONS_TAB_4_PAGE_COUNT 5
#define OPTIONS_TAB_4_PAGE_1_TEXT "T4 Page 1"
#define OPTIONS_TAB_4_PAGE_2_TEXT "T4 Page 2"
#define OPTIONS_TAB_4_PAGE_3_TEXT "T4 Page 3"
#define OPTIONS_TAB_4_PAGE_4_TEXT "T4 Page 4"
#define OPTIONS_TAB_4_PAGE_5_TEXT "T4 Page 5"
#define OPTIONS_TAB_4_PAGE_1_DESC_TEXT "Tab 4 Page 1 Settings"
#define OPTIONS_TAB_4_PAGE_2_DESC_TEXT "Tab 4 Page 2 Settings"
#define OPTIONS_TAB_4_PAGE_3_DESC_TEXT "Tab 4 Page 3 Settings"
#define OPTIONS_TAB_4_PAGE_4_DESC_TEXT "Tab 4 Page 4 Settings"
#define OPTIONS_TAB_4_PAGE_5_DESC_TEXT "Tab 4 Page 5 Settings"
#define OPTIONS_TAB_4_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_4_PAGE_COUNT)
#define OPTIONS_TAB_4_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_4_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_4_PAGE_WIDTH $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_4_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_4_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_4_PAGE_1_X $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_4_PAGE_2_X $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_4_PAGE_3_X $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_4_PAGE_4_X $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR * 3)
#define OPTIONS_TAB_4_PAGE_5_X $evalint(OPTIONS_TAB_4_PAGE_WIDTH_EXPR * 4)
#define OPTIONS_TAB_4_PAGE_1_RECT OPTIONS_TAB_4_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_4_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_4_PAGE_2_RECT OPTIONS_TAB_4_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_4_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_4_PAGE_3_RECT OPTIONS_TAB_4_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_4_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_4_PAGE_4_RECT OPTIONS_TAB_4_PAGE_4_X HEADER_HEIGHT OPTIONS_TAB_4_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_4_PAGE_5_RECT OPTIONS_TAB_4_PAGE_5_X HEADER_HEIGHT OPTIONS_TAB_4_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Tab 5 pages.
#define OPTIONS_TAB_5_PAGE_COUNT 5
#define OPTIONS_TAB_5_PAGE_1_TEXT "T5 Page 1"
#define OPTIONS_TAB_5_PAGE_2_TEXT "T5 Page 2"
#define OPTIONS_TAB_5_PAGE_3_TEXT "T5 Page 3"
#define OPTIONS_TAB_5_PAGE_4_TEXT "T5 Page 4"
#define OPTIONS_TAB_5_PAGE_5_TEXT "T5 Page 5"
#define OPTIONS_TAB_5_PAGE_1_DESC_TEXT "Tab 5 Page 1 Settings"
#define OPTIONS_TAB_5_PAGE_2_DESC_TEXT "Tab 5 Page 2 Settings"
#define OPTIONS_TAB_5_PAGE_3_DESC_TEXT "Tab 5 Page 3 Settings"
#define OPTIONS_TAB_5_PAGE_4_DESC_TEXT "Tab 5 Page 4 Settings"
#define OPTIONS_TAB_5_PAGE_5_DESC_TEXT "Tab 5 Page 5 Settings"
#define OPTIONS_TAB_5_PAGE_WIDTH_EXPR (MENU_WIDTH / OPTIONS_TAB_5_PAGE_COUNT)
#define OPTIONS_TAB_5_PAGE_HALF_WIDTH_EXPR (OPTIONS_TAB_5_PAGE_WIDTH_EXPR / 2)
#define OPTIONS_TAB_5_PAGE_WIDTH $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR)
#define OPTIONS_TAB_5_PAGE_HALF_WIDTH $evalint(OPTIONS_TAB_5_PAGE_HALF_WIDTH_EXPR)
#define OPTIONS_TAB_5_PAGE_1_X $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR * 0)
#define OPTIONS_TAB_5_PAGE_2_X $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR * 1)
#define OPTIONS_TAB_5_PAGE_3_X $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR * 2)
#define OPTIONS_TAB_5_PAGE_4_X $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR * 3)
#define OPTIONS_TAB_5_PAGE_5_X $evalint(OPTIONS_TAB_5_PAGE_WIDTH_EXPR * 4)
#define OPTIONS_TAB_5_PAGE_1_RECT OPTIONS_TAB_5_PAGE_1_X HEADER_HEIGHT OPTIONS_TAB_5_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_5_PAGE_2_RECT OPTIONS_TAB_5_PAGE_2_X HEADER_HEIGHT OPTIONS_TAB_5_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_5_PAGE_3_RECT OPTIONS_TAB_5_PAGE_3_X HEADER_HEIGHT OPTIONS_TAB_5_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_5_PAGE_4_RECT OPTIONS_TAB_5_PAGE_4_X HEADER_HEIGHT OPTIONS_TAB_5_PAGE_WIDTH PAGE_BUTTON_HEIGHT
#define OPTIONS_TAB_5_PAGE_5_RECT OPTIONS_TAB_5_PAGE_5_X HEADER_HEIGHT OPTIONS_TAB_5_PAGE_WIDTH PAGE_BUTTON_HEIGHT

// Generic page aliases for ROW_* declarations.
#define TAB1_PAGE1 newmenu_options_tab_1_page_1
#define TAB1_PAGE2 newmenu_options_tab_1_page_2
#define TAB1_PAGE3 newmenu_options_tab_1_page_3
#define TAB1_PAGE4 newmenu_options_tab_1_page_4
#define TAB1_PAGE5 newmenu_options_tab_1_page_5

#define TAB2_PAGE1 newmenu_options_tab_2_page_1
#define TAB2_PAGE2 newmenu_options_tab_2_page_2
#define TAB2_PAGE3 newmenu_options_tab_2_page_3
#define TAB2_PAGE4 newmenu_options_tab_2_page_4
#define TAB2_PAGE5 newmenu_options_tab_2_page_5

#define TAB3_PAGE1 newmenu_options_tab_3_page_1
#define TAB3_PAGE2 newmenu_options_tab_3_page_2
#define TAB3_PAGE3 newmenu_options_tab_3_page_3
#define TAB3_PAGE4 newmenu_options_tab_3_page_4
#define TAB3_PAGE5 newmenu_options_tab_3_page_5

#define TAB4_PAGE1 newmenu_options_tab_4_page_1
#define TAB4_PAGE2 newmenu_options_tab_4_page_2
#define TAB4_PAGE3 newmenu_options_tab_4_page_3
#define TAB4_PAGE4 newmenu_options_tab_4_page_4
#define TAB4_PAGE5 newmenu_options_tab_4_page_5

#define TAB5_PAGE1 newmenu_options_tab_5_page_1
#define TAB5_PAGE2 newmenu_options_tab_5_page_2
#define TAB5_PAGE3 newmenu_options_tab_5_page_3
#define TAB5_PAGE4 newmenu_options_tab_5_page_4
#define TAB5_PAGE5 newmenu_options_tab_5_page_5

// Shared visibility helpers.
#define HIDE_PAGE_BARS \
    hide        options_tab_1_pages ; \
    hide        options_tab_2_pages ; \
    hide        options_tab_3_pages ; \
    hide        options_tab_4_pages ; \
    hide        options_tab_5_pages ;

#define HIDE_OPTIONS_TAB_1_PAGE_BODIES \
    hide        newmenu_options_tab_1_page_1 ; \
    hide        newmenu_options_tab_1_page_2 ; \
    hide        newmenu_options_tab_1_page_3 ; \
    hide        newmenu_options_tab_1_page_4 ; \
    hide        newmenu_options_tab_1_page_5 ;

#define HIDE_OPTIONS_TAB_2_PAGE_BODIES \
    hide        newmenu_options_tab_2_page_1 ; \
    hide        newmenu_options_tab_2_page_2 ; \
    hide        newmenu_options_tab_2_page_3 ; \
    hide        newmenu_options_tab_2_page_4 ; \
    hide        newmenu_options_tab_2_page_5 ;

#define HIDE_OPTIONS_TAB_3_PAGE_BODIES \
    hide        newmenu_options_tab_3_page_1 ; \
    hide        newmenu_options_tab_3_page_2 ; \
    hide        newmenu_options_tab_3_page_3 ; \
    hide        newmenu_options_tab_3_page_4 ; \
    hide        newmenu_options_tab_3_page_5 ;

#define HIDE_OPTIONS_TAB_4_PAGE_BODIES \
    hide        newmenu_options_tab_4_page_1 ; \
    hide        newmenu_options_tab_4_page_2 ; \
    hide        newmenu_options_tab_4_page_3 ; \
    hide        newmenu_options_tab_4_page_4 ; \
    hide        newmenu_options_tab_4_page_5 ;

#define HIDE_OPTIONS_TAB_5_PAGE_BODIES \
    hide        newmenu_options_tab_5_page_1 ; \
    hide        newmenu_options_tab_5_page_2 ; \
    hide        newmenu_options_tab_5_page_3 ; \
    hide        newmenu_options_tab_5_page_4 ; \
    hide        newmenu_options_tab_5_page_5 ;

#define HIDE_PAGE_BODIES \
    HIDE_OPTIONS_TAB_1_PAGE_BODIES \
    HIDE_OPTIONS_TAB_2_PAGE_BODIES \
    HIDE_OPTIONS_TAB_3_PAGE_BODIES \
    HIDE_OPTIONS_TAB_4_PAGE_BODIES \
    HIDE_OPTIONS_TAB_5_PAGE_BODIES

#endif
