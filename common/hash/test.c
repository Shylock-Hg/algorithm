/*! \brief test hash module
 *  \author Shylock Hg
 *  \date 2018-04-16
 *  \email tcath2s@gmail.com
 * */

#include "hash.h"
#include <stdio.h>
#include <string.h>

#define HASH_TAB_SIZE 2

int main(int argc, char * argv[]){
	char key[200] = {0};
	char value[200] = {0};
	struct hash_class * instance = hash_new(HASH_TAB_SIZE);

	for(int i=0; i<5; i++){
		printf("[info]:please input key string :\n");
		scanf("%s",key);
		printf("[info]:please input value string :\n");
		scanf("%s",value);
		hash_insert(instance,key,value,strlen(value)+1);
	}

	int i = 4;

	while(i--){
		printf("[info]:please input key string to lookup :\n");
		scanf("%s",key);
		struct hash * item = hash_lookup(instance,key);
		if(NULL != item){
			printf("[info]:lookup key=`%s`,value=`%s`\n",item->key,(char*)(item->value));
		}else{
			printf("[err]:lookup fail!\n");
		}

		printf("[info]:please input key string to delete :\n");
		scanf("%s",key);
		hash_delete(instance,key);
		
		//hash_release(instance);
		//instance = NULL;
	}

	hash_release(instance);
}

