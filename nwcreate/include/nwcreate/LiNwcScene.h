/**
 * \file
 *
 * Represents a complete NavisWorks scene.
 * Typical use of the nwcreate API is to start with a scene, add geometry
 * and attributes to it, then write out as a NavisWorks nwd
 * file (exporter) or return to NavisWorks (import plugin).
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

#ifndef LINWCSCENE_HDR
#define LINWCSCENE_HDR
#pragma once

#include <nwcreate/LiNwcApi.h>
#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create an empty NavisWorks scene
 *
 * \return Newly created scene or NULL on error
 */
LI_NWC_PUBLIC LtNwcScene LI_NWC_API
LiNwcSceneCreate();

/**
 * Destroy a NavisWorks scene.
 *
 * \param scene Scene to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneDestroy(LtNwcScene scene);

/**
 * Sets the default material for all nodes in a NavisWorks scene. The
 * default is white.
 *
 * \param scene Scene to set default material for
 * \param material Material to use as default
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetDefaultMaterial(LtNwcScene scene, LtNwcMaterial material);

/**
 * Make the entire scene two sided. Both sides of geometry will be
 * rendered. Default is to render only the front side.
 * In 4.0 and later all geometry defaults to two sided unless solid. This call
 * is ignored.
 *
 * \param scene Scene to make two sided
 * \param b true to render two sided, false for default
 * \version Before 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetTwoSided(LtNwcScene scene, bool b);

/**
 * Set the background color for the scene. Default is black.
 *
 * \param scene Scene to set background color for
 * \param r Red component of background color (range 0 to 1)
 * \param g Green component of background color (range 0 to 1)
 * \param b Blue component of background color (range 0 to 1)
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetBackgroundColor(LtNwcScene scene, LtFloat r, LtFloat g, LtFloat b);

/**
 * Sets a graduated background on the scene. The background
 * will go from colour1 at the top of the screen to colour2
 * at the bottom.
 *
 * \param scene Scene to set background color for
 * \param colour1 Top colour
 * \param colour2 Bottom colour
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetGraduatedBackground(LtNwcScene scene,
                                 LtVector colour1,
                                 LtVector colour2);

/**
 * Sets a horizon background on the scene. A horizon
 * background consists of a graduated sky above a
 * graduated ground plane. The sky will go from sky_colour1
 * at the top to sky_colour2 at the horizon. The ground will
 * go from ground_colour1 at the horizon to ground_colour2
 * at the bottom.
 *
 * \param scene Scene to set background color for
 * \param sky_colour1 Sky top colour
 * \param sky_colour2 Sky bottom colour
 * \param ground_colour1 Ground top colour
 * \param ground_colour2 Ground bottom colour
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetHorizonBackground(LtNwcScene scene,
                               LtVector sky_colour1,
                               LtVector sky_colour2,
                               LtVector ground_colour1,
                               LtVector ground_colour2);

/**
 * Set 2D paper style to current background.
 *
 * \param scene Scene to set 2D paper style for
 * \param style 2D paper style
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetPaperStyle(LtNwcScene scene, LtNwcPlotPaperStyle style);

/**
 * Set the global ambient light to use with scene lights.
 *
 * \param scene Scene to set global ambient light for
 * \param r Red component of ambient light color (range 0 to 1)
 * \param g Green component of ambient light color (range 0 to 1)
 * \param b Blue component of ambient light color (range 0 to 1)
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetGlobalAmbient(LtNwcScene scene, LtFloat r, LtFloat g, LtFloat b);

/**
 * Set the current view for the scene. This is the view used when NavisWorks
 * first opens the scene.
 *
 * \param scene Scene to set current view for
 * \param view View to make current
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetCurrentView(LtNwcScene scene, LtNwcView view);

/**
 * Set the plan view for the scene. This is the view used to generate the
 * plan thumbnail when NavisWorks opens the scene.
 *
 * \param scene Scene to set plan view for
 * \param view View to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetPlanView(LtNwcScene scene, LtNwcView view);

/**
 * Set the section view for the scene. This is the view used to generate the
 * section thumbnail when NavisWorks opens the scene.
 *
 * \param scene Scene to set section view for
 * \param view View to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetSectionView(LtNwcScene scene, LtNwcView view);

/**
 * Set the home view for the scene. This is the view used by the
 * ViewCube in Roamer.
 *
 * \param scene Scene to set home view for
 * \param view Home view to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetHomeView(LtNwcScene scene,
                      LtNwcView view);

/**
 * Add a saved view to the set of saved views in the scene.
 *
 * \param scene Scene to add saved view to
 * \param view View to add
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddSavedView(LtNwcScene scene, LtNwcSavedView view);

/**
 * Add a node to a NavisWorks scene.
 *
 * \param scene Scene to add node to
 * \param node Node to add
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddNode(LtNwcScene scene, LtNwcNode node);

/**
 * Add an attribute to a NavisWorks scene.
 *
 * \param scene Scene to add node to
 * \param attribute Attribute to add
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddAttribute(LtNwcScene scene, LtNwcAttribute attribute);

/**
 * Add a light to a NavisWorks scene. Scene lights are used when the user
 * selects scene lights within NavisWorks.
 *
 * \param scene Scene to add light to
 * \param light Light to add
 * \version 2.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddLight(LtNwcScene scene, LtNwcCommonLight light);

/**
 * Add a saved set to a NavisWorks scene.
 *
 * \param scene Scene to add saved set to
 * \param set Saved set to add
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddSavedSet(LtNwcScene scene,
                      LtNwcSavedSet set);

/**
 * Get the number of children nodes in a scene.
 *
 * \param scene Scene to get number of children on.
 * \return Number of children nodes.
 * \version 5.0
 */
