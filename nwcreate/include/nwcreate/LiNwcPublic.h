/*
 * Copyright Notice:
 *
 * Copyright (C) NavisWorks Ltd. 2001
 * All rights reserved.
 *
 * This software and its associated documentation contains proprietary,
 * confidential and trade secret information of NavisWorks Limited
 * and may not be (a) disclosed to third parties, (b) copied in any form,
 * or (c) used for any purpose except as specifically permitted in
 * writing by NavisWorks Ltd.
 *
 */

#ifndef LINWCPUBLIC_HDR
#define LINWCPUBLIC_HDR

#if defined(_MSC_VER)
#define LI_NWC_DECLSPEC(x) __declspec(x)
#else
#define LI_NWC_DECLSPEC(x)
#endif

/*
 * Define LI_NWC_PUBLIC macro as import or export when using or building
 * DLL. Default with no symbols defined is for DLL import, i.e. what end
 * user would want.
 */
#if (!defined(LI_NWC_NOT_DLL) || defined(LI_IS_DLL)) && defined(_MSC_VER)
#ifdef LI_NWC_BUILD_DLL
#define LI_NWC_PUBLIC LI_NWC_DECLSPEC(dllexport)
#define LI_NWC_PUBLIC_TEMPLATE(a,b) template class LI_NWC_PUBLIC a; typedef a b
#else
#define LI_NWC_PUBLIC LI_NWC_DECLSPEC(dllimport)
#define LI_NWC_PUBLIC_TEMPLATE(a,b) extern template class LI_NWC_PUBLIC a; typedef a b
#endif /* LI_NWC_BUILD_DLL */
#else //* Using DLLs */
#define LI_NWC_PUBLIC
#define LI_NWC_PUBLIC_TEMPLATE(a,b) typedef a b
#endif /* Using DLLs */

/* Define LI_NWC_API to define calling convention used */
#if defined(_MSC_VER)
#define LI_NWC_API __stdcall
#else
#define LI_NWC_API
#endif

#define LI_NWC_INT32 int

#if defined(_MSC_VER)
#define LI_NWC_INT64 __int64
#else
#define LI_NWC_INT64 long long
#endif

#endif /* LINWCPUBLIC_HDR */
