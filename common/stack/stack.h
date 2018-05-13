/*! \brief a simple implement of ADT stack
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>

///! \defgroup stack_prototype
/// @{
#include "queue.h"

#define stack queue
typedef queue_t stack_t;

#define stack_class queue_class
typedef queue_class_t stack_class_t;

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
/// @}


///! \defgroup stack_interface
/// @{

/*! \brief create a stack instance
 *  \param size_value size(bytes) of value
 *  \retval instance of stack
 * */
//struct stack_class * stack_class_new(size_t size_value);
#define stack_class_new queue_class_new

/*! \brief create a stack element
 *  \param instance instance of stack
 *  \param value value pointer of element
 * */
//struct stack * stack_class_element_new(const struct stack_class * instance, void * value);
#define stack_class_element_new queue_class_element_new

/*! \brief release a stack
 *  \param instance instance of stack
 * */
//void stack_class_release(struct stack_class * instance);
#define stack_class_release queue_class_release

/*! \brief release a element of stack
 *  \param instance instance of stack 
 *  \param element pointer to element to release
 * */
//void stack_class_element_release(const struct stack_class * instance, struct stack * element);
#define stack_class_element_release queue_class_element_release

/*! \brief push a element to stack 
 *  \param instance instance of stack
 *  \param value value pointer to push
 * */
//void stack_class_push(struct stack_class * instance, void * value);
#define stack_class_push queue_class_enqueue

/*! \brief pop a element from stack
 *  \param instance instance of stack
 *  \retval pop element , must release manually when not use
 *          NULL for empty stack
 * */
struct stack * stack_class_pop(struct stack_class * instance);

/* \brief get a element but not remove from stack
 * \param instance instance of stack
 * \retval element , not release manually
 * */
struct stack * stack_class_peek(struct stack_class * instance);

/*! \brief get count of elements in stack
 *  \param instance instance of stack
 *  \retval count of elmenets in stack
 * */
//size_t stack_class_count(struct stack_class * instance);
#define stack_class_count queue_class_count

/*! \brief check stack is empty
 *  \param instance instance of stack
 *  \retval bool 0 for not empty,1 for empty
 * */
//int stack_class_is_empty(struct stack_class * instance);
#define stack_class_is_empty queue_class_is_empty

/// @}

#ifdef __cplusplus
	}
#endif

#endif  //!< _STACK_H_