LI_NWC_PUBLIC LtInt32 LI_NWC_API
LiNwcSceneGetNumChildren(LtNwcScene scene);

/**
 * Get a child node of the scene, using the index.
 *
 * \param scene Scene to get the child from.
 * \param pos Index position of the child to get.
 * \return A node representing the child node.
 * \version 5.0
 */
LI_NWC_PUBLIC LtNwcNode LI_NWC_API
LiNwcSceneGetChild(LtNwcScene scene, LtInt32 pos);

/**
 * Set guid to the scene
 *
 * \param scene Scene to set guid to
 * \param guid guid to set
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetGuid(LtNwcScene scene, LtNwcGuid guid);

/**
 * Set statistics about scene. This is an arbitrary string that will be
 * displayed in the scene statistics dialog in NavisWorks. Typically contains
 * a summary of the original data used to create the scene.
 *
 * \param scene Scene to set statistics for
 * \param statistics Statistics to set
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetStatistics(LtNwcScene scene, LtWideString statistics);

/**
 * Callback function invoked when all geometry callbacks for a scene have been
 * completed. Allows any user data required by geometry callbacks to be safely
 * cleaned up.
 *
 * \param scene Scene for which processing is complete
 * \param user_data User data passed in when callback set
 */
typedef void LI_NWC_API
LtNwcSceneCompleteCallback(LtNwcScene scene, void* user_data);

/**
 * Sets scene complete callback function.
 *
 * \param scene Scene to set scene complete callback for
 * \param cb Callback function to set
 * \param user_data User data pointer passed to callback when called
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetSceneCompleteCallback(LtNwcScene scene,
                                   LtNwcSceneCompleteCallback* cb,
                                   void* user_data);

/**
 * Status codes that can be returned by LiNwcSceneWrite, LiNwcSceneWriteCache,
 * LiNwcSceneWriteEx and LiNwcSceneWriteCacheEx - unless otherwise stated.
 */
typedef enum LtNwcWriteStatus__tag {
   LI_NWC_WRITE_OK,              /** Write succeeded */
   LI_NWC_WRITE_CANT_OPEN,       /** Can't open file for write */
   LI_NWC_WRITE_NO_ROOM,         /** Not enough disk space for write */
   LI_NWC_WRITE_CANCELED,        /** User canceled write */
   LI_NWC_WRITE_INTERNAL_ERROR,  /** Write failed due to API internal error */
   LI_NWC_WRITE_NOT_LICENSED,    /** LiNwcSceneWriteEx: No publisher license available */
   LI_NWC_WRITE_OUT_OF_MEMORY,   /** LiNwcSceneWriteEx/LiNecSceneWriteCache: Not enough memory to complete write */
} LtNwcWriteStatus;

/**
 * Called to report progress.
 * \param progress value between 0 and 1
 * \param user_data Data passed over when progress callback set
 * \return false to cancel the operation.
 */
typedef bool LI_NWC_API
LtNwcProgressCallback(LtFloat progress, void* user_data);

