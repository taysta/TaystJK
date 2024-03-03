//----------------------------------------------------------------------------------------------
//
//  newmenuext.h
//
//  Shared constants and item macros for the split newmenu implementation.
//  Include this before newmenuconfig.h in menu files: config uses the base layout constants here,
//  and a few helper macros here intentionally expand config-defined hide helpers later.
//
//  Usage notes / banana peels:
//  - Keep geometry derived from the screen/menu/padding/count constants instead of hard-coding
//    rects in the menu files.
//  - HEADER_* names describe the top layout region. MENU_CHROME_GROUP is the shared item group
//    that shows/hides the repeated frame, title, tab buttons, and other menu chrome.
//  - Each page body currently has 24 row slots. Adding more visible rows to a page means adding
//    more row geometry here or changing the paging/layout strategy.
//  - Do not nest $evalint. Put arithmetic in *_EXPR macros, reference other *_EXPR macros inside
//    that arithmetic, then expose exactly one final $evalint(...) value or rect component.
//  - Multi-line macros are fragile: every continued line needs a trailing backslash, and command
//    fragments that expand inside action blocks should keep their semicolons.
//  - Empty placeholder macros are not safe here: this preprocessor treats an empty define
//    expansion as a failed token read. ACT_NONE is deliberately a script semicolon, and itemDef
//    "no extra tokens" cases use separate helper macros instead of passing an empty argument.
//  - Use menu show/hide commands directly. "uiScript show" is not a valid uiScript command.
//
//----------------------------------------------------------------------------------------------
#ifndef NEWMENU_EXT_H
#define NEWMENU_EXT_H

// Base screen, menu, and font constants.
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640
#define MAX_CHARS 26

#define FONT_SMALL 1
#define FONT_MEDIUM 2
#define FONT_LARGE 3
#define FONT_SMALL2 4

#define MENU_WIDTH 240
#define MENU_WIDTH_HALF_EXPR (MENU_WIDTH / 2)
#define MENU_WIDTH_HALF $evalint(MENU_WIDTH_HALF_EXPR)
#define MENU_X_EXPR (SCREEN_WIDTH - MENU_WIDTH)
#define MENU_X $evalint(MENU_X_EXPR)

// Shared item groups.
#define MENU_CHROME_GROUP menu_chrome

// Header layout.
#define HEADER_TITLE "OPTIONS"

#define HEADER_HEIGHT 60
#define HEADER_HEIGHT_HALF_EXPR (HEADER_HEIGHT / 2)
#define HEADER_HEIGHT_SEVENTH_EXPR (HEADER_HEIGHT / 7)
#define HEADER_HEIGHT_HALF $evalint(HEADER_HEIGHT_HALF_EXPR)
#define HEADER_HEIGHT_SEVENTH $evalint(HEADER_HEIGHT_SEVENTH_EXPR)

#define HEADER_TITLE_WIDTH_EXPR (MENU_WIDTH_HALF_EXPR)
#define HEADER_TITLE_WIDTH $evalint(HEADER_TITLE_WIDTH_EXPR)

#define HEADER_EXIT_ICON_SIZE 10
#define HEADER_PADDING 5
#define HEADER_EXIT_ICON_X_EXPR (MENU_WIDTH - HEADER_EXIT_ICON_SIZE - HEADER_PADDING)
#define HEADER_EXIT_ICON_X $evalint(HEADER_EXIT_ICON_X_EXPR)

#define HEADER_HEIGHT_REMAINING_EXPR (SCREEN_HEIGHT - HEADER_HEIGHT)
#define HEADER_HEIGHT_REMAINING $evalint(HEADER_HEIGHT_REMAINING_EXPR)

// Shared colors and shaders.
#define COL_MENU_HEADER_BACK 0.035 0.045 0.055 0.95
#define COL_MENU_PANEL_BACK 0.015 0.018 0.023 0.88
#define COL_POPUP_PANEL_BACK 0.035 0.045 0.055 0.98
#define COL_HOVER 0.16 0.22 0.30 0.38
#define COL_ROW_CONTROL_BACK 0.08 0.10 0.12 0.55
#define COL_ROW_CONTROL_BORDER 0.18 0.23 0.29 0.65
#define COL_TEXT_PRIMARY 0.93 0.96 1 1
#define COL_TEXT_SECONDARY 0.76 0.82 0.90 1
#define COL_DESC_TEXT 0.80 0.86 0.92 1
#define COL_DARKGREY COL_MENU_HEADER_BACK
#define COL_LIGHTGREY COL_MENU_PANEL_BACK
#define COL_BLACK 0.01 0.01 0.01 1
#define COL_NONE 0 0 0 0
#define COL_WHITE 1 1 1 1
#define COL_DIM 0.75 0.75 0.75 1
#define COL_OVERLAY 0 0 0 0.72
#define COL_PANEL_BORDER 0.28 0.34 0.42 1
#define COL_APPLY_FORE 1 0.82 0.42 1
#define COL_APPLY_BACK 0.16 0.10 0.03 0.94
#define COL_APPLY_BORDER 0.78 0.45 0.12 1
#define COL_CONFIRM_BACK 0.16 0.30 0.18 0.95
#define COL_CONFIRM_BORDER 0.40 0.70 0.45 1
#define COL_DISCARD_BACK 0.32 0.22 0.12 0.95
#define COL_DISCARD_BORDER 0.74 0.50 0.24 1
#define COL_CANCEL_BACK 0.16 0.17 0.18 0.95
#define COL_CANCEL_BORDER COL_PANEL_BORDER
#define COL_SELECTED_TAB 0.16 0.24 0.34 0.46

#define HEADER_EXIT_ICON_SHADER "gfx/menus/close-cross"

// Header and body text styling.
#define HEADER_FONT 2
#define HEADER_FONT_SIZE 0.48
#define HEADER_FONT_STYLE 3
#define MENU_TAB_FONT_SIZE 0.46
#define PAGE_BUTTON_FONT_SIZE 0.40

#define BODY_FONT 2
#define BODY_FONT_SIZE 0.38

#define BODY_ELEMENT_HEIGHT 16
#define BODY_PADDING 5

// Hover description text placement.
#define DESC_TEXT_X_EXPR (MENU_X_EXPR + BODY_PADDING)
#define DESC_TEXT_Y_EXPR (SCREEN_HEIGHT - BODY_PADDING * 2)
#define DESC_TEXT_X $evalint(DESC_TEXT_X_EXPR)
#define DESC_TEXT_Y $evalint(DESC_TEXT_Y_EXPR)
#define DESC_TEXT_SCALE 0.5

#define INVISIBLE 0
#define VISIBLE 1

#define PAGE_BUTTON_HEIGHT 30
#define PAGE_BUTTON_TEXT_Y_EXPR (PAGE_BUTTON_HEIGHT / 4)
#define PAGE_BUTTON_TEXT_Y $evalint(PAGE_BUTTON_TEXT_Y_EXPR)
#define BODY_TOP_Y_EXPR (HEADER_HEIGHT + PAGE_BUTTON_HEIGHT)
#define BODY_TOP_Y $evalint(BODY_TOP_Y_EXPR)

// Body row positions.
#define BODY_ROW_1_Y_EXPR  ((1-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_2_Y_EXPR  ((2-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_3_Y_EXPR  ((3-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_4_Y_EXPR  ((4-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_5_Y_EXPR  ((5-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_6_Y_EXPR  ((6-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_7_Y_EXPR  ((7-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_8_Y_EXPR  ((8-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_9_Y_EXPR  ((9-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_10_Y_EXPR ((10-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_11_Y_EXPR ((11-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_12_Y_EXPR ((12-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_13_Y_EXPR ((13-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_14_Y_EXPR ((14-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_15_Y_EXPR ((15-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_16_Y_EXPR ((16-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_17_Y_EXPR ((17-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_18_Y_EXPR ((18-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_19_Y_EXPR ((19-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_20_Y_EXPR ((20-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_21_Y_EXPR ((21-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_22_Y_EXPR ((22-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_23_Y_EXPR ((23-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)
#define BODY_ROW_24_Y_EXPR ((24-1) * BODY_ELEMENT_HEIGHT + BODY_TOP_Y_EXPR)

