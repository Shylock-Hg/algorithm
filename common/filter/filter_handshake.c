/*! \brief simple implement of handshake filter
 *  \author Shylock Hg
 *  \date 2018-05-02
 *  \email tcath2s@gmail.com
 * */

#include <stddef.h>
#include "../sorting/sort_common.h"

void filter_handshake(array_t array, size_t start, size_t window, int limit){
	if(0 >= limit)
		return ;

	if(array.len-1 == start)  //!< end of recursive
		return ;

	if(array.len-window < start)
		window = array.len-start;

	static int counter = 0;
	int value = array.value[start];
	for(size_t i=0; i<window; i++){
		if(value == array.value[start+i]){
			counter = 0;
		}else{
			counter ++;
			if(counter > limit){
				value = array.value[start+i];
				counter = 0;
			}
				
		}
	}

	array.value[start] = value;

	filter_handshake(array, start+1, window, limit);
}

