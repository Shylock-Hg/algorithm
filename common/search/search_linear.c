/*! \brief simple implement of linear seach
 *  \author Shylock Hg
 *  \date 2018-04-25
 *  \email tcath2s@gmail.com
 * */

#include "../sorting/sort_common.h"

int search_linear(array_t array,int x){
	for(size_t i=0; i<array.len; i++){
		if(array.value[i] == x)
			return i;
	}

	return -1;
}
