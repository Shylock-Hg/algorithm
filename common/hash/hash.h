/*! \brief hash algorithm simple implement
 *  \author Shylock Hg
 *  \date 2018-04-14
 *  \email tcath2s@gmail.com
 * */

#ifndef _HASH_H_
#define _HASH_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

uintptr_t hash(const char * str, const size_t HASH_TAB_SIZE);

#ifdef __cplusplus
	}
#endif

#endif  //!< _HASH_H_