#define BODY_ROW_1_Y $evalint(BODY_ROW_1_Y_EXPR)
#define BODY_ROW_2_Y $evalint(BODY_ROW_2_Y_EXPR)
#define BODY_ROW_3_Y $evalint(BODY_ROW_3_Y_EXPR)
#define BODY_ROW_4_Y $evalint(BODY_ROW_4_Y_EXPR)
#define BODY_ROW_5_Y $evalint(BODY_ROW_5_Y_EXPR)
#define BODY_ROW_6_Y $evalint(BODY_ROW_6_Y_EXPR)
#define BODY_ROW_7_Y $evalint(BODY_ROW_7_Y_EXPR)
#define BODY_ROW_8_Y $evalint(BODY_ROW_8_Y_EXPR)
#define BODY_ROW_9_Y $evalint(BODY_ROW_9_Y_EXPR)
#define BODY_ROW_10_Y $evalint(BODY_ROW_10_Y_EXPR)
#define BODY_ROW_11_Y $evalint(BODY_ROW_11_Y_EXPR)
#define BODY_ROW_12_Y $evalint(BODY_ROW_12_Y_EXPR)
#define BODY_ROW_13_Y $evalint(BODY_ROW_13_Y_EXPR)
#define BODY_ROW_14_Y $evalint(BODY_ROW_14_Y_EXPR)
#define BODY_ROW_15_Y $evalint(BODY_ROW_15_Y_EXPR)
#define BODY_ROW_16_Y $evalint(BODY_ROW_16_Y_EXPR)
#define BODY_ROW_17_Y $evalint(BODY_ROW_17_Y_EXPR)
#define BODY_ROW_18_Y $evalint(BODY_ROW_18_Y_EXPR)
#define BODY_ROW_19_Y $evalint(BODY_ROW_19_Y_EXPR)
#define BODY_ROW_20_Y $evalint(BODY_ROW_20_Y_EXPR)
#define BODY_ROW_21_Y $evalint(BODY_ROW_21_Y_EXPR)
#define BODY_ROW_22_Y $evalint(BODY_ROW_22_Y_EXPR)
#define BODY_ROW_23_Y $evalint(BODY_ROW_23_Y_EXPR)
#define BODY_ROW_24_Y $evalint(BODY_ROW_24_Y_EXPR)

// Body option column layout.
#define BODY_OPTION_PADDING 5
#define BODY_OPTION_OFFSET 2
#define BODY_OPTION_FONT FONT_SMALL2
#define BODY_OPTION_SCALE 0.6
#define BODY_OPTION_TEXT ":"
#define BODY_LABEL_X 0
#define BODY_CONTROL_X MENU_WIDTH_HALF
#define BODY_COLUMN_W MENU_WIDTH_HALF
#define BODY_FULL_X 0
#define BODY_FULL_W MENU_WIDTH
#define BODY_ROW_H BODY_ELEMENT_HEIGHT
#define BODY_ROW_H2_EXPR (BODY_ROW_H * 2)
#define BODY_ROW_H2 $evalint(BODY_ROW_H2_EXPR)

// Apply-changes button layout.
#define APPLY_CHANGES_TEXT "APPLY"
#define APPLY_CHANGES_W_EXPR (MENU_WIDTH / 3)
#define APPLY_CHANGES_X_EXPR ((MENU_WIDTH - APPLY_CHANGES_W_EXPR) / 2)
#define APPLY_CHANGES_H_EXPR (HEADER_HEIGHT_HALF_EXPR - HEADER_PADDING * 2)
#define APPLY_CHANGES_X $evalint(APPLY_CHANGES_X_EXPR)
#define APPLY_CHANGES_Y HEADER_PADDING
#define APPLY_CHANGES_W $evalint(APPLY_CHANGES_W_EXPR)
#define APPLY_CHANGES_H $evalint(APPLY_CHANGES_H_EXPR)
#define APPLY_CHANGES_TEXT_X $evalint(APPLY_CHANGES_W_EXPR / 2)
#define APPLY_CHANGES_TEXT_Y BODY_OPTION_OFFSET
#define APPLY_CHANGES_TEXT_SCALE 0.38

// Shared popup layout.
#define POPUP_ORIGIN_X 0
#define POPUP_ORIGIN_Y 0
#define POPUP_BORDER_WIDTH 1
#define POPUP_PANEL_MARGIN_EXPR (MENU_WIDTH / 20)
#define POPUP_PANEL_W_EXPR (MENU_WIDTH - POPUP_PANEL_MARGIN_EXPR * 2)
#define POPUP_CONTENT_PADDING_EXPR (BODY_PADDING + BODY_OPTION_OFFSET + POPUP_BORDER_WIDTH)
#define POPUP_CONTENT_X_EXPR (POPUP_PANEL_MARGIN_EXPR + POPUP_CONTENT_PADDING_EXPR)
#define POPUP_CONTENT_W_EXPR (POPUP_PANEL_W_EXPR - POPUP_CONTENT_PADDING_EXPR * 2)
#define POPUP_TITLE_TOP_PADDING_EXPR (BODY_PADDING * 3 + BODY_OPTION_OFFSET + POPUP_BORDER_WIDTH)
#define POPUP_RESTART_TITLE_TOP_PADDING_EXPR (POPUP_TITLE_TOP_PADDING_EXPR + POPUP_BORDER_WIDTH)
#define POPUP_TITLE_H_EXPR (BODY_ELEMENT_HEIGHT + BODY_PADDING + BODY_OPTION_OFFSET + POPUP_BORDER_WIDTH)
#define POPUP_TEXT_GAP_EXPR (BODY_PADDING * 2 + BODY_OPTION_OFFSET)
#define POPUP_TEXT_H_EXPR (BODY_ELEMENT_HEIGHT + BODY_OPTION_OFFSET * 2)
#define POPUP_BUTTON_SIDE_PADDING_EXPR (BODY_PADDING * 2)
#define POPUP_BUTTON_TOP_GAP_EXPR (BODY_PADDING * 2 + BODY_OPTION_OFFSET)
#define POPUP_PANEL_BOTTOM_PADDING_EXPR (BODY_PADDING * 3)
#define POPUP_BUTTON_H_EXPR (BODY_ELEMENT_HEIGHT + BODY_PADDING * 2)
#define POPUP_DIM_RECT POPUP_ORIGIN_X POPUP_ORIGIN_Y MENU_WIDTH SCREEN_HEIGHT
#define POPUP_PANEL_X $evalint(POPUP_PANEL_MARGIN_EXPR)
#define POPUP_PANEL_W $evalint(POPUP_PANEL_W_EXPR)
#define POPUP_CONTENT_X $evalint(POPUP_CONTENT_X_EXPR)
#define POPUP_CONTENT_W $evalint(POPUP_CONTENT_W_EXPR)
#define POPUP_TITLE_H $evalint(POPUP_TITLE_H_EXPR)
#define POPUP_TEXT_H $evalint(POPUP_TEXT_H_EXPR)
#define POPUP_BUTTON_H $evalint(POPUP_BUTTON_H_EXPR)
#define POPUP_TEXT_ALIGN_X $evalint(POPUP_CONTENT_W_EXPR / 2)
#define POPUP_TITLE_TEXT_ALIGN_Y 3
#define POPUP_BODY_TEXT_ALIGN_Y 0
#define POPUP_BUTTON_TEXT_ALIGN_Y 4
#define POPUP_TITLE_TEXT_SCALE 0.45
#define POPUP_BODY_TEXT_SCALE 0.36
#define POPUP_BODY_SMALL_TEXT_SCALE 0.35
#define POPUP_BUTTON_TEXT_SCALE 0.38
#define POPUP_BUTTON_LONG_TEXT_SCALE 0.35

