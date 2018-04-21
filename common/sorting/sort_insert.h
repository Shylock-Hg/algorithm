#ifndef _SORT_INSERT_H_
#define _SORT_INSERT_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>
#include "sort_common.h"

/*  \brief simple implement of insert sort
 *  \param array array to sorted
 *  \note time:O(n2),space:O(1),stable
 * */
void sort_insert(array_t array);

#ifdef __cplusplus
	}
#endif

#endif

