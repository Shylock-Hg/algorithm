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

/*
typedef struct hash {
	char * key;
	void * value;
	struct hash * next;
} hash_t;
*/
/*
typedef struct hash_class {
	struct hash * list;  //!< head of list
	struct hash * array[];  //!< head of array
} hash_class_t;
*/

/*! \brief create hash-list and hash-table
 *  \param HASH_TAB_SIZE hash table count
 *  \retval hash instance
 * */
struct hash_class hash_new(const size_t HASH_TAB_SIZE){
	struct hash_class instance = {0};

	instance.list = NULL;  //!< list head
	instance.array = malloc(HASH_TAB_SIZE*sizeof(struct hash *));  //!< array head

	return instance;
}

/*! \brief release hash-list and hash-table
 *  \param instance hash instance
 * */
void hash_release(struct hash_class * instance){
	//!< free list
	while(NULL != instance->list){
		struct hash * temp = instance->list;
		instance->list = instance->list->next;

		free(temp->key);
		free(temp->value);
		free(temp);
	}

	//!< free array
	free(instance->array);
}

/*! \brief append a new hash to list and insert to table
 *  \param instance hash instance
 *  \param key keywords string 
 *  \param value 
 * */
void hash_append(struct hash_class * instance , const char * key, const void * value);

/*! \brief pop hash from lish and delete from table
 *  \param instance hash instance
 * */
void hash_pop(struct hash_class * instance);

/*! \brief lookup hash by keywords string
 *  \param instance hash instance
 *  \param key keywords string
 *  \retval lookuped hash pointer , NULL for not lookup
 * */
struct hash * hash_lookup(struct hash_class * instance, const char * key);

/*! \brief printf hash-table to c-array text in file
 *  \param instance hash instance
 * */
void hash_dump(struct hash_class * instance);

/*! \brief load hash-table frome file append to list and insert to table
 *  \param instance hash instance
 *  \param f file loadded
 *  \retval 0==ok,-1==err
 * */
int hash_load(struct hash_class * instance, FILE * f);

