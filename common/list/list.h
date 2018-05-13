/*! \brief a simple implement of ADT list
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#ifndef _LIST_H_
#define _LIST_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stddef.h>

///! \defgroup list_prototype
/// @{
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
/// @}


///! \defgroup list_interface
/// @{
//

/*! \brief create a list instance
 *  \param size_value size(bytes) of value
 *  \retval created instance pointer , NULL for fail
 * */
struct list_class * list_class_new(size_t size_value);

/*! \brief create a element of list by value
 *  \param instance instance of list 
 *  \param value value pointer
 *  \retval created list element pointer, NULL for fail
 * */
struct list * list_class_element_new(const struct list_class * instance, void * value);

/*! \brief release list instance
 *  \param instance instance of list
 * */
void list_class_release(struct list_class * instance);

/*! \brief release element of list
 *  \param instance instance of list
 *  \param element element poitner to release
 * */
void list_class_element_release(const struct list_class * instance, struct list * element);

/*! \brief get element of list by index
 *  \param instance instance of list
 *  \param index index of element query
 *  \retval query element pointer, NULL for fail
 * */
struct list * list_class_get_at(const struct list_class * instance, size_t index);

/*! \brief insert value to list at specify index
 *  \param instance instance of list
 *  \param index index to insert 
 *  \param element element to insert
 *  \retval 0 for ok ; -1 for fail
 * */
//int list_class_insert_at(struct list_class * instance, size_t index, void * value);
int list_class_insert_at(struct list_class * instance, size_t index, struct list * element);

/* \brief remove element at specify index
 * \param instance instance of list
 * \param index index to remove
 * \retval 0 for ok ; -1 for fail
 * */
int list_class_remove_at(struct list_class * instance, size_t index);

/*! \brief remove the value first occurrence
 *  \param instance instance of list
 *  \param value value to search
 *  \retval 0 for ok ; -1 for fail
 * */
int list_class_remove_value(struct list_class * instance, const void * value);

/*! \brief replace element at specify index
 *  \param instance instance of list
 *  \param index index to replace
 *  \param src element replace to 
 *  \retval 0 for ok ; -1 for fail
 * */
int list_class_replace_at(struct list_class * instance, size_t index, struct list * src);

/*! \brief get count of elements in list
 *  \param instance instance of list
 *  \retval count of elements in list
 * */
size_t list_class_count(const struct list_class * instance);

/*! \brief check is list empty 
 *  \param instance instance of list
 *  \retval bool 0 for not empty ; 1 for empty
 * */
int list_class_is_empty(const struct list_class * instance);

/// @}

#ifdef __cplusplus
	}
#endif

#endif  //!< _LIST_H_