// Unapplied-video warning popup layout.
#define VIDEO_WARNING_PANEL_H_EXPR (POPUP_TITLE_TOP_PADDING_EXPR + POPUP_TITLE_H_EXPR + POPUP_TEXT_GAP_EXPR + POPUP_TEXT_H_EXPR * 2 + POPUP_BUTTON_TOP_GAP_EXPR + POPUP_BUTTON_H_EXPR + POPUP_PANEL_BOTTOM_PADDING_EXPR)
#define VIDEO_WARNING_PANEL_Y_EXPR ((SCREEN_HEIGHT - VIDEO_WARNING_PANEL_H_EXPR) / 2 - HEADER_PADDING * 2)
#define VIDEO_WARNING_TITLE_Y_EXPR (VIDEO_WARNING_PANEL_Y_EXPR + POPUP_TITLE_TOP_PADDING_EXPR)
#define VIDEO_WARNING_TEXT1_Y_EXPR (VIDEO_WARNING_PANEL_Y_EXPR + POPUP_TITLE_TOP_PADDING_EXPR + POPUP_TITLE_H_EXPR + POPUP_TEXT_GAP_EXPR)
#define VIDEO_WARNING_TEXT2_Y_EXPR (VIDEO_WARNING_TEXT1_Y_EXPR + POPUP_TEXT_H_EXPR)
#define VIDEO_WARNING_BUTTON_GAP_EXPR (BODY_PADDING * 2 + POPUP_BORDER_WIDTH)
#define VIDEO_WARNING_BUTTON_W_EXPR ((POPUP_PANEL_W_EXPR - POPUP_BUTTON_SIDE_PADDING_EXPR * 2 - VIDEO_WARNING_BUTTON_GAP_EXPR * 2) / 3)
#define VIDEO_WARNING_BUTTON_Y_EXPR (VIDEO_WARNING_TEXT2_Y_EXPR + POPUP_TEXT_H_EXPR + POPUP_BUTTON_TOP_GAP_EXPR)
#define VIDEO_WARNING_BUTTON_APPLY_X_EXPR (POPUP_PANEL_MARGIN_EXPR + POPUP_BUTTON_SIDE_PADDING_EXPR)
#define VIDEO_WARNING_BUTTON_DISCARD_X_EXPR (VIDEO_WARNING_BUTTON_APPLY_X_EXPR + VIDEO_WARNING_BUTTON_W_EXPR + VIDEO_WARNING_BUTTON_GAP_EXPR)
#define VIDEO_WARNING_BUTTON_CANCEL_X_EXPR (VIDEO_WARNING_BUTTON_DISCARD_X_EXPR + VIDEO_WARNING_BUTTON_W_EXPR + VIDEO_WARNING_BUTTON_GAP_EXPR)
#define VIDEO_WARNING_PANEL_RECT POPUP_PANEL_X $evalint(VIDEO_WARNING_PANEL_Y_EXPR) POPUP_PANEL_W $evalint(VIDEO_WARNING_PANEL_H_EXPR)
#define VIDEO_WARNING_TITLE_RECT POPUP_CONTENT_X $evalint(VIDEO_WARNING_TITLE_Y_EXPR) POPUP_CONTENT_W POPUP_TITLE_H
#define VIDEO_WARNING_TEXT1_RECT POPUP_CONTENT_X $evalint(VIDEO_WARNING_TEXT1_Y_EXPR) POPUP_CONTENT_W POPUP_TEXT_H
#define VIDEO_WARNING_TEXT2_RECT POPUP_CONTENT_X $evalint(VIDEO_WARNING_TEXT2_Y_EXPR) POPUP_CONTENT_W POPUP_TEXT_H
#define VIDEO_WARNING_BUTTON_APPLY_RECT $evalint(VIDEO_WARNING_BUTTON_APPLY_X_EXPR) $evalint(VIDEO_WARNING_BUTTON_Y_EXPR) $evalint(VIDEO_WARNING_BUTTON_W_EXPR) POPUP_BUTTON_H
#define VIDEO_WARNING_BUTTON_DISCARD_RECT $evalint(VIDEO_WARNING_BUTTON_DISCARD_X_EXPR) $evalint(VIDEO_WARNING_BUTTON_Y_EXPR) $evalint(VIDEO_WARNING_BUTTON_W_EXPR) POPUP_BUTTON_H
#define VIDEO_WARNING_BUTTON_CANCEL_RECT $evalint(VIDEO_WARNING_BUTTON_CANCEL_X_EXPR) $evalint(VIDEO_WARNING_BUTTON_Y_EXPR) $evalint(VIDEO_WARNING_BUTTON_W_EXPR) POPUP_BUTTON_H
#define VIDEO_WARNING_BUTTON_TEXT_X $evalint(VIDEO_WARNING_BUTTON_W_EXPR / 2)

// Video-restart confirmation popup layout.
#define VIDEO_RESTART_PANEL_H_EXPR (POPUP_RESTART_TITLE_TOP_PADDING_EXPR + POPUP_TITLE_H_EXPR + POPUP_TEXT_GAP_EXPR + POPUP_TEXT_H_EXPR + POPUP_BUTTON_TOP_GAP_EXPR + POPUP_BUTTON_H_EXPR + POPUP_PANEL_BOTTOM_PADDING_EXPR)
#define VIDEO_RESTART_PANEL_Y_EXPR ((SCREEN_HEIGHT - VIDEO_RESTART_PANEL_H_EXPR) / 2 - HEADER_PADDING * 2 + POPUP_BORDER_WIDTH)
#define VIDEO_RESTART_TITLE_Y_EXPR (VIDEO_RESTART_PANEL_Y_EXPR + POPUP_RESTART_TITLE_TOP_PADDING_EXPR)
#define VIDEO_RESTART_TEXT1_Y_EXPR (VIDEO_RESTART_PANEL_Y_EXPR + POPUP_RESTART_TITLE_TOP_PADDING_EXPR + POPUP_TITLE_H_EXPR + POPUP_TEXT_GAP_EXPR)
#define VIDEO_RESTART_BUTTON_SIDE_PADDING_EXPR (BODY_PADDING * 6)
#define VIDEO_RESTART_BUTTON_GAP_EXPR (BODY_PADDING * 5 + BODY_OPTION_OFFSET + POPUP_BORDER_WIDTH)
#define VIDEO_RESTART_BUTTON_W_EXPR ((POPUP_PANEL_W_EXPR - VIDEO_RESTART_BUTTON_SIDE_PADDING_EXPR * 2 - VIDEO_RESTART_BUTTON_GAP_EXPR) / 2)
#define VIDEO_RESTART_BUTTON_Y_EXPR (VIDEO_RESTART_TEXT1_Y_EXPR + POPUP_TEXT_H_EXPR + POPUP_BUTTON_TOP_GAP_EXPR)
#define VIDEO_RESTART_BUTTON_NO_X_EXPR (POPUP_PANEL_MARGIN_EXPR + VIDEO_RESTART_BUTTON_SIDE_PADDING_EXPR)
#define VIDEO_RESTART_BUTTON_YES_X_EXPR (VIDEO_RESTART_BUTTON_NO_X_EXPR + VIDEO_RESTART_BUTTON_W_EXPR + VIDEO_RESTART_BUTTON_GAP_EXPR)
#define VIDEO_RESTART_PANEL_RECT POPUP_PANEL_X $evalint(VIDEO_RESTART_PANEL_Y_EXPR) POPUP_PANEL_W $evalint(VIDEO_RESTART_PANEL_H_EXPR)
#define VIDEO_RESTART_TITLE_RECT POPUP_CONTENT_X $evalint(VIDEO_RESTART_TITLE_Y_EXPR) POPUP_CONTENT_W POPUP_TITLE_H
#define VIDEO_RESTART_TEXT1_RECT POPUP_CONTENT_X $evalint(VIDEO_RESTART_TEXT1_Y_EXPR) POPUP_CONTENT_W POPUP_TEXT_H
#define VIDEO_RESTART_BUTTON_NO_RECT $evalint(VIDEO_RESTART_BUTTON_NO_X_EXPR) $evalint(VIDEO_RESTART_BUTTON_Y_EXPR) $evalint(VIDEO_RESTART_BUTTON_W_EXPR) POPUP_BUTTON_H
#define VIDEO_RESTART_BUTTON_YES_RECT $evalint(VIDEO_RESTART_BUTTON_YES_X_EXPR) $evalint(VIDEO_RESTART_BUTTON_Y_EXPR) $evalint(VIDEO_RESTART_BUTTON_W_EXPR) POPUP_BUTTON_H
#define VIDEO_RESTART_BUTTON_TEXT_X $evalint(VIDEO_RESTART_BUTTON_W_EXPR / 2)

