/*! \brief simple implement of sliding median mean filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-01
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_MEDIAN_MEAN_H_
#define _FILTER_MEDIAN_MEAN_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>

/*  \brief simple implement of sliding median mean filter algorithm
 *  \param array array to filter
 *  \param start index of start item in window
 *  \param window size of window
 * */
void filter_median_mean(array_t array, size_t start, size_t window);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_MEDIAN_MEAN_H_

