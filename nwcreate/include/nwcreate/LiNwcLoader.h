/**
 * \file
 *
 * Represents an object that can read data from a file and convert
 * it to a NavisWorks scene. NavisWorks invokes a loader whenever a
 * user opens a file.
 *
 * Loaders are compiled into DLLs with a single well defined entry
 * point. This is a stdcall function with a prototype matching
 * LtNwcLoaderEntry.
 *
 * Loaders are registered with NavisWorks by adding a string value
 * to the "NWCreate Loaders" key in the registry. The key exists
 * under both HKEY_LOCAL_MACHINE and HKEY_CURRENT_USER. NavisWorks
 * searches both keys for loaders, with those in HKEY_CURRENT_USER
 * taking precedence. The path to the key for NavisWorks 3 is
 * "Software\NavisWorks Ltd\NavisWorks\3.0\NWCreate Loaders".
 * Registry entries for newer versions of NavisWorks will exist under
 * a different path, however NavisWorks will search all previous
 * locations for loaders.
 *
 * The name of the string value must be different from that of any other
 * loader. We suggest combining your company name and the file type that
 * the loader supports. The value of the string must be the absolute path
 * to the installed location of your loader DLL.
 *
 * NavisWorks loads the loader DLL on demand when a file supported by
 * the loader is opened. The capabilities of the loader are described
 * to NavisWorks using a configuration file. The configuration file
 * must be in the same directory as the loader and have the same name, but
 * with a ".txt" extension. From NavisWorks 3, configuration filenames can
 * include a 3 letter language code, e.g. loader_enu.txt rather than
 * loader.txt. NavisWorks will use the configuration file that best
 * matches the language selected in the Windows regional settings dialog.
 *
 * Programmer errors in use of the API are reported by NavisWorks as
 * internal errors.
 *
 * Your application should link with lcodpnwcreate.lib from the lib
 * directory. Your loader dll and config file are all that need to
 * be distributed.
 *
 * There is one example of writing a loader in the examples directory.
 * Loader is written in C++ using the C++ wrapper API. If you are writing
 * in C, see the sidewinder exporter example.
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

#ifndef LINWCLOADER_HDR
#define LINWCLOADER_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>
#include <nwcreate/LiNwcData.h>
#include <nwcreate/LiNwcScene.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Prototype of entry point for loader. Loader DLL will be dynamically loaded
 * and a function called "LiNwcLoaderEntry" with this prototype called.
 * The function should set callbacks on the loader handle passed in.
 * \param loader Loader to be initialised
 * \return false if loader cannot be initialised correctly
 */
typedef bool LI_NWC_API LtNwcLoaderEntry(LtNwcLoader loader);

/**
 * Status codes that can be returned by LtNwcLoadFileCallback function.
 */
typedef enum LtNwcLoadStatus__tag {
   LI_NWC_LOAD_OK,               /** Load succeeded */
   LI_NWC_LOAD_CANT_OPEN,        /** Can't open file for read */
   LI_NWC_LOAD_FILE_CORRUPT,     /** File is corrupt */
   LI_NWC_LOAD_BAD_VERSION,      /** File has an unknown version number */
   LI_NWC_LOAD_INVALID_FILENAME, /** The filename is invalid */
   LI_NWC_LOAD_CANCELED,         /** User canceled load (progress callback returned false) */
   LI_NWC_LOAD_ERROR,            /** Any loader error not related to the actual file */
   LI_NWC_LOAD_NO_ENGINE,        /** No engine is installed that can load this file */
} LtNwcLoadStatus;

/**
 * Callback function invoked for loader to determine if file specified by pathname
 * is in a format it understands and is prepared to try loading.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to test
 * \param user_data User data passed in when callback set
 * \return true if loader understands file and believes it can load it
 * \version 7.0
 */
typedef bool LI_NWC_API
LtNwcUnderstandsFileCallback(LtNwcLoader loader,
                        LtWideString pathname,
                        void* user_data);

