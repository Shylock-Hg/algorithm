/*! \brief simple implement of limit filter algorithm
 *  \author Shylock Hg
 *  \date 2018-04-29
 *  \email tcath2s@gmail.com
 * */

#include <stdint.h>
#include <stdlib.h>

#include "../sorting/sort_common.h"

void filter_limit(array_t array, uint32_t limit){
	for(size_t i=0; i<array.len; i++){
		if(limit < abs(array.value[i]-array.value[i-1]))
			array.value[i] = array.value[i-1];
	}
}

