// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  *sum = 0;
  FILE * fptr = fopen(filename, "r");   // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  if (fptr == NULL)
  {
	  return false;
  }
  else
  {
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  int val;
  // * sum stores the result of adding all numbers from the file 
  while (fscanf(fptr, "%d", &val) == 1)
  {
	 *sum += val;
  }
  // When no more numbers can be read, fclose, return true
  fclose(fptr);
  }
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing 
  FILE * fptr = fopen(filename, "w");
  // if fopen succeeds, write sum as an integer using fprintf 
  if (fptr == NULL)
  {
	  return false;
  }
  else
  {
  // fprintf should use one newline '\n'
  fprintf(fptr, "%d\n", sum);
  // fclose, return true
  fclose(fptr);
  }
  return true;
}
#endif
