/*! \brief simple implement of fibonacci search algorithm
 *  \author Shylock Hg
 *  \date 2018-05-08
 *  \email tcath2s@gmail.com
 * */

#include "../sorting/sort_common.h"

#define min(a,b) (a<b ? a : b)

int search_fibonacci(array_t array, int x){
	//< initialize fibonacci 
	int fibMMm2 = 0;  //!< (m-2)'th fibonacci No.
	int fibMMm1 = 1;  //!< (m-1)'th fibonacci No.
	int fibM    = fibMMm2 + fibMMm1;  //!< m'th fibonacci No.

	//< iterate fibM to smallest fibonacci number >= len
	while(fibM < array.len){
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM    = fibMMm2 + fibMMm1;
	}

	//< 
	int offset = -1;

	//< iterate fibMMm2 to index of searched item
	//< divide array by fibMMm2 , [0,fibMMm2] (fibMMm1,fibM)
	while(fibM > 1){
		//< check if fibMMm2 is a valid index
		int i = min(offset+fibMMm2, array.len-1);
		
		if(array.value[i] < x){
			//< drop[0,fibMMm2)
			fibM    = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}else if(array.value[i] > x){
			//< drop[fibMMm2,fibM)
			fibM    = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}else  //!< find the item
			return i;
	}

	//< check last item
	if(fibMMm1 && array.value[offset+1] == x)
		return offset+1;
	else
		return -1;
}

