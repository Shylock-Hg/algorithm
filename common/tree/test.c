/*! \brief unit test of tree 
 *  \author Shylock Hg
 *  \date 2018-05-10
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>
#include <assert.h>

#include "tree.h"
#include "queue.h"

void interpreter(void * value){
	assert(NULL != value);
	if(NULL != value)
		printf("%d,", *((int*)value));
}

/*! \brief construct tree by bfs 
 *  \param instance instance of uninitialized tree
 *  \param count of tree nodes
 *  \note only for int type value (this implement)
 * */
/*
void construct_tree(struct tree_class * instance, const int count){
	assert(NULL != instance && NULL == instance->root);
	if(NULL == instance || NULL != instance->root)
		return ;

	//< create tree root
	int index = 0;
	instance->root = tree_class_node_new(instance, &index);
	
	//< construct queue 
	struct queue_class * p_queue = queue_class_new(sizeof(struct tree *));

	queue_class_enqueue(p_queue, &(instance->root));

	//< construct tree
	while(! queue_class_is_empty(p_queue) && index < count){
		struct queue * element = queue_class_dequeue(p_queue);
		struct tree  * node    = *(struct tree **)(element->value);
		
		for(size_t i=0; i<instance->count_children; i++){
			if(NULL == node->children[i]){
				index++;
				//printf("create : %d,  ", index);
				node->children[i] = tree_class_node_new(instance, &index);
				queue_class_enqueue(p_queue, &(node->children[i]));
			}
		}
	}

	//printf("\n");
}
*/

void construct_tree(struct tree_class * instance){
	int value = 0;

	instance->root = tree_class_node_new(instance, &value);
	value++;

	struct tree * root = instance->root;

	root->children[0] = tree_class_node_new(instance, &value);
	value++;

	root->children[1] = tree_class_node_new(instance, &value);
	value++;

	root->children[0]->children[0] = tree_class_node_new(instance, &value);
	value++;

	root->children[0]->children[1] = tree_class_node_new(instance, &value);
	value++;

	root->children[0]->children[0]->children[0] = tree_class_node_new(instance, &value);
	value++;

	root->children[0]->children[0]->children[1] = tree_class_node_new(instance, &value);
	value++;

	/*
	root->children[1]->children[0] = tree_class_node_new(instance, &value);
	value++;

	root->children[1]->children[1] = tree_class_node_new(instance, &value);
	*/
}

int main(int argc, char * argv[]){
	//< initialize tree to binary tree
	struct tree_class * instance = tree_class_new(sizeof(int), 2, interpreter);
	construct_tree(instance);
	//construct_tree(instance, 15);

	//< traversal tree
	printf("pre-order dfs:");
	tree_class_traversal_dfs(instance, 0);
	printf("\n");

	printf("post-order dfs:");
	tree_class_traversal_dfs(instance, instance->count_children);
	printf("\n");

	printf("bfs 0:");
	tree_class_traversal_bfs(instance, 0);
	printf("\n");

	printf("bfs 1:");
	tree_class_traversal_bfs(instance, 1);
	printf("\n");

	printf("bfs 2:");
	tree_class_traversal_bfs(instance, 2);
	printf("\n");

	printf("height of tree:%ld\n",tree_class_height(instance));

	if(tree_class_is_balanced(instance))
		printf("balanced tree!\n");
	else 
		printf("unbalanced tree!\n");

	printf("release tree by :");
	tree_class_release(instance);

	return 0;
}

