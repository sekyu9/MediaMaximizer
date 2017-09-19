/*============================================================================*/
/** \file IamBX.h

\brief This file defines the main amBX interface, IamBX.

*/
/*

It also contains the single function amBXCreateInterface()
which is used for obtaining the interface.

	$Date: 05/10/09$
	$Revision: 1.0.2$

--------------------------------------------------------------------------------

    Copyright (c) 2009 amBX UK Ltd.

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

#ifndef _IamBX_H_
#define _IamBX_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_VERSION_B 0 /* Minor Version number of the API */
/*
* DO NOT CHANGE
*/

#define DECLFUNC __declspec(dllexport)

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* forward-declarations
*/
struct IamBX_Light;
struct IamBX_Fan;
struct IamBX_Rumble;
struct IamBX_Movie;
struct IamBX_Event;

/**

    \brief Structure holding memory allocator functions, passed into 
	amBXCreateInterface().

    This structure can be passed into amBXCreateInterface() to allow game 
	creators to override amBX's default memory allocation and deallocation with 
	their own malloc and free functions. To do this, functions should be 
	declared of the appropriate type (with the same semantics as malloc() and 
	free())and an amBX_MemHandler object set up with pointers to these 
	functions. This object should then be passed into amBXCreateInterface() at 
	the start of the application when amBX is set up.
*/
struct amBX_MemHandler { 
	/*< pointer to an allocation function with the same semantics as malloc()*/
	void* (*malloc)(size_t);
	/*< pointer to a deallocation function with the same semantics as free()*/
	void (*free)(void *);	
};

/**
    \brief This is the main interface to amBX - all access to amBX is via this 
	structure, and all other interfaces are obtained through it. Your 
	application should create a single instance of this interface and keep it 
	open throughout its run, finally releasing the interface when it shuts down. 
	See \ref page_core for more details.

    The interface should be created by calling amBXCreateInterface() and 
	released using release():

    \code
IamBX* pIamBX;
amBXCreateInterface(&pIamBX,1,0,"test","test",NULL,0);

...

pIamBX->release();
    \endcode
*/   

struct IamBX {
	/** \brief Releases all interfaces created using this IamBX (with the 
		exception of IamBX_Event and IamBX_Movie events), and finally releases 
		the interface itself. This closes down the application's association 
		with amBX.

        \param pThis a pointer to this IamBX interface.
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
        IamBX* pIamBX;
        amBXCreateInterface(&pIamBX,1,0,"test","test",NULL,false);

        ...

        pIamBX->release();
        \endcode
    */
	amBX_RESULT (*release) (struct IamBX * pThis);

	/** \brief Creates a light device interface for the specified location(s)
	     and height(s) (see \ref page_devs).
        \param pThis A pointer to this IamBX interface.
        \param loc The location(s) this light interface targets. Multiple locations can be
               combined (e.g. amBX_N|amBX_S|amBX_SW )
        \param height The height this light interface targets. Multiple heights can be
               combined. Recommend using amBX_EVERYHEIGHT.
        \param ppLight A pointer to the created light interface.
        \see IamBX_Light, \ref page_locs_and_heights
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
        IamBX_Light *pIamBXLightFront;

        if(amBX_OK == pIamBX->createLight(pIamBX, 
            (amBX_loc)(amBX_N|amBX_C), 
            (amBX_height)amBX_EVERYHEIGHT, 
            &pIamBXLightFront))
        {
            printf("light interface created ok\n");
        }
        \endcode
	*/
	amBX_RESULT (*createLight) (struct IamBX * pThis,
                                amBX_u32 loc,
                                amBX_u32 height,
                                struct IamBX_Light** ppLight);

	/** \brief Creates a fan device interface for the specified location(s) and
	    height(s) (see \ref page_devs).
        \param pThis A pointer to this IamBX interface.
        \param loc The location(s) this fan device interface targets. Multiple 
		       locations can be combined (e.g. amBX_N|amBX_S|amBX_SW )
        \param height The height this fan device interface targets. Multiple 
		       heights can be combined. Recommend using amBX_EVERYHEIGHT.
	    \param ppFan A pointer to the created fan interface.
        \see IamBX_Fan, \ref page_locs_and_heights
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
        IamBX_Fan *pIamBXFan;

        if(amBX_OK == pIamBX->createFan(pIamBX, 
            (amBX_loc)amBX_S,
            (amBX_height)amBX_EVERYHEIGHT,
            &pIamBXFan))
        {
            printf("fan interface created ok\n");
        }
        \endcode
	*/
	amBX_RESULT (*createFan) (struct IamBX * pThis,
                              amBX_u32 loc,
                              amBX_u32 height,
                              struct IamBX_Fan** ppFan);

