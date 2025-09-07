/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001-2002
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCTYPES_HDR
#define LINWCTYPES_HDR
#pragma once

/* For public use we don't want user to have to specify internal LightWork
 * symbols to compiler
 */
#ifndef LINWC_IMPL
#ifndef LI_IS_DLL
#define LI_IS_DLL
#endif
#else
#ifdef LINWC_IMPL_API
#include <lcutil/LtUTypes.h>
#endif
#endif

#include <ctype.h>
#include <nwcreate/LiNwcPublic.h>
#include <time.h>

#ifndef __cplusplus
#include <stdbool.h>
#endif // __cplusplus

#ifndef LINWC_IMPL

/* Standard LightWork Design types.
 */
typedef         LI_NWC_INT32       LtInt32;
typedef         LtInt32            LtBoolean;
typedef     unsigned LI_NWC_INT32  LtNat32;
typedef         LtNat32            LtEnum;
typedef         LtNat32            LtBitfield;
typedef         double             LtFloat;
typedef         float              LtSingle;
typedef         unsigned char      LtNat8;
typedef         signed char        LtInt8;
typedef         signed short       LtInt16;
typedef         unsigned short     LtNat16;
typedef         LtFloat            LtVector[3];
typedef         LtVector           LtPoint;
typedef         LtVector           LtUnitVector;
typedef         char*              LtString;


/**
 * General purpose constant values
 */
#ifndef NULL
#define         NULL               0
#endif

#ifndef FALSE
#define         FALSE              (LtBoolean)0
#endif

#ifndef TRUE
#define         TRUE               (LtBoolean)1
#endif
#endif /** LINWC_IMPL */

/* Additional 2D data type variants.
 */
typedef         LtFloat            LtVector2d[2];
typedef         LtVector2d         LtPoint2d;
typedef         LtVector2d         LtUnitVector2d;

typedef         LtFloat            LtNwcPlotTransform[9];
typedef         LtFloat            LtNwcPlotBounds2d[8];
typedef         LtInt32            LtPlotInt32Vector[2];
typedef         LtPlotInt32Vector  LtPlotInt32Point;
typedef         LtPlotInt32Vector  LtPlotInt32Size;

typedef enum LtNwcSense_tag
{
   LI_NWC_SENSE_NEGATIVE = -1,
   LI_NWC_SENSE_POSITIVE = +1,
}LtNwcSense;

#define LI_NWC_POSITIVE_INFINITY    1.0e+300
#define LI_NWC_NEGATIVE_INFINITY   -1.0e+300

typedef			void*			   LtHINSTANCE;

/*
 * Types defined by NWCreate but not by LADS. Must still define if
 * aware of implementation but using API.
 */
#if !defined(LINWC_IMPL) || defined(LINWC_IMPL_API)

typedef         LI_NWC_INT64       LtInt64;
typedef     unsigned LI_NWC_INT64  LtNat64;
typedef         LtVector           LtUnitVector;
typedef         LtInt64            LtTime_t;
typedef         wchar_t*           LtWideStringBuffer;
#ifdef __cplusplus
typedef         const wchar_t*     LtWideString;
#else
typedef         wchar_t*           LtWideString;
#endif

/* Type definitions for opaque handles. If this is C++ we define types as a
 * class hierarchy so that derived type can be passed to function that expects
 * base type. If in C we define as nested structures with macro for safe
 * casting, so programmer has to do extra work of specifying that base type
 * is the one wanted.
 */
#ifdef __cplusplus

#define LI_DECLARE_HANDLE(handle,type) \
class type \
{ \
   private: \
   type(); \
   type(const type&); \
   type& operator=(const type&); \
}; \
typedef type* handle

#define LI_DECLARE_CONST_HANDLE(handle,type) \
class type \
{ \
   private: \
   type(); \
   type(const type&); \
   type& operator=(const type&); \
}; \
typedef const type* handle

