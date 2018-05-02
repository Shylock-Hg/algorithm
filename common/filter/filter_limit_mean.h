/*! \brief simple implement of limit mean filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_LIMIT_MEAN_H_
#define _FILTER_LIMIT_MEAN_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*  \brief simple implement of limit mean filter algortihm
 *  \param array array to filter
 *  \param start start index of window
 *  \param window length of window
 * */
void filter_limit_mean(array_t array, size_t start, size_t window, int limit);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_LIMIT_MEAN_H_

