#ifndef _SORT_SELECT_H_
#define _SORT_SELECT_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>
#include "sort_common.h"

/*  \brief simple implement of select sort
 *  \param array array to sorted
 *  \note  time:O(n2), space:O(1),nonstable
 * */
void sort_select(array_t array);

#ifdef __cplusplus
	}
#endif

#endif