#define LI_DECLARE_SUB_HANDLE(handle,type,basetype) \
class type : public basetype \
{ \
   private: \
   type(); \
   type(const type&); \
   type& operator=(const type&); \
}; \
typedef type* handle

#else

#define LI_DECLARE_HANDLE(handle,type) \
struct type \
{ \
   int dummy; \
}; \
typedef struct type* handle

#define LI_DECLARE_CONST_HANDLE(handle,type) \
struct type \
{ \
   int dummy; \
}; \
typedef const struct type* handle

#define LI_DECLARE_SUB_HANDLE(handle,type,basetype) \
struct type \
{ \
   struct basetype base; \
}; \
typedef struct type* handle

#define LI_BASE(handle) (&(handle->base))

#endif /* __cplusplus */

#else /* LINWC_IMPL_API */

#define LI_DECLARE_HANDLE(handle,type) \
typedef type* handle

#define LI_DECLARE_CONST_HANDLE(handle,type) \
typedef const type* handle

#define LI_DECLARE_SUB_HANDLE(handle,type,basetype) \
typedef type* handle

#endif /* LINWC_IMPL_API */

LI_DECLARE_HANDLE(LtNwcScene,LcNwcScene__Handle);

LI_DECLARE_HANDLE(LtNwcNode,LcNwcNode__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcGroup,LcNwcGroup__Handle, LcNwcNode__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcGeometry,LcNwcGeometry__Handle, LcNwcNode__Handle);
LI_DECLARE_HANDLE(LtNwcGeometryStream,LcNwcGeomStream__Handle);

LI_DECLARE_HANDLE(LtNwcAttribute,LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcTransform,LcNwcTransform__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcMaterial,LcNwcMaterial__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcNameAttribute,LcNwcNameAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcNat64Attribute,LcNwcNat64Attribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBinaryAttribute,LcNwcBinaryAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcTextAttribute,LcNwcTextAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcURLAttribute,LcNwcURLAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPropertyAttribute,LcNwcPropertyAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSemanticPriority,LcNwcSemanticPriority__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcXRefAttribute,LcNwcXRefAttribute__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPresenterMaterial,LcNwcPresenterMaterial__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPresenterTextureSpace,LcNwcPresenterTextureSpace__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcAutodeskMaterial,LcNwcAutodeskMaterial__Handle, LcNwcAttribute__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaPropertyAttribute,LcNwcSchemaPropertyAttribute__Handle, LcNwcAttribute__Handle);

LI_DECLARE_HANDLE(LtNwcSavedView,LcNwcSavedView__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcFolderView,LcNwcFolderView__Handle, LcNwcSavedView__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcView,LcNwcView__Handle, LcNwcSavedView__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCutView,LcNwcCutView__Handle, LcNwcSavedView__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcAnimView,LcNwcAnimView__Handle, LcNwcSavedView__Handle);

LI_DECLARE_HANDLE(LtNwcSavedSet,LcNwcSavedSet__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcFolderSet,LcNwcFolderSet__Handle, LcNwcSavedSet__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSelectionSet,LcNwcSelectionSet__Handle, LcNwcSavedSet__Handle);

LI_DECLARE_HANDLE(LtNwcCommonLight,LcNwcCommonLight__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcDistantLight,LcNwcDistantLight__Handle, LcNwcCommonLight__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPointLight,LcNwcPointLight__Handle, LcNwcCommonLight__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSpotLight,LcNwcSpotLight__Handle, LcNwcCommonLight__Handle);

LI_DECLARE_HANDLE(LtNwcData,LcNwcData__Handle);
LI_DECLARE_HANDLE(LtNwcLoader,LcNwcLoader__Handle);
LI_DECLARE_HANDLE(LtNwcLoaderSpec, LcNwcLoaderSpec__Handle);
LI_DECLARE_HANDLE(LtNwcTextStyle,LcNwcTextStyle__Handle);

LI_DECLARE_HANDLE(LtNwcImageHeader, LcNwcImageHeader__Handle);

