/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from Rockchip.
 * Copyright (c) 2017 FUZHOU ROCKCHIP ELECTRONICS CO., LTD. ("Rockchip").
 * 	http://www.rock-chips.com
 * 		ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from Rockchip.
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/* THIS IS NOT AN X CONSORTIUM STANDARD OR AN X PROJECT TEAM SPECIFICATION */

#ifndef _XF86VIDMODEPROTO_H_
#define _XF86VIDMODEPROTO_H_

#include <X11/extensions/xf86vm.h>

#define XF86VIDMODENAME "XFree86-VidModeExtension"

#define XF86VIDMODE_MAJOR_VERSION	2	/* current version numbers */
#define XF86VIDMODE_MINOR_VERSION	2

#define X_XF86VidModeQueryVersion	0
#define X_XF86VidModeGetModeLine	1
#define X_XF86VidModeModModeLine	2
#define X_XF86VidModeSwitchMode		3
#define X_XF86VidModeGetMonitor		4
#define X_XF86VidModeLockModeSwitch	5
#define X_XF86VidModeGetAllModeLines	6
#define X_XF86VidModeAddModeLine	7
#define X_XF86VidModeDeleteModeLine	8
#define X_XF86VidModeValidateModeLine	9
#define X_XF86VidModeSwitchToMode	10
#define X_XF86VidModeGetViewPort	11
#define X_XF86VidModeSetViewPort	12
/* new for version 2.x of this extension */
#define X_XF86VidModeGetDotClocks	13
#define X_XF86VidModeSetClientVersion	14
#define X_XF86VidModeSetGamma		15
#define X_XF86VidModeGetGamma		16
#define X_XF86VidModeGetGammaRamp	17
#define X_XF86VidModeSetGammaRamp	18
#define X_XF86VidModeGetGammaRampSize	19
#define X_XF86VidModeGetPermissions	20
/*
 * major version 0 == uses parameter-to-wire functions in XFree86 libXxf86vm.
 * major version 1 == uses parameter-to-wire functions hard-coded in xvidtune
 *                    client.
 * major version 2 == uses new protocol version in XFree86 4.0.
 */

typedef struct _XF86VidModeQueryVersion {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeQueryVersion */
    CARD16	length B16;
} xXF86VidModeQueryVersionReq;
#define sz_xXF86VidModeQueryVersionReq	4

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD16	majorVersion B16;	/* major version of XF86VidMode */
    CARD16	minorVersion B16;	/* minor version of XF86VidMode */
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86VidModeQueryVersionReply;
#define sz_xXF86VidModeQueryVersionReply	32

typedef struct _XF86VidModeGetModeLine {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	pad B16;
} xXF86VidModeGetModeLineReq,
  xXF86VidModeGetAllModeLinesReq,
  xXF86VidModeGetMonitorReq,
  xXF86VidModeGetViewPortReq,
  xXF86VidModeGetDotClocksReq,
  xXF86VidModeGetPermissionsReq;
#define sz_xXF86VidModeGetModeLineReq		8
#define sz_xXF86VidModeGetAllModeLinesReq	8
#define sz_xXF86VidModeGetMonitorReq		8
#define sz_xXF86VidModeGetViewPortReq		8
#define sz_xXF86VidModeGetDotClocksReq		8
#define sz_xXF86VidModeGetPermissionsReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	hskew B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD16	pad2 B16;
    CARD32	flags B32;
    CARD32	reserved1 B32;
    CARD32	reserved2 B32;
    CARD32	reserved3 B32;
    CARD32	privsize B32;
} xXF86VidModeGetModeLineReply;
#define sz_xXF86VidModeGetModeLineReply	52

/* 0.x version */
typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD32	flags B32;
    CARD32	privsize B32;
} xXF86OldVidModeGetModeLineReply;
#define sz_xXF86OldVidModeGetModeLineReply	36

typedef struct {
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD32	hskew B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD16	pad1 B16;
    CARD32	flags B32;
    CARD32	reserved1 B32;
    CARD32	reserved2 B32;
    CARD32	reserved3 B32;
    CARD32	privsize B32;
} xXF86VidModeModeInfo;

/* 0.x version */
typedef struct {
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD32	flags B32;
    CARD32	privsize B32;
} xXF86OldVidModeModeInfo;

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	modecount B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86VidModeGetAllModeLinesReply;
#define sz_xXF86VidModeGetAllModeLinesReply	32

