/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-04-20
 *  \email tcath2s@gmail.com
 * */

#ifndef _SORT_MERGE_H_
#define _SORT_MERGE_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include "sort_common.h"

/*! \brief simple merge sort algorithm implement
 *  \param array array to sorted
 *  \param len count of array items
 * */
void sort_merge(array_t array);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SORT_MERGE_H_

