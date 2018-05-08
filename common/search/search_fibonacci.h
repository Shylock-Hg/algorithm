/*! \brief simple implement of fibonacci search
 *  \author Shylock Hg
 *  \date 2018-05-08
 *  \email tcath2s@gmail.com
 * */

#ifndef _SEARCH_FIBONACCI_H_
#define _SEARCH_FIBONACCI_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*  \brief fibonacci search
 *  \param array array to search
 *  \param x value to search
 *  \retval index of item searched , -1 for not find
 * */
int search_fibonacci(array_t array, int x);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SEARCH_FIBONACCI_H_