/**
 * Write a scene out as a NavisWorks NWD file. This converts all data into
 * NavisWorks internal format. After writing no operations apart from destroy
 * are permitted.
 * From NavisWorks 3 onwards will fail with a LI_NWC_WRITE_INTERNAL_ERROR if
 * a publisher license is not available.
 * From NavisWorks 4.1 onwards will fail with a LI_NWC_WRITE_INTERNAL_ERROR if
 * write runs out of memory.
 *
 * \param scene Node to add
 * \param filename Filename to write to, including .nwd extention
 * \param progress Progress callback, or NULL if not interested
 * \param user_data User data pointer passed to progress callback
 * \return LI_NWC_WRITE_OK if successfull
 */
LI_NWC_PUBLIC LtNwcWriteStatus LI_NWC_API
LiNwcSceneWrite(LtNwcScene scene, LtWideString filename,
                LtNwcProgressCallback* progress, void* user_data);

/**
 * Same as LiNwcSceneWrite but can also return LI_NWC_WRITE_NOT_LICENSED
 * or LI_NWC_OUT_OF_MEMORY.
 *
 * \param scene Node to add
 * \param filename Filename to write to, including .nwd extention
 * \param progress Progress callback, or NULL if not interested
 * \param user_data User data pointer passed to progress callback
 * \return LI_NWC_WRITE_OK if successfull
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcWriteStatus LI_NWC_API
LiNwcSceneWriteEx(LtNwcScene scene, LtWideString filename,
                  LtNwcProgressCallback* progress, void* user_data);

/**
 * Write a scene out as a NavisWorks NWC file. This converts all data into
 * NavisWorks internal format. After writing no operations apart from destroy
 * are permitted.
 * From NavisWorks 4.1 onwards will fail with a LI_NWC_WRITE_INTERNAL_ERROR if
 * write runs out of memory.
 *
 * \param scene Node to add
 * \param orig_filename Filename for which cache is being generated, NULL if unknown or not applicable.
 * \param filename Filename to write to, including .nwc extention
 * \param progress Progress callback, or NULL if not interested
 * \param user_data User data pointer passed to progress callback
 * \return LI_NWC_WRITE_OK if successfull
 * \version 3.0
 */
LI_NWC_PUBLIC LtNwcWriteStatus LI_NWC_API
LiNwcSceneWriteCache(LtNwcScene scene, LtWideString orig_filename,
                     LtWideString filename,
                     LtNwcProgressCallback* progress, void* user_data);

/**
 * Same as LiNwcSceneWriteCache but can also return LI_NWC_WRITE_OUT_OF_MEMORY.
 *
 * \param scene Node to add
 * \param orig_filename Filename for which cache is being generated, NULL if unknown or not applicable.
 * \param filename Filename to write to, including .nwc extention
 * \param progress Progress callback, or NULL if not interested
 * \param user_data User data pointer passed to progress callback
 * \return LI_NWC_WRITE_OK if successfull
 * \version 4.1
 */
LI_NWC_PUBLIC LtNwcWriteStatus LI_NWC_API
LiNwcSceneWriteCacheEx(LtNwcScene scene, LtWideString orig_filename,
                       LtWideString filename,
                       LtNwcProgressCallback* progress, void* user_data);

/**
 * Formats an error message for a given LtNwcWriteStatus value. Use to
 * display a message to the user if writing a file fails.
 *
 * Note that it uses a shared buffer for formatting the string, so the
 * return value is only valid until the next time this function is called.
 *
 * \param status Write status code.
 * \param filename Name of file being loaded.
 * \return Formatted error message. Only valid until next call to function.
 * \version 5.4
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcSceneGetWriteStatusErrorMessage(LtNwcWriteStatus status,
                                     LtWideString filename);

/**
 * OBSOLETE: Does nothing.
 *
 * Adds a mapping between a presenter material and a node.
 *
 * \param scene Scene to add material / node mapping to
 * \param node Node to map to material
 * \param material Material to map to node
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneAddPresenterMaterialToNode(LtNwcScene scene,
                                LtNwcNode node,
                                LtNwcPresenterMaterial material);

/**
 * Sets the presenter scale. This function has been replaced by
 * LiNwcSetLinearUnits. For NavisWorks 3.0 and later the scale
 * set will be converted into the approriate units.
 *
 * \param scene Scene to set Presenter scale for.
 * \param scale Scale to use.
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneSetPresenterScale(LtNwcScene scene,
                            LtFloat    scale);

/**
 * OBSOLETE: Does nothing.
 *
 * Sets the Presenter background shader to use
 *
 * \param scene Scene to modify
 * \param shader_name Name of shader to use
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneSetPresenterBackgroundShader(LtNwcScene scene,LtWideString shader_name);

/**
 * OBSOLETE: Does nothing.
 *
 * Sets the an argument on the current Presenter background shader
 *
 * \param scene Scene to modify
 * \param arg_name Argument name
 * \param arg Argument data
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneSetPresenterBackgroundShaderArg(LtNwcScene scene,LtWideString arg_name,LtNwcPresenterData arg);

/**
 * Units that can be set with LiNwcSceneSetLinearUnits
 */