/**
 * Set understands file callback function. This callback is optional. If the callback is not
 * supplied, the load file callback will be called for any file whose extension mentions
 * the filter specified in the loaders configuration file. If the callback is supplied, it
 * will be called and passed any file that matches the filter. If the callback returns false,
 * Navisworks will continue searching for a loader that can handle the file.
 *
 * The callback should be implemented for all loaders which handle files with an extension
 * shared with another loader. The implementation of the callback is assumed to be relatively,
 * simple - typically opening the file and checking data in a file header.
 *
 * \param loader Loader to set understands file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 * \version 7.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetUnderstandsFileCallback(LtNwcLoader loader,
                                 LtNwcUnderstandsFileCallback* cb,
                                 void* user_data);

/**
 * Extended version of the "understands file" callback function invoked on a
 * loader to determine if it can load a given file. Can optionally specify
 * a child loader to use to load the file.
 *
 * If a child loader is specified (by setting the pathname on the child_loader_spec
 * object), then that module will be used to load the file instead of this loader.
 * This child loader will share all the loader options with the parent loader.
 *
 * If this function returns true but no child loader is specified, then this loader
 * will be used, and must implement at least one of the "load file" callbacks.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to test
 * \param child_loader_spec Specification for loader to use to load file
 * \param user_data User data passed in when callback set
 * \return true if loader understands file
 * \version 9.0
 */
typedef bool LI_NWC_API
LtNwcUnderstandsFileExCallback(LtNwcLoader loader,
                               LtWideString pathname,
                               LtNwcLoaderSpec child_loader_spec,
                               void* user_data);

/**
 * Set the extended "understands file" callback function. This callback is optional.
 *
 * If you provide an implementation of this callback, then you cannot also
 * provide an implementation of "LtNwcUnderstandsFileCallback".
 *
 * \param loader Loader to set understands file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetUnderstandsFileExCallback(LtNwcLoader loader,
                                        LtNwcUnderstandsFileExCallback* cb,
                                        void* user_data);
/**
 * Callback function invoked for loader to read file and convert to a
 * NavisWorks scene. The load file function should report progress via the
 * progress argument and be prepared to stop the load and
 * return LI_NWC_LOAD_CANCELED if the progress function returns false.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to read
 * \param scene Scene to add file contents to
 * \param progress Call to report progress of file load operation
 * \param progress_data Pass to progress callback
 * \param user_data User data passed in when callback set
 * \return LI_NWC_LOAD_OK if load succeeds
 */
typedef LtNwcLoadStatus LI_NWC_API
LtNwcLoadFileCallback(LtNwcLoader loader,
                      LtWideString pathname,
                      LtNwcScene scene,
                      LtNwcProgressCallback* progress,
                      void* progress_data,
                      void* user_data);

/**
 * New version of callback function invoked for loader to read file and convert
 * to a NavisWorks scene. The load file function should report progress via the
 * progress argument and be prepared to stop the load and
 * return LI_NWC_LOAD_CANCELED if the progress function returns false.
 *
 * This new version allows the use of the new LtNwcProgress object for more
 * sophisticated progress reporting.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to read
 * \param scene Scene to add file contents to
 * \param progress Handle to progress reporting object
 * \param user_data User data passed in when callback set
 * \return LI_NWC_LOAD_OK if load succeeds
 * \version 3.0
 */
typedef LtNwcLoadStatus LI_NWC_API
LtNwcLoadFileExCallback(LtNwcLoader loader,
                        LtWideString pathname,
                        LtNwcScene scene,
                        LtNwcProgress progress,
                        void* user_data);

/**
 * Callback function invoked for loader to read file information
 * The load file function should report progress via the
 * progress argument and be prepared to stop the load and
 * return LI_NWC_LOAD_CANCELED if the progress function returns false.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to read
 * \param file_info File Info to add sheet info contents to
 * \param progress Call to report progress of file load operation
 * \param user_data User data passed in when callback set
 * \return LI_NWC_LOAD_OK if load succeeds
 * \version 9.0
 */
typedef LtNwcLoadStatus LI_NWC_API
LtNwcLoadFileInfoCallback(LtNwcLoader loader,
                          LtWideString pathname,
                          LtNwcFileInfo file_info,
                          LtNwcProgress progress,
                          void *user_data);

/**
 * Callback function invoked for loader to read file information
 * The load file function should report progress via the
 * progress argument and be prepared to stop the load and
 * return LI_NWC_LOAD_CANCELED if the progress function returns false.
 *
 * \param loader Loader callback is being invoked on
 * \param pathname Absolute pathname for file to read
 * \param sheet_id Sheet id to load the pointed sheet
 * \param scene Scene to add pointed sheet contents to
 * \param progress Call to report progress of file load operation
 * \param user_data User data passed in when callback set
 * \return LI_NWC_LOAD_OK if load succeeds
 * \version 9.0
 */
