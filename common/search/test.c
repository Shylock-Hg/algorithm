/*! \brief unit test of search algorithm
 *  \author Shylock Hg
 *  \date 2018-04-25
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>

#include "search_linear.h"
#include "search_binary.h"

int buf0[] = {-1,22,33,22,33,446,4463,22222,2354,2345,23,2342,2342,24532,-1,-444,32,-1,-324,111,234,-444};

int buf1[] = {-55,-44,-33,-22,-11,1,2,3,4,5,6,7,8,33,33,44,45,66,777,8888,99999};

int main(int argc, char * argv[]){
	printf("[info]:test search algorithm!\n");
	array_t array_unsorted = {buf0,sizeof(buf0)/sizeof(buf0[0])};
	array_t array_sorted   = {buf1,sizeof(buf1)/sizeof(buf1[0])};

	int ret = search_linear(array_unsorted,22222);
	if(-1 == ret){
		printf("[warn]:not find!\n");
	}else{
		printf("[info]:find in index `%d` \n",ret);
	}

	ret = search_binary(array_sorted.value,0,array_sorted.len-1,5);
	if(-1 == ret){
		printf("[warn]:not find!\n");
	}else{
		printf("[info]:find in index `%d` \n",ret);
	}
	
	return 0;
}