typedef enum LtNwcLinearUnits__tag {
   LI_NWC_UNITS_METERS,       /** Meters */
   LI_NWC_UNITS_CENTIMETERS,  /** Centimeters */
   LI_NWC_UNITS_MILLIMETERS,  /** Millimeters */
   LI_NWC_UNITS_FEET,         /** Feet */
   LI_NWC_UNITS_INCHES,       /** Inches */
   LI_NWC_UNITS_YARDS,        /** Yards */
   LI_NWC_UNITS_KILOMETERS,   /** Kilometres */
   LI_NWC_UNITS_MILES,        /** Miles */
   LI_NWC_UNITS_MICROMETERS,  /** Micrometres */
   LI_NWC_UNITS_MILS,         /** Mils */
   LI_NWC_UNITS_MICROINCHES,  /** MicroInches */
} LtNwcLinearUnits;

/**
 * Sets the linear units for the scene. If no units are set, meters will
 * be used by default.
 *
 * \param scene Scene to set linear units for.
 * \param units Units to use.
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetLinearUnits(LtNwcScene scene, LtNwcLinearUnits units);

/**
 * Converts a linear unit measurement from one unit to another.
 *
 *  \param value Linear dimension to convert
 *  \param from Units input is in
 *  \param to Units output is required in
 *  \return Converted value
 *  \version 3.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcSceneConvertLinearUnit(LtFloat value, LtNwcLinearUnits from, LtNwcLinearUnits to);

/**
 * Converts a linear unit measurement from one unit to another with dimension.
 *
 *  \param value Linear dimension to convert
 *  \param from Units input is in
 *  \param to Units output is required in
 *  \param dimension Dimension units are in (e.g. 1 for linear, 2 for area, 3 for volume)
 *  \return Converted value
 *  \version 24.0
 */
LI_NWC_PUBLIC LtFloat LI_NWC_API
LiNwcSceneConvertLinearUnitEx(LtFloat value, LtNwcLinearUnits from, LtNwcLinearUnits to, int dimension);