// Shared popup menu names.
#define NEWMENU_VIDEO_WARNING newmenu_video_warning_menu
#define NEWMENU_VIDEO_RESTART newmenu_video_restart_menu

// Video dirty-state helpers.
#define MARK_VIDEO_DIRTY \
    setcvar    ui_r_modified 1 ; \
    show       applyChanges ;

#define MARK_VIDEO_RESTART \
    setcvar    ui_r_modified 1 ; \
    setcvar    ui_vidrestart 1 ; \
    show       applyChanges ;

#define HIDE_APPLY \
    hide        applyChanges ;

#define HIDE_PAGE_UI \
    HIDE_PAGE_BARS \
    HIDE_PAGE_BODIES

// Hover/focus helpers.
#define HIGHLIGHT \
itemDef \
{ \
    name                newmenu_hover_highlight \
    rect                0 0 0 0 \
    style               WINDOW_STYLE_FILLED \
    forecolor           COL_HOVER \
    backcolor           COL_HOVER \
    visible             1 \
    decoration \
}

#define DUMMYHIGHLIGHT \
itemDef \
{ \
    name                newmenu_focus_dummy \
    rect                0 0 0 0 \
    style               WINDOW_STYLE_FILLED \
    forecolor           COL_BLACK \
    backcolor           COL_BLACK \
    visible             0 \
    decoration \
}

#define SELECTEDHIGHLIGHT(highlightName) \
itemDef \
{ \
    name        highlightName \
    rect        0 0 0 0 \
    style       WINDOW_STYLE_FILLED \
    forecolor   COL_SELECTED_TAB \
    backcolor   COL_SELECTED_TAB \
    visible     1 \
    decoration \
}

#define MAKE_INTERACTIVE(interactiveRect) \
    mouseEnter { \
        setitemrect newmenu_hover_highlight interactiveRect ; \
    } \
    mouseExit { \
        setitemrect newmenu_hover_highlight interactiveRect ; \
        setfocus newmenu_focus_dummy ; \
    }

#define NOBORDER \
    border      0 \
    bordercolor COL_NONE

// Conditional visibility/enabling fragments.
// OpenJK supports exactly one show/hide/enable/disable condition per item.
// These fragments are intended to be spliced into custom itemDefs when needed.
#define ROW_COND_SHOW(testCvar, values) \
    cvarTest        testCvar \
    showCvar        values

#define ROW_COND_HIDE(testCvar, values) \
    cvarTest        testCvar \
    hideCvar        values

#define ROW_COND_ENABLE(testCvar, values) \
    cvarTest        testCvar \
    enableCvar      values

#define ROW_COND_DISABLE(testCvar, values) \
    cvarTest        testCvar \
    disableCvar     values

// Generic item building blocks.
#define ITEM_COMMON(itemName, itemGroup, itemRect, itemStyle, itemColor, itemBorder, itemVisible) \
    name        itemName \
    group       itemGroup \
    rect        itemRect \
    style       itemStyle \
    backcolor   itemColor \
    forecolor   itemColor \
    itemBorder \
    visible     itemVisible

#define ITEM_BACKGROUND(itemName, itemGroup, itemRect, itemColor) \
    itemDef { \
        ITEM_COMMON(itemName, itemGroup, itemRect, WINDOW_STYLE_FILLED, itemColor, NOBORDER, INVISIBLE) \
        decoration \
    }


// Standalone widget helpers.
// These are intentionally ITEM_* helpers, not ROW_* helpers: listboxes, ownerdraws,
// models, shader images, and text scrolls are full widgets/containers rather than
// label+control body rows.
#define ITEM_SHADER(itemName, itemGroup, itemRect, itemShader, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        style           WINDOW_STYLE_SHADER \
        background      itemShader \
        forecolor       COL_WHITE \
        visible         itemVisible \
        decoration \
    }

#define ITEM_SHADER_EX(itemName, itemGroup, itemRect, itemShader, itemVisible, itemExtra) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        style           WINDOW_STYLE_SHADER \
        background      itemShader \
        forecolor       COL_WHITE \
        visible         itemVisible \
        itemExtra \
    }

#define ITEM_IMAGE(itemName, itemGroup, itemRect, itemShader, itemVisible) \
    ITEM_SHADER(itemName, itemGroup, itemRect, itemShader, itemVisible)

#define ITEM_IMAGE_EX(itemName, itemGroup, itemRect, itemShader, itemVisible, itemExtra) \
    ITEM_SHADER_EX(itemName, itemGroup, itemRect, itemShader, itemVisible, itemExtra)

#define ITEM_IMAGE_COLOR(itemName, itemGroup, itemRect, itemShader, itemColor, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        style           WINDOW_STYLE_SHADER \
        background      itemShader \
        forecolor       itemColor \
        visible         itemVisible \
        decoration \
    }

#define ITEM_OWNERDRAW(itemName, itemGroup, itemRect, itemOwnerdraw, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        style           WINDOW_STYLE_EMPTY \
        ownerdraw       itemOwnerdraw \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        textalign       ITEM_ALIGN_LEFT \
        textalignx      BODY_PADDING \
        textaligny      BODY_OPTION_OFFSET \
        forecolor       COL_TEXT_PRIMARY \
        visible         itemVisible \
    }

#define ITEM_OWNERDRAW_EX(itemName, itemGroup, itemRect, itemOwnerdraw, itemVisible, itemExtra) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        style           WINDOW_STYLE_EMPTY \
        ownerdraw       itemOwnerdraw \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        textalign       ITEM_ALIGN_LEFT \
        textalignx      BODY_PADDING \
        textaligny      BODY_OPTION_OFFSET \
        forecolor       COL_TEXT_PRIMARY \
        visible         itemVisible \
        itemExtra \
    }

#define ITEM_LISTBOX_TEXT(itemName, itemGroup, itemRect, itemFeeder, itemElementHeight, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_LISTBOX \
        style           WINDOW_STYLE_FILLED \
        feeder          itemFeeder \
        elementtype     LISTBOX_TEXT \
        elementwidth    BODY_COLUMN_W \
        elementheight   itemElementHeight \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        textaligny      BODY_OPTION_OFFSET \
        forecolor       COL_TEXT_PRIMARY \
        backcolor       COL_ROW_CONTROL_BACK \
        border          1 \
        bordercolor     COL_ROW_CONTROL_BORDER \
        visible         itemVisible \
    }

#define ITEM_LISTBOX_TEXT_EX(itemName, itemGroup, itemRect, itemFeeder, itemElementHeight, itemVisible, itemExtra) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_LISTBOX \
        style           WINDOW_STYLE_FILLED \
        feeder          itemFeeder \
        elementtype     LISTBOX_TEXT \
        elementwidth    BODY_COLUMN_W \
        elementheight   itemElementHeight \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        textaligny      BODY_OPTION_OFFSET \
        forecolor       COL_TEXT_PRIMARY \
        backcolor       COL_ROW_CONTROL_BACK \
        border          1 \
        bordercolor     COL_ROW_CONTROL_BORDER \
        visible         itemVisible \
        itemExtra \
    }

