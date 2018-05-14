/*! \brief simple implement of heap sort algorithm
 *  \author Shylock Hg
 *  \date 2018-04-24
 *  \email tcath2s@gmail.com
 * */

#include <assert.h>

#include "sort_common.h"

/*  \brief to heapify a subtree to max(min) heap
 *  \param array array to sorted
 *  \param len length of sub-heap
 *  \param root root of sub-heap
 * */
static void heapify(array_t array,int root,int len){
	int largest = root;
	int lc = 2*root+1;  //(root<<2) + 1;  //2*root + 1;
	int rc = 2*root+2;  //(root<<2) + 2;  //2*root + 2;

	//< compare left child
	if(lc<len && array.value[lc]>array.value[largest])
		largest = lc;
	//< compare right child
	if(rc<len && array.value[rc]>array.value[largest])
		largest = rc;

	//< if largest is not the root
	if(largest != root){
		swap_item(array.value+root,array.value+largest);
		heapify(array,largest,len);
	}
}

void sort_heap(array_t array){
	assert(NULL != array.value && 0 != array.len);
	if(NULL == array.value || 0 == array.len)
		return ;

	//< build heap (apply headify to last nonleaf node)
	for(int i=array.len/2-1; i>=0; i--){
		heapify(array,i,array.len);  //!< heapify heap[i,array.len)
	}

	//< sort by select root and re-headify from root
	for(int i=array.len-1; i>=0; i--){
		//< select root to sorted partion
		swap_item(array.value+0,array.value+i);

		//< re-headify heap[0-i)
		heapify(array,0,i);
	}
}

