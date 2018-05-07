/*! \brief simple implement of jump search algorithm
 *  \author Shylock Hg
 *  \date 2018-05-07
 *  \email tcath2s@gmail.com
 * */

#ifndef _SEARCH_JUMP_H_
#define _SEARCH_JUMP_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*  \brief search in array by jump algorithm
 *  \param array array to search
 *  \param x value to search
 *  \retval index of searched item or -1 for not find
 *  \note just for ascending array
 *  \time O(sqrt(n))
 * */
int search_jump(array_t array, int x);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SEARCH_JUMP_H_

