#include <assert.h>
#include <stddef.h>


/*! \brief swap two item value in array
 *  \param a[i/o] pointer to item in array
 *  \parma b[i/o] pointer to item in array
 * */
void swap_item(int * a, int * b){
	assert(NULL != a && NULL != b);
	if(NULL == a || NULL == b)
		return ;

	int temp = *a;
	*a = *b;
	*b = temp;
}
