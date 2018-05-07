/*! \brief simple implement of jump search algorithm
 *  \author Shylock Hg
 *  \date 2018-05-07
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>
#include <math.h>

#include "../sorting/sort_common.h"

#define min(a,b) (a<b ? a : b)

int search_jump(array_t array, int x){
	//< best size of block to jump
	const size_t step = sqrt(array.len);

	//< finding the block where element is present (if present)
	int pre = 0;
	size_t temp = step;
	while(array.value[min(temp,array.len-1)] < x){
		pre = temp;
		temp += step;

		if(pre >= array.len)
			return -1;
	}

	//< doing linear search in block [ pre,min(temp,array.len) )
	while(array.value[pre] < x){
		pre++;
		if(pre == min(temp,array.len))
			return -1;
	}

	//< check element value
	if(array.value[pre] == x)
		return pre;
	else 
		return -1;
}