typedef LtNwcLoadStatus LI_NWC_API
LtNwcLoadFileSheetCallback(LtNwcLoader loader,
                           LtWideString pathname,
                           LtWideString sheet_id,
                           LtNwcScene scene,
                           LtNwcProgress progress,
                           void* user_data);

/**
 * Set load file callback function. Used to read file and convert to a
 * NavisWorks scene. This callback must be set for a loader to be able
 * to load a file.
 *
 * \param loader Loader to set load file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetLoadFileCallback(LtNwcLoader loader,
                               LtNwcLoadFileCallback* cb,
                               void* user_data);

/**
 * Set load file information callback function. Used to read file information.
 * This callback must be set for a loader to be able to load a file.
 *
 * \param loader Loader to set load file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetLoadFileInfoCallback(LtNwcLoader loader,
                               LtNwcLoadFileInfoCallback* cb,
                               void* user_data);

/**
 * Set load file sheet callback function. Used to read pointed sheet from a file.
 * This callback must be set for a loader to be able to load a file.
 *
 * \param loader Loader to set load file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetLoadFileSheetCallback(LtNwcLoader loader,
                                    LtNwcLoadFileSheetCallback *cb,
                                    void *user_data);


/**
 * Set extended load file callback function. Used to read file and convert
 * to a NavisWorks scene. This callback must be set for a loader to be able
 * to load a file.
 *
 * \param loader Loader to set load file callback for
 * \param cb callback function
 * \param user_data User data pointer passed to callback when called
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetLoadFileExCallback(LtNwcLoader loader,
                                 LtNwcLoadFileExCallback* cb,
                                 void* user_data);

/**
 * Callback function invoked to set value of a parameter.
 *
 * \param loader Loader callback is being invoked on
 * \param which Which parameter to set value of. Will be between 0 and number of defined parameters -1
 * \param data Data handle with value to set
 * \param user_data User data passed in when callback set
 * \return false if value is invalid for parameter
 */
typedef bool LI_NWC_API
LtNwcParameterCallback(LtNwcLoader loader,
                       LtInt32 which,
                       LtNwcData data,
                       void* user_data);

/**
 * Sets parameter callback function. The callback is run immediately after
 * the loader entry point is called to inform the loader of the current
 * values of all parameters. It will also be called whenever the end user
 * changes the value of a parameter through the options dialog.
 * The number, types and default values of loader
 * parameters are defined in the loader's configuration file. NavisWorks saves the
 * values of all parameters between sessions, so the values reported on initial load
 * may not be the defaults from the configuration file.
 * This callback is only required if parameters are defined.
 *
 * \param loader Loader to set parameter callback for
 * \param cb Callback function used to set value of parameter
 * \param user_data User data pointer passed to callback when called
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetParameterCallback(LtNwcLoader loader,
                                LtNwcParameterCallback* cb,
                                void* user_data);

/**
 * Callback function invoked to define default options for
 * loader.
 *
 * \param loader Loader callback is being invoked on.
 * \param user_data User data passed in when callback set.
 * \return default option set.
 * \version 6.0
 */
typedef void LI_NWC_API
LtNwcDefineOptionsCallback(LtNwcLoader loader,
                           LtNwcOptionSet option_set,
                           void* user_data);

/**
 * Sets the define options callback. Invoked when the loader is
 * first loaded, and allows it to define options.
 *
 * \param loader Loader to set callback for.
 * \param cb callback to invoke.
 * \param user_data User data pointer pass to callback when invoked.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetDefineOptionsCallback(LtNwcLoader loader,
                                    LtNwcDefineOptionsCallback *cb,
                                    void *user_data);

/**
 * Callback function invoked just before use of loader is terminated
 * (typically at program exit).
 *
 * \param loader Loader callback is being invoked on
 * \param user_data User data passed in when callback set
 * \version 3.0
 */
typedef void LI_NWC_API
LtNwcTerminateCallback(LtNwcLoader loader, void* user_data);

/**
 * Sets terminate callback function. Allows any resources
 * allocated by loader to be released.
 *
 * \param loader Loader to set terminate callback for
 * \param cb Callback function invoked on termination of loader use
 * \param user_data User data pointer passed to callback when called
 * \version 3.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetTerminateCallback(LtNwcLoader loader,
                                LtNwcTerminateCallback* cb,
                                void* user_data);

/**
 * Returns strings contained in a string table within the loader's
 * configuration file. The memory for the strings is maintained by the
 * loader. The caller should not attempt to delete or free the strings
 * returned.
 *
 * \param loader Loader to get string from string table for
 * \param index Index of string (starting from 0) to get
 * \return String if succeeded, NULL if no string with that index exists.
 * \version 2.0
 */
