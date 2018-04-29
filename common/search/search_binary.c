/*! \brief simple implement of binary search algorithm
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>

int search_binary(int array[], size_t start, size_t end, int x){
	if(start == end){
		if(array[start] == x)
			return start;
		else
			return -1;
	}

	size_t mid = (end-start)/2+start;

	//< ascending
	if(x <= array[mid]){
		return search_binary(array,start,mid,x);
	}else{
		return search_binary(array,mid+1,end,x);
	}
}

