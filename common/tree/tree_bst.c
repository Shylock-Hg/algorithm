/*! \brief a simple implement of binary search tree 
 *  \author Shylock Hg
 *  \date 2018-06-21
 *  \email tcath2s@gmail.com
 * */

#include <assert.h>
#include <string.h>

#include "tree_bst.h"

#define compare_less(a, b)  (*(int*)(a) < *(int*)(b))
#define compare_more(a, b)  (*(int*)(a) > *(int*)(b))
#define compare_equal(a, b) (*(int*)(a) == *(int*)(b))

tree_t * tree_class_bst_min(tree_t * root){
	assert(root);

	tree_t * node = root;
	while(node->children[0]){

		node = node->children[0];
	}

	return node;
}

tree_t * tree_class_bst_max(tree_t * root){
	assert(root);

	tree_t * node = root;
	while(node->children[1]){
	
		node = node->children[1];
	}
	
	return node;
}

static tree_t * _tree_class_bst_insert(tree_class_bst_t * bst, tree_t * root, void * value){
	assert(bst);
	assert(value);

	if(NULL == root){
		//bst->interpreter(value);
		return tree_class_bin_node_new(bst, value);
	}

	if(compare_less(value, root->value))
		root->children[0] = _tree_class_bst_insert(bst, root->children[0], value);
	else
		root->children[1] = _tree_class_bst_insert(bst, root->children[1], value);

	return root;
}

void tree_class_bst_insert(tree_class_bst_t * bst, void * value){
	assert(bst);
	assert(value);

	if(NULL == bst->root)
		bst->root = _tree_class_bst_insert(bst, bst->root, value);
	else
		_tree_class_bst_insert(bst, bst->root, value);
}

static tree_t * _tree_class_bst_delete(tree_class_bst_t * bst, tree_t * root, void * value){
	assert(bst);
	assert(value);

	if(NULL == root)
		return root;

	if(compare_less(value, root->value)){
		root->children[0] = _tree_class_bst_delete(bst, root->children[0], value);
	}else if(compare_more(value, root->value)){
		root->children[1] = _tree_class_bst_delete(bst, root->children[1], value);
	}else{  //!< search the value
		if(NULL == root->children[0]){
			tree_t * temp = root->children[1];
			tree_class_bin_node_release(root);
			return temp;
		}else if(NULL == root->children[1]){
			tree_t * temp = root->children[0];
			tree_class_bin_node_release(root);
			return temp;
		}else{
			tree_t * min = tree_class_bst_min(root->children[1]);
			memcpy(root->value, min->value, bst->size_value);
			root->children[1] = _tree_class_bst_delete(bst, root->children[1], min->value);
		}
	}

	return root;
}

void tree_class_bst_delete(tree_class_bst_t * bst, void * value){
	assert(bst);
	assert(value);
	
	_tree_class_bst_delete(bst, bst->root, value);
}

static tree_t * _tree_class_bst_search(tree_class_bst_t * bst, tree_t * root, void * value){
	assert(bst);
	assert(value);

	if(NULL == root || compare_equal(value, root->value))
		return root;

	if(compare_less(value, root->value)){
		return _tree_class_bst_search(bst, root->children[0], value);
	}else{
		return _tree_class_bst_search(bst, root->children[1], value);
	}
}

tree_t * tree_class_bst_search(tree_class_bst_t * bst, void * value){
	assert(bst);
	assert(value);

	return _tree_class_bst_search(bst, bst->root, value);
}