#define ITEM_MODEL(itemName, itemGroup, itemRect, itemModel, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_MODEL \
        asset_model     itemModel \
        style           WINDOW_STYLE_EMPTY \
        forecolor       COL_WHITE \
        visible         itemVisible \
    }

#define ITEM_MODEL_EX(itemName, itemGroup, itemRect, itemModel, itemVisible, itemExtra) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_MODEL \
        asset_model     itemModel \
        style           WINDOW_STYLE_EMPTY \
        forecolor       COL_WHITE \
        visible         itemVisible \
        itemExtra \
    }

#define ITEM_TEXTSCROLL(itemName, itemGroup, itemRect, itemFeeder, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_TEXTSCROLL \
        style           WINDOW_STYLE_FILLED \
        feeder          itemFeeder \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        forecolor       COL_TEXT_PRIMARY \
        backcolor       COL_ROW_CONTROL_BACK \
        border          1 \
        bordercolor     COL_ROW_CONTROL_BORDER \
        visible         itemVisible \
    }

#define ITEM_TEXTSCROLL_EX(itemName, itemGroup, itemRect, itemFeeder, itemVisible, itemExtra) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        rect            itemRect \
        type            ITEM_TYPE_TEXTSCROLL \
        style           WINDOW_STYLE_FILLED \
        feeder          itemFeeder \
        font            BODY_FONT \
        textscale       BODY_FONT_SIZE \
        forecolor       COL_TEXT_PRIMARY \
        backcolor       COL_ROW_CONTROL_BACK \
        border          1 \
        bordercolor     COL_ROW_CONTROL_BORDER \
        visible         itemVisible \
        itemExtra \
    }

// Header and menu chrome items.
#define ITEM_EXIT(itemName, itemGroup, itemRect, itemColor, itemShader) \
    itemDef { \
        ITEM_COMMON(itemName, itemGroup, itemRect, WINDOW_STYLE_SHADER, itemColor, NOBORDER, INVISIBLE) \
        type            ITEM_TYPE_BUTTON \
        background      itemShader \
        MAKE_INTERACTIVE(itemRect) \
        action \
        { \
            defer VideoSetup NEWMENU_VIDEO_WARNING ; \
            close ingame_newmenu ; \
        } \
    }

#define ITEM_EXIT_SELF(itemName, itemGroup, itemRect, itemColor, itemShader, currentMenu) \
    itemDef { \
        ITEM_COMMON(itemName, itemGroup, itemRect, WINDOW_STYLE_SHADER, itemColor, NOBORDER, INVISIBLE) \
        type            ITEM_TYPE_BUTTON \
        background      itemShader \
        MAKE_INTERACTIVE(itemRect) \
        action \
        { \
            defer VideoSetup NEWMENU_VIDEO_WARNING ; \
            close currentMenu ; \
        } \
    }

#define ITEM_APPLY_CHANGES \
    itemDef \
    { \
        name            applyChanges \
        group           applyChanges \
        text            APPLY_CHANGES_TEXT \
        type            ITEM_TYPE_BUTTON \
        style           WINDOW_STYLE_FILLED \
        rect            APPLY_CHANGES_X APPLY_CHANGES_Y APPLY_CHANGES_W APPLY_CHANGES_H \
        font            HEADER_FONT \
        textscale       APPLY_CHANGES_TEXT_SCALE \
        textalign       ITEM_ALIGN_CENTER \
        textalignx      APPLY_CHANGES_TEXT_X \
        textaligny      APPLY_CHANGES_TEXT_Y \
        textstyle       HEADER_FONT_STYLE \
        forecolor       COL_APPLY_FORE \
        backcolor       COL_APPLY_BACK \
        border          1 \
        bordercolor     COL_APPLY_BORDER \
        cvarTest        ui_r_modified \
        showCvar        { 1 } \
        visible         0 \
        descText        "Apply modified video settings." \
        MAKE_INTERACTIVE(APPLY_CHANGES_X APPLY_CHANGES_Y APPLY_CHANGES_W APPLY_CHANGES_H) \
        action \
        { \
            play        "sound/interface/button1" ; \
            open        NEWMENU_VIDEO_RESTART ; \
        } \
    }

// Text and navigation items.
#define ITEM_TEXT(itemName, itemGroup, itemRect, itemStyle, itemColor, itemBorder, itemVisible, itemText, itemTextAlign, itemFont, itemTextScale, itemTextAlignX, itemTextAlignY, itemOutlineColor, itemTextStyle) \
        ITEM_COMMON(itemName, itemGroup, itemRect, itemStyle, itemColor, itemBorder, itemVisible) \
        text            itemText \
        textalign       itemTextAlign \
        font            itemFont \
        textscale       itemTextScale \
        textalignx      itemTextAlignX \
        textaligny      itemTextAlignY \
        outlinecolor    itemOutlineColor \
        textstyle       itemTextStyle

#define TEXT_BOX_HEADER(itemName, itemGroup, itemRect, itemVisible, itemText) \
    itemDef \
    { \
    ITEM_TEXT(itemName, itemGroup, itemRect, WINDOW_STYLE_EMPTY, COL_TEXT_PRIMARY, NOBORDER, itemVisible, itemText, ITEM_ALIGN_LEFT, HEADER_FONT, HEADER_FONT_SIZE, HEADER_PADDING,  0, COL_NONE, ITEM_TEXTSTYLE_NORMAL) \
    }

#define TEXT_BOX_BODY(itemName, itemGroup, itemRect, itemVisible, itemText, itemDesc) \
    itemDef \
    { \
    ITEM_TEXT(itemName, itemGroup, itemRect, WINDOW_STYLE_EMPTY, COL_TEXT_SECONDARY, NOBORDER, itemVisible, itemText, ITEM_ALIGN_LEFT, BODY_FONT, BODY_FONT_SIZE, BODY_PADDING,  0, COL_NONE, ITEM_TEXTSTYLE_NORMAL) \
    descText        itemDesc \
    MAKE_INTERACTIVE(itemRect) \
    }

#define TEXT_BOX_BODY2Y(itemName, itemGroup, itemRect, itemVisible, itemText, itemText2, itemText2AlignY, itemDesc) \
    itemDef \
    { \
    ITEM_TEXT(itemName, itemGroup, itemRect, WINDOW_STYLE_EMPTY, COL_TEXT_SECONDARY, NOBORDER, itemVisible, itemText, ITEM_ALIGN_LEFT, BODY_FONT, BODY_FONT_SIZE, BODY_PADDING, 0, COL_NONE, ITEM_TEXTSTYLE_NORMAL) \
    text2           itemText2 \
    text2aligny     itemText2AlignY \
    descText        itemDesc \
    MAKE_INTERACTIVE(itemRect) \
    }

#define TEXT_BOX_BODY2(itemName, itemGroup, itemRect, itemVisible, itemText, itemText2, itemDesc) \
    TEXT_BOX_BODY2Y(itemName, itemGroup, itemRect, itemVisible, itemText, itemText2, BODY_ROW_H, itemDesc)

#define ITEM_BODY_TEXT_BOX(itemName, itemGroup, rowY, itemText, itemDesc) \
    TEXT_BOX_BODY(itemName, itemGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, itemText, itemDesc)

#define ITEM_TAB_BUTTON(itemName, itemGroup, itemText, itemRect, itemTextAlignX, itemDesc, targetDefaultPage, targetDefaultPageRect, targetPageBar, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        text            itemText \
        style           WINDOW_STYLE_EMPTY \
        type            ITEM_TYPE_BUTTON \
        rect            itemRect \
        font            HEADER_FONT \
        textscale       MENU_TAB_FONT_SIZE \
        textalignx      itemTextAlignX \
        textaligny      HEADER_HEIGHT_SEVENTH \
        textstyle       HEADER_FONT_STYLE \
        textalign       ITEM_ALIGN_CENTER \
        forecolor       COL_TEXT_PRIMARY \
        visible         itemVisible \
        descText        itemDesc \
        MAKE_INTERACTIVE(itemRect) \
        action \
        { \
            play        "sound/interface/button1.wav" ; \
            defer       VideoSetup NEWMENU_VIDEO_WARNING ; \
            HIDE_PAGE_UI \
            HIDE_APPLY \
            show        targetPageBar ; \
            show        targetDefaultPage ; \
            setitemrect newmenu_selected_page_highlight targetDefaultPageRect ; \
        } \
    }