/**
 * Returns the units abbreviation (m,cm,ft,etc.) for a linear unit
 *
 *  \param units Units to return abbreviation for
 *  \return Abbreviation for units. Only valid until next call to function.
 *  \version 7.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcSceneGetLinearUnitAbbreviation(LtNwcLinearUnits units);

/**
 * OBSOLETE: Does nothing.
 *
 * Adds a mapping between a presenter texture space and a node.
 *
 * \param scene Scene to add material / node mapping to
 * \param node Node to map to material
 * \param tex_space Texture space
 * \return true if ok , false on error
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneAddPresenterTextureSpaceToNode(LtNwcScene scene,
                                         LtNwcNode node,
                                         LtNwcPresenterTextureSpace tex_space);

/**
 * Adds a mapping between a texture space and a node.
 *
 * \param scene Scene to add material / node mapping to
 * \param node Node to map to material
 * \param tex_space Texture space
 * \return true if ok , false on error
 * \version 20.1
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcSceneAddAutodeskTextureSpaceToNode(LtNwcScene scene,
                                        LtNwcNode node,
                                        LtNwcAutodeskTextureSpace tex_space);


/**
 * Adds an XRef description into the scene.
 *
 * A dependency on a directory can be set, by using the directory name in xref_name and resolved_name
 * exactly as for a file.  When a dependency is on a directory, creation or destruction of the directory
 * will cause the scene to be recached, as will any change to a file within the directory.
 *
 * A dependency on only files with a certain extension with the directory can also be set.  This is done by
 * setting:
 * xref_name to the directory path, and
 * resolved_name to the path plus an extression "*.TYPE" (where "TYPE" is the extension of the files you
 * want to depend upon).  As with other dependencies, this must be NULL if the dependency is
 * missing, which in this case means that the directory was not found, this should not be NULL if
 * the directory exists but does not contain any files of the type required.
 *
 * When a dependency is on a type of file, you must still add in explicit dependencies for which files
 * of that type existed at the time.  The advantage of setting a dependency on a type of file is that
 * if new files of that type appear, the scene will be reloaded to take account of them.
 *
 * \param scene Scene to add XRef to
 * \param xref_name Original path to XRef
 * \param resolved_name Resolved path to XRef
 * \version 3.2
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneDescribeXRef(LtNwcScene scene, LtWideString xref_name, LtWideString resolved_name);

/**
 * Adds a dependent file loader description onto the scene.
 *
 * Any change in the specified loader's arguments will cause the scene to be recached. For NWCreate based
 * loaders the name required is "LcNwcLoaderPlugin:LOADER" where LOADAER is the name of the
 * NWCreate loader.
 *
 * This is only required if using LiNwcLoaderCreateXRef to add data to the scene that requires a
 * different loader (ie. uses a different file format).
 *
 * \param scene Scene to add dependent file loader to
 * \param file_loader Name of dependent file loader
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneDescribeDependentFileLoader(LtNwcScene scene,
                                      LtString file_loader);

/**
 * Sets the world up vector on the scene.
 *
 * \param scene Scene to set vector on
 * \param x X coordinate of world up vector
 * \param y Y coordinate of world up vector
 * \param z Z coordinate of world up vector
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetWorldUpVector(LtNwcScene scene,
                           LtFloat x,
                           LtFloat y,
                           LtFloat z);

/**
 * Sets the world north vector on the scene.
 *
 * \param scene Scene to set vector on
 * \param x X coordinate of world north vector
 * \param y Y coordinate of world north vector
 * \param z Z coordinate of world north vector
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetWorldNorthVector(LtNwcScene scene,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Sets the world front vector on the scene.
 *
 * \param scene Scene to set vector on
 * \param x X coordinate of world front vector
 * \param y Y coordinate of world front vector
 * \param z Z coordinate of world front vector
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetWorldFrontVector(LtNwcScene scene,
                              LtFloat x,
                              LtFloat y,
                              LtFloat z);

/**
 * Sets the source filename of the scene.
 *
 * \param scene Scene to set filename on.
 * \param filename Source filename of scene.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetFilename(LtNwcScene scene,
                      LtWideString filename);

/**
 * Mark the scene as being a 2D plot (all geometry is defined using a plot stream).
 * Default is false.
 *
 * \param scene Scene to mark as a 2D plot
 * \param b true to mark as plot, false for default
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetIsPlot(LtNwcScene scene, bool b);

/**
 * Enum for preferred graphics system.
 */
typedef enum LtNwcGraphicsSystem__tag {
   LI_NWC_GRAPHICS_ANY,
   LI_NWC_GRAPHICS_AUTODESK,
   LI_NWC_GRAPHICS_PRESENTER,
} LtNwcGraphicsSystem;

/**
 * OBSOLETE: since Presenter Graphics have been retired there is only one graphics system
 *
 * Sets the preferred graphics system for the scene. If you have added
 * Presenter materials, you should use LI_NWC_GRAPHICS_PRESENTER. If you
 * have added Autodesk materials, you should set to LI_NWC_GRAPHICS_AUTODESK.
 *
 * Just by setting this value, it does not guarentee that the particular
 * system will actually be used, just which one NavisWorks will try to use
 * in preference to any other.
 *
 * By default, value is LI_NWC_GRAPHICS_ANY.
 *
 * Note that Presenter is now obsolete, Presenter materials now have no affect
 * and LI_NWC_GRAPHICS_PRESENTER now represents support for basic graphics.
 *
 * \param scene Scene to set system on.
 * \param system Preferred graphics system to use.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneSetPreferredGraphicsSystem(LtNwcScene scene, LtNwcGraphicsSystem system);

/**
 * Adds a grid system to the scene.
 *
 * You can add multiple grid systems to the same scene, but only
 * one system will be active at any one time.
 *
 * \param scene Scene to add system to.
 * \param system Grid system to add.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddGridSystem(LtNwcScene scene,
                        LtNwcGridSystem system);

/**
 * Add Autodesk environment
 *
 * \param scene Scene to add Autodesk environment to.
 * \param asset Autodesk environment to add.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddAutodeskEnvironment(LtNwcScene scene,
                                 LtNwcAutodeskAsset asset);
/**
 * Add Autodesk environment
 *
 * \param scene Scene to add Autodesk environment to.
 * \param json_asset Autodesk environment with json format to add.
 * \version 13.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneAddAutodeskJsonEnvironment(LtNwcScene scene,
                                 LtNwcAutodeskJsonAsset json_asset);

/**
 * Applies a transform to the scene.
 *
 * The transform will update everything in the scene including geometry,
 * views and grid systems.
 *
 * \param scene Scene to apply transform to
 * \param transform Transform to apply.
 * \version 10.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcSceneApplyTransform(LtNwcScene scene,
                        LtNwcTransform transform);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcScene API calls
 *
 * \see LiNwcScene.h
 */
