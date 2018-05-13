/*! \brief simple test of ADT list
 *  \author Shylock Hg
 *  \date 2018-05-13
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>

#include "list.h"

int main(int argc, char * argv[]){
	struct list_class * instance = list_class_new(sizeof(int));

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	printf("insert retval : ");
	for(int i=0; i<15; i++){
		struct list * ele = list_class_element_new(instance, &i);
		int ret = list_class_insert_at(instance, i, ele);
		printf("%d,", ret);
	}
	printf("\n");

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	printf("get value : ");
	for(int i=0; i<17; i++){
		struct list * ele = list_class_get_at(instance, i);
		if(NULL != ele)
			printf("%d,", *(int*)(ele->value));
	}
	printf("\n");

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	printf("replace retval : ");
	for(int i=0; i<17; i++){
		struct list * ele = list_class_element_new(instance, &i);
		int ret = list_class_replace_at(instance, i, ele);
		printf("%d,", ret);
		//list_class_element_release(instance, ele);
	}
	printf("\n");

	printf("get value : ");
	for(int i=0; i<17; i++){
		struct list * ele = list_class_get_at(instance, i);
		if(NULL != ele)
			printf("%d,", *(int*)(ele->value));
	}
	printf("\n");

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	printf("remove at retval : ");
	for(int i=0; i<17; i++){
		int ret = list_class_remove_at(instance,0);
		printf("%d,", ret);
		//list_class_element_release(instance, ele);
	}
	printf("\n");

	printf("get value : ");
	for(int i=0; i<17; i++){
		struct list * ele = list_class_get_at(instance, i);
		if(NULL != ele)
			printf("%d,", *(int*)(ele->value));
	}
	printf("\n");

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	printf("remove value retval : ");
	for(int i=0; i<17; i++){
		int ret = list_class_remove_value(instance,&i);
		printf("%d,", ret);
		//list_class_element_release(instance, ele);
	}
	printf("\n");

	printf("is empty = `%d`\n",list_class_is_empty(instance));
	printf("count = `%ld`\n", list_class_count(instance));

	list_class_release(instance);
	
	return 0;
}

