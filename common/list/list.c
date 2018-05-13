/*! \brief a simple implement of ADT list
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#define NDEBUG

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "list.h"

///! \defgroup list_prototype
/// @{
/*
typedef struct list {
	void * value;
	struct list * _pre;
	struct list * _next;
} list_t;

typedef struct list_class {
	struct list * _head;
	struct list * _tail;
	size_t size_value;
} list_class_t;
*/
/// @}


///! \defgroup list_interface
/// @{
//

/*! \brief create a list instance
 *  \param size_value size(bytes) of value
 *  \retval created instance pointer , NULL for fail
 * */
struct list_class * list_class_new(size_t size_value){
	struct list_class * instance = malloc(sizeof(struct list_class));

	instance->_head = NULL;
	instance->_tail = NULL;
	instance->size_value = size_value;

	return instance;
}

/*! \brief create a element of list by value
 *  \param instance instance of list 
 *  \param value value pointer
 *  \retval created list element pointer, NULL for fail
 * */
struct list * list_class_element_new(const struct list_class * instance, void * value){
	assert(NULL != instance);
	if(NULL == instance)
		return NULL;

	struct list * element = malloc(sizeof(struct list));
	assert(NULL != element);
	if(NULL == element)
		return NULL;

	element->value = malloc(instance->size_value);
	assert(NULL != element);
	if(NULL == element)
		return NULL;
	memcpy(element->value, value, instance->size_value);

	element->_pre  = NULL;
	element->_next = NULL;

	return element;

}

/*! \brief release list instance
 *  \param instance instance of list
 * */
void list_class_release(struct list_class * instance){
	assert(NULL != instance);
	if(NULL == instance)
		return;

	//< release list memory
	while(NULL != instance->_head){
		struct list * temp = instance->_head;
		instance->_head = instance->_head->_next;

		list_class_element_release(instance, temp);
	}

	//< release handle memory
	free(instance);
}

/*! \brief release element of list
 *  \param instance instance of list
 *  \param element element poitner to release
 * */
void list_class_element_release(const struct list_class * instance, struct list * element){
	assert(NULL != instance && NULL != element);
	if(NULL == instance || NULL == element)
		return ;

	free(element->value);
	free(element);
}

/*! \brief get element of list by index
 *  \param instance instance of list
 *  \param index index of element query
 *  \retval query element pointer, NULL for fail
 * */
struct list * list_class_get_at(const struct list_class * instance, size_t index){
	assert(NULL != instance && NULL != instance->_head);
	if(NULL == instance || NULL == instance->_head)
		return NULL;

	struct list * ret = instance->_head;
	while(index--){
		if(NULL != ret)
			ret = ret->_next;
	}

	return ret;
}

/*! \brief insert value to list at specify index
 *  \param instance instance of list
 *  \param index index to insert 
 *  \param element element to insert
 *  \retval 0 for ok ; -1 for fail
 * */
//int list_class_insert_at(struct list_class * instance, size_t index, void * value);
int list_class_insert_at(struct list_class * instance, size_t index, struct list * element){
	assert(NULL != instance && NULL != element);
	if(NULL == instance || NULL == element)
		return -1;

	//< iterate to index or NULL value
	struct list * pre  = NULL;
	struct list * temp = instance->_head;
	while(index--){
		if(NULL != temp){
			pre = temp;
			temp = temp->_next;
		}
	}

	//< insert element
	/*
	if(NULL == pre){  //!< insert to head
		//pre->_next = element;
		if(NULL != temp)
			temp->_pre = element;
		else
			temp = element;
	}else if(instance->_tail == temp){  //!< insert to tail
		
	}else{
	}
	*/
	if(NULL != pre)
		pre->_next = element;
	else  //!< append to head
		instance->_head = element;
	element->_pre = pre;
	if(NULL != temp)
		temp->_pre = element;
	else  //!< append to tail
		instance->_tail = element;
	element->_next = temp;

	return 0;
}

