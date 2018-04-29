/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */

#ifndef _SEARCH_BINARY_H_
#define _SEARCH_BINARY_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "../sorting/sort_common.h"

/*! \brief simple implement of binary search algorithm 
 *  \param array array to sort
 *  \param start the index of first item
 *  \param end the index of last item
 *  \param x value to search
 *  \retval index of searched item,-1 for not find
 * */
int search_binary(int array[], size_t start, size_t end, int x);

#ifdef __cplusplus
	}
#endif

#endif  //!< _SEARCH_BINARY_H_

