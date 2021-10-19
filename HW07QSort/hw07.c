// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // If fopen fails, return -1
  FILE * fptr = fopen(filename,"r");
  int sum = 0;
  if (fptr == NULL)
  {
	  return -1;
  }
  else
  {
  // count the number of integers in the file
  // 124 378 -56
  // There are three integers: 124, 378, -56
  int val;
  while (fscanf(fptr, "%d", &val) == 1)
  {
	sum++;
  }
  // remember to fclose if fopen succeeds
  fclose(fptr);
  }
  return sum;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL)
  {
	  return false;
  }
  else
  {
  // read integers from the file.
  int val;
  int sum = 0;
  	while (fscanf(fptr, "%d", &val) == 1)
  	{
		sum++;
  	}
  // if the number of integers is different from size (too
  // few or too many) return false
	if (sum != size)
	{
		return false;
	}

	int i = 0;
	fseek(fptr, 0, SEEK_SET); 
	while (fscanf(fptr, "%d", &intArr[i]) == 1)
  	  {
	  	i++;
  	  } 

  // if everything is fine, fclose and return true
  fclose(fptr);
  }
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  const int * ptr1 = (const int*)p1;
  const int * ptr2 = (const int*)p2;
  int val1 = * ptr1;
  int val2 = * ptr2;
  
  if (val1 < val2)
  {
	  return -1;
  }

  if (val1 == val2)
  {
	  return 0;
  }
  
  return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"w");
  if (fptr == NULL)
  {
	  return false;
  }
  else
  {
  // write integers to the file.
  // one integer per line
  for(int i = 0; i < size; i++)
	{
  		fprintf(fptr,"%d\n", intArr[i]);
	}
  // fclose and return true
  fclose(fptr);
  }
  return true;
}
#endif