LI_DECLARE_HANDLE(LtNwcPresenterData,LcNwcPresenterData__Handle);

LI_DECLARE_HANDLE(LtNwcAutodeskAssetData,LcNwcAutodeskAssetData__Handle);
LI_DECLARE_HANDLE(LtNwcAutodeskAsset,LcNwcAutodeskAsset__Handle);
LI_DECLARE_HANDLE(LtNwcAutodeskJsonAsset,LcNwcAutodeskJsonAsset__Handle);
LI_DECLARE_HANDLE(LtNwcAutodeskTextureSpace, LcNwcAutodeskTextureSpace__Handle);

LI_DECLARE_HANDLE(LtNwcProgress, LcNwcProgress__Handle);

LI_DECLARE_HANDLE(LtNwcOptionSet, LcNwcOptionSet__Handle);

LI_DECLARE_HANDLE(LtNwcCurve2d, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcLine2d, LcNwcLine2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCircle2d, LcNwcCircle2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcEllipse2d, LcNwcEllipse2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcParabola2d, LcNwcParabola2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcHyperbola2d, LcNwcHyperbola2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBezierCurve2d, LcNwcBezierCurve2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBSplineCurve2d, LcNwcBSplineCurve2d__Handle, LcNwcCurve2d__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcTrimmedCurve2d, LcNwcTrimmedCurve2d__Handle, LcNwcCurve2d__Handle);

LI_DECLARE_HANDLE(LtNwcCurve, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcLine, LcNwcLine__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCircle, LcNwcCircle__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcEllipse, LcNwcEllipse__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcParabola, LcNwcParabola__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcHyperbola, LcNwcHyperbola__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBezierCurve, LcNwcBezierCurve__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBSplineCurve, LcNwcBSplineCurve__Handle, LcNwcCurve__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcTrimmedCurve, LcNwcTrimmedCurve__Handle, LcNwcCurve__Handle);

LI_DECLARE_HANDLE(LtNwcSurface, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlane, LcNwcPlane__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcConicalSurface, LcNwcConicalSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcToroidalSurface, LcNwcToroidalSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSphericalSurface, LcNwcSphericalSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCylindricalSurface, LcNwcCylindricalSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBezierSurface, LcNwcBezierSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBSplineSurface, LcNwcBSplineSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcRectangularTrimmedSurface, LcNwcRectangularTrimmedSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcOffsetSurface, LcNwcOffsetSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcExtrudedSurface, LcNwcExtrudedSurface__Handle, LcNwcSurface__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcRevolvedSurface, LcNwcRevolvedSurface__Handle, LcNwcSurface__Handle);

LI_DECLARE_HANDLE(LtNwcBRepEntity, LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCompound, LcNwcCompound__Handle, LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcBody,     LcNwcBody__Handle,     LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSolid,    LcNwcSolid__Handle,    LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcShell,    LcNwcShell__Handle,    LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcFace,     LcNwcFace__Handle,     LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcLoop,     LcNwcLoop__Handle,     LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcCoedge,   LcNwcCoedge__Handle,   LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcEdge,     LcNwcEdge__Handle,     LcNwcBRepEntity__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcVertex,   LcNwcVertex__Handle,   LcNwcBRepEntity__Handle);

LI_DECLARE_HANDLE(LtNwcBRepProfileBuilder, LcNwcBRepProfileBuilder__Handle);
LI_DECLARE_HANDLE(LtNwcBRepImporter, LcNwcBRepImporter__Handle);

