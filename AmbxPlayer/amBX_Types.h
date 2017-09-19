/*============================================================================*/
/** \file amBX_Types.h

\brief 
This file contains the definitions of basic amBX types.
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

#ifndef _amBX_TYPES_H_
#define _amBX_TYPES_H_

/** 
* DO NOT CHANGE
*/
#define IAMBX_TYPES_VERSION_A 1 /** Major Version number of the API */
#define IAMBX_TYPES_VERSION_B 0 /** Minor Version number of the API */
/** 
* DO NOT CHANGE
*/


#ifndef amBX_DONT_TYPEDEF_TYPES

typedef char amBX_i8;				/**< 8-bit signed integer */
typedef unsigned char amBX_u8;		/**< 8-bit unsigned integer */
typedef short amBX_i16;				/**< 16-bit signed integer */
typedef unsigned short amBX_u16;	/**< 16-bit unsigned integer */
typedef int amBX_i32;				/**< 32-bit signed integer */
typedef long amBX_long;				/**< 32 bit signed */
typedef unsigned int amBX_u32;		/**< 32-bit unsigned integer */
typedef long long amBX_i64;			/**< 64-bit signed integer */
typedef unsigned long long amBX_u64;/**< 64-bit unsigned integer */
typedef char amBX_char;				/**< UTF-8 character.  */
typedef amBX_i8 amBX_bool;			/**< Boolean. 0=false, other values=true */
typedef amBX_i64 amBX_time;			/**< Time in milliseconds */
typedef float amBX_float;			/**< 32 bit float */
typedef void* amBX_ptr;				/**< POINTER. This assumes pointers are the 
									     same size as int. */
typedef char amBX_file;				/**< Used for passing in amBX_bn/ck files */
typedef amBX_ptr amBX_Handle;		/**< Handle for an amBX Thread */
typedef amBX_ptr amBX_Flag;			/**< Flag to set,reset and wait on threads*/
typedef amBX_ptr amBX_Mutex;		/**< Mutex for threads to get, release */

/* Don't define these types again. */
#define amBX_DONT_TYPEDEF_TYPES
#endif


#ifndef AMBX_TYPES_STATIC_ASSERT
/** Compile time check that the Test expression is valid.
If the result of the expression if false, the macro attempts to create a typedef
of an array with 0 entries which is illegal in C and C++.  The TestName needs to
be unique within the scope of the call.
\param TestName
Unique name of this test.
\param Test
Compile-time resolvable expression to test against.
*/
#define AMBX_TYPES_STATIC_ASSERT( TestName, Test ) \
	typedef int amBX_TypeError_##TestName[ (Test) ? 1 : 0 ];
#endif


#ifndef AMBX_TYPES_IS_SIGNED
/** Determine if a type is signed or not.
\param Type
Type who's sign is to be determined.
\return
\li 1 if Type is signed.
\li 0 if Type is not signed.
*/
#define AMBX_TYPES_IS_SIGNED( Type ) \
	((((Type)-1) >> 1) == (Type)-1)
#endif


/* Make sure the standard types are the correct size and sign */
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_i8, sizeof(amBX_i8) == 1 && AMBX_TYPES_IS_SIGNED(amBX_i8) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_u8, sizeof(amBX_u8) == 1 && AMBX_TYPES_IS_SIGNED(amBX_u8) == 0 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_i16, sizeof(amBX_i16) == 2 && AMBX_TYPES_IS_SIGNED(amBX_i16) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_u16, sizeof(amBX_u16) == 2 && AMBX_TYPES_IS_SIGNED(amBX_u16) == 0 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_i32, sizeof(amBX_i32) == 4 && AMBX_TYPES_IS_SIGNED(amBX_i32) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_u32, sizeof(amBX_u32) == 4 && AMBX_TYPES_IS_SIGNED(amBX_u32) == 0 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_i64, sizeof(amBX_i64) == 8 && AMBX_TYPES_IS_SIGNED(amBX_i64) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_u64, sizeof(amBX_u64) == 8 && AMBX_TYPES_IS_SIGNED(amBX_u64) == 0 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_char, sizeof(amBX_char) == 1 && AMBX_TYPES_IS_SIGNED(amBX_char) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_bool, sizeof(amBX_bool) == 1 && AMBX_TYPES_IS_SIGNED(amBX_bool) == 1 );
AMBX_TYPES_STATIC_ASSERT( _ambx_types_Check1_0_time, sizeof(amBX_time) == 8 && AMBX_TYPES_IS_SIGNED(amBX_time) == 1 );


