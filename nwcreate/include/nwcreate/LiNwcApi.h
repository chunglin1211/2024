/**
 * \file
 *
 * Initialisation and termination of nwcreate. These functions must be
 * called when writing an exporter from third party software. They should
 * not be called when writing a file loader (see LiNwcLoader.h) for NavisWorks.
 *
 * To export a model to an NWD file, first call LiNwcApiInitialise(). Create
 * an LtNwcScene handle. Add nodes, attributes and views that define the
 * model. Write the scene to file. Destroy the scene. Call
 * LiNwcApiTerminate().
 *
 * Programmer errors in use of the API are reported via an error callback.
 *
 * Your application should link with nwcreate.lib from the lib directory.
 * The implementation of the API is in nwcreate.dll from the release
 * directory. You should distribute this DLL with your application.
 *
 * There are two examples of writing an exporter in the examples directory.
 * Gecko is written in C++ using the C++ wrapper API. Sidewinder is written
 * in C.
 */

/**
 * \mainpage Overview
 *
 * The NWCreate API provides a means of creating NavisWorks models,
 * either for export of NWD files from a third party application
 * (LiNwcApi.h) or to implement a file loader (LiNwcLoader.h) for
 * NavisWorks. NWCreate is a stdcall interface callable from C, C++,
 * etc. All data manipulation is by means of handles (LiNwcTypes.h)
 * providing complete encapsulation. For ease of use a C++ wrapper API is
 * provided that gives an object oriented interface to the API.
 *
 * A NavisWorks model is represented by a scene (LiNwcScene.h). The
 * structure of the model is represented by a hierarchy of nodes
 * (LiNwcNode.h). Nodes can be added to more than one group node
 * (LiNwcGroup.h) supporting multiple instancing. Each geometric object in
 * the scene is represented by a geometry node (LiNwcGeometry.h). The
 * geometric data stored in a geometry node is defined by opening a
 * geometry stream (LiNwcGeometryStream.h) for the geometry node and
 * defining geometric primitives to the stream. Geometric primitives can
 * be defined directly on the stream or by creating primitive objects
 * (LiNwcBRepAPI.h, LiNwcCurve2d.h, LiNwcCurve.h, LiNwcSurface.h, LiNwcTopology.h)
 * and passing them to the stream.
 *
 * Each node can have multiple attributes (LiNwcAttribute.h) attached to
 * it. Attributes are used to position objects (LiNwcTransform.h), define
 * materials (LiNwcMaterial.h) and priorities (LiNwcSemanticPriority.h) for
 * rendering. They are also used to add arbitrary properties
 * (LiNwcTextAttribute.h, LiNwcNameAttribute.h, LiNwcNat64Attribute.h,
 * LiNwcPropertyAttribute.h, LiNwcURLAttribute.h, LiNwcBinaryAttribute.h) to a
 * node that are displayed to an end user on the object property sheet
 * within NavisWorks.
 *
 * NWcreate provides a mechanism to link to an external geometry
 * provider. Currently it supports providing point data, which can be
 * useful for viewing large point cloud datasets. The
 * LiNwcExternalGeometry.h component allows the definition of the geometry,
 * whilst the LiNwcExternalLink.h defines a protocol for communicating with
 * the external source.
 *
 * In addition to 3D geometry, NWcreate can also be used to create 2D
 * plot-style geometry, the sort you would find on a 2D drawing. For
 * this, you need to use the LiNwcPlotXXX components. You start by
 * opening a plot stream (LiNwcPlotStream.h). Next, you would begin a
 * canvas (LiNwcPlotCanvasStyle.h). Within a canvas, you can create
 * multiple viewports (LiNwcPlotViewportStyle.h). Once you have begun a
 * viewport, you can then add text (LiNwcPlotFontStyle.h,
 * LiNwcPlotTextStyle.h), or paths (LiNwcPlotPathStyle.h). Then, you would
 * begin a path geometry stream (LiNwcPlotGeometryStream.h), to which you
 * can add 2D plot primitives (LiNwcPlotArcSegment.h,
 * LiNwcPlotCircleSegment.h, LiNwcPlotEllipseSegment.h).
 *
 * Models with 2D plots often comprise multiple models, or
 * sheets. NWcreate allows you to define a model with multiple
 * sheets. Each sheet has its own name, and can contain either 2D or 3D
 * data. The LiNwcFileInfo component lets you define how many sheets the
 * file contains, then each sheet is defined using the LiNwcSheetInfo
 * component.
 *
 * The scene also defines a current view and views for plan and section
 * thumbnails (LiNwcView.h). A collection of saved views (LiNwcSavedView.h)
 * can also be defined for a scene including simple views (LiNwcView.h),
 * folders (LiNwcFolderView.h) and animations (LiNwcAnimView.h) defined by a
 * sequence of simple views and cuts (LiNwcCutView.h). Scenes also contain
 * a collection of lights (LiNwcCommonLight.h) including distant lights
 * (LiNwcDistantLight.h), point lights (LiNwcPointLight.h) and spot lights
 * (LiNwcSpotLight.h).
 *
 * Selection sets (LiNwcSelectionSet.h) that contain a set of geometry
 * nodes or groups can be defined. These sets can be grouped into folders
 * (LiNwcFolderSet.h).
 *
 * \section software-architecture Software Architecture
 *
 * NWCreate is a NavisWorks module. NWCreate is split into multiple
 * components. Each component is defined by a single header file with the
 * same name. For example the LiNwcScene component is defined by the
 * LiNwcScene.h header. A component contains an inter-related collection
 * of classes, typedefs, global functions and macros which cannot be
 * conveniently split. A component may depend on other components (e.g. a
 * component containing a class depends on the component containing its
 * base class).
 *
 * \section naming-conventions Naming Conventions
 *
 * All data types that appear in the API adopt the prefix "Lt". In
 * general, the standard C data types, such as int, float, etc. are not
 * used. In place of these a number of standard or generic data types,
 * defined in the header file nwcreate/LiNwcTypes.h, are employed
 * throughout the API. These have names such as LtChar, LtString, LtInt32.
 *
 * The API operates by creating, manipulating and destroying handle types
 * (defined in LiNwcTypes.h). Each NWCreate specific type (including handle
 * types) adopts the prefix "LtNwc". The API functions that manipulate
 * handles have the form Li&lt;handle&gt;&lt;method&gt;. Thus,
 * the convention is an object oriented one in which the name of the
 * handle that is to be operated upon appears first followed by the name
 * of the method that is to be applied to the handle. For example,
 * LiNwcSceneAddNode adds a node to an LtNwcScene handle. All methods
 * that operate on the handle LtNwc&lt;handle&gt; are defined in the
 * component LiNwc&lt;handle&gt;. For example, methods that operate
 * on LtNwcNode are defined in the LiNwcNode component.
 *
 * Some handles allow pointers to callback functions to be set on them. A
 * callback is a function that is implemented by some external software
 * and is supplied to NWCreate in the form of a pointer. This function
 * will then be invoked when its particular functionality is
 * required. The function prototype for each callback is defined by a
 * typedef of the form LtNwc&lt;name&gt;Callback. All callback
 * functions use the stdcall calling convention.
 *
 * \section usage Usage
 *
 * The headers for NWCreate are in the include\nwcreate directory. The
 * include directory should be added to your include search path and
 * headers included with an nwcreate prefix. The header LiNwcAll.h
 * includes all other NWCreate headers. For example, #include
 * &lt;nwcreate/LiNwcAll.h&gt;, will include all NWCreate headers.
 *
 * Linking with NWCreate depends on whether you're writing a stand alone
 * exporter for NWD files (see LiNwcApi) or a file loader for NavisWorks
 * (see LiNwcLoader).
 *
 * Handles are created through a Create method
 * (e.g. LiNwcNodeCreate). Every handle created must be destroyed by a
 * call to the corresponding Destroy method (e.g. LiNwcNodeDestroy). You
 * should never destroy a handle you haven't created. Destruction of a
 * handle will only destroy the object being manipulated through the
 * handle if there are no other references to the object. The first
 * argument to all methods (except for Create methods) is the handle
 * being operated on.
 *
 * Handles are arranged in a class hierarchy (see LiNwcTypes). For
 * example, \c LtNwcGroup and \c LtNwcGeometry are both subclasses of the
 * \c LtNwcNode handle. All methods on a base handle are available on a
 * subclass. For example, \c LiNwcNodeSetName can be called with an
 * \c LtNwcGroup handle. Sub/base class relations cannot be expressed in C,
 * so the macro \c LI_BASE is provided to perform type safe casting of a
 * subclass handle to a base class handle.
 *
 * \section cpp-api C++ API
 *
 * When used from C++ the NWCreate handle types are defined as classes,
 * so use of the \c LI_BASE macro is unnecessary. Additionally, C++ wrapper
 * classes are also defined. Each handle \c LtNwc&lt;handle&gt; has a
 * corresponding wrapper class \c LcNwc&lt;handle&gt;. Where the handle
 * has a Create method, the default constructor of the wrapper will
 * create a handle and the destructor will destroy it. For every method
 * on a handle \c Li&lt;handle&gt;&lt;method&gt;, the wrapper class
 * has a member function \c &lt;method&gt;. All methods are inline. The
 * wrappers simply make code less verbose and ensure that every handle
 * create has a matching destroy.
 *
 * Where handles are not creatable, the wrapper has a constructor that
 * takes an existing handle as an argument. It can then be used in the
 * same way as any other wrapper. If constructed from an existing handle,
 * the wrapper will NOT call destroy for you. This makes for a simple
 * rule. Every time you explicitly write a Create method you must write a
 * matching Destroy.
 *
 * Most wrappers behave as smart pointers. They can be copied, assigned
 * to and returned from functions. This means that you should rarely need
 * to write an explicit Create or Destroy.
 *
 * The wrapper classes have a type conversion operator so can be passed
 * directly to any function that expects an argument of the corresponding
 * handle type. Finally, many wrapper methods are overloaded to take
 * arguments in whatever form is most convenient. For example,
 * \c LcNwcGeometryStream::TriangleVertex can be called with 3 LtFloat
 * arguments or a single LtPoint argument.
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

#ifndef LINWCAPI_HDR
#define LINWCAPI_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Status codes that can be returned by LiNwcApiInitialise.
 */
