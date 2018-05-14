/*! \brief simple implement of linear seach
 *  \author Shylock Hg
 *  \date 2018-04-25
 *  \email tcath2s@gmail.com
 * */

#include <assert.h>

#include "../sorting/sort_common.h"

int search_linear(array_t array,int x){
	assert(NULL != array.value && 0 != array.len);
	if(NULL == array.value || 0 == array.len)
		return -1;

	for(size_t i=0; i<array.len; i++){
		if(array.value[i] == x)
			return i;
	}

	return -1;
}
