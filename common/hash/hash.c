/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-04-14
 *  \email tcath2s@gmail.com
 * */

#include <stdint.h>
#include <stddef.h>

/*! \brief map characters to one integer 
 *  \param str c-string
 *  \param HASH_TAB_SIZE count of hash table
 *  \retval integer hashed
 *  \note $hashval(t) = [c(t) + 31 * hashval(t-1)] % HASH_TAB_SIZE$
 * */
uintptr_t hash(const char * str, const size_t HASH_TAB_SIZE){
	uintptr_t hashval = 0;

	while('\0' != *str){
		hashval = ((*str++) + 31 * hashval);
	}

	return hashval % HASH_TAB_SIZE;
}

