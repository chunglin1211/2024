/**
 * \file
 *
 * A named viewpoint in the scene.
 */

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

#ifndef LINWCVIEW_HDR
#define LINWCVIEW_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcSavedView.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a view.
 *
 * \return Newly created view or NULL on error
 */
LI_NWC_PUBLIC LtNwcView LI_NWC_API
LiNwcViewCreate();

/**
 * Defines camera projection type
 */
typedef enum LtNwcProjection__tag {
   LI_NWC_PERSPECTIVE,        /** Perspective projection */
   LI_NWC_ORTHOGRAPHIC,       /** Orthographic projection */
} LtNwcProjection;

/**
 * Viewpoint render style.
 */
typedef enum LtNwcRenderStyle__tag {
   eFULL_RENDER,              /** Highest quality */
   ePREVIEW_RENDER,           /** Lower quality, same appearance */
   eSHADED_RENDER,            /** Smooth shaded (simple shade model, no textures) */
   eWIRE_RENDER,              /** Wire frame */
   eHLINE_RENDER,             /** Hidden line wire frame */
} LtNwcRenderStyle;

/**
 * Describes the users intentions if the product has to modify near and far distances (typically because of graphics system limitations).
 */
typedef enum LtNwcDistanceType__tag {
   LI_NWC_DISTANCE_TYPE_FIXED,      /** User has specified exact distance. */
   LI_NWC_DISTANCE_TYPE_CONSTRAINED,/* For near distance, user has specified maximum distance and the product can use a smaller value to increase render quality.
                                    For far distance, user has specified minimum distance and the product can use a larger value to increase render quality. */
   LI_NWC_DISTANCE_TYPE_AUTO,       /** Distance was chosen automatically by the product. */
} LtNwcDistanceType;

/**
 * Describes how to adapt the camera view so that it's aspect ratio matches that of the display window.
 */
typedef enum LtNwcImageFit__tag {
   LI_NWC_IMAGE_FIT_MASK,        /** The frustum is used as is within the largest subset of the window that has the correct aspect ratio. The rest of the window is masked out (e.g. black bars). */
   LI_NWC_IMAGE_FIT_FILL,        /** The frustum extents are enlarged so that all of the original image is visible. */
   LI_NWC_IMAGE_FIT_VERTICAL,    /** Only HorizontalExtent is modified so that vertical extent is preserved. */
   LI_NWC_IMAGE_FIT_HORIZONTAL,  /** Only VerticalExtent is modified so that horizontal extent is preserved. */
   LI_NWC_IMAGE_FIT_OVERSCAN,    /** The frustum extents are reduced so that a subset of the original image is visible. */
} LtNwcImageFit;

