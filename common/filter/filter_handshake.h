/*! \brief simple implement of handshake filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#ifndef _FILTER_HANDSHAKE_H_
#define _FILTER_HANDSHAKE_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>

#include "../sorting/sort_common.h"

/*  \brief simple implement of handshake filter
 *  \param array array to filter
 *  \param window length of window
 *  \param limit limit of counter
 * */
void filter_handshake(array_t array, size_t start, size_t window, int limit);

#ifdef __cplusplus
	}
#endif

#endif  //!< _FILTER_HANDSHAKE_H_