typedef struct _XF86VidModeAddModeLine {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeAddMode */
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	hskew B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD16	pad1 B16;
    CARD32	flags B32;
    CARD32	reserved1 B32;
    CARD32	reserved2 B32;
    CARD32	reserved3 B32;
    CARD32	privsize B32;
    CARD32	after_dotclock B32;
    CARD16	after_hdisplay B16;
    CARD16	after_hsyncstart B16;
    CARD16	after_hsyncend B16;
    CARD16	after_htotal B16;
    CARD16	after_hskew B16;
    CARD16	after_vdisplay B16;
    CARD16	after_vsyncstart B16;
    CARD16	after_vsyncend B16;
    CARD16	after_vtotal B16;
    CARD16	pad2 B16;
    CARD32	after_flags B32;
    CARD32	reserved4 B32;
    CARD32	reserved5 B32;
    CARD32	reserved6 B32;
} xXF86VidModeAddModeLineReq;
#define sz_xXF86VidModeAddModeLineReq	92

/* 0.x version */
typedef struct _XF86OldVidModeAddModeLine {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeAddMode */
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD32	flags B32;
    CARD32	privsize B32;
    CARD32	after_dotclock B32;
    CARD16	after_hdisplay B16;
    CARD16	after_hsyncstart B16;
    CARD16	after_hsyncend B16;
    CARD16	after_htotal B16;
    CARD16	after_vdisplay B16;
    CARD16	after_vsyncstart B16;
    CARD16	after_vsyncend B16;
    CARD16	after_vtotal B16;
    CARD32	after_flags B32;
} xXF86OldVidModeAddModeLineReq;
#define sz_xXF86OldVidModeAddModeLineReq	60

typedef struct _XF86VidModeModModeLine {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeModModeLine */
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	hskew B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD16	pad1 B16;
    CARD32	flags B32;
    CARD32	reserved1 B32;
    CARD32	reserved2 B32;
    CARD32	reserved3 B32;
    CARD32	privsize B32;
} xXF86VidModeModModeLineReq;
#define sz_xXF86VidModeModModeLineReq	48

/* 0.x version */
typedef struct _XF86OldVidModeModModeLine {
    CARD8	reqType;		/* always XF86OldVidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86OldVidModeModModeLine */
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD32	flags B32;
    CARD32	privsize B32;
} xXF86OldVidModeModModeLineReq;
#define sz_xXF86OldVidModeModModeLineReq	32

typedef struct _XF86VidModeValidateModeLine {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	hskew B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD16	pad1 B16;
    CARD32	flags B32;
    CARD32	reserved1 B32;
    CARD32	reserved2 B32;
    CARD32	reserved3 B32;
    CARD32	privsize B32;
} xXF86VidModeDeleteModeLineReq,
  xXF86VidModeValidateModeLineReq,
  xXF86VidModeSwitchToModeReq;
#define sz_xXF86VidModeDeleteModeLineReq	52
#define sz_xXF86VidModeValidateModeLineReq	52
#define sz_xXF86VidModeSwitchToModeReq		52

/* 0.x version */
typedef struct _XF86OldVidModeValidateModeLine {
    CARD8	reqType;		/* always XF86OldVidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD32	screen B32;		/* could be CARD16 but need the pad */
    CARD32	dotclock B32;
    CARD16	hdisplay B16;
    CARD16	hsyncstart B16;
    CARD16	hsyncend B16;
    CARD16	htotal B16;
    CARD16	vdisplay B16;
    CARD16	vsyncstart B16;
    CARD16	vsyncend B16;
    CARD16	vtotal B16;
    CARD32	flags B32;
    CARD32	privsize B32;
} xXF86OldVidModeDeleteModeLineReq,
  xXF86OldVidModeValidateModeLineReq,
  xXF86OldVidModeSwitchToModeReq;
#define sz_xXF86OldVidModeDeleteModeLineReq	36
#define sz_xXF86OldVidModeValidateModeLineReq	36
#define sz_xXF86OldVidModeSwitchToModeReq	36

typedef struct _XF86VidModeSwitchMode {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeSwitchMode */
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	zoom B16;
} xXF86VidModeSwitchModeReq;
#define sz_xXF86VidModeSwitchModeReq	8