LI_NWC_PUBLIC LtWideString LI_NWC_API
LiNwcLoaderGetString(LtNwcLoader loader, LtInt32 index);

/**
 * Loads a referenced file and creates a node representing the file.
 * The filename must specify an existing file. The function will not
 * perform any resolution of the file it the specified file cannot be
 * found. If you need to resolve the filename first, use the
 * LiNwcLoaderResolveXRef functions.
 *
 * You can pass in a progress object to the function, but you should
 * call LiNwcProgressBeginSubOp/EndSubOp around this function
 * call in order for it to work correctly. If you don't call these
 * functions, the progress bar may behave in an unexpected manner.
 *
 * \param loader Loader to use
 * \param filename File to load
 * \param write_cache Should a cache file be produced after loading the file.
 * \param progress Progress object. Can be NULL.
 * \return Node that represents the loaded file.
 * \version 5.3
 */
LI_NWC_PUBLIC LtNwcNode LI_NWC_API
LiNwcLoaderCreateXRef(LtNwcLoader loader,
                      LtWideString filename,
                      bool write_cache,
                      LtNwcProgress progress);

/**
 * Status codes that can be returned by LiNwcResolveXRef and LiNwcResolveXRefEx function.
 */
typedef enum LtNwcXRefStatus__tag {
   LI_NWC_XREF_OK,            /** Resolve succeeded */
   LI_NWC_XREF_CANCEL,        /** Entire operation canceled by user */
   LI_NWC_XREF_IGNORE,        /** Ignore this unresolved xref */
   LI_NWC_XREF_IGNORE_ALL,    /** Ignore this and all other unresolved xrefs */
} LtNwcXRefStatus;

/**
 * Tries to resolve an externally referenced file for the loader, optionally
 * prompting user to find file.
 *
 * \param loader Loader to resolve xref for
 * \param filename Full pathname for file that contains the reference
 * \param xref_name Name of file being referenced (full or relative path)
 * \param interactive If true will prompt user to find xref if not found
 * \param xref_path Buffer in which to return resolved pathname. Should be at least _MAX_PATH chars long.
 * \return LI_NWC_XREF_OK if resolve succeeds
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcXRefStatus LI_NWC_API
LiNwcLoaderResolveXRef(LtNwcLoader loader, LtWideString filename,
                       LtWideString xref_name, bool interactive,
                       LtWideStringBuffer xref_path);

/**
 * Tries to resolve an externally referenced file for the loader, optionally
 * prompting user to find file.
 *
 * \param loader Loader to resolve xref for
 * \param saved_filename Full original saved pathname for file that contains the reference
 * \param filename Full pathname for file that contains the reference
 * \param xref_name Name of file being referenced (full or relative path)
 * \param interactive If true will prompt user to find xref if not found
 * \param xref_path Buffer in which to return resolved pathname. Should be at least _MAX_PATH chars long.
 * \return LI_NWC_XREF_OK if resolve succeeds
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcXRefStatus LI_NWC_API
LiNwcLoaderResolveXRefEx(LtNwcLoader loader, LtWideString saved_filename,LtWideString filename,
                         LtWideString xref_name, bool interactive,
                         LtWideStringBuffer xref_path);

/**
 * Tries to resolve an externally referenced file for the loader, optionally
 * prompting user to find file, will not download the file if it is remote
 *
 * \param loader Loader to resolve xref for
 * \param saved_filename Full original saved pathname for file that contains the reference
 * \param filename Full pathname for file that contains the reference
 * \param xref_name Name of file being referenced (full or relative path)
 * \param interactive If true will prompt user to find xref if not found
 * \param xref_path Buffer in which to return resolved pathname. Should be at least _MAX_PATH chars long.
 * \return LI_NWC_XREF_OK if resolve succeeds
 * \version 2.2
 */
LI_NWC_PUBLIC LtNwcXRefStatus LI_NWC_API
LiNwcLoaderResolveXRefNoDownload(LtNwcLoader loader, LtWideString saved_filename,LtWideString filename,
                                 LtWideString xref_name, bool interactive,
                                 LtWideStringBuffer xref_path);

