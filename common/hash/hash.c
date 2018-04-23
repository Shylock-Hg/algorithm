/*! \brief 
 *  \author Shylock Hg
 *  \date 2018-04-14
 *  \email tcath2s@gmail.com
 * */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

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

	//instance.list = NULL;  //!< list head
	instance.array = calloc(HASH_TAB_SIZE,sizeof(struct hash *));  //!< array head
	instance.hash_tab_size = HASH_TAB_SIZE;

	return instance;
}

/*! \brief release hash-list and hash-table
 *  \param instance hash instance
 * */
void hash_release(struct hash_class * instance){
	//!< free list
	/*
	while(NULL != instance->list){
		struct hash * temp = instance->list;
		instance->list = instance->list->next;

		free(temp->value);
		free(temp->key);
		free(temp);
	}
	*/
	//instance->list = NULL;
	
	//< free list
	for(size_t i=0; i<instance->hash_tab_size; i++){
		while(NULL != instance->array[i]){
			struct hash * temp = instance->array[i];
			instance->array[i] = instance->array[i]->next;

			free(temp->value);
			free(temp->key);
			free(temp);
		}
	}

	//< free array
	free(instance->array);
	instance->array = NULL;

	//< reset hash table size
	instance->hash_tab_size = 0;
}

/*! \brief append a new hash to list and insert to table
 *  \param instance hash instance
 *  \param key keywords string 
 *  \param value 
 * */
void hash_push(struct hash_class * instance , const char * key, const void * value,
		const size_t value_size){
	//< find hash table index
	uintptr_t index = hash(key,instance->hash_tab_size);

	//< iterate list until pre point to tail
	struct hash * pre  = instance->array[index];
	struct hash * temp = instance->array[index];
	while(NULL != temp){
		if(0 == strcmp(temp->key,key)){
			memcpy(temp->value,value,value_size);
			printf("[info]:overwrite value of key-`%s`\n",key);
			break;  //< already exist key
		}
		
		pre  = temp;
		temp = temp->next;
	}
	/*
	if(NULL == instance->array[index]){
		instance->array[index] = it;
	}else if(0 == strcmp(key,instance->array[index]->key)){
		printf("[warn]:repeated key\n");
		//!< TODO handle repeated define
	}else{
		printf("[err]:hash conflict!\n");
		//!< TODO handle hash conflict!!!
	}
	*/

	/*
	struct hash * pre = instance->list;
	struct hash * it = instance->list;
	while(NULL != it){
		pre = it;
		it = it->next;
	}
	*/

	//!< create new list item
	temp = malloc(sizeof(struct hash));

	temp->key = malloc(strlen(key)+1);
	memcpy(temp->key,key,strlen(key)+1);

	temp->value = malloc(value_size);
	memcpy(temp->value,value,value_size);

	temp->next = NULL;

	//< add new item to list
	if(NULL != pre){
		pre->next = temp;  //!< add to list chain
	}else{
		//!< empty list
		instance->array[index] = temp;  //!< add to list chain(head)
		printf("empty list\n");
	}
}

/*! \brief pop hash from lish and delete from table
 *  \param instance hash instance
 * */
/*
void hash_pop(struct hash_class * instance){
	struct hash * pre = instance->list;
	struct hash * it  = instance->list;
	if(NULL == instance->list){
		return;  //!< empty list
	}
	while(NULL != it->next){
		pre = it;
		it = it->next;
	}

	if(it == instance->list){
		instance->list = NULL;  //!< empty list
	}

	//!< hash table
	uintptr_t index = hash(it->key,instance->hash_tab_size);
	instance->array[index] = NULL;

	//!< tail list item
	pre->next = NULL;
	free(it->value);
	free(it->key);
	free(it);
}
*/

/*! \brief lookup hash by keywords string
 *  \param instance hash instance
 *  \param key keywords string
 *  \retval lookuped hash pointer , NULL for don't lookup 
 * */
struct hash * hash_lookup(struct hash_class instance, const char * key){
	if(NULL == instance.array)
		return NULL;

	uintptr_t index = hash(key,instance.hash_tab_size);

	while(NULL != instance.array[index]){
		if(0 == strcmp(instance.array[index]->key,key))
			return instance.array[index];
		instance.array[index] = instance.array[index]->next;
	}
	
	return NULL;
}

/*! \brief dump hash table in binary
 *  \param instance hash instance
 * */
void hash_dump(struct hash_class instance, FILE * f);

/*! \brief load hash-table frome file append to list and insert to table
 *  \param instance hash instance
 *  \param f file loadded
 *  \retval 0==ok,-1==err
 * */
int hash_load(struct hash_class instance, FILE * f);

