/*
 * (C) Copyright 2014 Weng Xuetian <wengxt@gmail.com>
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef XIMPROTO_H
#define XIMPROTO_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t *xcb_im_bytearray_t;

#include "ximproto-gen.h"

#define XCB_IM_HEADER_SIZE 4

/*
 * Client Message data size
 */
#define XCB_XIM_CM_DATA_SIZE    20

/*
 * Xim implementation revision
 */
#define XCB_XIM_PROTOCOLMAJORVERSION        0
#define XCB_XIM_PROTOCOLMINORVERSION        0

/*
 * Major Protocol number
 */
#define XCB_XIM_CONNECT           1
#define XCB_XIM_CONNECT_REPLY         2
#define XCB_XIM_DISCONNECT            3
#define XCB_XIM_DISCONNECT_REPLY          4

#define XCB_XIM_AUTH_REQUIRED        10
#define XCB_XIM_AUTH_REPLY           11
#define XCB_XIM_AUTH_NEXT            12
#define XCB_XIM_AUTH_SETUP           13
#define XCB_XIM_AUTH_NG          14

#define XCB_XIM_ERROR            20

#define XCB_XIM_OPEN             30
#define XCB_XIM_OPEN_REPLY           31
#define XCB_XIM_CLOSE            32
#define XCB_XIM_CLOSE_REPLY          33
#define XCB_XIM_REGISTER_TRIGGERKEYS     34
#define XCB_XIM_TRIGGER_NOTIFY       35
#define XCB_XIM_TRIGGER_NOTIFY_REPLY     36
#define XCB_XIM_SET_EVENT_MASK       37
#define XCB_XIM_ENCODING_NEGOTIATION     38
#define XCB_XIM_ENCODING_NEGOTIATION_REPLY   39
#define XCB_XIM_QUERY_EXTENSION      40
#define XCB_XIM_QUERY_EXTENSION_REPLY    41
#define XCB_XIM_SET_IM_VALUES        42
#define XCB_XIM_SET_IM_VALUES_REPLY      43
#define XCB_XIM_GET_IM_VALUES        44
#define XCB_XIM_GET_IM_VALUES_REPLY      45

#define XCB_XIM_CREATE_IC            50
#define XCB_XIM_CREATE_IC_REPLY      51
#define XCB_XIM_DESTROY_IC           52
#define XCB_XIM_DESTROY_IC_REPLY         53
#define XCB_XIM_SET_IC_VALUES        54
#define XCB_XIM_SET_IC_VALUES_REPLY      55
#define XCB_XIM_GET_IC_VALUES        56
#define XCB_XIM_GET_IC_VALUES_REPLY      57
#define XCB_XIM_SET_IC_FOCUS         58
#define XCB_XIM_UNSET_IC_FOCUS       59
#define XCB_XIM_FORWARD_EVENT        60
#define XCB_XIM_SYNC             61
#define XCB_XIM_SYNC_REPLY           62
#define XCB_XIM_COMMIT           63
#define XCB_XIM_RESET_IC             64
#define XCB_XIM_RESET_IC_REPLY       65

#define XCB_XIM_GEOMETRY             70
#define XCB_XIM_STR_CONVERSION       71
#define XCB_XIM_STR_CONVERSION_REPLY     72
#define XCB_XIM_PREEDIT_START        73
#define XCB_XIM_PREEDIT_START_REPLY      74
#define XCB_XIM_PREEDIT_DRAW         75
#define XCB_XIM_PREEDIT_CARET        76
#define XCB_XIM_PREEDIT_CARET_REPLY      77
#define XCB_XIM_PREEDIT_DONE         78
#define XCB_XIM_STATUS_START         79
#define XCB_XIM_STATUS_DRAW          80
#define XCB_XIM_STATUS_DONE          81

