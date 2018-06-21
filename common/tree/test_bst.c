/*! \brief base test of binary search tree
 *  \author Shylock Hg
 *  \date 2018-06-21
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>
#include <assert.h>

#include "tree_bst.h"
#include "tree_bin.h"


void interpreter(void * value){
	assert(NULL != value);
	if(NULL != value)
		printf("%d,", *((int*)value));
}

int array[] = {1,2,3,4,5,-1,0,3,-11,-233,23,56,-34,0};

int main(int argc, char * argv[]){
	tree_class_bst_t * bst = tree_class_bin_new(sizeof(int), interpreter);

	for(int i=0; i<sizeof(array)/sizeof(array[0]); i++){
		tree_class_bst_insert(bst, array+i);
	}

	tree_class_bin_traversal_bfs(bst, 0);
	//tree_class_bin_traversal_dfs(bst, 0);

	putchar('\n');

	tree_t * node = tree_class_bst_search(bst, array+0);
	if(node)
		interpreter(node->value);

	tree_class_bst_delete(bst, array+0);

	node = tree_class_bst_search(bst, array+0);
	if(node)
		interpreter(node->value);

	putchar('\n');

	tree_class_bin_traversal_bfs(bst, 0);

	tree_class_bin_release(bst);

	return 0;
}