class LcNwcScene
{
public:
   LcNwcScene() : m_handle(LiNwcSceneCreate()), m_own(true) {}
   LcNwcScene(LtNwcScene scene) : m_handle(scene), m_own(false) {}
   ~LcNwcScene() { if (m_own) LiNwcSceneDestroy(m_handle); }

   operator LtNwcScene () { return m_handle; }
   LtNwcScene GetHandle() const { return m_handle; }

   void SetDefaultMaterial(LtNwcMaterial material)
   { LiNwcSceneSetDefaultMaterial(m_handle, material); }

   void SetTwoSided(bool b)
   { LiNwcSceneSetTwoSided(m_handle, b); }

   void SetBackgroundColor(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcSceneSetBackgroundColor(m_handle, r, g, b); }

   void SetGraduatedBackground(LtVector colour1,
                               LtVector colour2)
   { LiNwcSceneSetGraduatedBackground(m_handle, colour1, colour2); }

   void SetHorizonBackground(LtVector sky_colour1,
                             LtVector sky_colour2,
                             LtVector ground_colour1,
                             LtVector ground_colour2)
   { LiNwcSceneSetHorizonBackground(m_handle, sky_colour1, sky_colour2, ground_colour1, ground_colour2); }

   void SetPaperStyle(LtNwcPlotPaperStyle style)
   { LiNwcSceneSetPaperStyle(m_handle, style); }

   void SetGlobalAmbient(LtFloat r, LtFloat g, LtFloat b)
   { LiNwcSceneSetGlobalAmbient(m_handle, r, g, b); }

   void SetCurrentView(LtNwcView view)
   { LiNwcSceneSetCurrentView(m_handle, view); }

   void SetPlanView(LtNwcView view)
   { LiNwcSceneSetPlanView(m_handle, view); }

   void SetSectionView(LtNwcView view)
   { LiNwcSceneSetSectionView(m_handle, view); }

   void SetHomeView(LtNwcView view)
   { LiNwcSceneSetHomeView(m_handle, view); }

   void AddSavedView(LtNwcSavedView view)
   { LiNwcSceneAddSavedView(m_handle, view); }

   void AddNode(LtNwcNode node)
   { LiNwcSceneAddNode(m_handle, node); }

   void AddAttribute(LtNwcAttribute attribute)
   { LiNwcSceneAddAttribute(m_handle, attribute); }

   void AddLight(LtNwcCommonLight light)
   { LiNwcSceneAddLight(m_handle, light); }

   void AddSavedSet(LtNwcSavedSet set)
   { LiNwcSceneAddSavedSet(m_handle, set); }

   LtInt32 GetNumChildren() const
   { return LiNwcSceneGetNumChildren(GetHandle()); }

   LtNwcNode GetChild(LtInt32 pos)
   { return LiNwcSceneGetChild(GetHandle(), pos); }

   void SetStatistics(LtWideString statistics)
   { LiNwcSceneSetStatistics(m_handle, statistics); }

   void SetSceneCompleteCallback(LtNwcSceneCompleteCallback* cb,
      void* user_data)
   { LiNwcSceneSetSceneCompleteCallback(m_handle, cb, user_data); }

   LtNwcWriteStatus Write(LtWideString filename,
      LtNwcProgressCallback* progress, void* user_data)
   { return LiNwcSceneWrite(m_handle, filename, progress, user_data); }

    LtNwcWriteStatus WriteEx(LtWideString filename,
      LtNwcProgressCallback* progress, void* user_data)
   { return LiNwcSceneWriteEx(m_handle, filename, progress, user_data); }