/**
 * Set projection type used by camera for view. Default is perspective.
 *
 * \param view View to set projection for
 * \param proj Projection to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetProjection(LtNwcView view, LtNwcProjection proj);

/**
 * OBSOLETE: Always fails.
 *
 * Set rendering style for this view.
 *
 * \param view View to set rendering style for
 * \param flag true to use presenter rendering, false to use default rendering
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcViewSetUsePresenterRender(LtNwcView view, bool flag);

/**
 * Set rendering style for this view.  Offers more options than LiNwcViewSetUsePresenterRender
 *
 * \param view View to set render style for
 * \param style see the definition of LtNwcRenderStyle for options
 * \return true if ok , false on error
 * \version 5.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcViewSetRenderStyle(LtNwcView view, LtNwcRenderStyle style);

/**
 * Set position of camera for view
 *
 * \param view View to set position for
 * \param x X coordinate of camera position
 * \param y Y coordinate of camera position
 * \param z Z coordinate of camera position
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetPosition(LtNwcView view, LtFloat x, LtFloat y, LtFloat z);

/**
 * Set rotation of camera for view. The camera is oriented by rotating from
 * a default position looking down the negative Z axis with
 * +X to the right and +Y up. The rotation is specified as a rotation about
 * an arbitrary axis. For a simpler interface see LiNwcViewPointAt() and
 * LiNwcViewAlignUp().
 *
 * \param view View to set position for
 * \param x X coordinate of axis to rotate about
 * \param y Y coordinate of axis to rotate about
 * \param z Z coordinate of axis to rotate about
 * \param a Angle to rotate by in radians
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetRotation(LtNwcView view,
                     LtFloat x, LtFloat y, LtFloat z, LtFloat a);

/**
 * Set height field of camera in view.
 * For a perspective camera, this is the vertical field of view.
 * That is, the angle (in radians) between the top and bottom planes of the
 * camera view frustum.
 * For an orthographic camera, this is the distance between top and
 * bottom planes (in world coordinates) of the camera view frustum.
 * Default 0.785398 radians (45 degrees).
 *
 * \param view View to set height field for
 * \param height Height to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetHeightField(LtNwcView view, LtFloat height);

/**
 * Rotate camera so that it points at target position using shortest
 * rotation path.
 * From 3.3 also sets focal distance based on target position.
 *
 * \param view View to change rotation for
 * \param x X coordinate of target position
 * \param y Y coordinate of target position
 * \param z Z coordinate of target position
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewPointAt(LtNwcView view, LtFloat x, LtFloat y, LtFloat z);

/**
 * Rotate camera so that it points in given direction using shortest
 * rotation path.
 *
 * \param view View to change rotation for
 * \param x X coordinate of direction vector
 * \param y Y coordinate of direction vector
 * \param z Z coordinate of direction vector
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewAlignDirection(LtNwcView view, LtFloat x, LtFloat y, LtFloat z);

/**
 * Rotate camera about view direction so that camera up vector is
 * aligned with given up vector (in same plane as view direction and
 * given up vector).
 * \param view View to change rotation for
 * \param x X coordinate of up vector
 * \param y Y coordinate of up vector
 * \param z Z coordinate of up vector
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewAlignUp(LtNwcView view, LtFloat x, LtFloat y, LtFloat z);

/**
 * Define preferred up vector for view. Used by "Walk" and "Turntable"
 * navigation modes to keep camera upright.
 * Default is [ 0 1 0 ].
 * \param view View to set world up vector for
 * \param x X coordinate of world up vector
 * \param y Y coordinate of world up vector
 * \param z Z coordinate of world up vector
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetWorldUpVector(LtNwcView view, LtFloat x, LtFloat y, LtFloat z);

/**
 * Add a section plane to the view.
 * \param view View to add section plane to
 * \param x X coordinate of plane normal
 * \param y Y coordinate of plane normal
 * \param z Z coordinate of plane normal
 * \param d Distance of plane from the origin along plane normal
 * \version 3.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewAddSectionPlane(LtNwcView view, LtFloat x, LtFloat y, LtFloat z, LtFloat d);

/**
 * Set linked flag on view's section planes
 * Default is false.
 * \param view View to set linked flag for
 * \param b Should section planes be linked together
 * \version 3.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetSectionPlanesLinked(LtNwcView view, bool b);

/**
 * Define distance to focal point of view. Used by "Examine" and "Orbit"
 * navigation modes to define point to rotate about.
 * If unset an appropriate focal point is determined when needed.
 * \param view View to set focal distance for
 * \param d Distance from position along view direction to focal point
 * \version 3.3
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetFocalDistance(LtNwcView view, LtFloat d);

/**
 * Set the distances between the left and right planes, and the top and bottom planes of the
 * view frustum at the focal distance along the view direction from the camera position.
 * Need to call SetFocalDistance before calling this method.
 * \param view View to set extents for
 * \param horizontal Distance between the left and right planes on the view frustum
 * \param vertical Distance between the top and bottom planes on the view frustum
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetExtentsAtFocalDistance(LtNwcView view, LtFloat horizontal, LtFloat vertical);

/**
 * The ratio between the up offset (the distance that the target plane is offset upwards) and the
 * vertical extent (the distance between the top and bottom planes of the view frustum at the target distance).
 * \param view View to set the up offset factor for.
 * \param up_offset_factor The up offset factor required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetUpOffsetFactor(LtNwcView view, LtFloat up_offset_factor);

/**
 * The ratio between the right offset (the distance that the target plane is offset to the right) and the
 * horizontal extent (the distance between the left and right planes of the view frustum at the target distance).
 * \param view View to set the right offset factor for.
 * \param right_offset_factor The right offset factor required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetRightOffsetFactor(LtNwcView view, LtFloat right_offset_factor);

/**
 * Distance that the target plane is offset upwards.
 * \param view View to set the up offset for.
 * \param up_offset The up offset required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetUpOffsetAtFocalDistance(LtNwcView view, LtFloat up_offset);

/**
 * Distance that the target plane is offset to the right.
 * \param view View to set the right offset for.
 * \param right_offset The right offset required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetRightOffsetAtFocalDistance(LtNwcView view, LtFloat right_offset);

/**
 * Distance from eye point to near plane along view direction. Must be greater than zero.
 * \param view View to set near distance for.
 * \param near_distance The distance to the near plane.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetNearDistance(LtNwcView view, LtFloat near_distance);

/**
 * Describes the users intentions if the product has to modify the near distance (typically because of graphics system limitations).
 * \param view View to set near distance type for.
 * \param near_distance_type The type of near distance modification required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetNearDistanceType(LtNwcView view, LtNwcDistanceType near_distance_type);

/**
 * Distance from eye point to far plane along view direction. Must be greater than near distance.
 * \param view View to set far distance for.
 * \param far_distance The distance to the far plane.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetFarDistance(LtNwcView view, LtFloat far_distance);

/**
 * Describes the users intentions if the product has to modify the far distance (typically because of graphics system limitations).
 * \param view View to set far distance type for.
 * \param far_distance_type The type of far distance modification required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetFarDistanceType(LtNwcView view, LtNwcDistanceType far_distance_type);

/**
 * Describes how to adapt the camera view so that it's aspect ratio matches that of the display window.
 * \param view View to set the type of image fitting for.
 * \param image_fit The type of image fitting required.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetImageFit(LtNwcView view, LtNwcImageFit image_fit);

/**
 * Required horizontal scaling of the image when adapting the camera view to the display window
 * \param view View to set the horizontal scaling for.
 * \param horizontal_scale The required horizontal scaling.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetHorizontalScale(LtNwcView view, LtFloat horizontal_scale);

/**
 * The diameter of the physical camera aperture in camera units. Used for advanced rendering effects.
 * The aperture is positioned at the eye point.
 * A value of 0 (zero) means the thin lens is an ideal pin hole with infinite depth-of-field.
 * \param view View to set the diameter of the physical camera aperture for.
 * \param aperture_diameter The required aperture diameter.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetApertureDiameter(LtNwcView view, LtFloat aperture_diameter);

/**
 * The time measured in seconds that the physical aperture is open. Used for advanced rendering effects.
 * A value of 0 (zero) means this value is undefined.
 * \param view View to set the duration that the physical aperture is open for.
 * \param shutter_speed The required duration that the physical aperture is open.
 * \version 11
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetShutterSpeed(LtNwcView view, LtFloat shutter_speed);

/**
 * Set the linear speed that the viewpoint will move at when, e.g. walking.
 * Also determines speed between keyframes in animations.
 * \param view View to set focal distance for
 * \param s Linear speed in meters per second.
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetLinearSpeed(LtNwcView view, LtFloat s);

/**
 * Set the angular speed that the viewpoint will turn at.
 * \param view View to set focal distance for
 * \param s angular speed in radians per second.
 * \version 5.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewSetAngularSpeed(LtNwcView view, LtFloat s);

/**
 * Destroy a NavisWorks view
 *
 * \param view View to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcViewDestroy(LtNwcView view);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcView API calls
 *
 * \see LiNwcView.h
 */
