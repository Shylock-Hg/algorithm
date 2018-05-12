/*! \brief simple implement of tree structure
 *  \author Shylock Hg
 *  \date 2018-05-09
 *  \email tcath2s@gmail.com
 * */

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"


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

struct tree_class * tree_class_new(size_t size_value, size_t count_children, tree_value_interpreter interpreter){
	//< create and initialize tree instance
	struct tree_class * instance = malloc(sizeof(struct tree_class));
	instance->root = NULL;
	instance->size_value = size_value;
	instance->count_children = count_children;
	instance->interpreter = interpreter;

	return instance;
}

/*  \brief query a does a father has chrilden
 *  \param instance instance pointer of tree class
 *  \param father the father want to know his chrildren
 *  \param the first valide child pointer , NULL for no valid children
 * */
static struct tree * tree_valide_child(struct tree_class * instance, struct tree * father){
	assert(NULL != instance);

	if(NULL == instance)
		return NULL;

	for(size_t i=0; i<instance->count_children; i++){
		if(NULL != father->children[i])
			return father->children[i];
	}

	return NULL;
}

/*  \brief release a tree from root by post order [leaf to root]
 *  \param instance instance pointer of tree 
 *  \param father the father of node being to release
 *  \param node the tree node being to release
 *  \param rank rank of tree node in chrildren of father
 * */
static void tree_release_post(struct tree_class * instance, struct tree * node){
	assert(NULL != instance);

	if(NULL == node || NULL == instance)
		return ;

	for(size_t i=0; i<instance->count_children; i++){
		tree_release_post(instance, node->children[i]);
	}

	//< release leaf node
	/*
	if(NULL == tree_valide_child(instance, node)){
		//< show time before death
		instance->interpreter(node->value);

		//< don't have chilren 
		free(node->value);
		free(node);

		//< tell death msg to his father(if any...)
		if(NULL != father)
			father->children[rank] = NULL;
	}
	*/

	//< show time before death
	if(NULL != instance->interpreter)
		instance->interpreter(node->value);

	//< don't have chilren 
	free(node->value);
	free(node->children);
	free(node);

}

/*  \brief release tree structure by pre order [root to leaf]
 *  \param instance instance pointer to tree class
 *  \param node node to being release
 * */
/*
void tree_release_pre(struct tree_class * instance, struct tree * node){
	if(NULL == node)
		return ;
	
	//< record children
	struct tree ** children = node->children;

	//< show time before death
	instance->interpreter(node->value);

	//< release node
	free(node->value);
	free(node);

	for(size_t i=0; i<instance->count_children; i++){
		tree_release_pre(instance, children[i]);
	}
}
*/

void tree_class_release(struct tree_class * instance){
	assert(NULL !=instance || NULL != instance->root);

	if(NULL == instance || NULL == instance->root)  //!< null tree
		return ;

	//< release tree structure
	//< root have no father
	tree_release_post(instance, instance->root);
	instance->root = NULL;

	//< release tree handle
	free(instance);
}

struct tree * tree_class_node_new(const struct tree_class * instance, const void * value){
	assert(NULL != value);

	if(NULL == instance || NULL == value)
		return NULL;

	struct tree * node = malloc(sizeof(struct tree));

	node->children = calloc(sizeof(struct tree *),instance->count_children);

	node->value = malloc(instance->size_value);
	memcpy(node->value, value, instance->size_value);

	return node;
}

static uintptr_t max(uintptr_t array[], size_t length){
	uintptr_t maxvalue = 0;
	for(size_t i=0; i<length; i++){
		if(maxvalue < array[i]){
			maxvalue = array[i];
		}
	}

	return maxvalue;
}

uintptr_t _tree_class_height(const struct tree_class * instance, struct tree * node, uintptr_t height){
	if(NULL == node)
		return height;

	uintptr_t * heights = calloc(sizeof(uintptr_t), instance->count_children);

	for(size_t i=0; i<instance->count_children; i++){
		heights[i] = _tree_class_height(instance, node->children[i], height+1);
	}

	uintptr_t maxvalue = max(heights, instance->count_children);

	free(heights);

	return maxvalue;
}

uintptr_t tree_class_height(const struct tree_class * instance){
	if(NULL == instance)
		return 0;

	return _tree_class_height(instance, instance->root, 0);
}

/*
void tree_class_node_release(struct tree_class * instance, struct tree * node){
	free(node->value
}
*/

static void _tree_class_traversal_dfs(const struct tree_class * instance, const struct tree * node, const uintptr_t order){
	assert(NULL != instance);

	if(NULL == node || NULL == instance)
		return;

	size_t i = 0;
	for(; i<instance->count_children; i++){
		if(i == order && NULL != instance->interpreter)
			instance->interpreter(node->value);

		_tree_class_traversal_dfs(instance, node->children[i], order);
	}

	if(i == order && NULL != instance->interpreter)
		instance->interpreter(node->value);
}

void tree_class_traversal_dfs(const struct tree_class * instance, const uintptr_t order){
	assert(NULL != instance);

	if(NULL == instance)
		return ;

	if(order > instance->count_children)
		return;

	_tree_class_traversal_dfs(instance, instance->root, order);
}

static void _tree_class_traversal_bfs(const struct tree_class * instance, const struct tree * node, const uintptr_t level){
	assert(NULL != instance);

	if(NULL == node || NULL == instance)
		return;

	if(0 == level && NULL != instance->interpreter)
		instance->interpreter(node->value);

	for(size_t i=0; i<instance->count_children; i++){
		_tree_class_traversal_bfs(instance, node->children[i], level-1);
	}
}

void tree_class_traversal_bfs(const struct tree_class * instance, const uintptr_t level){
	assert(NULL != instance);

	if(NULL == instance)
		return;

	uintptr_t height = tree_class_height(instance);

	for(size_t i=level; i<height; i++){
		_tree_class_traversal_bfs(instance, instance->root, i);
	}
}

