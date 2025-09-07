/**
 * \file
 *
 * A means to define nonvisible 2D plot geometry streams that can be inserted
 * into visible streams using the visible streams' style.
 */

/*
 * Copyright Notice:
 *
 * Copyright 2009 Autodesk, Inc. All rights reserved.
 *
 * This computer source code and related instructions and
 * comments are the unpublished confidential and proprietary
 * information of Autodesk, Inc. and are protected under
 * United States and foreign intellectual property laws.
 * They may not be disclosed to, copied or used by any third
 * party without the prior written consent of Autodesk, Inc.
 *
 */

#ifndef LINWCPLOTRESOURCE_HDR
#define LINWCPLOTRESOURCE_HDR
#pragma once

#include <nwcreate/LiNwcTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  Create a NavisWorks resource
 *
 *  \return Newly created Resource or NULL on error
 */
LI_NWC_PUBLIC LtNwcPlotResource LI_NWC_API
LiNwcPlotResourceCreate();

/**
 *  Destroy a NavisWorks resource
 *
 *  \param resource Resource to destroy
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotResourceDestroy( LtNwcPlotResource resource );

/**
 *  Open a NavisWorks 2D stream to define the geometric data that will
 *  be stored in a resource. Only one 2D stream can be open for
 *  a resource at any time.
 *
 *  \param resource Resource node in which to store geometric data
 *  \return Newly opened 2D stream or NULL on error
 */
LI_NWC_PUBLIC LtNwcPlotStream LI_NWC_API
LiNwcPlotResourceOpenPlotStream( LtNwcPlotResource resource );

/**
 *  Close an open geometry stream. Completes the definition of data to be stored
 *  in the resource. Once closed, the stream handle is no longer valid.
 *
 *  \param resource Resource for which to close stream
 *  \param stream Stream to close. Must have been opened on given resource.
 */
LI_NWC_PUBLIC void LI_NWC_API
LiNwcPlotResourceClosePlotStream(LtNwcPlotResource resource, LtNwcPlotStream stream);

#ifdef __cplusplus
}

#include <nwcreate/LiNwcNode.h>

/**
 * C++ wrapper around LtNwcPlotResource API calls
 *
 * \see LiNwcPlotResource.h
 */
class LcNwcPlotResource
{
public:
    LcNwcPlotResource() : m_handle( LiNwcPlotResourceCreate() ) {}
    ~LcNwcPlotResource() { LiNwcPlotResourceDestroy( m_handle ); };

    operator LtNwcPlotResource () const
    { return static_cast<LtNwcPlotResource>( GetHandle()); }

    LtNwcPlotResource GetHandle() const
    { return static_cast<LtNwcPlotResource>( m_handle ); }

    LtNwcPlotStream OpenPlotStream()
    { return LiNwcPlotResourceOpenPlotStream( GetHandle() ); }

    void ClosePlotStream(LtNwcPlotStream stream)
    { LiNwcPlotResourceClosePlotStream( GetHandle(), stream ); }

private:
    LtNwcPlotResource m_handle;

};

#endif /* __cplusplus */

#endif /* LINWCPLOTRESOURCE_HDR */
