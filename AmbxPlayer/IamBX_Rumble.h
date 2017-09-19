/*============================================================================*/
/** \file IamBX_Rumble.h

\brief
This file contains the definition of IamBX_Rumble, the rumble device interface.

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

#ifndef _IamBX_RUMBLE_H_
#define _IamBX_RUMBLE_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_RUMBLE_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_RUMBLE_VERSION_B 0 /* Minor Version number of the SDK */
/*
* DO NOT CHANGE
*/

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**

\brief This structure represents the rumble device interface, enabling the 
creation of rumble experiences. A rumble device interface is created by calling 
\ref IamBX::createRumble "createRumble()" in the IamBX interface. See 
\ref page_devs for more information on devices and their interfaces.
<br><br>
The properties for the rumble device interface are slightly more complex than 
those for the other devices. They are all set in a single call by setRumble():
- a '''rumble name''', which is the name of the rumble waveform.
- a '''speed''', which is the rate at which the rumble waveform is to be 
  played.
- an '''intensity''', which is the amplitude at which the waveform is to be 
  played.

*/

struct IamBX_Rumble {

    /** \brief
        Releases this rumble interface. This is called automatically when the 
		core IamBX interface is released.

        \param pThis A pointer to this rumble interface.
        \return amBX_RESULT
    */
	amBX_RESULT (*release) (struct IamBX_Rumble * pThis);

    /** \brief
        Sets the target properties of the rumble device interface - the 
		waveform, speed and intensity.
        \param pThis A pointer to this rumble interface.
        \param pszRumbleName A null terminated string giving the name of the 
		rumble waveform to be used. Allowed values
               are:
        \li amBX_boing
        \li amBX_crash
        \li amBX_engine
        \li amBX_explosion
        \li amBX_hit
        \li amBX_quake
        \li amBX_rattle
        \li amBX_road
        \li amBX_shot
        \li amBX_thud
        \li amBX_thunder
        \param fSpeed the speed to be used for this rumble (range: 0.1f -10.0f)
        \param fIntensity The intensity to be used for this rumble
               (range: 0.0f - 1.0f)
        \return amBX_RESULT
    */
	amBX_RESULT (*setRumble) (struct IamBX_Rumble * pThis,
                              amBX_char* pszRumbleName,
                              amBX_float fSpeed,
                              amBX_float fIntensity);

    /** \brief
        Gets the current rumble properties.
        \param pThis A pointer to this rumble interface.
        \param uMaxLen The maximum length of the string buffer, pszRumbleString.
        \param pszRumbleString Where to store the name of the current rumble 
		waveform.
        \param puLen Where to store the actual length of the name of the current 
		rumble waveform.
        \param pfSpeed Where to store the speed of the current rumble.
        \param pfIntensity Where to store the intensity of the current rumble
        \return amBX_RESULT
    */
    amBX_RESULT (*getRumble) (struct IamBX_Rumble * pThis,
                              amBX_u32 uMaxLen,
                              amBX_char* pszRumbleName,
                              amBX_u32* puLen,
                              amBX_float * pfSpeed,
                              amBX_float * pfIntensity);

    /** \brief
        Get the target location of this rumble device interface
        \param pThis A pointer to this rumble interface.
        \param pLoc Where to store the location(s) of this rumble device 
		       interface. pLoc can be a combination of multiple locations 
			   (e.g. ( amBX_N | amBX_S | amBX_SW) )
        \return amBX_RESULT
    */
	amBX_RESULT (*getLocation) (struct IamBX_Rumble * pThis,
                                amBX_loc* pLoc);

    /** \brief
        Returns whether the rumble interface is currently enabled - see 
		\ref getEnabled().
        \param pThis A pointer to this rumble interface.
        \param pState Where to store the state of the rumble device interface. 
		     pState can be:
        \li ENABLED if the rumble interface is enabled
		\li ENABLING if the rumble interface is currently not enabled, but will 
		    be enabled after the next time the \ref IamBX::update() is called.
		\li DISABLED if the rumble interface is not disabled
		\li DISABLING if the rumble interface is currently enabled, but will
			be disabled after the next time the \ref IamBX::update() is called.
        \return amBX_RESULT
    */
	amBX_RESULT (*getEnabled) (struct IamBX_Rumble * pThis,
                               amBX_state* pState);

    /** \brief
        Enable or disable this rumble device interface. Disabling a rumble 
		interface will turn it off - i.e. cause it to instantly retract its 
		experience from the amBX engine). The state will not change until 
		\ref IamBX::update() is called..
        \param pThis A pointer to this rumble interface.
        \param bEnabled if set to true (nonzero), this rumble device interface 
		        will be enabled by the amBX system after the next time the 
				\ref IamBX::update() function is called.
               False (zero) means that this rumble device will be disabled after 
			   the next time the \ref IamBX::update() function is called.
        \return amBX_RESULT
    */
	amBX_RESULT (*setEnabled) (struct IamBX_Rumble * pThis,
                               amBX_bool bEnabled);

    /** \brief
        Sets the update properties of this rumble device interface - these are 
		the minimum time between updates, and the changes in speed and intensity
		required to trigger an update. Changing the rumble waveform name will
		always trigger an update. See \ref sec_core_updating for more details.
        The current defaults for these values are:
        - rumbleUpdateIntervalMS = 250ms
        - fSpeedDelta = 0.3
        - fIntensityDelta = 0.05

        \param pThis A pointer to this rumble interface.
        \param rumbleUpdateIntervalMS Uupdates in this rumble interface will 
		       not be sent to the amBX engine before a time of 
			   rumbleUpdateIntervalMS has passed since the previous update of this 
			   interface that has been sent to the engine.
        \param fSpeedDelta Minimum required change in speed that triggers
               sending an update. 0.0f <= fSpeedDelta <= 10.0f
        \param fIntensityDelta Minimum required change in intensity that
               triggers sending an update. 0.0f <= fIntensityDelta <= 1.0f
        \return amBX_RESULT
    */
	amBX_RESULT (*setUpdateProperties) (struct IamBX_Rumble * pThis,
									    amBX_time rumbleUpdateIntervalMS,
                                        amBX_float fSpeedDelta,
                                        amBX_float fIntensityDelta);

	/** \brief
		Gets the update properties of this rumble device interface, as set by 
		\ref setUpdateProperties().
		\param pThis A pointer to this rumble interface.
		\param pRumbleUpdateIntervalMS Where to store the minimum time between 
		       updates - updates in this rumble interface will not be sent to the 
			   amBX engine before a time of rumbleUpdateIntervalMS has passed
			   since the previous update of this interface that has been sent to
			   the engine.
		\param pfSpeedDelta Where to store the minimum required change in speed 
			   that triggers sending an update. 0.0f <= fSpeedDelta <= 10.0f
		\param pfIntensityDelta Where to store the minimum required change in 
		       intensity that triggers sending an update. 0.0f <= 
			   fIntensityDelta <= 1.0f
			   
		\return amBX_RESULT
	*/
	amBX_RESULT (*getUpdateProperties) (struct IamBX_Rumble * pThis,
									    amBX_time * pRumbleUpdateIntervalMS,
										amBX_float * pfSpeedDelta,
										amBX_float * pfIntensityDelta);

};

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_RUMBLE_H_*/


