/*! \brief a simple implement of binary tree
 *  \author Shylock Hg
 *  \date 2018-05-15
 *  \email tcath2s@gmail.com
 * */

#ifndef _TREE_BIN_H_
#define _TREE_BIN_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include "tree.h"

///! \defgroup tree_bin_prototype
/// @{
typedef struct tree_class tree_class_bin_t;

/*
typedef struct tree {
	void * value;  //!< pointer to value
	struct tree ** children;  //!< array of children pointer
} tree_t;

typedef void (*tree_value_interpreter)(void * value);

typedef struct tree_class {
	struct tree * root;  //!< pointer to tree root
	size_t size_value;  //!< bytes count of tree node value
	size_t count_children;  //!< max count of children
	tree_value_interpreter interpreter;  //!< callback function to interprete value
} tree_class_t;
*/

/// @}

/*  \brief create a tree instance
 *  \param size_value bytes size of value memory
 *  \param count_children max count of children
 *  \retval pointer to tree instance
 * */
#define tree_class_bin_new(size_value, interpreter) tree_class_new(size_value, 2, interpreter)
//struct tree_class * tree_class_new(size_t size_value, size_t count_children, tree_value_interpreter interpreter);

/*  \brief release a tree instance
 *  \param instance instance pointer to a tree
 * */
#define tree_class_bin_release(instance) tree_class_release(instance)
//void tree_class_release(struct tree_class * instance);

/*  \brief create a new tree node 
 *  \param instance instance pointer to tree
 *  \param value pointer to value
 *  \retval pointer to new tree node , NULL for create fail
 * */
#define tree_class_bin_node_new(instance, value) tree_class_node_new(instance, value)
//struct tree * tree_class_node_new(const struct tree_class * instance, const void * value);

/*  \brief release a tree node
 *  \param instance instance pointer to tree
 *  \param node tree node to release
 * */
#define tree_class_bin_node_release(node) tree_class_node_release(node)
//void tree_class_node_release(struct tree_class * instance, struct tree * node);

/*!  \brief get max height of tree
 *   \param instance instance of tree
 *   \retval max height of tree
 * */
#define tree_class_bin_height(instance) tree_class_height(instance)
//uintptr_t tree_class_height(const struct tree_class * instance);

/*  \brief depth first traversal tree by order
 *  \param instance pointer to tree instance
 *  \param order traversal order [0, ...)
 * */
#define tree_class_bin_traversal_dfs(instance, order) tree_class_traversal_dfs(instance, order)
//void tree_class_traversal_dfs(const struct tree_class * instance, const uintptr_t order);

/*  \brief breadth first traversal tree from level
 *  \param instance pointer to tree instance
 *  \param level level start to show tree [0, ...)
 * */
#define tree_class_bin_traversal_bfs(instance, level) tree_class_traversal_bfs(instance, level)
//void tree_class_traversal_bfs(const struct tree_class * instance, const uintptr_t level);


#ifdef __cplusplus
	}
#endif

#endif  //!< _TREE_BIN_H_

