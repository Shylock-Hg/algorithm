#include "sort_insert.h"

#include "sort_select.h"

#include <stdio.h>

#define println_array(array,len)  do{\
		for(size_t _i = 0; _i < len; _i++){\
			printf("%d,",array[_i]);\
		}\
		printf("\n");\
	}while(0);

//! data to sorting 
int array0[] = {0,1,22,22,3,5,2,99,10000,32,0,32,566,66,66,66,22,33,11,435,657,745,73254,747,467,342,462,21,1346};

int main(int argc, char * argv[]){

	printf("origin:\n");
	println_array(array0,sizeof(array0)/sizeof(array0[0]));
	
	//sort_insert(array0,sizeof(array0)/sizeof(array0[0]));
	sort_select(array0,sizeof(array0)/sizeof(array0[0]));
	
	printf("sorted:\n");
	println_array(array0,sizeof(array0)/sizeof(array0[0]));
	return 0;
}
