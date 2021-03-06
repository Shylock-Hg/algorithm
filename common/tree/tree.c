/*! \brief simple implement of tree structure
 *  \author Shylock Hg
 *  \date 2018-05-09
 *  \email tcath2s@gmail.com
 * */

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "queue.h"
#include "stack.h"

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
	//if(NULL != instance->interpreter)
		//instance->interpreter(node->value);

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

void tree_class_node_release(struct tree * node){
	assert(node);

	free(node->children);
	free(node->value);
	free(node);
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
	assert(NULL != instance);
	if(NULL == instance)
		return 0;

	if(NULL == node)
		return height;

	// uintptr_t * heights = calloc(sizeof(uintptr_t), instance->count_children);
        uintptr_t max = 0;
        uintptr_t child_height = 0;

	for(size_t i=0; i<instance->count_children; i++){
		// heights[i] = _tree_class_height(instance, node->children[i], height+1);
                child_height = _tree_class_height(instance, node->children[i], height+1);
                if (max < child_height) {
                        max = child_height;
                }
	}

	// uintptr_t maxvalue = max(heights, instance->count_children);

	// free(heights);

	// return maxvalue;
        return max;
}

uintptr_t tree_class_height(const struct tree_class * instance){
	if(NULL == instance)
		return 0;

	return _tree_class_height(instance, instance->root, 0);
}

/*! \brief check is difference of subtree heights less than 2
 * */
static bool _tree_class_check_balanced(uintptr_t * heights, size_t count){
	assert(NULL != heights);
	if(NULL == heights)
		return false;

	for(size_t i=1; i<count; i++){
		if((heights[0] ^ heights[i]) > 2)
			return false;
	}

	return true;
}

static uintptr_t _tree_class_is_balanced(const struct tree_class * instance, struct tree * node, 
		uintptr_t height, bool * flag){
	assert(NULL != instance);
	if(NULL == instance)
		return 0;

	if(NULL == node)
		return height;

	uintptr_t * heights = calloc(sizeof(uintptr_t), instance->count_children);

	for(size_t i=0; i<instance->count_children; i++){
		heights[i] = _tree_class_is_balanced(instance, node->children[i], height+1, flag);
	}

	if(! _tree_class_check_balanced(heights, instance->count_children)){
		*flag = false;
	}

	uintptr_t maxvalue = max(heights, instance->count_children);

	free(heights);
	
	return maxvalue;
}

bool tree_class_is_balanced(const struct tree_class * instance){
	assert(NULL != instance);
	if(NULL == instance)
		return false;

	bool flag = true;

	_tree_class_is_balanced(instance, instance->root, 0, &flag);

	return flag;
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

/*! \brief macro select breath first traversal implement
 *         0 for multi-dfs by level , 
 *         1 for queue implement    ,
 *         2 for stack implement
 * */
#define BFS 1

void tree_class_traversal_bfs(const struct tree_class * instance, const uintptr_t level){
	assert(NULL != instance && NULL != instance->root);

	if(NULL == instance || NULL == instance->root)
		return;

#if (0 == BFS)

	uintptr_t height = tree_class_height(instance);

	for(size_t i=level; i<height; i++){
		_tree_class_traversal_bfs(instance, instance->root, i);
	}

#elif (1 ==BFS)  //!< can't specify start level

	//< create and initialize a queue
	struct queue_class * queue = queue_class_new(sizeof(struct tree *));
	queue_class_enqueue(queue, &(instance->root));

	while(! queue_class_is_empty(queue)){
		//< show time for current tree node at head of queue
		struct queue * element = queue_class_dequeue(queue);
		struct tree * node = (struct tree *)(*(struct tree **)(element->value));
		instance->interpreter(node->value);

		//< enqueue childen(if any ...)
		for(size_t i=0; i<instance->count_children; i++){
			if(NULL != node->children[i])
				queue_class_enqueue(queue, &(node->children[i]));
		}

		//< free element
		queue_class_element_release(queue, element);
	}

	//< free queue
	queue_class_release(queue);

#elif (2 == BFS)

	//< create stack
	struct stack_class * p_stack = stack_class_new(sizeof(struct stack *));
	stack_class_push(p_stack, &(instance->root));

	//< breath first traversal by stack
	while(! stack_class_is_empty(p_stack)){
		//< show time for node
		struct stack * element = stack_class_pop(p_stack);
		struct tree * node = (struct tree *)(*(struct tree **)(element->value));
		instance->interpreter(node->value);

		//< push children to stack (if any ...)
		for(size_t i=0; i<instance->count_children; i++){
			if(NULL != node->children[i])
				stack_class_push(p_stack, &(node->children[i]));
		}
	}

	//< free stack
	stack_class_release(p_stack);

#else 

#error "No BFS implement selected!\n"

#endif

}