/**
 * Normally an NWCreate based loader will require an "nwcreate_loader"
 * module in the NavisWorks license. This function allows an alternative
 * module to be required. The alternative licensing is specified
 * via a block of encrypted data.
 * Call during LtNwcLoaderEntry.
 * \version 4.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSetLicenseData(LtNwcLoader loader, LtNat8* data, LtInt32 num_bytes);

/**
 * Sets a loader parameter. The changed value will be visible in the NavisWorks
 * option dialog and will be remembered for future sessions.
 *
 * \param loader Loader to set parameter for
 * \param index Index of parameter to set (zero-based)
 * \param data Value of parameter
 * \return true if successful, false otherwise
 * \version 3.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcLoaderSetParameter(LtNwcLoader loader, LtInt32 index, LtNwcData data);

/**
 * Gets a loader parameter.
 *
 * \param loader Loader to get parameter for
 * \param index Index of parameter to get (zero-based)
 * \param data Value of parameter
 * \return true if successful, false otherwise
 * \version 3.2
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcLoaderGetParameter(LtNwcLoader loader, LtInt32 index, LtNwcData data);

/**
 * Gets the loader options.
 *
 * \param loader Loader to get parameter for.
 * \return option set for the loader.
 * \version 6.0
 */
LI_NWC_PUBLIC LtNwcOptionSet LI_NWC_API
LiNwcLoaderGetOptions(LtNwcLoader loader);

/**
 * Adds an external link to the loader. The link will be used by any ExternalGeometry created by the loader.
 *
 * \param loader Loader to add link too.
 * \param link link to add.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderAddLink(LtNwcLoader loader,
                    LtNwcExternalLink link);

/**
 * Returns an instance of a loader by NWCreate loader name.
 *
 * \param name Name of loader instance to return.
 * \return The loader instance, or NULL if not availabe.
 * \version 9.0
 */
LI_NWC_PUBLIC LtNwcLoader LI_NWC_API
LiNwcLoaderGetInstance(LtString name);

/**
 * Sets the pathname on a loader spec object.
 *
 * \param loader_spec Loader specification to set pathname on.
 * \param pathname pathname to DLL of loader. Can be absolute or relative to executable.
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderSpecSetPathname(LtNwcLoaderSpec loader_spec,
                           LtWideString pathname);

typedef enum LtNwcMessageCategory__tag {
   LI_NWC_MESSAGE_INFO,      /** Informational */
   LI_NWC_MESSAGE_WARNING,   /** Warning */
   LI_NWC_MESSAGE_ERROR,     /** Error */
   LI_NWC_MESSAGE_DEVELOPER, /** Developer */
} LtNwcMessageCategory;

/**
 * Posts a message to Message Center
 *
 * \param internal_id Internal ID.
 * \param source_filename Source filename.
 * \param category Message category.
 * \param message Message to post.
 * \param extended_message Extended message that might contain more information.
 * \param flags Reserved for future use. Use 0.
 * \version 21.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcLoaderPostMessage(LtWideString internal_id,
                       LtWideString source_filename,
                       LtNwcMessageCategory category,
                       LtWideString message,
                       LtWideString extended_message,
                       int flags);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcLoader API calls
 *
 * \see LiNwcLoader.h
 */
class LcNwcLoader
{
public:
   LcNwcLoader(LtNwcLoader handle) : m_handle(handle) {}

   operator LtNwcLoader () const { return m_handle; }
   LtNwcLoader GetHandle() const { return m_handle; }

   void SetUnderstandsFileCallback(LtNwcUnderstandsFileCallback* cb, void* user_data)
   { LiNwcLoaderSetUnderstandsFileCallback(m_handle, cb, user_data); }

   void SetUnderstandsFileExCallback(LtNwcUnderstandsFileExCallback* cb, void* user_data)
   { LiNwcLoaderSetUnderstandsFileExCallback(m_handle, cb, user_data); }

   void SetLoadFileCallback(LtNwcLoadFileCallback* cb, void* user_data)
   { LiNwcLoaderSetLoadFileCallback(m_handle, cb, user_data); }

   void SetLoadFileInfoCallback(LtNwcLoadFileInfoCallback* cb, void* user_data)
   { LiNwcLoaderSetLoadFileInfoCallback(m_handle, cb, user_data); }

