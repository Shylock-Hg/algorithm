/*! \brief simple implement of linear search algorithm
 *  \author Shylock Hg
 *  \date 2018-04-25
 *  \email tcath2s@gmail.com
 * */

#ifndef _SEARCH_LINEAR_H_
#define _SEARCH_LINEAR_H_

#ifdef __cplusplus
	extern "C" {
#endif


#include "../sorting/sort_common.h"

/*  \brief search item in array
 *  \param array array to search
 *  \param x value to search
 *  \retval index of searched item,-1 for failed
 *  \note time:O(n),space:O(1)
 * */
int search_linear(array_t array,int x);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SEARCH_LINEAR_H_

