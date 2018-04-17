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

/*! \brief map c-string to integer value
 *  \param str c-string
 *  \param HASH_TAB_SIZE hash table count
 *  \retval hashed integer value
 * */
uintptr_t hash(const char * str, const size_t HASH_TAB_SIZE);

/*! \brief create hash-list and hash-table
 *  \param HASH_TAB_SIZE hash table count
 *  \retval hash list head
 * */
struct hash * hash_new(const size_t HASH_TAB_SIZE);

/*! \brief release hash-list and hash-table
 *  \param head head of hash-list
 * */
void hash_release(struct hash * head);

/*! \brief append a new hash to list and insert to table
 *  \param head head of hash-list
 *  \param key keywords string 
 *  \param value 
 * */
void hash_append(struct hash * head, const char * key, const void * value);

/*! \brief pop hash from lish and delete from table
 *  \param head head of hash-list
 * */
void hash_pop(struct hash * head);

/*! \brief lookup hash by keywords string
 *  \param head head of hash-list
 *  \param key keywords string
 *  \retval lookuped hash pointer , NULL for not lookup
 * */
struct hash * hash_lookup(const struct hash * head, const char * key);

/*! \brief printf hash-table to c-array text in file*/
void hash_dump(const struct hash * head);

/*! \brief load hash-table frome file append to list and insert to table
 *  \param head head of hash-list
 *  \param f file loadded
 *  \retval 0==ok,-1==err
 * */
int hash_load(struct hash * head, FILE * f);

#ifdef __cplusplus
	}
#endif

#endif  //!< _HASH_H_