typedef enum {
    XCB_XIM_SYNCHRONOUS = (1 << 0),
    XCB_XIM_LOOKUP_CHARS = (1 << 1),
    XCB_XIM_LOOKUP_KEYSYM = (1 << 2),
    XCB_XIM_LOOKUP_BOTH = XCB_XIM_LOOKUP_CHARS | XCB_XIM_LOOKUP_KEYSYM,
} xcb_xim_lookup_flags_t;

#define frame_opcode(FRAME) _Generic((FRAME), \
    xcb_im_connect_reply_fr_t: XCB_XIM_CONNECT_REPLY, \
    xcb_im_open_fr_t: XCB_XIM_OPEN, \
    xcb_im_open_reply_fr_t: XCB_XIM_OPEN_REPLY, \
    xcb_im_close_fr_t: XCB_XIM_CLOSE, \
    xcb_im_close_reply_fr_t: XCB_XIM_CLOSE_REPLY, \
    xcb_im_query_extension_fr_t: XCB_XIM_QUERY_EXTENSION, \
    xcb_im_query_extension_reply_fr_t: XCB_XIM_QUERY_EXTENSION_REPLY, \
    xcb_im_encoding_negotiation_fr_t: XCB_XIM_ENCODING_NEGOTIATION, \
    xcb_im_encoding_negotiation_reply_fr_t: XCB_XIM_ENCODING_NEGOTIATION_REPLY, \
    xcb_im_get_im_values_fr_t: XCB_XIM_GET_IM_VALUES, \
    xcb_im_get_im_values_reply_fr_t: XCB_XIM_GET_IM_VALUES_REPLY, \
    xcb_im_set_event_mask_fr_t: XCB_XIM_SET_EVENT_MASK, \
    xcb_im_create_ic_fr_t: XCB_XIM_CREATE_IC, \
    xcb_im_create_ic_reply_fr_t: XCB_XIM_CREATE_IC_REPLY, \
    xcb_im_set_ic_values_fr_t: XCB_XIM_SET_IC_VALUES, \
    xcb_im_set_ic_values_reply_fr_t: XCB_XIM_SET_IC_VALUES_REPLY, \
    xcb_im_get_ic_values_fr_t: XCB_XIM_GET_IC_VALUES, \
    xcb_im_get_ic_values_reply_fr_t: XCB_XIM_GET_IC_VALUES_REPLY, \
    xcb_im_register_triggerkeys_fr_t: XCB_XIM_REGISTER_TRIGGERKEYS, \
    xcb_im_destroy_ic_fr_t: XCB_XIM_DESTROY_IC, \
    xcb_im_destroy_ic_reply_fr_t: XCB_XIM_DESTROY_IC_REPLY, \
    xcb_im_reset_ic_fr_t: XCB_XIM_RESET_IC, \
    xcb_im_reset_ic_reply_fr_t: XCB_XIM_RESET_IC_REPLY, \
    xcb_im_trigger_notify_fr_t: XCB_XIM_TRIGGER_NOTIFY, \
    xcb_im_trigger_notify_reply_fr_t: XCB_XIM_TRIGGER_NOTIFY_REPLY, \
    xcb_im_preedit_start_fr_t: XCB_XIM_PREEDIT_START, \
    xcb_im_preedit_draw_fr_t: XCB_XIM_PREEDIT_DRAW, \
    xcb_im_preedit_caret_fr_t: XCB_XIM_PREEDIT_CARET, \
    xcb_im_preedit_done_fr_t: XCB_XIM_PREEDIT_DONE, \
    xcb_im_status_start_fr_t: XCB_XIM_STATUS_START, \
    xcb_im_status_draw_text_fr_t: XCB_XIM_STATUS_DRAW, \
    xcb_im_status_draw_bitmap_fr_t: XCB_XIM_STATUS_DRAW, \
    xcb_im_status_done_fr_t: XCB_XIM_STATUS_DONE, \
    xcb_im_commit_chars_fr_t: XCB_XIM_COMMIT, \
    xcb_im_commit_both_fr_t: XCB_XIM_COMMIT, \
    xcb_im_connect_fr_t: XCB_XIM_CONNECT, \
    xcb_im_disconnect_fr_t: XCB_XIM_DISCONNECT, \
    xcb_im_disconnect_reply_fr_t: XCB_XIM_DISCONNECT_REPLY, \
    xcb_im_set_ic_focus_fr_t: XCB_XIM_SET_IC_FOCUS, \
    xcb_im_unset_ic_focus_fr_t: XCB_XIM_UNSET_IC_FOCUS, \
    xcb_im_sync_fr_t: XCB_XIM_SYNC, \
    xcb_im_sync_reply_fr_t: XCB_XIM_SYNC_REPLY, \
    xcb_im_geometry_fr_t: XCB_XIM_GEOMETRY \
    )