typedef enum LtNwcApiStatus__tag {
   LI_NWC_API_OK,             /** Initialise succeeded */
   LI_NWC_API_NOT_LICENSED,   /** API is not licensed for use */
   LI_NWC_API_INTERNAL_ERROR, /** An internal error occured */
} LtNwcApiStatus;


/**
 * Alternative extended initialisation function for the nwcreate API. Must be called
 * before any other NWCreate API function. By default NWCreate looks for its
 * external data (in nwcreate_data folder) relative to NWCreate.dll. When
 * using this initialisation function, NWCreate will look for its external data
 * relative to the given module.
 *
 * \param module_instance windows module handle.
 * \return Returns LI_NWC_API_OK if successfull.
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcApiStatus LI_NWC_API
LiNwcApiInitialiseEx(LtHINSTANCE module_instance);

/**
 * Initialise the nwcreate API. Must be called before any other NWCreate API
 * function.
 *
 * \return Returns LI_NWC_API_OK if successfull.
 */
LI_NWC_PUBLIC LtNwcApiStatus LI_NWC_API
LiNwcApiInitialise();

/**
 * Severity of error in error callback
 */
typedef enum LtNwcSeverity__tag {
   LI_NWC_SEVERITY_ERROR,     /** Fatal error */
   LI_NWC_SEVERITY_WARNING    /** Warning */
} LtNwcSeverity;

