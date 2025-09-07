/**
 * \file
 *
 * Allows NWCreate based file loader to report progress.
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

#ifndef LINWCPROGRESS_HDR
#define LINWCPROGRESS_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Updates the current progress to a fraction between 0 and 1.
 * \param progress handle to progress object
 * \param fraction fraction of work completed, in the range 0 to 1
 * \return false if conversion was cancelled
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcProgressUpdate(LtNwcProgress progress, LtFloat fraction);

/**
 * Begins a new sub-operation.
 * \param progress handle to progress object
 * \param fraction fraction of current operation this sub-operation will use
 * \param message message to display to user
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcProgressBeginSubOp(LtNwcProgress progress, LtFloat fraction, const LtWideString message);

/**
 * Ends the current sub-operation.
 * \param progress handle to progress object
 * \param completed did this sub-operation complete successfully?
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcProgressEndSubOp(LtNwcProgress progress, bool completed);

/**
 * Reports an error during a process that is being reported using a progress object.
 * \param progress handle to progress object
 * \param error_code an error code.
 * \param message the message to display.
 * \param display_filename should the error message append the file being loaded to the dialog box.
 * \return false should cancel the operation, true to continue.
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcProgressError(LtNwcProgress progress, LtInt32 error_code, const LtWideString message, bool display_filename);

/**
 * Sets the error code on the progress object. Note that the error is not displayed
 * to the user. This information is for the use of the callee to provide more
 * informative error messages if the file loading fails.
 * \param progress handle to progress object
 * \param error_code an error code
 * \param message user-friendly description of error.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcProgressSetError(LtNwcProgress progress,
                      LtInt32 error_code,
                      const LtWideString message);

/**
 * Requests the user input a password.
 * The function will first return any cached passwords. Once all
 * cached passwords have been returned, it will then prompt the user
 * for a password. Any password is returned in the "password" buffer,
 * up to a maximum length of "len".
 *
 * If the user clicks "Cancel", the function returns false.
 *
 * \param progress handle to progress object
 * \param password buffer to store inputted password. Must be at least len characters long.
 * \param len length of password buffer
 * \return true if user clicked OK, false if they clicked Cancel.
 * \version 9.0
 */
LI_NWC_PUBLIC bool LI_NWC_API
LiNwcProgressInputPassword(LtNwcProgress progress,
                           LtWideStringBuffer password,
                           LtInt32 len);

/**
 * Notify NWcreate that a valid password has been entered.
 * This function will cache the password, and next time will try to use
 * it with the LiNwcProgressInputPassword() function.
 *
 * \param progress handle to progress object
 * \param password valid password that was entered by user
 * \version 9.0
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcProgressValidPasswordEntered(LtNwcProgress progress,
                                  LtWideString password);

#ifdef __cplusplus
}

/**
 * C++ wrapper around LtNwcProgress API calls
 *
 * \see LiNwcProgress.h
 */
class LcNwcProgress
{
public:
   LcNwcProgress(LtNwcProgress handle) : m_handle(handle) {}

   operator LtNwcProgress () const { return m_handle; }
   LtNwcProgress GetHandle() const { return m_handle; }

   bool Update(LtFloat fraction)
   { return LiNwcProgressUpdate(m_handle, fraction); }

   void BeginSubOp(LtFloat fraction, const LtWideString message=NULL)
   { LiNwcProgressBeginSubOp(m_handle, fraction, message); }

   void EndSubOp(bool completed=true)
   { LiNwcProgressEndSubOp(m_handle, completed); }

   bool Error(LtInt32 error_code, const LtWideString message, bool display_filename)
   { return LiNwcProgressError(m_handle, error_code, message, display_filename); }

   void SetError(LtInt32 error_code, const LtWideString message)
   { LiNwcProgressSetError(m_handle, error_code, message); }

   bool InputPassword(LtWideStringBuffer password, LtInt32 len)
   { return LiNwcProgressInputPassword(m_handle, password, len); }

   void ValidPasswordEntered(LtWideString password)
   { LiNwcProgressValidPasswordEntered(m_handle, password); }

private:
   // Can't copy
   LcNwcProgress(const LcNwcProgress&);
   LcNwcProgress& operator= (const LcNwcProgress&);

   LtNwcProgress m_handle;
};

#endif

#endif /* LINWCPROGRESS_HDR */
