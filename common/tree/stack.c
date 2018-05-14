/*! \brief simple implement of ADT stack
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#define NDEBUG

#include <assert.h>
#include <stddef.h>

#include "stack.h"

/*
typedef struct stack {
	void * value;
	struct stack * _pre;
	struct stack * _next;
} stack_t;

typedef struct stack_class {
	struct stack * _head;  //!< head pointer
	struct stack * _tail;  //!< tail pointer
	size_t size_value;  //!< size(bytes) of value
} stack_class_t;
*/

/*! \brief pop a element from stack
 *  \param instance instance of stack
 *  \retval pop element , must release manually when not use
 * */
struct stack * stack_class_pop(struct stack_class * instance){
	assert(NULL != instance && NULL != instance->_tail);
	if(NULL == instance || NULL == instance->_tail)
		return NULL;

	struct stack * ret = stack_class_element_new(instance, instance->_tail->value);

	assert(NULL != ret);
	if(NULL == ret)
		return NULL;

	struct stack * pre = instance->_tail->_pre;
	
	stack_class_element_release(instance, instance->_tail);

	instance->_tail = pre;
	if(NULL != instance->_tail)
		instance->_tail->_next = NULL;
	else 
		instance->_head = NULL;

	return ret;
}

/* \brief get a element but not remove from stack
 * \param instance instance of stack
 * \retval element , not release manually
 * */
struct stack * stack_class_peek(struct stack_class * instance){
	assert(NULL != instance && NULL != instance->_tail);
	if(NULL == instance || NULL == instance->_tail)
		return NULL;
	
	return instance->_tail;
}

