/*! \brief simple implement of limit filter algorithm
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_LIMIT_H_
#define _FILTER_LIMIT_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

#include "../sorting/sort_common.h"

/*  \brief simple implement of limit filter algorithm
 *  \param array array to filter
 *  \param limit maximum of increment
 *  \note $ f(t) = 
 *               \begin{case}
 *               f(t), & \test{if $f(t)-f(t-1) < limit $  \\
 *               f(t-1), & \test{others}
 *               \end{case}
 *        $
 * */
void filter_limit(array_t array, uint32_t limit);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_LIMIT_H_

