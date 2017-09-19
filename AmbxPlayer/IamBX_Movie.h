/*============================================================================*/
/** \file IamBX_Movie.h

\brief This file contains the definition of the IamBX_Movie interface.

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

#ifndef _IamBX_MOVIE_H_
#define _IamBX_MOVIE_H_

/*
* DO NOT CHANGE
*/
#define IAMBX_MOVIE_VERSION_A 1 /* Major Version number of the API */
#define IAMBX_MOVIE_VERSION_B 0 /* Minor Version number of the API */
/*
* DO NOT CHANGE
*/

#include "amBX_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
\brief The IamBX_Movie interface encapsulates an amBX movie file - a sequence
of ambience intended to accompany a movie or a cutscene.

Unlike \ref sec_script_events,
movies can be paused and seeked (i.e. their playback
position can be changed). This comes at a cost, however - each movie interface 
open requires its own connection to the amBX engine. Therefore not too many 
movie interfaces should exist at a time, and seeking and pausing should not be 
done too often. For more details, see \ref sec_script_movies.
*/
struct IamBX_Movie {
    /** \brief
        Releases the movie interface and deallocates all resources owned by this 
		movie.
        \param pThis A pointer to this movie interface.
        \return amBX_RESULT
    */
	amBX_RESULT (*release) (struct IamBX_Movie * pThis);

    /** \brief 
        Freezes or unfreezes this movie (actually freezes this movies engine
        connection). See \ref sec_script_freeze.

        \param pThis A pointer to this movie interface.
        \param bFrozen Boolean to indicate whether the movie should be frozen or
               unfrozen (nonzero => frozen, zero => unfrozen)
        \return amBX_RESULT
    */
	amBX_RESULT (*setFrozen) (struct IamBX_Movie * pThis,
                              amBX_bool bFrozen);

    /** \brief
        Returns whether the movie is frozen or not. See \ref sec_script_freeze.
        \param pThis A pointer to this movie interface.
        \param pbFrozen Boolean to indicate whether the movie is frozen or
               unfrozen (nonzero => frozen, zero => unfrozen)
        \return amBX_RESULT
    */
	amBX_RESULT (*getFrozen) (struct IamBX_Movie * pThis,
                              amBX_bool* pbFrozen);

    /** \brief
        Suspends or unsuspends this movie (actually suspends this movies engine
        connection). See \ref sec_script_suspend.

        \param pThis A pointer to this movie interface.
        \param bSuspended Boolean to indicate whether the movie should be
               suspended or unsuspended (nonzero => suspend, zero => unsuspend)
        \return amBX_RESULT
    */
	amBX_RESULT (*setSuspended) (struct IamBX_Movie * pThis,
                                 amBX_bool bSuspended);

    /** \brief
        Returns whether the movie is suspended or not. See 
		\ref sec_script_suspend.
        \param pThis A pointer to this movie interface.
        \param pbSuspended Boolean to indicate whether the movie is suspended or
               unsuspended (nonzero  => suspended, zero => unsuspended)
        \return amBX_RESULT
    */
	amBX_RESULT (*getSuspended) (struct IamBX_Movie * pThis,
                                 amBX_bool* pbSuspended);

    /** \brief
        Jumps to the specified point in time within the movie. The seek will
		on be made if the absolute difference of the current time 
		and the last seek time is greater than the seek threshold
		(Currently 0.2 seconds).
        \param pThis A pointer to this movie interface
        \param fSecs The time in seconds (from the start of the movie) you want
               to jump to. Values should be larger than 0.
        \return amBX_RESULT
    */
	amBX_RESULT (*seek) (struct IamBX_Movie * pThis,
                         amBX_float fSecs);

	};

#ifdef __cplusplus
}
#endif

#endif	/*_IamBX_MOVIE_H_*/

