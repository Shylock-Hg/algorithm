/*! \brief simple implement of sliding arithmetic average filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-01
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_ARITHMETIC_AVERAGE_H_
#define _FILTER_ARITHMETIC_AVERAGE_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>

#include "../sorting/sort_common.h"

/*  \brief simple implement of sliding arithmetic average filter
 *  \param array array to filter
 *  \param start index of start item
 *  \param window filter window size
 * */
void filter_arithmetic_average(array_t array, size_t start, size_t window);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_ARITHMETIC_AVERAGE_H_

