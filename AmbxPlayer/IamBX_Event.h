/*============================================================================*/
/** \file IamBX_Event.h

\brief This file contains the definition of the IamBX_Event interface.

*/
/*

	$Date: 19/01/09$
	$Revision: 1.0.1$

--------------------------------------------------------------------------------

    Copyright (c) 2008 amBX UK Ltd.

    All rights reserved. This source code is part of the amBX Software 
	Development Kit. Reproduction in whole or in part is prohibited without 
	the written consent of the copyright owner. Any usage is restricted by 
	the terms of the amBX SDK License Agreement for Non-Commercial Use 
	which is available on http://developer.ambx.com.
	
	Under no circumstances is this software to be used for commercial use 
	without the written consent of the copyright owner. Please contact 
	amBX UK ltd. if you require a license for commercial use.
	
    This source code and any compilation or derivative thereof is the
    proprietary information of amBX UK Ltd. and is confidential in nature.

    Under no circumstances is this software to be combined with any Open
    Source Software in any way or licensed under any Open License Terms
    without the express written permission of amBX UK Ltd.

    For the purpose of this clause, the term Open Source Software means any
    software that is licensed under Open License Terms. Open License Terms
    means terms in any license that require as a condition of use,
    modification and/or distribution of a work

        1.    the making available of source code or other materials
              preferred for modification, or

        2.    the granting of permission for creating derivative works, or

        3.    the reproduction of certain notices or license terms in
              derivative works or accompanying documentation, or

        4.    the granting of a royalty-free license to any party under
              Intellectual Property Rights

    regarding the work and/or any work that contains, is combined with,
    requires or otherwise is based on the work.
*//*--------------------------------------------------------------------------*/

/*  Header for abstract interface of amBX_Event, which represents a pre-compiled
    amBX file that can be sent to the amBX system that triggers an amBX effect.
    amBX_Event interfaces use a connection to amBX system provided by the IamBX
    interface. After an amBX_Event has been played using the
    \ref IamBX_Event::Play() "Play()" function, the associated
    \ref IamBX_Event::Stop() "Stop()" function must be called regardless of
    whether the effect has stopped playing.
*/

#ifndef _IamBX_EVENT_H_
#define _IamBX_EVENT_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_EVENT_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_EVENT_VERSION_B 0 /* Minor Version number of the API */
/*
* DO NOT CHANGE
*/

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
\brief The IamBX_Event interface encapsulates an 'event' - a short sequence of 
ambience which does not need to be paused or seeked into, or ambience
that only requires turning on or off, but no other kind of control.

See \ref sec_script_events for more details, and contrast with 
\ref sec_script_movies,
which are used for cutscenes and movies and can be seeked and paused, but have 
different constraints.

*/
struct IamBX_Event {

    /** \brief
        Plays the amBX file loaded when the interface was created.
        \param pThis A pointer to this Event interface
        \return amBX_RESULT
	*/
    amBX_RESULT (*play) (struct IamBX_Event * pThis);

    /** \brief
        Stops the play back of the event (i.e. sends a request to the engine to
        stop the event).
        \param pThis A pointer to this Event interface
        \return amBX_RESULT
	*/
	amBX_RESULT (*stop) (struct IamBX_Event * pThis);

	/** \brief
        Releases the event. Note that all events must be released once they are 
		no longer needed. Releasing the event frees up internal resources and 
		sends the retract segment of the amBX file to the amBX Engine. Once 
		released, the interface should not be used
		\param pThis A pointer to this Event interface
		\return amBX_RESULT
	*/
	amBX_RESULT (*release) (struct IamBX_Event * pThis);
};

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_EVENT_H_*/
