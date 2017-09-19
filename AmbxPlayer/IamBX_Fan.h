/*============================================================================*/
/** \file IamBX_fan.h

\brief
This file contains the definition of IamBX_Fan, the fan device interface.

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

#ifndef _IamBX_FAN_H_
#define _IamBX_FAN_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_FAN_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_FAN_VERSION_B 0 /* Minor Version number of the API */
/*
* DO NOT CHANGE
*/

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**

\brief This structure represents the fan device interface - enabling the 
creation of air flow (wind) experiences. An interface is created by calling 
\ref IamBX::createFan "createFan()" in the IamBX interface.  
See \ref page_devs for more information on devices and their interfaces.

*/

struct IamBX_Fan {

    /** \brief
        Releases this fan interface. This is called automatically when the core 
		IamBX interface is released.

        \param pThis A pointer to this fan interface.
	    \return amBX_RESULT
    */
	amBX_RESULT (*release) (struct IamBX_Fan * pThis);

    /** \brief
        Set the target intensity (i.e. strength of air current) for this fan
		device interface. This is a value between 0 and 1.0f. The actual value 
		will not be sent to the amBX engine unless \ref IamBX::update() "update()"
        is called in the IamBX interface regularly.

        \param pThis A pointer to this fan interface.
        \param fIntensity The target intensity for fan.
               0<= fIntensity <= 1.0f
        \return amBX_RESULT
    */
    amBX_RESULT (*setIntensity) (struct IamBX_Fan * pThis,
                                 amBX_float fIntensity);

    /** \brief
        Get the target fan intensity as set by \ref setIntensity().

        \param pThis A pointer to this fan interface.
        \param pfIntensity where to store the returned target intensity of the 
		fan - (0 <= *pfIntensity <= 1.0f)
        \return amBX_RESULT
    */
	amBX_RESULT (*getIntensity) (struct IamBX_Fan * pThis,
                                 amBX_float* pfIntensity);

    /** \brief
        Get the target location(s) of this fan interface - see 
		\ref sec_devs_creating and \ref page_locs_and_heights.
        \param pThis A pointer to this fan interface.
        \param pLoc Where to store the location(s) of this device interface. 
		The result may be a combination of multiple locations 
		(e.g. ( amBX_N | amBX_S | amBX_SW ) )
        \return amBX_RESULT
    */
	amBX_RESULT (*getLocation) (struct IamBX_Fan * pThis,
                                amBX_loc* pLoc);

    /** \brief
        Returns whether the fan interface is currently enabled - see 
		\ref setEnabled().
        \param pThis A pointer to this fan interface.
        \param pState Where to store the state of the device interface. The 
		       state will be one of:
        \li ENABLED if the fan interface is enabled
        \li ENABLING if the fan interface is currently not enabled, but will be
		    enabled after the next time the \ref IamBX::update() function is called.
        \li DISABLED if the fan interface is disabled
        \li DISABLING if the fan interface is currently enabled, but will 
		    disabled after the next time the \ref IamBX::update() function is called.
        \return amBX_RESULT
    */
	amBX_RESULT (*getEnabled) (struct IamBX_Fan * pThis,
                               amBX_state * pState);

    /** \brief
        Enable or disable this fan interface. Disabling a fan interface will 
		turn it off (i.e. cause it to instantly retract the attributes 
		from the amBX engine). The state will not change until 
		\ref IamBX::update() is called.
        \param pThis A pointer to this fan interface.
        \param bEnabled If set to true (nonzero), this fan interface will be 
  		       enabled by the amBX system after the next time the 
			   \ref IamBX::update() function is called. False (zero) means that
			   this fan will be disabled after the next time the
			   \ref IamBX::update() function is called.
        \return amBX_RESULT
    */
	amBX_RESULT (*setEnabled) (struct IamBX_Fan * pThis,
                               amBX_bool bEnabled);

    /** \brief
        Sets the update properties of this fan device interface - these are the
		minimum time between updates, and the change in intensity required to trigger
        an update. See \ref sec_core_updating for more details.
        The current defaults for these values are:
        - fFanUpdateIntervalMS = 100 ms
        - fFanDelta = 0.04

        \param pThis A pointer to this fan interface.
        \param fanUpdateIntervalMS Updates in this fan interface will not
		       be sent to the amBX engine before a time of 
			   fanUpdateIntervalMS has passed since the previous update of this
			   interface that has been sent to the engine.
        \param fFanDelta the minimum change in fan intensity (0.0f-1.0f) that
               will result in an update being sent to the amBX engine.
        \return amBX_RESULT
    */
	amBX_RESULT (*setUpdateProperties)(struct IamBX_Fan * pThis,
                                       amBX_time fanUpdateIntervalMS,
                                       amBX_float fFanDelta);

	/** \brief
		Gets the update properties for this fan device interface, as set by 
		\ref setUpdateProperties().
		\param pThis A pointer to this fan interface.
		\param pFanUpdateIntervalMS Where to store the minimum time between 
		       updates - updates in this fan interface will not be sent to the 
			   amBX engine before a time of FanUpdateIntervalMS has passed 
			   since the previous update of this interface that has been sent 
			   to the engine.
		\param pfFanDelta Where to store the minimum change in fan intensity 
		(0.0f-1.0f) that will result in an update being sent to the amBX engine.
		\return amBX_RESULT
	*/
	amBX_RESULT (*getUpdateProperties)(struct IamBX_Fan * pThis,
									   amBX_time * pFanUpdateIntervalMS,
									   amBX_float * pfFanDelta);

};

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_FAN_H_*/