LI_DECLARE_HANDLE(LtNwcPlotStream, LcNwcPlotStream__Handle);
LI_DECLARE_HANDLE(LtNwcPlotGeometryStream, LcNwcPlotGeometryStream__Handle);
LI_DECLARE_HANDLE(LtNwcPlotResource, LcNwcPlotResource__Handle);
LI_DECLARE_HANDLE(LtNwcPlotPathStreamStyle, LcNwcPlotPathStreamStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotArcSegment, LcNwcPlotArcSegment__Handle);
LI_DECLARE_HANDLE(LtNwcPlotCircleSegment, LcNwcPlotCircleSegment__Handle);
LI_DECLARE_HANDLE(LtNwcPlotEllipseSegment, LcNwcPlotEllipseSegment__Handle);
LI_DECLARE_HANDLE(LtNwcPlotCanvasStyle, LcNwcPlotCanvasStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotViewportStyle, LcNwcPlotViewportStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotEmbeddedFont, LcNwcPlotEmbeddedFont__Handle);
LI_DECLARE_HANDLE(LtNwcPlotFontStyle, LcNwcPlotFontStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotPathFigureStyle, LcNwcPlotPathFigureStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotPathStyle, LcNwcPlotPathStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotStroke, LcNwcPlotStroke__Handle);
LI_DECLARE_HANDLE(LtNwcPlotTextStyle, LcNwcPlotTextStyle__Handle);
LI_DECLARE_HANDLE(LtNwcPlotPaperStyle,LcNwcPlotPaperStyle__Handle);

LI_DECLARE_HANDLE(LtNwcPlotBrush, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotGeometryBrush, LcNwcPlotGeometryBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotHatchBrush, LcNwcPlotHatchBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotVertexColorBrush, LcNwcPlotVertexColorBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotImageBrush, LcNwcPlotImageBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotLinearGradientBrush, LcNwcPlotLinearGradientBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotRadialGradientBrush, LcNwcPlotRadialGradientBrush__Handle, LtNwcPlotBrush__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcPlotSolidColorBrush, LcNwcPlotSolidColorBrush__Handle, LtNwcPlotBrush__Handle);

LI_DECLARE_HANDLE(LtNwcSheetInfo, LcNwcSheetInfo_Handle);
LI_DECLARE_HANDLE(LtNwcFileInfo, LcNwcFileInfo_Handle);

LI_DECLARE_HANDLE(LtNwcGuid, LcNwcGuid__Handle);

LI_DECLARE_HANDLE(LtNwcExternalGeometry, LcNwcExternalGeometry__Handle);
LI_DECLARE_HANDLE(LtNwcExternalLink, LcNwcExternalLink__Handle);
LI_DECLARE_HANDLE(LtNwcGeneratePrimitivesContext, LcNwcGeneratePrimitivesContext__Handle);
LI_DECLARE_HANDLE(LtNwcRenderContext, LcNwcRenderContext__Handle);
LI_DECLARE_HANDLE(LtNwcPickContext, LcNwcPickContext__Handle);
LI_DECLARE_HANDLE(LtNwcUpgradeContext, LcNwcUpgradeContext__Handle);

LI_DECLARE_HANDLE(LtNwcGridLine, LcNwcGridLine__Handle);
LI_DECLARE_HANDLE(LtNwcGridLevel, LcNwcGridLevel__Handle);
LI_DECLARE_HANDLE(LtNwcGridSystem, LcNwcGridSystem__Handle);

LI_DECLARE_CONST_HANDLE(LtNwcSchema, LcNwcSchema__Handle);
LI_DECLARE_HANDLE(LtNwcSchemaBuilder, LcNwcSchemaBuilder__Handle);
LI_DECLARE_HANDLE(LtNwcSchemaField, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaDoubleField, LcNwcSchemaDoubleField__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaStructField, LcNwcSchemaStructField__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaVectorField, LcNwcSchemaVectorField__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaGuidField, LcNwcSchemaGuidField__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaInt32Field, LcNwcSchemaInt32Field__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaBooleanField, LcNwcSchemaBooleanField__Handle, LcNwcSchemaField__Handle);
LI_DECLARE_SUB_HANDLE(LtNwcSchemaWideStringField, LcNwcSchemaWideStringField__Handle, LcNwcSchemaField__Handle);

#undef LI_DECLARE_HANDLE
#undef LI_DECLARE_SUB_HANDLE

#endif /* LINWCTYPES_HDR */
