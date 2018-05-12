/*! \brief unit test of tree 
 *  \author Shylock Hg
 *  \date 2018-05-10
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>
#include <assert.h>

#include "tree.h"

void interpreter(void * value){
	assert(NULL != value);
	if(NULL != value)
		printf("%d,", *((int*)value));
}

/*
struct tree * construct_tree(struct tree_class * instance, int index){

	struct tree * root = tree_class_node_new(instance, &index);

	if(0 > index)
		return;
	
	for(size_t i=0; i<instance->count_children; i++){
		construct_tree(instance, root->children[i], index-1);
	}

	return root
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

	root->children[1]->children[0] = tree_class_node_new(instance, &value);
	value++;

	root->children[1]->children[1] = tree_class_node_new(instance, &value);
}

int main(int argc, char * argv[]){
	//< initialize tree to binary tree
	struct tree_class * instance = tree_class_new(sizeof(int), 2, interpreter);
	construct_tree(instance);

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

	tree_class_release(instance);

	return 0;
}
