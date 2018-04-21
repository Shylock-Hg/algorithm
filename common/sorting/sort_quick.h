/*! \brief simple implement of quick sort
 *  \author Shylock Hg
 *  \date 2018-04-21
 *  \email tcath2s@gmail.com
 * */

#ifndef _SORT_QUICK_H_
#define _SORT_QUICK_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "sort_common.h"

/*  \brief quick sort 
 *  \param array array to sorted
 *  \note time:O(n2),space:O(1),nonstable
 * */
void sort_quick(array_t array);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SORT_QUICK_H_