class LcNwcView : public LcNwcSavedView
{
public:
   LcNwcView() : LcNwcSavedView(LiNwcViewCreate(), true) {}
   LcNwcView(LtNwcView handle) : LcNwcSavedView(handle, false) {}

   operator LtNwcView () const
   { return static_cast<LtNwcView>(LcNwcSavedView::GetHandle()); }
   LtNwcView GetHandle() const
   { return static_cast<LtNwcView>(LcNwcSavedView::GetHandle()); }

   void SetProjection(LtNwcProjection proj)
   { LiNwcViewSetProjection(GetHandle(), proj); }

   void SetPosition(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcViewSetPosition(GetHandle(), x, y, z); }

   void SetPosition(LtPoint pnt)
   { LiNwcViewSetPosition(GetHandle(), pnt[0], pnt[1], pnt[2]); }

   void SetRotation(LtFloat x, LtFloat y, LtFloat z, LtFloat a)
   { LiNwcViewSetRotation(GetHandle(), x, y, z, a); }

   void SetHeightField(LtFloat height)
   { LiNwcViewSetHeightField(GetHandle(), height); }

   void PointAt(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcViewPointAt(GetHandle(), x, y, z); }

   void PointAt(LtPoint pnt)
   { LiNwcViewPointAt(GetHandle(), pnt[0], pnt[1], pnt[2]); }

