/*! \brief simple implement of sliding median filter algorithm
 *  \author Shylock Hg
 *  \date 2018-04-30
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_MEDIAN_H_
#define _FILTER_MEDIAN_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*  \brief simple implement of sliding median filter
 *  \param array array to filter
 *  \param start start index of window
 *  \param window count to filter once
 *  \note $
 *        f(t) = mid(f(t), f(t+1), f(t+2))
 *        $
 * */
void filter_median(array_t array, size_t start, size_t window);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_MEDIAN_H_