    /** \brief Creates a rumble device interface for the specified location(s) and 
	height(s) (see \ref page_devs)
        \param pThis A pointer to this IamBX interface.
        \param loc The location(s) this rumble device interface targets. 
		       Multiple locations can be combined (e.g. amBX_N|amBX_S|amBX_SW )
        \param height The height this rumble device interface targets. Multiple
		       heights can be combined. Recommend using amBX_EVERYHEIGHT.
        \param ppRumble A pointer to the created rumble interface.
        \see IamBX_Rumble, \ref page_locs_and_heights
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
        IamBX_Rumble *pIamBXRumble;

        if(amBX_OK == pIamBX->createRumble(pIamBX, 
            (amBX_loc)amBX_S,
            (amBX_height)amBX_EVERYHEIGHT,
            &pIamBXRumble))
        {
            printf("rumble interface created ok\n");
        }
        \endcode
	*/
	amBX_RESULT (*createRumble) (struct IamBX * pThis,
                                 amBX_u32 loc,
                                 amBX_u32 height,
                                 struct IamBX_Rumble** ppRumble);

	/** \brief Creates a Movie interface given an amBX file to play. 
	(See \ref page_script).

        Movies, unlike Events, are intended for extended movies and cutscenes - 
		any ambience where the user should be able to pause, skip, minimise the 
		application, rewind, fast forward or otherwise interrupt or manipulate 
		the flow of time through the ambience.

        Note that a movie uses a separate connection to the amBX system. You 
		should, therefore, not create too many movie interfaces at the same time. 
		Just create them as you need them, rather than creating an interface for 
		each movie at startup.

        \param pThis A pointer to this IamBX interface.
        \param pFile A pointer to an amBX_file. This should point to the start
			   a piece of memory containing a complete amBX file contents
        \param uSize length of the file in bytes.
        \param ppMovie A pointer to the movie interface. Note, the movie will
               be in suspended state after creation.
        \see IamBX_Movie, \ref page_script
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
    	// Create an amBX Movie Interface

        IamBX_Movie *pIamBXMovie;

    	if(amBX_OK == pIamBX->createMovie(
            pIamBX,
            pMovie, // pointer to data in movie file
            uMovieSize, // size of movie file data
            &pIamBXMovie))
        {
            printf("movie created OK\n");
       }
       \endcode

	*/
	amBX_RESULT (*createMovie) (struct IamBX * pThis,
                                amBX_file* pFile,
                                amBX_u32 uSize,
                                struct IamBX_Movie** ppMovie);

	/** \brief Creates an IamBX_Event interface  (see \ref page_script).
        IamBX_Event is most applicable for short ambience "events", e.g. weapons
        fire, pickups; or for ambience that you want to toggle on and off, e.g.
        "player has quad damage so turn everything green".

        \param pThis A pointer to this IamBX interface.
        \param pFile A pointer to an amBX_file. This should point to the start
			   a piece of memory containing a complete amBX_bn/ck file contents.
        \param uSize length of the file data in bytes.
        \param ppEvent A pointer to the event interface.
        \see IamBX_Event, \ref page_script
        \return \ref amBX_RESULT

        <b>Usage example:</b>
        \code
    	// Create an amBX Event Interface

        IamBX_Event *pIamBXEvent;
    	if(amBX_OK == pIamBX->createEvent(pIamBX,
                    pEvent, // pointer to amBX file
                    uEventSize, // size of data in file
                    &pIamBXEvent))
        {
            printf("event created OK\n");
        }
        \endcode
    */
    amBX_RESULT (*createEvent) (struct IamBX * pThis,
                                amBX_file* pFile,
                                amBX_u32 uSize,
                                struct IamBX_Event** ppEvent);

	/** \brief Enables/disables all device interfaces. When disabled, attributes for all
		device interfaces are retracted and no new attributes are sent to the engine.
        \param pThis A pointer to this IamBX interface.
        \param bEnabled boolean indicating whether all devices should be
               enabled (true/nonzero) or disabled (false/zero). If set to false, 
			   attributes for all devices are retracted from the
        	   engine and no new attributes for devices are sent.
        \return \ref amBX_RESULT
	*/
	amBX_RESULT (*setAllEnabled) (struct IamBX * pThis,
                                  amBX_bool bEnabled);