/**
 * Called to report warning/error in programmer's use of the API.
 * \param severity code indicating severity of error. Warnings can be ignored.
 * \param message message describing the error. Not for display to user.
 * \param user_data User pointer passed over when error callback set
 */
typedef void LI_NWC_API
LtNwcErrorCallback(LtNwcSeverity severity, LtString message, void* user_data);

/**
 * Called to report warning/error in programmer's use of the API.
 * \param severity code indicating severity of error. Warnings can be ignored.
 * \param message message describing the error. Not for display to user.
 * \param user_data User pointer passed over when error callback set
 */
typedef void LI_NWC_API
LtNwcErrorCallbackWide(LtNwcSeverity severity, LtWideString message, void* user_data);

/**
 * Set global error handler. Used for warnings and unresolvable errors.
 * Warnings can be reported or ignored. Unresolvable errors should cause
 * a termination of program or generate an exception.
 *
 * If no handler is set, warnings will be ignored and unresolvable errors
 * will call abort().
 *
 * \param handler callback function
 * \param user_data User data pointer passed to handler when called
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetErrorHandler(LtNwcErrorCallback* handler, void* user_data);

/**
 * Optional wide-string error handler, as above. The most recently set handler
 * will be used. This error should also terminate/throw as required.
 *
 * \param handler callback function
 * \param user_data User data pointer passed to handler when called
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetErrorHandlerWide(LtNwcErrorCallbackWide* handler, void* user_data);

/**
 * Terminate the nwcreate API. All nwcreate handles should be destroyed before
 * termination.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiTerminate();

/**
 * OBSOLETE: Returns NULL.
 *
 * Creates a directory to store generated maps in.
 * \param base_file Complete path and filename of file being read / exported to.
 * \return Returns name of directory to store maps in. Name is valid until next call. Returns NULL on failure.
 * \version 5.1
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcApiCreateMapDir(LtWideString base_file);

/**
 * Creates an image map from specified DIB pixel data and filename.
 * \param file Complete path and filename of file to be created. Be sure to add the extension of the image type you want!
 * \param header Image header describing the pixel data.
 * \param pixels Pointer to pixel data.
 * \return Returns true if the file was created successfully.
 * \version 4.1
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiCreateMap(LtWideString file, LtNwcImageHeader header, const LtNat8* pixels);

/**
 * Presenter is OBSOLETE: Returns false
 *
 * Checks if presenter is available and Licensed.
 * Presenter functions will do nothing if this returns false.
 * Should be called after LiNwcApiInitialise
 * \return Returns true if Presenter available.
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiIsPresenterAvailable();

/**
 * OBSOLETE: Returns false
 *
 * Checks if presenter can read a particular map file.
 * \param filename map file to check
 * \return Returns true if map file readable.
 * \version 2.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiPresenterIsMapReadable(LtWideString filename);

/**
 * OBSOLETE: Does nothing.
 *
 * Creates an Presenter image map pair from specified DIB pixel data and filenames.
 * \param color_file Complete path and filename of file to be created for holding color data. Be sure to add the extension of the image type you want!
 * \param alpha_file Complete path and filename of file to be created for holding alpha data. Can be NULL if not required.
 * \param header Image header describing the pixel data.
 * \param pixels Pointer to pixel data.
 * \return Returns true if the files were created successfully.
 * \version 4.1
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiPresenterCreateMap(LtWideString color_file, LtWideString alpha_file, LtNwcImageHeader header, const LtNat8* pixels);

/**
 * Checks if NWD Write is available and Licensed.
 * LiNwcSceneWrite() fail if this returns false.
 * Should be called after LiNwcApiInitialise
 * \return Returns true if NWD Write module is available.
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiIsNwdWriteAvailable();

/**
 * Returns a name defined in Name Table section of loader configuration
 * file or in separate .name file.
 * \param name identifier for name to find
 * \return Returns user string for name or NULL if not found
 * \version 3.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcApiFindName(LtString name);

/**
 * Same as LiNwcApiFindName except can specify default string to return
 * if not found.
 * \param name identifier for name to find
 * \param default_string String returned if name not found.
 * \return Returns user string for name or default_string if not found
 * \version 3.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcApiGetName(LtString name, LtWideString default_string);

/**
 * Returns the current value
 * exporter. The available parameters are defined in the same way as loader
 * parameters. The configuration file should be placed in the nwcreate_data
 * folder and be named "EXPORTER.txt" where EXPORTER is the name passed
 * to LiNwcApiSetExporterName().
 * This function will fail if the NavisWorks application is not installed
 * or no configuration file is found.
 *
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiInvokeParameterEditor();

/**
 * Launches the options editor.
 * \version 6.1
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiInvokeParameterEditorEx(bool advanced_mode);

/**
 * Returns the current value of an exporter parameter. The available
 * parameters are defined in the same way as loader
 * parameters. The configuration file should be placed in the nwcreate_data
 * folder and be named "EXPORTER.cfg" where EXPORTER is the name passed
 * to LiNwcApiSetExporterName().
 *
 * \param index parameter index
 * \param data parameter value
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiGetParameter(LtInt32 index, LtNwcData data);

/**
 * Initialise just the error and name handling parts of the nwcreate API.
 * Called automatically by LiNwcApiInitialise(). Use when you want error
 * and name handling available before initialising the full API or in case
 * of a full initialisation failure.
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiErrorInitialise();

/**
 * Alternative extended initialisation function for the error and name
 * handling parts of the nwcreate API. Called automatically by
 * LiNwcApiInitialiseEx().
 *
 * \param module_instance windows module handle.
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiErrorInitialiseEx(LtHINSTANCE module_instance);

/**
 * Terminate just the error and name handling parts of the nwcreate API.
 * Called automatically by LiNwcApiTerminate().
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiErrorTerminate();

/**
 * Normally an NWCreate based exporter will require an "nwcreate_exporter"
 * module in the NavisWorks license. This function allows an alternative
 * or no module to be required. The alternative module is specified
 * via a block of encrypted data.
 * Call after LiNwcApiErrorInitialise() and before LiNwcApiInitialise().
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetLicenseData(LtNat8* data, LtInt32 num_bytes);

/**
 * Prior to 6.0 NWCreate based exporters required the NavisWorks
 * license manager to be installed and an appropriate license to be
 * present. This function allows the application to specify an
 * embedded license file. The license file is specified via a block
 * of encrypted data.
 * Has no effect for 6.0 and later.
 * Call after LiNwcApiErrorInitialise() and before LiNwcApiInitialise().
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetLicenseFile(LtNat8* data, LtInt32 num_bytes);

/**
 * To use the provided support for exporter parameters, the exporter must
 * be given a unique name to use as a key when storing the parameters in
 * the registry. Sets the name to use.
 * Call after LiNwcApiErrorInitialise() and before LiNwcApiInitialise().
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetExporterName(LtString name);

/**
 * Sets the language NWcreate should use. The langauge is specified
 * as a IETF language tag. This function must be called before any
 * initialisation calls are made, and the language cannot be changed
 * after NWcreate has been initialised.
 * \param language_tag tag of language to use.
 * \version 11.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcApiSetLanguageTag(LtWideString language_tag);

/**
 * Looks for a given license.
 * \param name name of license to look for.
 * \return Returns LI_NWC_API_OK if valid license found.
 * \version 3.4
 */
LI_NWC_PUBLIC LtNwcApiStatus LI_NWC_API
LiNwcApiIsLicenseAvailable(LtString name);

/**
 * Returns directory that NWCreate loads its runtime data from.
 * \return Directory that NWCreate loads its runtime data from.
 * \version 4.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcApiGetPluginDirectory();

/**
 * Verifies a cache file.
 * \param orig_filename name of file to validate cache for.
 * \param cache_filename name of the cache file to validate.
 * \return Returns true if cache is valid, false otherwise.
 * \version 4.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcApiIsCacheValid(LtWideString orig_filename,
                     LtWideString cache_filename);

#ifdef __cplusplus
}
#endif

#endif /* LINWCAPI_HDR */
