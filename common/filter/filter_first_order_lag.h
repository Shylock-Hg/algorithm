/*! \brief simple imlement of first-order lag filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_FIRST_ORDER_LAG_H_
#define _FILTER_FIRST_ORDER_LAG_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*  \brief simple implement of first-order lag filter 
 *  \param array array to filter
 * */
void filter_first_order_lag(array_t array, float k);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_FIRST_ORDER_LAG_H_

