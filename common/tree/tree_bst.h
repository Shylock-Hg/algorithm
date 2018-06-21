/*! \brief a simple implement of binary search tree
 *  \author Shylock Hg
 *  \date 2018-06-21
 *  \email tcath2s@gmail.com
 * */

#ifndef _TREE_BST_H_
#define _TREE_BST_H_

#ifdef __cplusplus
	extern "C" {
#endif


/******************** inherit all method of binary tree ********************/
#include "tree_bin.h"
typedef tree_class_bin_t tree_class_bst_t;

/******************** extended method of binary search tree ********************/

/*! \brief get the minimal value of binary search tree
 *  \param bst binary search tree
 *  \retval minimal value tree node pointer
 * */
tree_t * tree_class_bst_min(tree_t * root);

/*! \brief get the maximum value of binary search tree
 *  \param bst binary search tree
 *  \retval maximum value tree node pointer
 * */
tree_t * tree_class_bst_max(tree_t * root);

/*! \brief insert a value to binary search tree
 *  \param bst binary search tree
 *  \param value value to insert
 * */
void tree_class_bst_insert(tree_class_bst_t * bst, void * value);

/*! \brief delete a value from binary search tree
 *  \param bst binary search tree
 *  \param value value to delete
 * */
void tree_class_bst_delete(tree_class_bst_t * bst, void * value);

/*! \brief search a value from binary serach tree
 *  \param bst binary search tree
 *  \param value value to search
 * */
tree_t * tree_class_bst_search(tree_class_bst_t * bst, void * value);

#ifdef __cplusplus
	}
#endif

#endif  //!< _TREE_BST_H_

