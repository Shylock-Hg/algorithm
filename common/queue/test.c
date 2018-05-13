/*! \brief simple unit test of queue interface
 *  \author Shylock Hg
 *  \date 2018-05-12
 *  \email tcath2s@gmail.com
 * */

#include <stdio.h>

#include "queue.h"


int main(int argc, char * argv[]){
	struct queue_class * instance = queue_class_new(sizeof(int));
	for(int i=0; i<15; i++){
		queue_class_enqueue(instance, &i);
		struct queue * element = queue_class_dequeue(instance);
		//printf("%p,", element);
		if(NULL != element){
			printf("%d,", *((int*)element->value));
			queue_class_element_release(instance, element);
		}
	}

	//printf("%p,%p\n", instance->_head, instance->_tail);
	//printf("%d,%d\n", *(int*)(instance->_head->value), *(int*)(instance->_tail->value));

	printf("count=`%ld`\n", queue_class_count(instance));
	printf("empty=`%d`\n", queue_class_is_empty(instance));

	for(int i=0; i<17; i++){
		struct queue * element = queue_class_dequeue(instance);
		//printf("%p,", element);
		if(NULL != element){
			printf("%d,", *((int*)element->value));
			queue_class_element_release(instance, element);
		}
	}
	printf("\n");

	printf("%p,%p\n", instance->_head, instance->_tail);


	printf("count=`%ld`\n", queue_class_count(instance));
	printf("empty=`%d`\n", queue_class_is_empty(instance));

	for(int i=0; i<17; i++){
		struct queue * element = queue_class_peek(instance);
		if(NULL != element)
			printf("%d,", *((int*)(element->value)));
	}
	printf("\n");


	queue_class_release(instance);

	return 0;
}

