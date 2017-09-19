/*============================================================================*/
/** \file IamBX_Light.h

\brief
This file contains the definition of IamBX_Light, the light device interface.

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

#ifndef _IamBX_LIGHT_H_
#define _IamBX_LIGHT_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_LIGHT_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_LIGHT_VERSION_B 0 /* Minor Version number of the API */
/*
* DO NOT CHANGE
*/

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**

\brief This structure represents the light device interface, enabling the 
creation of coloured light experiences. A light device interface is created by
calling 
\ref IamBX::createLight() "createLight()" in the IamBX interface. See 
\ref page_devs for more information on devices and their interfaces.

*/

struct IamBX_Light {

    /** \brief
        Releases this light interface. This is called automatically when the 
		core IamBX interface is released.

        \param pThis A pointer to this light interface.
        \return amBX_RESULT
    */
	amBX_RESULT (*release) (struct IamBX_Light * pThis);

	/** \brief
        Set the target colour of the light device interface, towards which the
        actual colour of the light should change at the fade rate set by 
		\ref IamBX_Light::setFadeTime() "setFadeTime()".
        The actual colour of the light interface will not be sent to the amBX 
		engine unless \ref IamBX::update() "update()" is called in the IamBX 
		interface regularly.

        \param pThis A pointer to this light interface.
        \param fRed  The target colour's red component (0.0f<=uRed<=1.0f)
        \param fGreen The target colour's green component (0.0f<=uGreen<=1./0f)
        \param fBlue The target colour's blue component (0.0f<=uBlue<=1.0f)
        \return amBX_RESULT
    */
	amBX_RESULT (*setCol)(struct IamBX_Light * pThis,
                          amBX_float fRed,
                          amBX_float fGreen,
                          amBX_float fBlue);

    /** \brief
        Get the target colour of the light device interface, as last set by 
		setCol().
        \param pThis A pointer to this light interface.
        \param pfRed  Where to store the target colour's red component 
		(0.0f<= * pfRed<=1.0f)
        \param pfGreen Where to store the target colour's green component
               (0.0f<= * pfGreen <=1.0f)
        \param pfBlue Where to store the target colour's blue component 
		(0.0f<= * pfBlue <=1.0f)
        \return amBX_RESULT
    */
	amBX_RESULT (*getCol) (struct IamBX_Light * pThis,
                           amBX_float* pfRed,
                           amBX_float* pfGreen,
                           amBX_float* pfBlue);

    /** \brief 
        Sets the time taken to transition to the target colour when the colour 
		is changed with \ref setCol().
        \param pThis A pointer to this light interface.
        \param FadeTime the fade time in milliseconds
        \return amBX_RESULT
    */
	amBX_RESULT (*setFadeTime) (struct IamBX_Light * pThis,
                                amBX_time FadeTime);

    /** \brief
        Gets the colour transition time as set by \ref setFadeTime().
        \param pThis A pointer to this light interface.
        \param pFadeTime the fade time in milliseconds
        \return amBX_RESULT
    */
	amBX_RESULT (*getFadeTime) (struct IamBX_Light * pThis,
                                amBX_time* FadeTime);

    /** \brief
        Get the target location(s) of this light interface - see 
		\ref sec_devs_creating and \ref page_locs_and_heights.
        \param pThis A pointer to this light interface.
        \param pLoc Where to store the location(s) of this device interface.
        	The result, *pLoc, can be a combination of multiple locations
        	(e.g. ( amBX_N | amBX_S | amBX_SW ) )
        \return amBX_RESULT
    */
	amBX_RESULT (*getLocation) (struct IamBX_Light * pThis,
                                amBX_loc* pLoc);

    /** \brief 
        Enable or disable this light interface. Disabling a light interface 
		will turn it off (i.e. cause it to instantly retract its experience 
		from the amBX engine). The state will not change until 
		\ref IamBX::update() is called.
		\param pThis A pointer to this light interface.
		\param bEnabled if set to true (nonzero), this light interface will be enabled by 
			   the amBX system after the next time the \ref IamBX::update() function is 
			   called.
			   False (zero) means that this light interface will be disabled after the next
			   time the \ref IamBX::update() function is called.
		\return amBX_RESULT
	*/
	amBX_RESULT (*setEnabled) (struct IamBX_Light * pThis,
							   amBX_bool bEnabled);

    /** \brief
        Returns whether the light interface is currently enabled - see 
		\ref setEnabled().
        \param pThis A pointer to this light interface.
        \param Pivate Where to store the state of the light. Pivate will be one 
		of:
	    \li ENABLED if the light interface is enabled
	 	\li ENABLING if the light interface is currently not enabled, but will 
		       be enabled after the next time the \ref IamBX::update() function is 
			   called.
		\li DISABLED if the light interface is disabled
	 	\li DISABLING if the light interface is currently enabled, but will disabled
		       after the next time the \ref IamBX::update() function is called.
        \return amBX_RESULT
    */
	amBX_RESULT (*getEnabled) (struct IamBX_Light * pThis,
                               amBX_state* Pivate);

    /** \brief
        Sets the update properties of this light device interface - these are 
		the minimum time between updates, and the change in a colour component 
		required for an update to be sent to the amBX engine.
        See \ref sec_core_updating for more details.

        The current defaults for these values are:
        - flightUpdateIntervalMS = 100 ms
        - fLightDelta = 0.02f.
        \param pThis A pointer to this light interface.
        \param lightUpdateIntervalMS updates in this light interface will not
		       be sent to the amBX engine before a time of 
			   LightUpdateIntervalMS has passed since the previous update of this 
			   interface that has been sent to the engine.
        \param fLightDelta Minimum required change per colour component that
               triggers sending an update. 0.0f <= fLightDelta <= 1.0f
        \return amBX_RESULT
    */
	amBX_RESULT (*setUpdateProperties)(struct IamBX_Light * pThis,
                                       amBX_time lightUpdateIntervalMS,
                                       amBX_float fLightDelta);

	/** \brief
		Gets the update properties of this light device interface, as set by 
		\ref setUpdateProperties().
		\param pThis A pointer to this light interface.
		\param pLightUpdateIntervalMS Where to store the minimum time between 
		       updates - updates in this light interface will not be sent to the amBX
			   engine before a time of LightUpdateIntervalMS has passed since the 
			   previous update of this interface that has been sent to the engine.
		\param pfLightDelta Where to store the minimum required change per 
		colour component that triggers sending an update. 0.0f <= fLightDelta 
		<= 1.0f
		\return amBX_RESULT
	*/
	amBX_RESULT (*getUpdateProperties)(struct IamBX_Light * pThis,
									   amBX_time * pLightUpdateIntervalMS,
									   amBX_float * pfLightDelta);

};

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_LIGHT_H_*/

