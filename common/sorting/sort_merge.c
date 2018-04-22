/*! \brief  simple merge sort algorithm implement
 *  \author Shylock Hg
 *  \date 2018-04-20
 *  \email tcath2s@gmail.com
 * */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort_common.h"

static void merge(array_t array, size_t i_start, size_t i_mid, size_t i_end){
	static int * temp = NULL;
	if(NULL == temp){  //!< alloc once
		temp = calloc(array.len,sizeof(int));
	}

	size_t i_left = i_start;
	size_t i_right = i_mid;
	size_t i_temp = i_start;

	//< merge and sort two sub-array to temp
	//< sub[i_start,i_mid), sub[i_mid,i_end) --> partion[i_start,i_end)
	while(i_left < i_mid || i_right < i_end){  
		if(i_left == i_mid){
			temp[i_temp] = array.value[i_right];
			i_right++;
		}else if(i_right == i_end){
			temp[i_temp] = array.value[i_left];
			i_left++;
		}else if(array.value[i_left] < array.value[i_right]){
			temp[i_temp] = array.value[i_left];
			i_left++;
		}else{
			temp[i_temp] = array.value[i_right];
			i_right++;
		}
		i_temp++;
	}

	//< update origin partion-array[i_start,i_end)
	for(i_temp=i_start; i_temp<i_end; i_temp++){  
		array.value[i_temp] = temp[i_temp];
	}
	//memcpy(array.value+i_start,temp+i_start,i_end-i_start); error for bytes order
}

static void sort_merge_origin(array_t array, size_t i_start, size_t i_end){
	if(i_start < i_end-1){  //!< divide to one element
		int i_mid = i_start + (i_end - i_start)/2;  //!< divide array
		sort_merge_origin(array,i_start,i_mid);
		sort_merge_origin(array,i_mid,i_end);

		merge(array,i_start,i_mid,i_end);
	}
}

void sort_merge(array_t array){
	sort_merge_origin(array,0,array.len);
}

