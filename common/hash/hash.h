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
#include <stdio.h>

typedef struct hash {
	char * key;
	void * value;
	struct hash * next;
} hash_t;

typedef struct hash_class {
	//struct hash * list;  //!< head of list
	struct hash ** array;  //!< head of array
	size_t hash_tab_size;
} hash_class_t;

/*! \brief map c-string to integer value
 *  \param str c-string
 *  \param HASH_TAB_SIZE hash table count
 *  \retval hashed integer value
 * */
uintptr_t hash(const char * str, const size_t HASH_TAB_SIZE);

/*! \brief create hash-list and hash-table
 *  \param HASH_TAB_SIZE hash table count
 *  \retval hash instance
 * */
struct hash_class hash_new(const size_t HASH_TAB_SIZE);

/*! \brief release hash-list and hash-table
 *  \param instance hash instance
 * */
void hash_release(struct hash_class * instance);

/*! \brief append a new hash to list and insert to table
 *  \param instance hash instance
 *  \param key keywords string 
 *  \param value 
 * */
void hash_push(struct hash_class * instance , const char * key, const void * value,
		size_t value_size);

/*! \brief pop hash from lish and delete from table
 *  \param instance hash instance
 * */
//void hash_pop(struct hash_class * instance);

/*! \brief lookup hash by keywords string
 *  \param instance hash instance
 *  \param key keywords string
 *  \retval lookuped hash pointer , NULL for not lookup
 * */
struct hash * hash_lookup(struct hash_class instance, const char * key);

/*! \brief printf hash-table to c-array text in file
 *  \param instance hash instance
 * */
void hash_dump(struct hash_class instance, FILE * f);

/*! \brief load hash-table frome file append to list and insert to table
 *  \param instance hash instance
 *  \param f file loadded
 *  \retval 0==ok,-1==err
 * */
int hash_load(struct hash_class instance, FILE * f);

#ifdef __cplusplus
	}
#endif

#endif  //!< _HASH_H_

