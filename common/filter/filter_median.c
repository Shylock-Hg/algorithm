/*! \brief simple implement of sliding median filter algorithm
 *  \author Shylock Hg
 *  \date 2018-04-30
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>

#include "filter_median.h"
#include "../sorting/sort_insert.h"

void filter_median(array_t array, size_t start, size_t window){
	//size_t end = (array.len-start-1)%window + start;  //!< end index of window
	if(window < 1)
		return ;

	size_t end = 0;
	if(array.len-start < window){
		end = (array.len-start-1)%window + start;
	}else{
		end = window-1 + start;
	}
	printf("%ld,%ld\n",start,end);
	if(start >= array.len-1)
		return ;

	array_t temp = {array.value+start,end-start+1};
	sort_insert(temp);
	//println_array(temp);
	//println_array(array);
	//printf("%ld\n",(end-start)/2);
	array.value[start] = temp.value[(end-start)/2];
	
	filter_median(array,start+1,window);
}