	/** \brief Checks all device interfaces for updates and sends
	updated attributes to the amBX engine, if required.  
	If the interface has been created as unthreaded in amBXCreateInterface(), 
	this function call will actually do the update itself, which may take some 
	time. If the interface is threaded, it will send a message to the thread, 
	which should be running runThread(). This will cause the thread to perform 
	the update, while the update() call should return immediately. However, the 
	thread may be busy running the previous update, so this call may still block. 
	The uMaxWaitInMilliseconds parameter specifies how long the thread should 
	wait before abandoning the attempt to send the message. See \ref page_threading 
	more details.

        This should be called every time you would like to update physical devices
        with new attributes. See \ref sec_core_updatefreq for more details.

        \param pThis A pointer to this IamBX interface.
        \param uMaxWaitInMilliseconds If the interface is threaded, the amount of time 
		to wait before abandoning an attempt to send an update to the engine. 
		(see \ref page_threading and the description above). In a non-threaded 
		interface, this argument is ignored.
        \return \ref amBX_RESULT
	*/
	amBX_RESULT (*update) (struct IamBX * pThis, 
						   amBX_u32 uMaxWaitInMilliseconds);


	/** \brief Returns the version of amBX system
        \param pThis A pointer to this IamBX interface.
        \param pu32Major is the major version number of the amBX system
        \param pu32Minor is the minor version number of the amBX system
        \param pu32Revision is the revision number of the amBX system
        \param pu32Build is the build number of the amBX system
        \return \ref amBX_RESULT
	*/
    amBX_RESULT (*getVersionInfo) (struct IamBX * pThis,
                                   amBX_u32* pu32Major,
                                   amBX_u32* pu32Minor,
                                   amBX_u32* pu32Revision,
                                   amBX_u32* pu32Build);

	/** \brief The entry point for a thread used by amBX to send updates from 
	the device interfaces to the amBX engine. 
	This should be called inside your thread, and it will not exit until you 
	call stopThread() with the thread ID from outside the thread. 

        See \ref page_threading for more details.

		\param pThis A pointer to this IamBX interface.
		\param eThreadType An indicator of how the thread being run should
		       be used. Currently the only valid value is \b amBX_Ambient_Update.
	    \param uThreadID An identifier for the thread being run. This value is 
		       used to identify the thread ready for 'stopThread'. This value
			   must be unique otherwise the functionality of stopThread is
			   undetermined. Typically the operating system thread ID is used.
	    \return \ref amBX_RESULT
	*/
	amBX_RESULT (*runThread) (struct IamBX * pThis,
							  amBX_Thread_Type eThreadType,
							  amBX_u32 uThreadID);

	/** \brief Used to stop the execution of a thread started with runThread(). 
	After the successful call of stopThread(), runThread() - which was called 
	inside the thread - will return. See \ref page_threading.
		\param pThis A pointer to this IamBX interface
		\param uThreadID An identifier for the thread being stopped. This value
			   should be the same as the ID passed to runThread().
		\return \ref amBX_RESULT
	*/
	amBX_RESULT (*stopThread) (struct IamBX * pThis,
							   amBX_u32 uThreadID);
};

/**
    \brief This function creates an interface to amBX.
	After use, the interface must be deleted by the runtime by calling release().
	See the IamBX class
	documentation or "Creating the Interface" for more 
	details.

    \param ppIamBX the pointer to the interface that is created
	\param uMajorVersionRequired is the major version of the amBX API/Runtime
		   required by this application. This value should be the same Major 
		   value defined at the top of each interface header file 
		   i.e. #define IAMBX_VERSION_A 1
		   would indicate that Major version 1 is required.
	\param uMinorVersionRequired is the Minor version of the amBX API/Runtime
		   required by this application. This value should be the same Minor 
		   value defined at the top of each interface header file 
		   i.e. #define IAMBX_VERSION_B 0
		   would indicate that Minor version 0 is required.
    \param pszAppName A null terminated string containing the application name
    \param pszAppVersion A null terminated string containing the application
           version
    \param pMemHandler A pointer to the memory handler
    \param bUsingThreads True if we intend to use a thread to update devices. 
	See \ref page_threading.
    \return \ref amBX_RESULT
*/
DECLFUNC amBX_RESULT amBXCreateInterface (
	struct IamBX ** ppIamBX,
	amBX_u32 uMajorVersionRequired,
	amBX_u32 uMinorVersionRequired,
	amBX_char* pszAppName,
	amBX_char* pszAppVersion,
	struct amBX_MemHandler* pMemHandler,
	amBX_bool bUsingThreads);

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_H_*/
