/*! \brief simple implement of first-order lag filter algorithm
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#include "../sorting/sort_common.h"

void filter_first_order_lag(array_t array, float k){
	for(size_t i=0; i<array.len; i++){
		array.value[i] = k * array.value[i] + (1 - k) * array.value[i-1];
	}
}

