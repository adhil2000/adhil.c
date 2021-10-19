// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
	int i; // first level control var
	int j; // second level control var
	int min; // minimum number
	int var; // switch variable

	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < (size); j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}		
		var = arr[i];
		arr[i] = arr[min];
		arr[min] = var;
	}

  // This function has two levels of for