/* \brief remove element at specify index
 * \param instance instance of list
 * \param index index to remove
 * \retval 0 for ok ; -1 for fail
 * */
int list_class_remove_at(struct list_class * instance, size_t index){
	assert(NULL != instance && NULL != instance->_head);
	if(NULL == instance || NULL == instance->_head)
		return -1;

	
	//< iterate to index or NULL value
	struct list * pre  = NULL;
	struct list * temp = instance->_head;
	while(index--){
		if(NULL != temp){
			printf("%d,",*(int*)(temp->value));
			pre = temp;
			temp = temp->_next;
		}
	}

	//printf("%p",temp);
	//< remove temp
	if(NULL != temp){
		struct list * next = temp->_next;

		if(NULL != pre)
			pre->_next = next;
		else  //!< remove head
			instance->_head = next;

		if(NULL != next)
			next->_pre = pre;
		else  //!< remove tail
			instance->_tail = pre;

		list_class_element_release(instance, temp);
		temp = NULL;

		return 0;
	}else{
		return -1;
	}

}

/*! \brief remove the value first occurrence
 *  \param instance instance of list
 *  \param value value to search
 *  \retval 0 for ok ; -1 for fail
 * */
int list_class_remove_value(struct list_class * instance, const void * value){
	assert(NULL != instance && NULL != value);
	if(NULL == instance || NULL == value)
		return -1;

	//< iterate to index or NULL value to find value
	struct list * pre  = NULL;
	struct list * temp = instance->_head;
	int index = 0;
	while(index--){
		if(NULL != temp){
			if(0 == memcmp(temp->value, value, instance->size_value))
				break;
			pre = temp;
			temp = temp->_next;
		}
	}

	//< found
	if(NULL != temp){
		if(0 == memcmp(temp->value, value, instance->size_value)){
			struct list * next = temp->_next;

			if(NULL != pre)
				pre->_next = next;
			else  //!< remove head
				instance->_head = next;

			if(NULL != next)
				next->_pre = pre;
			else  //!< remove tail
				instance->_tail = pre;

			list_class_element_release(instance, temp);
			temp = NULL;

			return 0;
		}
	}

	return -1;
}

/*! \brief replace element at specify index
 *  \param instance instance of list
 *  \param index index to replace
 *  \param src element replace to 
 *  \retval 0 for ok ; -1 for fail
 * */
int list_class_replace_at(struct list_class * instance, size_t index, struct list * src){
	assert(NULL != instance && NULL != src);
	if(NULL == instance || NULL == src)
		return -1;

	//< iterate to index or NULL value
	struct list * pre  = NULL;
	struct list * temp = instance->_head;
	while(index--){
		if(NULL != temp){
			pre = temp;
			temp = temp->_next;
		}
	}

	//< remove temp
	if(NULL != temp){
		struct list * next = temp->_next;

		if(NULL != pre)
			pre->_next = src;
		else  //!< remove head
			instance->_head = src;
		src->_pre  = pre;

		if(NULL != next)
			next->_pre = src;
		else  //!< remove tail
			instance->_tail = src;
		src->_next = next;

		list_class_element_release(instance, temp);
		temp = NULL;

		return 0;
	}else{
		return -1;
	}

}

/*! \brief get count of elements in list
 *  \param instance instance of list
 *  \retval count of elements in list
 * */
size_t list_class_count(const struct list_class * instance){
	assert(NULL != instance);
	if(NULL == instance)
		return 0;

	size_t count = 0;
	struct list * temp = instance->_head;
	while(NULL != temp){
		temp = temp->_next;
		count++;
	}

	return count;
}

/*! \brief check is list empty 
 *  \param instance instance of list
 *  \retval bool 0 for not empty ; 1 for empty
 * */
int list_class_is_empty(const struct list_class * instance){
	assert(NULL != instance);
	if(NULL == instance)
		return 1;

	if(NULL == instance->_head)
		return 1;

	return 0;
}

/// @}

