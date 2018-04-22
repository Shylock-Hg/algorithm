#include "sort_insert.h"
#include "sort_select.h"
#include "sort_merge.h"
#include "sort_quick.h"

#include <stdio.h>

#define println_array(array)  do{\
		for(size_t _i = 0; _i < array.len; _i++){\
			printf("%d,",array.value[_i]);\
		}\
		printf("\n");\
	}while(0);

//! data to sorting 
int array0[] = {0,1,-22,22,3,5,2,99,-10000,32,0,-32,566,66,66,66,22,-33,11,435,657,-745,73254,747,467,342,-462,21,-1346};

array_t array = {array0+0,sizeof(array0)/sizeof(array0[0])};

int main(int argc, char * argv[]){
	printf("origin:\n");
	println_array(array);
	
	sort_insert(array);
	//sort_select(array);
	//sort_merge(array);
	//sort_quick(array);
	
	printf("sorted:\n");
	println_array(array);
	return 0;
}