typedef struct _XF86VidModeLockModeSwitch {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeLockModeSwitch */
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	lock B16;
} xXF86VidModeLockModeSwitchReq;
#define sz_xXF86VidModeLockModeSwitchReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	status B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86VidModeValidateModeLineReply;
#define sz_xXF86VidModeValidateModeLineReply	32

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD8	vendorLength;
    CARD8	modelLength;
    CARD8	nhsync;
    CARD8	nvsync;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86VidModeGetMonitorReply;
#define sz_xXF86VidModeGetMonitorReply	32

typedef struct {
    BYTE	type;
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	x B32;
    CARD32	y B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
} xXF86VidModeGetViewPortReply;
#define sz_xXF86VidModeGetViewPortReply	32

typedef struct _XF86VidModeSetViewPort {
    CARD8	reqType;		/* always VidModeReqCode */
    CARD8	xf86vidmodeReqType;	/* always X_XF86VidModeSetViewPort */
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	pad B16;
    CARD32      x B32;
    CARD32	y B32;
} xXF86VidModeSetViewPortReq;
#define sz_xXF86VidModeSetViewPortReq	16

typedef struct {
    BYTE	type;
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	flags B32;
    CARD32	clocks B32;
    CARD32	maxclocks B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
} xXF86VidModeGetDotClocksReply;
#define sz_xXF86VidModeGetDotClocksReply	32

typedef struct _XF86VidModeSetClientVersion {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD16	major B16;
    CARD16	minor B16;
} xXF86VidModeSetClientVersionReq;
#define sz_xXF86VidModeSetClientVersionReq	8

typedef struct _XF86VidModeGetGamma {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	pad B16;
    CARD32	pad1 B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86VidModeGetGammaReq;
#define sz_xXF86VidModeGetGammaReq		32

typedef struct {
    BYTE	type;
    BOOL	pad;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	red B32;
    CARD32	green B32;
    CARD32	blue B32;
    CARD32	pad1 B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
} xXF86VidModeGetGammaReply;
#define sz_xXF86VidModeGetGammaReply		32

typedef struct _XF86VidModeSetGamma {
    CARD8	reqType;		/* always XF86VidModeReqCode */
    CARD8	xf86vidmodeReqType;
    CARD16	length B16;
    CARD16	screen B16;
    CARD16	pad B16;
    CARD32	red B32;
    CARD32	green B32;
    CARD32	blue B32;
    CARD32	pad1 B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
} xXF86VidModeSetGammaReq;
#define sz_xXF86VidModeSetGammaReq		32


typedef struct _XF86VidModeSetGammaRamp {
    CARD8       reqType;                /* always XF86VidModeReqCode */
    CARD8       xf86vidmodeReqType;
    CARD16      length B16;
    CARD16      screen B16;
    CARD16      size B16;
} xXF86VidModeSetGammaRampReq;
#define sz_xXF86VidModeSetGammaRampReq             8 

typedef struct _XF86VidModeGetGammaRamp {
    CARD8       reqType;                /* always XF86VidModeReqCode */
    CARD8       xf86vidmodeReqType;
    CARD16      length B16;
    CARD16      screen B16;
    CARD16      size B16;
} xXF86VidModeGetGammaRampReq;
#define sz_xXF86VidModeGetGammaRampReq             8

typedef struct {
    BYTE        type;
    BOOL        pad;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD16      size B16;
    CARD16      pad0 B16;
    CARD32      pad1 B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
} xXF86VidModeGetGammaRampReply;
#define sz_xXF86VidModeGetGammaRampReply            32

typedef struct _XF86VidModeGetGammaRampSize {
    CARD8       reqType;                /* always XF86VidModeReqCode */
    CARD8       xf86vidmodeReqType;
    CARD16      length B16;
    CARD16      screen B16;
    CARD16      pad B16;
} xXF86VidModeGetGammaRampSizeReq;
#define sz_xXF86VidModeGetGammaRampSizeReq             8

typedef struct {
    BYTE        type;
    BOOL        pad;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD16      size B16;
    CARD16      pad0 B16;
    CARD32      pad1 B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
} xXF86VidModeGetGammaRampSizeReply;
#define sz_xXF86VidModeGetGammaRampSizeReply            32

typedef struct {
    BYTE        type;
    BOOL        pad;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD32      permissions B32;
    CARD32      pad1 B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
} xXF86VidModeGetPermissionsReply;
#define sz_xXF86VidModeGetPermissionsReply            32


#endif /* _XF86VIDMODEPROTO_H_ */

