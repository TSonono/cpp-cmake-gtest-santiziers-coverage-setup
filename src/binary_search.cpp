/**
* @file binary_search.cpp
*
* Description
*
*/

/*======= Includes ==========================================================*/

#include <vector>
#include <math.h>
#include "binary_search.hpp"

/*======= Local Macro Definitions ===========================================*/
/*======= Type Definitions ==================================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/
/*======= Global function implementations ===================================*/
/*======= Local function implementations ====================================*/

using namespace std;

int binarySearch(vector<int> array, int target) {

	int low = 0;
	int high = array.size() - 1;

	while (low <= high)
	{
		if (array[floor((low + high) / 2)] < target)
		{
			low = floor((low + high) / 2) + 1;
		}
		else if (array[floor((low + high) / 2)] > target)
		{
			high = floor((low + high) / 2) - 1;
		}
		else
		{
			return floor((low + high) / 2);
		}
	}
	return -1;
}

