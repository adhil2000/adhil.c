// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

int supercount = 0; // counter for total elements
int count = 0;      // counter for k
int size = n;       // array size

//creates array element values
for(int j = 0; j < size; j++)
{
	arr[j] = j;
}

//scans array
while(supercount < size)
{

for(int i = 0; i < size; i++)
{
	if(arr[i] >= 0)
	{
	++count;
	
	if(count == k)
	{
		count = 0;
		++supercount;
		printf("%d\n", arr[i]);
		arr[i] = -1;
	}


	if(i == (size - 1))
	{
		i = -1;
	}

	}

}
}

//frees array
free (arr);
}
#endif