   void AlignDirection(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcViewAlignDirection(GetHandle(), x, y, z); }

   void AlignDirection(LtPoint pnt)
   { LiNwcViewAlignDirection(GetHandle(), pnt[0], pnt[1], pnt[2]); }

   void AlignUp(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcViewAlignUp(GetHandle(), x, y, z); }

   void AlignUp(LtPoint pnt)
   { LiNwcViewAlignUp(GetHandle(), pnt[0], pnt[1], pnt[2]); }

   void SetWorldUpVector(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcViewSetWorldUpVector(GetHandle(), x, y, z); }

   void SetWorldUpVector(LtPoint pnt)
   { LiNwcViewSetWorldUpVector(GetHandle(), pnt[0], pnt[1], pnt[2]); }

   void SetUsePresenterRender(bool flag)
   { LiNwcViewSetUsePresenterRender(GetHandle(),flag);}

   void SetRenderStyle(LtNwcRenderStyle style)
   { LiNwcViewSetRenderStyle(GetHandle(),style);}

   void AddSectionPlane(LtFloat x, LtFloat y, LtFloat z, LtFloat d)
   { LiNwcViewAddSectionPlane(GetHandle(), x, y, z, d); }

   void SetSectionPlanesLinked(bool b)
   { LiNwcViewSetSectionPlanesLinked(GetHandle(), b); }

   void SetFocalDistance(LtFloat d)
   { LiNwcViewSetFocalDistance(GetHandle(), d); }

   void SetExtentsAtFocalDistance(LtFloat horizontal, LtFloat vertical)
   { LiNwcViewSetExtentsAtFocalDistance(GetHandle(), horizontal, vertical);}

   void SetUpOffsetFactor(LtFloat up_offset_factor)
   { LiNwcViewSetUpOffsetFactor(GetHandle(), up_offset_factor);}

   void SetRightOffsetFactor(LtFloat right_offset_factor)
   { LiNwcViewSetRightOffsetFactor(GetHandle(),right_offset_factor);}

   void SetUpOffsetAtFocalDistance(LtNwcView /*unused*/, LtFloat up_offset)
   { LiNwcViewSetUpOffsetAtFocalDistance(GetHandle(), up_offset);}

   void SetRightOffsetAtFocalDistance(LtNwcView /*unused*/, LtFloat right_offset)
   { LiNwcViewSetRightOffsetAtFocalDistance(GetHandle(), right_offset);}

   void SetNearDistance(LtFloat near_distance)
   { LiNwcViewSetNearDistance(GetHandle(), near_distance);}

   void SetNearDistanceType(LtNwcDistanceType near_distance_type)
   { LiNwcViewSetNearDistanceType(GetHandle(), near_distance_type);}

   void SetFarDistance(LtFloat far_distance)
   { LiNwcViewSetFarDistance(GetHandle(), far_distance);}

   void SetFarDistanceType(LtNwcDistanceType far_distance_type)
   { LiNwcViewSetFarDistanceType(GetHandle(), far_distance_type);}

   void SetImageFit(LtNwcImageFit image_fit)
   { LiNwcViewSetImageFit(GetHandle(), image_fit);}

   void SetHorizontalScale(LtFloat horizontal_scale)
   { LiNwcViewSetHorizontalScale(GetHandle(), horizontal_scale);}

   void SetApertureDiameter(LtFloat aperture_diameter)
   { LiNwcViewSetApertureDiameter(GetHandle(), aperture_diameter);}

   void SetShutterSpeed(LtFloat shutter_speed)
   { LiNwcViewSetShutterSpeed(GetHandle(), shutter_speed);}

   void SetLinearSpeed(LtFloat s)
   { LiNwcViewSetLinearSpeed(GetHandle(), s); }

   void SetAngularSpeed(LtFloat s)
   { LiNwcViewSetAngularSpeed(GetHandle(), s); }

private:
   // Can't copy
   LcNwcView(const LcNwcView&);
   LcNwcView& operator= (const LcNwcView&);
};

#endif

#endif /* LINWCVIEW_HDR */
