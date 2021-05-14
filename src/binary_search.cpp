/**
* @file binary_search.cpp
*
* Description
*
*/

/*======= Includes ==========================================================*/

#include <vector>
#include <cmath>
#include "binary_search.hpp"

/*======= Local Macro Definitions ===========================================*/
/*======= Type Definitions ==================================================*/
/*======= Local function prototypes =========================================*/
/*======= Local variable declarations =======================================*/
/*======= Global function implementations ===================================*/
/*======= Local function implementations ====================================*/

using namespace std;

int binarySearch(vector<int> &array, int target) {

	int low = 0;
	int high = (int)array.size() - 1;

	while (low <= high)
	{
		if (array[(int)floor((low + high) / 2)] < target)
		{
			low = (int)floor((low + high) / 2) + 1;
		}
		else if (array[floor((low + high) / 2)] > target)
		{
			high = (int)floor((low + high) / 2) - 1;
		}
		else
		{
			return floor((low + high) / 2);
		}
	}
	return -1;
}