#define ITEM_TAB_NAV(itemName, itemGroup, itemText, itemRect, itemTextAlignX, itemDesc, currentMenu, targetMenu, itemVisible) \
    itemDef \
    { \
        name            itemName \
        group           itemGroup \
        text            itemText \
        style           WINDOW_STYLE_EMPTY \
        type            ITEM_TYPE_BUTTON \
        rect            itemRect \
        font            HEADER_FONT \
        textscale       MENU_TAB_FONT_SIZE \
        textalignx      itemTextAlignX \
        textaligny      HEADER_HEIGHT_SEVENTH \
        textstyle       HEADER_FONT_STYLE \
        textalign       ITEM_ALIGN_CENTER \
        forecolor       COL_TEXT_PRIMARY \
        visible         itemVisible \
        descText        itemDesc \
        MAKE_INTERACTIVE(itemRect) \
        action \
        { \
            play        "sound/interface/button1.wav" ; \
            defer       VideoSetup NEWMENU_VIDEO_WARNING ; \
            close       currentMenu ; \
            open        targetMenu ; \
        } \
    }

#define ITEM_PAGE_BUTTON(itemName, itemGroup, itemText, itemRect, itemTextAlignX, itemDesc, targetPage) \
    ITEM_PAGE_BUTTON_IMPL(itemName, itemGroup, itemText, itemRect, itemTextAlignX, itemDesc, targetPage)

#define ITEM_PAGE_BUTTON_IMPL(itemName, itemGroup, itemText, itemRect, itemTextAlignX, itemDesc, targetPage) \
    itemDef { \
        name            itemName \
        group           itemGroup \
        text            itemText \
        style           WINDOW_STYLE_EMPTY \
        type            ITEM_TYPE_BUTTON \
        rect            itemRect \
        font            HEADER_FONT \
        textscale       PAGE_BUTTON_FONT_SIZE \
        textalignx      itemTextAlignX \
        textaligny      PAGE_BUTTON_TEXT_Y \
        textstyle       HEADER_FONT_STYLE \
        textalign       ITEM_ALIGN_CENTER \
        forecolor       COL_TEXT_SECONDARY \
        visible         INVISIBLE \
        descText        itemDesc \
        MAKE_INTERACTIVE(itemRect) \
        action { \
            play        "sound/interface/button1.wav" ; \
            HIDE_PAGE_UI \
            setitemrect newmenu_selected_page_highlight itemRect ; \
            show        itemGroup ; \
            show        targetPage ; \
        } \
    }

// Body control action tails.
// Pass these as the final rowAction argument to rows with controls.
// Custom action fragments are also valid as long as they do not contain commas.
#define ACT_NONE \
    ;

#define ACT_DIRTY \
    MARK_VIDEO_DIRTY

#define ACT_RESTART \
    MARK_VIDEO_RESTART

// Low-level helpers for direct action-block use. Prefer ROW_CMD for command rows; do not pass
// parameterized helpers through rowAction because nested macro parentheses are stripped.
#define ACT_CMD(commandText) \
    exec commandText ;

#define ACT_OPEN(menuName) \
    open menuName ;

#define ACT_CLOSE(menuName) \
    close menuName ;

// Body control primitives.
// ITEM_BODY_CONTROL_IMPL emits a normal control. ITEM_BODY_CONTROL_EX_IMPL also splices
// itemDef-level extras such as cvarTest/showCvar/hideCvar/enableCvar/disableCvar.
// controlAction is inserted inside action { ... } after play.
#define ITEM_BODY_CONTROL_IMPL(controlName, controlGroup, controlRect, controlDesc, controlAction) \
    name                controlName##_control \
    group               controlGroup \
    text                BODY_OPTION_TEXT \
    rect                controlRect \
    textalign           ITEM_ALIGN_RIGHT \
    textalignx          BODY_OPTION_PADDING \
    textaligny          BODY_OPTION_OFFSET \
    textscale           BODY_OPTION_SCALE \
    font                BODY_OPTION_FONT \
    style               WINDOW_STYLE_FILLED \
    forecolor           COL_TEXT_PRIMARY \
    backcolor           COL_ROW_CONTROL_BACK \
    border              1 \
    bordercolor         COL_ROW_CONTROL_BORDER \
    descText            controlDesc \
    visible             VISIBLE \
    MAKE_INTERACTIVE(controlRect) \
    action \
    { \
        play            "sound/interface/button1" ; \
        controlAction \
    }

#define ITEM_BODY_CONTROL_EX_IMPL(controlName, controlGroup, controlRect, controlDesc, controlExtra, controlAction) \
    name                controlName##_control \
    group               controlGroup \
    text                BODY_OPTION_TEXT \
    rect                controlRect \
    textalign           ITEM_ALIGN_RIGHT \
    textalignx          BODY_OPTION_PADDING \
    textaligny          BODY_OPTION_OFFSET \
    textscale           BODY_OPTION_SCALE \
    font                BODY_OPTION_FONT \
    style               WINDOW_STYLE_FILLED \
    forecolor           COL_TEXT_PRIMARY \
    backcolor           COL_ROW_CONTROL_BACK \
    border              1 \
    bordercolor         COL_ROW_CONTROL_BORDER \
    descText            controlDesc \
    visible             VISIBLE \
    controlExtra \
    MAKE_INTERACTIVE(controlRect) \
    action \
    { \
        play            "sound/interface/button1" ; \
        controlAction \
    }

#define ITEM_BODY_CONTROL_CMD_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCommand) \
    name                controlName##_control \
    group               controlGroup \
    text                BODY_OPTION_TEXT \
    rect                controlRect \
    textalign           ITEM_ALIGN_RIGHT \
    textalignx          BODY_OPTION_PADDING \
    textaligny          BODY_OPTION_OFFSET \
    textscale           BODY_OPTION_SCALE \
    font                BODY_OPTION_FONT \
    style               WINDOW_STYLE_FILLED \
    forecolor           COL_TEXT_PRIMARY \
    backcolor           COL_ROW_CONTROL_BACK \
    border              1 \
    bordercolor         COL_ROW_CONTROL_BORDER \
    descText            controlDesc \
    visible             VISIBLE \
    MAKE_INTERACTIVE(controlRect) \
    action \
    { \
        play            "sound/interface/button1" ; \
        exec            controlCommand ; \
    }

// Backwards-compatible action aliases for older helper names.
#define ITEM_BODY_GENERIC(controlName, controlGroup, controlRect, controlDesc) \
    ITEM_BODY_CONTROL_IMPL(controlName, controlGroup, controlRect, controlDesc, ACT_NONE)

#define ITEM_BODY_D(controlName, controlGroup, controlRect, controlDesc) \
    ITEM_BODY_CONTROL_IMPL(controlName, controlGroup, controlRect, controlDesc, ACT_DIRTY)

#define ITEM_BODY_DR(controlName, controlGroup, controlRect, controlDesc) \
    ITEM_BODY_CONTROL_IMPL(controlName, controlGroup, controlRect, controlDesc, ACT_RESTART)

#define ITEM_BODY_ACTION_IMPL(controlName, controlGroup, controlRect, controlDesc, controlAction) \
    ITEM_BODY_CONTROL_IMPL(controlName, controlGroup, controlRect, controlDesc, controlAction)

#define ITEM_BODY_CMD_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCommand) \
    ITEM_BODY_CONTROL_CMD_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCommand)

#define ITEM_BODY_GENERIC_COND(controlName, controlGroup, controlRect, controlDesc, controlCond) \
    ITEM_BODY_CONTROL_EX_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCond, ACT_NONE)

