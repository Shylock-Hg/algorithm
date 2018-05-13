/*! \brief a simple test of ADT stack
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>

#include "stack.h"

int main(int argc, char * argv[]){
	struct stack_class * instance = stack_class_new(sizeof(int));

	printf("is empty = `%d`\n",stack_class_is_empty(instance));
	printf("count = `%ld`\n", stack_class_count(instance));

	for(int i=0; i<15; i++){
		stack_class_push(instance, &i);
	}

	printf("is empty = `%d`\n",stack_class_is_empty(instance));
	printf("count = `%ld`\n", stack_class_count(instance));

	for(int i=0; i<17; i++){
		struct stack * ele = stack_class_peek(instance);
		if(NULL != ele)
			printf("%d,", *(int*)(ele->value));
	}
	printf("\n");

	printf("is empty = `%d`\n",stack_class_is_empty(instance));
	printf("count = `%ld`\n", stack_class_count(instance));

	for(int i=0; i<17; i++){
		struct stack * ele = stack_class_pop(instance);
		if(NULL != ele){
			printf("%d,", *(int*)(ele->value));
			stack_class_element_release(instance, ele);
		}
	}
	printf("\n");

	printf("is empty = `%d`\n",stack_class_is_empty(instance));
	printf("count = `%ld`\n", stack_class_count(instance));

	stack_class_release(instance);

	return 0;
}