   void SetLoadFileSheetCallback(LtNwcLoadFileSheetCallback*cb, void *user_data)
   { LiNwcLoaderSetLoadFileSheetCallback(m_handle, cb, user_data); }

   void SetLoadFileExCallback(LtNwcLoadFileExCallback* cb, void* user_data)
   { LiNwcLoaderSetLoadFileExCallback(m_handle, cb, user_data); }

   void SetParameterCallback(LtNwcParameterCallback* cb, void* user_data)
   { LiNwcLoaderSetParameterCallback(m_handle, cb, user_data); }

   void SetDefineOptionsCallback(LtNwcDefineOptionsCallback* cb, void *user_data)
   { LiNwcLoaderSetDefineOptionsCallback(m_handle, cb, user_data); }

   void SetTerminateCallback(LtNwcTerminateCallback* cb, void* user_data)
   { LiNwcLoaderSetTerminateCallback(m_handle, cb, user_data); }

   LtWideString GetString(LtInt32 index)
   { return LiNwcLoaderGetString(m_handle, index); }

   LtNwcNode CreateXRef(LtWideString filename,
                        bool write_cache,
                        LtNwcProgress progress)
   { return LiNwcLoaderCreateXRef(m_handle,
                                  filename,
                                  write_cache,
                                  progress); }

   LtNwcXRefStatus ResolveXRef(LtWideString filename,
      LtWideString xref_name, bool interactive,
      LtWideStringBuffer xref_path)
   {
      return LiNwcLoaderResolveXRef(m_handle, filename, xref_name,
                                   interactive, xref_path);
   }

   LtNwcXRefStatus ResolveXRefNoDownload(LtWideString saved_filename,
                                         LtWideString filename,
                                         LtWideString xref_name,
                                         bool interactive,
                                         LtWideStringBuffer xref_path)
   {
      return LiNwcLoaderResolveXRefNoDownload(m_handle,
                                              saved_filename,
                                              filename,
                                              xref_name,
                                              interactive,
                                              xref_path);
   }

   LtNwcXRefStatus ResolveXRefEx(LtWideString saved_filename,
                                 LtWideString filename,
                                 LtWideString xref_name,
                                 bool interactive,
                                 LtWideStringBuffer xref_path)
   {
      return LiNwcLoaderResolveXRefEx(m_handle,
                                      saved_filename,
                                      filename,
                                      xref_name,
                                      interactive,
                                      xref_path);
   }

   void SetLicenseData(LtNat8* data, LtInt32 num_bytes)
   { LiNwcLoaderSetLicenseData(m_handle, data, num_bytes); }

   bool SetParameter(LtInt32 index, LtNwcData data)
   { return LiNwcLoaderSetParameter(m_handle, index, data); }

   bool GetParameter(LtInt32 index, LtNwcData data)
   { return LiNwcLoaderGetParameter(m_handle, index, data); }

   LtNwcOptionSet GetOptions()
   { return LiNwcLoaderGetOptions(m_handle); }

   void AddLink(LtNwcExternalLink link)
   { LiNwcLoaderAddLink(m_handle, link); }

   static LtNwcLoader GetInstance(LtString name)
   { return LiNwcLoaderGetInstance(name); }

   static void PostMessage(LtWideString internal_id,
                           LtWideString source_filename,
                           LtNwcMessageCategory category,
                           LtWideString message,
                           LtWideString extended_message,
                           int flags)
   { LiNwcLoaderPostMessage(internal_id, source_filename, category, message, extended_message, flags); }

private:
   // Can't copy
   LcNwcLoader(const LcNwcLoader&);
   LcNwcLoader& operator= (const LcNwcLoader&);

   LtNwcLoader m_handle;
};

/**
 * C++ wrapper around LtNwcLoaderSpec API calls
 *
 * \see LiNwcLoader.h
 */
class LcNwcLoaderSpec
{
public:
   LcNwcLoaderSpec(LtNwcLoaderSpec handle) : m_handle(handle) {}

   void SetPathname(LtWideString pathname)
   { LiNwcLoaderSpecSetPathname(m_handle, pathname); }

private:
   // Can't copy
   LcNwcLoaderSpec(const LcNwcLoaderSpec&);
   LcNwcLoaderSpec& operator= (const LcNwcLoaderSpec&);

   LtNwcLoaderSpec m_handle;
};

#endif

#endif /* LINWCLOADER_HDR */
