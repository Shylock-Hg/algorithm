/*! \brief test hash module
 *  \author Shylock Hg
 *  \date 2018-04-16
 *  \email tcath2s@gmail.com
 * */

#include "hash.h"
#include <stdio.h>

int main(int argc, char * argv[]){
	char str[200] = {0};
	while(1){
		printf("[info]:please input string :\n");
		scanf("%s",str);
		printf("[info]:input `%s`\n",str);
		printf("[info]:hashed integer=`%lu`\n",hash(str+0,100));
	}
}
