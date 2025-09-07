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

#ifndef LINWCALL_HDR
#define LINWCALL_HDR
#pragma once

#include <nwcreate/LiNwcApi.h>
#include <nwcreate/LiNwcScene.h>

#include <nwcreate/LiNwcNode.h>
#include <nwcreate/LiNwcGroup.h>
#include <nwcreate/LiNwcGeometry.h>
#include <nwcreate/LiNwcGeometryStream.h>

#include <nwcreate/LiNwcAttribute.h>
#include <nwcreate/LiNwcTransform.h>
#include <nwcreate/LiNwcMaterial.h>
#include <nwcreate/LiNwcSemanticPriority.h>
#include <nwcreate/LiNwcNameAttribute.h>
#include <nwcreate/LiNwcNat64Attribute.h>
#include <nwcreate/LiNwcBinaryAttribute.h>
#include <nwcreate/LiNwcTextAttribute.h>
#include <nwcreate/LiNwcURLAttribute.h>
#include <nwcreate/LiNwcPropertyAttribute.h>
#include <nwcreate/LiNwcXRefAttribute.h>

#include <nwcreate/LiNwcSavedView.h>
#include <nwcreate/LiNwcView.h>
#include <nwcreate/LiNwcFolderView.h>
#include <nwcreate/LiNwcAnimView.h>
#include <nwcreate/LiNwcCutView.h>

#include <nwcreate/LiNwcSavedSet.h>
#include <nwcreate/LiNwcSelectionSet.h>
#include <nwcreate/LiNwcFolderSet.h>

#include <nwcreate/LiNwcCommonLight.h>
#include <nwcreate/LiNwcDistantLight.h>
#include <nwcreate/LiNwcPointLight.h>
#include <nwcreate/LiNwcSpotLight.h>

#include <nwcreate/LiNwcData.h>
#include <nwcreate/LiNwcLoader.h>
#include <nwcreate/LiNwcImageHeader.h>
#include <nwcreate/LiNwcTextStyle.h>

#include <nwcreate/LiNwcPresenterData.h>
#include <nwcreate/LiNwcPresenterMaterial.h>
#include <nwcreate/LiNwcPresenterTextureSpace.h>

#include <nwcreate/LiNwcAutodeskAssetData.h>
#include <nwcreate/LiNwcAutodeskAsset.h>
#include <nwcreate/LiNwcAutodeskMaterial.h>
#include <nwcreate/LiNwcAutodeskJsonAsset.h>
#include <nwcreate/LiNwcAutodeskTextureSpace.h>

#include <nwcreate/LiNwcProgress.h>

#include <nwcreate/LiNwcOptionSet.h>

#include <nwcreate/LiNwcCurve.h>
#include <nwcreate/LiNwcCurve2d.h>
#include <nwcreate/LiNwcSurface.h>
#include <nwcreate/LiNwcTopology.h>
#include <nwcreate/LiNwcBRepAPI.h>
#include <nwcreate/LiNwcBRepImporter.h>


#include <nwcreate/LiNwcPlotFontStyle.h>

#include <nwcreate/LiNwcPlotPathStreamStyle.h>
#include <nwcreate/LiNwcPlotStream.h>
#include <nwcreate/LiNwcPlotGeometryStream.h>
#include <nwcreate/LiNwcPlotResource.h>
#include <nwcreate/LiNwcPlotArcSegment.h>
#include <nwcreate/LiNwcPlotCircleSegment.h>
#include <nwcreate/LiNwcPlotEllipseSegment.h>
#include <nwcreate/LiNwcPlotCanvasStyle.h>
#include <nwcreate/LiNwcPlotEmbeddedFont.h>
#include <nwcreate/LiNwcPlotHatchBrush.h>
#include <nwcreate/LiNwcPlotVertexColorBrush.h>
#include <nwcreate/LiNwcPlotImageBrush.h>
#include <nwcreate/LiNwcPlotPathFigureStyle.h>
#include <nwcreate/LiNwcPlotPathStyle.h>
#include <nwcreate/LiNwcPlotStroke.h>
#include <nwcreate/LiNwcPlotTextStyle.h>
#include <nwcreate/LiNwcPlotViewportStyle.h>
#include <nwcreate/LiNwcPlotGeometryBrush.h>
#include <nwcreate/LiNwcPlotLinearGradientBrush.h>
#include <nwcreate/LiNwcPlotRadialGradientBrush.h>
#include <nwcreate/LiNwcPlotSolidColorBrush.h>
#include <nwcreate/LiNwcPlotPaperStyle.h>

#include <nwcreate/LiNwcFileInfo.h>
#include <nwcreate/LiNwcSheetInfo.h>
#include <nwcreate/LiNwcGuid.h>
#include <nwcreate/LiNwcExternalGeometry.h>
#include <nwcreate/LiNwcExternalLink.h>

#include <nwcreate/LiNwcGridLine.h>
#include <nwcreate/LiNwcGridLevel.h>
#include <nwcreate/LiNwcGridSystem.h>

#include <nwcreate/LiNwcSchema.h>
#include <nwcreate/LiNwcSchemaBuilder.h>
#include <nwcreate/LiNwcSchemaField.h>
#include <nwcreate/LiNwcSchemaPropertyAttribute.h>

#endif /* LINWCALL_HDR */