   LtNwcWriteStatus WriteCache(LtWideString orig_filename, LtWideString filename,
      LtNwcProgressCallback* progress, void* user_data)
   { return LiNwcSceneWriteCache(m_handle, orig_filename, filename, progress, user_data); }

   LtNwcWriteStatus WriteCacheEx(LtWideString orig_filename, LtWideString filename,
      LtNwcProgressCallback* progress, void* user_data)
   { return LiNwcSceneWriteCacheEx(m_handle, orig_filename, filename, progress, user_data); }

   static LtWideString GetWriteStatusErrorMessage(LtNwcWriteStatus status,
                                                  LtWideString filename)
   { return LiNwcSceneGetWriteStatusErrorMessage(status, filename); }

   bool AddPresenterMaterialToNode(LtNwcNode node,LtNwcPresenterMaterial material)
   { return LiNwcSceneAddPresenterMaterialToNode(GetHandle(),node,material);}

   bool SetPresenterBackgroundShader(LtWideString shader_name)
   { return LiNwcSceneSetPresenterBackgroundShader(GetHandle(),shader_name);}

   bool SetPresenterBackgroundShaderArg(LtWideString arg_name,LtNwcPresenterData arg)
   { return LiNwcSceneSetPresenterBackgroundShaderArg(GetHandle(),arg_name,arg);}

   bool SetPresenterScale(LtFloat scale)
   { return LiNwcSceneSetPresenterScale(GetHandle(),scale);  }

   void SetLinearUnits(LtNwcLinearUnits units)
   { LiNwcSceneSetLinearUnits(GetHandle(), units); }

   static LtFloat ConvertLinearUnit(LtFloat value, LtNwcLinearUnits from, LtNwcLinearUnits to)
   { return LiNwcSceneConvertLinearUnit(value, from, to); }

   static LtWideString GetLinearUnitAbbreviation(LtNwcLinearUnits units)
   { return LiNwcSceneGetLinearUnitAbbreviation(units); }

   bool AddPresenterTextureSpaceToNode(LtNwcNode node, LtNwcPresenterTextureSpace tex_space)
   { return LiNwcSceneAddPresenterTextureSpaceToNode(GetHandle(), node, tex_space); }

   bool AddAutodeskTextureSpaceToNode(LtNwcNode node, LtNwcAutodeskTextureSpace tex_space)
   { return LiNwcSceneAddAutodeskTextureSpaceToNode(GetHandle(), node, tex_space); }

   void DescribeXRef(LtWideString xref_name, LtWideString resolved_name)
   { LiNwcSceneDescribeXRef(GetHandle(), xref_name, resolved_name); }

   void DescribeDependentFileLoader(LtString file_loader)
   { LiNwcSceneDescribeDependentFileLoader(GetHandle(), file_loader); }

   void SetWorldUpVector(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcSceneSetWorldUpVector(GetHandle(), x, y, z); }

   void SetWorldNorthVector(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcSceneSetWorldNorthVector(GetHandle(), x, y, z); }

   void SetWorldFrontVector(LtFloat x, LtFloat y, LtFloat z)
   { LiNwcSceneSetWorldFrontVector(GetHandle(), x, y, z); }

   void SetFilename(LtWideString filename)
   { LiNwcSceneSetFilename(GetHandle(), filename); }

   void SetIsPlot(bool b)
   { LiNwcSceneSetIsPlot(m_handle, b); }

   void SetPreferredGraphicsSystem(LtNwcGraphicsSystem system)
   { LiNwcSceneSetPreferredGraphicsSystem(GetHandle(), system); }

   void AddGridSystem(LtNwcGridSystem system)
   { LiNwcSceneAddGridSystem(m_handle, system); }

   void AddAutodeskEnvironment(LtNwcAutodeskAsset asset)
   { LiNwcSceneAddAutodeskEnvironment(GetHandle(), asset); }

   void AddAutodeskJsonEnvironment(LtNwcAutodeskJsonAsset json_asset)
   { LiNwcSceneAddAutodeskJsonEnvironment(GetHandle(), json_asset); }

   void ApplyTransform(LtNwcTransform transform)
   { LiNwcSceneApplyTransform(m_handle, transform); }

private:
   // Can't copy
   LcNwcScene(const LcNwcScene&);
   LcNwcScene& operator= (const LcNwcScene&);

   LtNwcScene m_handle;
   bool m_own;
};

#endif

#endif /* LINWCSCENE_HDR */