typedef struct _xcb_im_ext_list{
    char *name;
    uint8_t major_opcode;
    uint8_t minor_opcode;
} xcb_im_ext_list;

/*
 * Minor Protocol Number for Extension Protocol
 */
#define XCB_XIM_EXTENSION               128
#define XCB_XIM_EXT_SET_EVENT_MASK          (0x30)
#define XCB_XIM_EXT_FORWARD_KEYEVENT        (0x32)
#define XCB_XIM_EXT_MOVE                (0x33)

#define XCB_XIM_XNQueryInputStyle "queryInputStyle"
#define XCB_XIM_XNClientWindow "clientWindow"
#define XCB_XIM_XNInputStyle "inputStyle"
#define XCB_XIM_XNFocusWindow "focusWindow"
#define XCB_XIM_XNFilterEvents "filterEvents"
#define XCB_XIM_XNPreeditAttributes "preeditAttributes"
#define XCB_XIM_XNStatusAttributes "statusAttributes"
#define XCB_XIM_XNArea "area"
#define XCB_XIM_XNAreaNeeded "areaNeeded"
#define XCB_XIM_XNSpotLocation "spotLocation"
#define XCB_XIM_XNColormap "colorMap"
#define XCB_XIM_XNStdColormap "stdColorMap"
#define XCB_XIM_XNForeground "foreground"
#define XCB_XIM_XNBackground "background"
#define XCB_XIM_XNBackgroundPixmap "backgroundPixmap"
#define XCB_XIM_XNFontSet "fontSet"
#define XCB_XIM_XNLineSpace "lineSpace"
#define XCB_XIM_XNSeparatorofNestedList "separatorofNestedList"


typedef enum _xcb_im_style_t
{
    XCB_IM_PreeditArea      = 0x0001,
    XCB_IM_PreeditCallbacks = 0x0002,
    XCB_IM_PreeditPosition  = 0x0004,
    XCB_IM_PreeditNothing   = 0x0008,
    XCB_IM_PreeditNone      = 0x0010,
    XCB_IM_StatusArea       = 0x0100,
    XCB_IM_StatusCallbacks  = 0x0200,
    XCB_IM_StatusNothing    = 0x0400,
    XCB_IM_StatusNone       = 0x0800,
} xcb_im_style_t;

enum {
    XCB_IM_TextType = 0,
    XCB_IM_BitmapType = 1
};

typedef enum {
    XCB_XIM_REVERSE = (1 << 0),
    XCB_XIM_UNDERLINE = (1 << 1),
    XCB_XIM_HIGHLIGHT = (1 << 2),
    XCB_XIM_PRIMARY = (1 << 5),
    XCB_XIM_SECONDARY = (1 << 6),
    XCB_XIM_TERTIARY = (1 << 7),
    XCB_XIM_VISIBLE_TO_FORWARD = (1 << 8),
    XCB_XIM_VISIBLE_TO_BACKWORD = (1 << 9),
    XCB_XIM_VISIBLE_TO_CENTER = (1 << 10),
} xcb_im_feedback_t;

typedef struct _xcb_im_trigger_keys_t{
    uint16_t nKeys;
    xcb_im_ximtriggerkey_fr_t *keys;
} xcb_im_trigger_keys_t;

#endif // XIMPROTO_H