/**
* enums
*/

/** This is the type returned from almost all amBX calls - 
   amBX_OK means the call was successful, any other result is an error. */

typedef enum {
	amBX_OK = 0,			/**< OK */
	amBX_NO_SPACE,			/**< out of buffer space */
	amBX_ERROR,				/**< generic error */
	amBX_NOT_FOUND,			/**< no file/device etc. found */
	amBX_VERSION_NOT_FOUND,	/**< The requested version of amBX API is not 
								 available */
	amBX_BAD_ARGS,			/**< arguments passed in bad (usually null
                                 pointers passed in) */
	amBX_OUT_OF_RANGE,		/**< Value given is beyond usable range using 
								 default values if possible */
	amBX_OUT_OF_MEMORY,		/**< couldn't allocate memory */
	amBX_NOT_INSTALLED,		/**< amBX isn't installed on the PC */
	amBX_OLD_VERSION,		/**< amBX installed, but need newer version */
	amBX_ENGINE_LOST,		/**< connection to amBX Engine currently
                                 inoperative */
	amBX_SENDING_TIMEOUT,	/**< request to send a script timed out */
	amBX_NOT_THREADED,		/**< returned by a threaded function if threading is 
								 no being used for the purpose specified */
    amBX_BAD_THREADID,		/**< returned by a function if the thread ID is 
								 incorrect or doesn't exist. The thread with the
								 ID could have been recently removed */
	amBX_THREAD_EXISTS,		/**< returned by a threaded function if a thread is
								currently being used for that function */
	amBX_UPDATE_TIMEOUT,	/**< returned if waiting to perform an update
								times out. This could be waiting for a thread
								to finish or waiting for a critical section */
	amBX_THREAD_TIMEOUT		/**< returned if the request to run a thread times
								out. This could be because another thread is
								already being run or another thread is using the
								resources needed to run the thread*/
}amBX_RESULT;

/** The enabled/disabled state of a device interface - see the setState() and 
getState() calls in the device interfaces */
typedef enum {
	ENABLED = 0,    /**< amBX Currently Enabled */
	DISABLED,       /**< amBX Currently Disabled */
	ENABLING,       /**< amBX in the process of becoming Enabled */
	DISABLING       /**< amBX in the process of becoming Disabled */
}amBX_state;

/** The location of a device, represented as compass points, where N is in front 
of the user and S is behind the user - see \ref page_locs_and_heights */
typedef enum {
 	amBX_EVERYWHERE = 0, /**< amBX Location considered to be all Locations */
 	amBX_N = 1,          /**< amBX Location North */
 	amBX_NE = 2,         /**< amBX Location North-East */
 	amBX_E = 4,          /**< amBX Location East */
 	amBX_SE = 8,         /**< amBX Location South-East */
 	amBX_S = 16,         /**< amBX Location South */
 	amBX_SW = 32,        /**< amBX Location South-West */
 	amBX_W = 64,         /**< amBX Location West */
 	amBX_NW = 128,       /**< amBX Location North-West */
 	amBX_C = 256         /**< amBX Location Center */
}amBX_loc;
 
/** The height of a device relative to the user's head - 
see \ref page_locs_and_heights. */
typedef enum {
 	amBX_ANYHEIGHT = 0,	   /**< amBX Height considered to be Any Height */
 	amBX_EVERYHEIGHT = 1,  /**< amBX Height considered to be Every Height */
 	amBX_TOP = 2,          /**< amBX Height Top */
 	amBX_MIDDLE = 4,       /**< amBX Height Middle */
 	amBX_BOTTOM = 8        /**< amBX Height Bottom */
}amBX_height;

/** The intended purpose of a thread passed to runThread -
see \ref page_threading  */
typedef enum {
	amBX_Ambient_Update = 0,
}amBX_Thread_Type;

#endif /*_amBX_TYPES_H_*/