#define ITEM_BODY_D_COND(controlName, controlGroup, controlRect, controlDesc, controlCond) \
    ITEM_BODY_CONTROL_EX_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCond, ACT_DIRTY)

#define ITEM_BODY_DR_COND(controlName, controlGroup, controlRect, controlDesc, controlCond) \
    ITEM_BODY_CONTROL_EX_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCond, ACT_RESTART)

#define ITEM_BODY_ACTION_COND_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCond, controlAction) \
    ITEM_BODY_CONTROL_EX_IMPL(controlName, controlGroup, controlRect, controlDesc, controlCond, controlAction)

#define ITEM_BODY_BUTTON_IMPL(controlName, controlGroup, controlRect, controlDesc, controlAction) \
    ITEM_BODY_ACTION_IMPL(controlName, controlGroup, controlRect, controlDesc, controlAction)

// Body control item wrappers.
// Each wrapper emits a left-side TEXT_BOX_BODY label plus a right-side control in the same row.
//
// Row action model:
// - Pass ACT_NONE for ordinary controls.
// - Pass ACT_DIRTY for video changes that can apply without vid_restart.
// - Pass ACT_RESTART for video changes that require vid_restart.
// - Pass a raw custom action fragment for special rows, e.g. uiScript glCustom ; ACT_RESTART
// - Use ROW_CMD for exec commands. Parameterized action helpers such as ACT_CMD(...),
//   ACT_OPEN(...), and ACT_CLOSE(...) cannot be forwarded as rowAction arguments because the
//   botlib macro parser strips nested parentheses.
//
// Conditional/extras model:
// - *_EX variants splice rowExtra into both label and control itemDefs.
// - Use ROW_COND_SHOW/HIDE/ENABLE/DISABLE as rowExtra.
// - OpenJK supports one cvar condition kind per item.

#define TEXT_BOX_BODY_EX(itemName, itemGroup, itemRect, itemVisible, itemText, itemDesc, itemExtra) \
    itemDef \
    { \
    ITEM_TEXT(itemName, itemGroup, itemRect, WINDOW_STYLE_EMPTY, COL_TEXT_SECONDARY, NOBORDER, itemVisible, itemText, ITEM_ALIGN_LEFT, BODY_FONT, BODY_FONT_SIZE, BODY_PADDING,  0, COL_NONE, ITEM_TEXTSTYLE_NORMAL) \
    descText        itemDesc \
    itemExtra \
    MAKE_INTERACTIVE(itemRect) \
    }

#define ITEM_BODY_TEXT_BOX_EX(itemName, itemGroup, rowY, itemText, itemDesc, itemExtra) \
    TEXT_BOX_BODY_EX(itemName, itemGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, itemText, itemDesc, itemExtra)

