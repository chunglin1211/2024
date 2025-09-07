/**
 * \file
 *
 * Allows NWCreate based file loader to define global options.
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

#ifndef LINWCOPTIONSET_HDR
#define LINWCOPTIONSET_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Profile for option set.
 */
typedef enum LtNwcOptionProfile__tag {
   LI_NWC_OPTION_PROFILE_NORMAL, /** Normal */
   LI_NWC_OPTION_PROFILE_HIDDEN, /** Hidden */
} LtNwcOptionProfile;

/**
 * Flags for options.
 */
typedef enum LtNwcOptionFlags__tag {
   LI_NWC_OPTION_FLAG_CACHE            = 0x01, /** Option affects file conversion. */
   LI_NWC_OPTION_FLAG_COMPOSITE        = 0x02, /** Option is a composite. */
   LI_NWC_OPTION_FLAG_LOCAL_NAME       = 0x04, /** Option has a local name. */
   LI_NWC_OPTION_FLAG_RESTART_NEEDED   = 0x08, /** Application requires a restart on option change. */
   LI_NWC_OPTION_FLAG_COMBINED_LABEL   = 0x10, /** Option has a combined name. */
   LI_NWC_OPTION_FLAG_EQUAL_COLUMNS    = 0x20  /** Option should have equal sized columns. */
} LtNwcOptionFlags;

/**
 * Creates a new option set.
 * \return empty option set.
 * \version 6.0
 */
LI_NWC_PUBLIC LtNwcOptionSet LI_NWC_API
LiNwcOptionSetCreate();

/**
 * Creates a reference to an existing option set.
 * \param option_set option set to reference.
 * \return reference to option set.
 * \version 6.0
 */
LI_NWC_PUBLIC LtNwcOptionSet LI_NWC_API
LiNwcOptionSetCreateRef(LtNwcOptionSet option_set);

/**
 * Destroys an option set.
 * \param option_set option set to destroy.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcOptionSetDestroy(LtNwcOptionSet option_set);

/**
 * Defines an option on a set.
 * \param option_set option set to define option on.
 * \param name option name.
 * \param value default option value.
 * \param profile option profile.
 * \param flags flags for the option set.
 * \param class_name option class name.
 * \version 6.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcOptionSetDefineOption(LtNwcOptionSet option_set,
                           LtString name,
                           LtNwcData value,
                           LtNwcOptionProfile profile,
                           LtInt32 flags,
                           LtString class_name);

/**
 * Gets a value from an option set.
 * \param option_set option set to get value from.
 * \param name option name.
 * \param data option value.
 * \return true if successful, false if option couldn't be found.
 * \version 6.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcOptionSetGetOption(LtNwcOptionSet option_set,
                        LtString name,
                        LtNwcData data);

/**
 * Sets a value on an option set.
 * \param option_set option set to set value on.
 * \param name option name.
 * \param data option value.
 * \return true if successful, false if option couldn't be found.
 * \version 6.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcOptionSetSetOption(LtNwcOptionSet option_set,
                        LtString name,
                        LtNwcData data);
#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcOptionSet API calls
 *
 * \see LiNwcOptionSet.h
 */
class LcNwcOptionSet
{
public:
   LcNwcOptionSet() : m_handle(LiNwcOptionSetCreate()) {}
   LcNwcOptionSet(LtNwcOptionSet handle) : m_handle(LiNwcOptionSetCreateRef(handle)) {}
   ~LcNwcOptionSet() { LiNwcOptionSetDestroy(m_handle); }

   LcNwcOptionSet(const LcNwcOptionSet &other) : m_handle(LiNwcOptionSetCreateRef(other)) {}

   LcNwcOptionSet& operator = (const LcNwcOptionSet &other)
   { LiNwcOptionSetDestroy(m_handle); m_handle = LiNwcOptionSetCreateRef(other); return *this; }

   operator LtNwcOptionSet () const { return m_handle; }
   LtNwcOptionSet GetHandle() const { return m_handle; }

   void DefineOption(const char* name,
                     LtNwcData value,
                     LtNwcOptionProfile profile = LI_NWC_OPTION_PROFILE_NORMAL,
                     LtInt32 flags = 0,
                     LtString class_name = NULL)
   { LiNwcOptionSetDefineOption(m_handle, const_cast<LtString>(name), value, profile, flags, class_name); }

   bool GetOption(const char* name,
                       LtNwcData value) const
   { return LiNwcOptionSetGetOption(m_handle, const_cast<LtString>(name), value); }

   bool SetOption(const char* name,
                       LtNwcData value)
   { return LiNwcOptionSetSetOption(m_handle, const_cast<LtString>(name), value); }

private:

   LtNwcOptionSet m_handle;
};

#endif

#endif // LINWCOPTIONSET_HDR
