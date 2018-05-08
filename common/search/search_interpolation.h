/*! \brief simple implement of interpolation search
 *  \author Shylock Hg
 *  \date 2018-05-08
 *  \email tcath2s@gmail.com
 * */

#ifndef _SEARCH_INTERPOLATION_H_
#define _SEARCH_INTERPOLATION_H_

#ifdef __cplusplus
	extern "C" {
#endif

/*  \brief interpolation search in array
 *  \param array array to search
 *  \param x value to search
 *  \retval index of item searched , -1 for not find
 *  \note O(loglog(n)) for sorted uniformly distributed array, O(n) for general array
 * */
int search_interpolation(array_t array, int x);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SEARCH_INTERPOLATION_H_