#define ITEM_BODY_MULTI_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowChoices, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarStrList         rowChoices \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_MULTI(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowChoices, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarStrList         rowChoices \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_MULTIFL_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowChoices, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarFloatList       rowChoices \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_MULTIFL(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowChoices, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarFloatList       rowChoices \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_MULTI_FEEDER_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowFeeder, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        feeder              rowFeeder \
        cvarStrList         feeder \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_MULTI_FEEDER(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowFeeder, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        feeder              rowFeeder \
        cvarStrList         feeder \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_NUMERIC_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_NUMERICFIELD \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_NUMERIC(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_NUMERICFIELD \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_SLIDERFL_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_SLIDER \
        cvarFloat           rowCvar rowDefault rowMin rowMax \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_SLIDERFL(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_SLIDER \
        cvarFloat           rowCvar rowDefault rowMin rowMax \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_SLIDERINT_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_INTSLIDER \
        cvarInt             rowCvar rowDefault rowMin rowMax \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_SLIDERINT(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_INTSLIDER \
        cvarInt             rowCvar rowDefault rowMin rowMax \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_CHECKBOX_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowBitMask, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_CHECKBOX \
        cvar                rowCvar \
        bitMask             rowBitMask \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_CHECKBOX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowBitMask, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_CHECKBOX \
        cvar                rowCvar \
        bitMask             rowBitMask \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_YESNO_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_YESNO \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_YESNO(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_YESNO \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_EDITFIELD_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowMaxChars, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_EDITFIELD \
        cvar                rowCvar \
        maxChars            rowMaxChars \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_EDITFIELD(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowMaxChars, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_EDITFIELD \
        cvar                rowCvar \
        maxChars            rowMaxChars \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_BIND_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_BIND \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_BIND(rowName, rowGroup, rowY, rowText, rowDesc, rowCvar, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_BIND \
        cvar                rowCvar \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_ACTION_EX(rowName, rowGroup, rowY, rowText, rowDesc, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_BUTTON \
        ITEM_BODY_CONTROL_EX_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ITEM_BODY_ACTION(rowName, rowGroup, rowY, rowText, rowDesc, rowAction) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_BUTTON \
        ITEM_BODY_CONTROL_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ITEM_BODY_CMD(rowName, rowGroup, rowY, rowText, rowDesc, rowCommand) \
    TEXT_BOX_BODY(rowName##_label, rowGroup, BODY_LABEL_X rowY BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_BUTTON \
        ITEM_BODY_CONTROL_CMD_IMPL(rowName, rowGroup, BODY_CONTROL_X rowY BODY_COLUMN_W BODY_ROW_H, rowDesc, rowCommand) \
    }

#define ITEM_BODY_BUTTON(rowName, rowGroup, rowY, rowText, rowDesc, rowAction) \
    ITEM_BODY_ACTION(rowName, rowGroup, rowY, rowText, rowDesc, rowAction)

// Public row declaration API.
// Prefer these in tab .menu files. They keep call sites focused on page, row, text, cvar,
// and action while hiding BODY_ROW_*_Y and the label/control column plumbing.
// Keep cvarStrList/cvarFloatList values as no-comma label/value pairs:
// { "Low" "low" "High" "high" } or { "Low" 0 "High" 1 }.
// Do not pass ROW_CHOICES_N(...) through row macros: nested parentheses are stripped by the
// botlib preprocessor before the inner macro can expand.
// ROW_TEXT2/ROW_SECTION2 and their Y variants consume the current row and the next row;
// use row 23 or lower for those two-line rows.
//
// Example:
//   ROW_YESNO(PAGE, 1, "Simple Items", "Use simple item models.", "cg_simpleItems", ACT_NONE)
//   ROW_SLIDERFL(PAGE, 2, "Gamma", "Adjust gamma.", "ui_r_gamma", 1.0, 0.5, 3.0, ACT_DIRTY)
//   ROW_MULTI(PAGE, 3, "Texture Filter", "Texture filtering.", "ui_r_texturemode", { "Bilinear" "GL_LINEAR_MIPMAP_NEAREST" "Trilinear" "GL_LINEAR_MIPMAP_LINEAR" }, ACT_RESTART)
//   ROW_ACTION(PAGE, 4, "Apply", "Apply video settings.", uiScript updatevideosetup ; HIDE_APPLY)
//
// Item ID is automatically generated as:   <page>_row_<row>

// Low-level choice helpers. Safe only when expanded directly beside cvarStrList/cvarFloatList,
// not when passed as a rowChoices argument to ROW_MULTI/ROW_MULTIFL.
#define ROW_CHOICES_1(text1, value1) \
    { text1 value1 }

#define ROW_CHOICES_2(text1, value1, text2, value2) \
    { text1 value1 text2 value2 }

#define ROW_CHOICES_3(text1, value1, text2, value2, text3, value3) \
    { text1 value1 text2 value2 text3 value3 }

#define ROW_CHOICES_4(text1, value1, text2, value2, text3, value3, text4, value4) \
    { text1 value1 text2 value2 text3 value3 text4 value4 }

#define ROW_CHOICES_5(text1, value1, text2, value2, text3, value3, text4, value4, text5, value5) \
    { text1 value1 text2 value2 text3 value3 text4 value4 text5 value5 }

#define ROW_CHOICES_6(text1, value1, text2, value2, text3, value3, text4, value4, text5, value5, text6, value6) \
    { text1 value1 text2 value2 text3 value3 text4 value4 text5 value5 text6 value6 }

#define ROW_CHOICES_7(text1, value1, text2, value2, text3, value3, text4, value4, text5, value5, text6, value6, text7, value7) \
    { text1 value1 text2 value2 text3 value3 text4 value4 text5 value5 text6 value6 text7 value7 }

#define ROW_CHOICES_8(text1, value1, text2, value2, text3, value3, text4, value4, text5, value5, text6, value6, text7, value7, text8, value8) \
    { text1 value1 text2 value2 text3 value3 text4 value4 text5 value5 text6 value6 text7 value7 text8 value8 }

#define ROW_TEXT(pageName, rowNumber, rowText, rowDesc) \
    ITEM_BODY_TEXT_BOX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc)

#define ROW_TEXT_EX(pageName, rowNumber, rowText, rowDesc, rowExtra) \
    ITEM_BODY_TEXT_BOX_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowExtra)

#define ROW_SECTION(pageName, rowNumber, rowText, rowDesc) \
    TEXT_BOX_BODY(pageName##_row_##rowNumber, pageName, BODY_FULL_X BODY_ROW_##rowNumber##_Y BODY_FULL_W BODY_ROW_H, INVISIBLE, rowText, rowDesc)

#define ROW_SECTION_EX(pageName, rowNumber, rowText, rowDesc, rowExtra) \
    TEXT_BOX_BODY_EX(pageName##_row_##rowNumber, pageName, BODY_FULL_X BODY_ROW_##rowNumber##_Y BODY_FULL_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra)

#define ROW_TEXT2(pageName, rowNumber, rowText, rowText2, rowDesc) \
    TEXT_BOX_BODY2(pageName##_row_##rowNumber, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H2, INVISIBLE, rowText, rowText2, rowDesc)

#define ROW_SECTION2(pageName, rowNumber, rowText, rowText2, rowDesc) \
    TEXT_BOX_BODY2(pageName##_row_##rowNumber, pageName, BODY_FULL_X BODY_ROW_##rowNumber##_Y BODY_FULL_W BODY_ROW_H2, INVISIBLE, rowText, rowText2, rowDesc)

#define ROW_TEXT2Y(pageName, rowNumber, rowText, rowText2, rowText2AlignY, rowDesc) \
    TEXT_BOX_BODY2Y(pageName##_row_##rowNumber, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H2, INVISIBLE, rowText, rowText2, rowText2AlignY, rowDesc)

#define ROW_SECTION2Y(pageName, rowNumber, rowText, rowText2, rowText2AlignY, rowDesc) \
    TEXT_BOX_BODY2Y(pageName##_row_##rowNumber, pageName, BODY_FULL_X BODY_ROW_##rowNumber##_Y BODY_FULL_W BODY_ROW_H2, INVISIBLE, rowText, rowText2, rowText2AlignY, rowDesc)

#define ROW_MULTI(pageName, rowNumber, rowText, rowDesc, rowCvar, rowChoices, rowAction) \
    TEXT_BOX_BODY(pageName##_row_##rowNumber##_label, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarStrList         rowChoices \
        ITEM_BODY_CONTROL_IMPL(pageName##_row_##rowNumber, pageName, BODY_CONTROL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ROW_MULTI_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowChoices, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(pageName##_row_##rowNumber##_label, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarStrList         rowChoices \
        ITEM_BODY_CONTROL_EX_IMPL(pageName##_row_##rowNumber, pageName, BODY_CONTROL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ROW_MULTIFL(pageName, rowNumber, rowText, rowDesc, rowCvar, rowChoices, rowAction) \
    TEXT_BOX_BODY(pageName##_row_##rowNumber##_label, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarFloatList       rowChoices \
        ITEM_BODY_CONTROL_IMPL(pageName##_row_##rowNumber, pageName, BODY_CONTROL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, rowDesc, rowAction) \
    }

#define ROW_MULTIFL_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowChoices, rowExtra, rowAction) \
    TEXT_BOX_BODY_EX(pageName##_row_##rowNumber##_label, pageName, BODY_LABEL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, INVISIBLE, rowText, rowDesc, rowExtra) \
    itemDef \
    { \
        type                ITEM_TYPE_MULTI \
        cvar                rowCvar \
        cvarFloatList       rowChoices \
        ITEM_BODY_CONTROL_EX_IMPL(pageName##_row_##rowNumber, pageName, BODY_CONTROL_X BODY_ROW_##rowNumber##_Y BODY_COLUMN_W BODY_ROW_H, rowDesc, rowExtra, rowAction) \
    }

#define ROW_MULTI_FEEDER(pageName, rowNumber, rowText, rowDesc, rowCvar, rowFeeder, rowAction) \
    ITEM_BODY_MULTI_FEEDER(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowFeeder, rowAction)

#define ROW_MULTI_FEEDER_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowFeeder, rowExtra, rowAction) \
    ITEM_BODY_MULTI_FEEDER_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowFeeder, rowExtra, rowAction)

#define ROW_NUMERIC(pageName, rowNumber, rowText, rowDesc, rowCvar, rowAction) \
    ITEM_BODY_NUMERIC(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowAction)

#define ROW_NUMERIC_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    ITEM_BODY_NUMERIC_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowExtra, rowAction)

#define ROW_SLIDERFL(pageName, rowNumber, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction) \
    ITEM_BODY_SLIDERFL(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction)

#define ROW_SLIDERFL_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction) \
    ITEM_BODY_SLIDERFL_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction)

#define ROW_SLIDERINT(pageName, rowNumber, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction) \
    ITEM_BODY_SLIDERINT(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowAction)

#define ROW_SLIDERINT_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction) \
    ITEM_BODY_SLIDERINT_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowDefault, rowMin, rowMax, rowExtra, rowAction)

#define ROW_CHECKBOX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowBitMask, rowAction) \
    ITEM_BODY_CHECKBOX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowBitMask, rowAction)

#define ROW_CHECKBOX_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowBitMask, rowExtra, rowAction) \
    ITEM_BODY_CHECKBOX_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowBitMask, rowExtra, rowAction)

#define ROW_YESNO(pageName, rowNumber, rowText, rowDesc, rowCvar, rowAction) \
    ITEM_BODY_YESNO(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowAction)

#define ROW_YESNO_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    ITEM_BODY_YESNO_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowExtra, rowAction)

#define ROW_EDITFIELD(pageName, rowNumber, rowText, rowDesc, rowCvar, rowMaxChars, rowAction) \
    ITEM_BODY_EDITFIELD(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowMaxChars, rowAction)

#define ROW_EDITFIELD_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowMaxChars, rowExtra, rowAction) \
    ITEM_BODY_EDITFIELD_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowMaxChars, rowExtra, rowAction)

#define ROW_BIND(pageName, rowNumber, rowText, rowDesc, rowCvar, rowAction) \
    ITEM_BODY_BIND(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowAction)

#define ROW_BIND_EX(pageName, rowNumber, rowText, rowDesc, rowCvar, rowExtra, rowAction) \
    ITEM_BODY_BIND_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCvar, rowExtra, rowAction)

#define ROW_ACTION(pageName, rowNumber, rowText, rowDesc, rowAction) \
    ITEM_BODY_ACTION(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowAction)

#define ROW_ACTION_EX(pageName, rowNumber, rowText, rowDesc, rowExtra, rowAction) \
    ITEM_BODY_ACTION_EX(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowExtra, rowAction)

#define ROW_CMD(pageName, rowNumber, rowText, rowDesc, rowCommand) \
    ITEM_BODY_CMD(pageName##_row_##rowNumber, pageName, BODY_ROW_##rowNumber##_Y, rowText, rowDesc, rowCommand)

#define ROW_BUTTON(pageName, rowNumber, rowText, rowDesc, rowAction) \
    ROW_ACTION(pageName, rowNumber, rowText, rowDesc, rowAction)

#endif
