// ***
// *** You MUST modify this file
// ***

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
	FILE * fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
	    free(arithlist);
		fclose(fptr);
		return false;
	}
	else if(arithlist == NULL)
	{
		free(arithlist);
		fclose(fptr);
		return false;
	}
	else
	{
	char numchar[WORDLENGTH];
	int count = 0;
	while(fgets(numchar, WORDLENGTH, fptr))
	{
		++count;
		if (count > WORDLENGTH)
		{
			free(arithlist);
		 	fclose(fptr);
			return false;
		}
		else if((strchr(numchar,'\n') != NULL) && (count <= WORDLENGTH))
		{
			addNode(arithlist, numchar);
			count = 0;
		}
	}
	fclose(fptr);
	}
    return true;
}
#endif

#ifdef TEST_DELETELIST
void deleteList(List * arithlist)
{
    ListNode *head = arithlist->head;
	while(head != NULL)
	{
		ListNode *next= head->next;
		free(head);
		head = next;
	}
	free(arithlist);
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if (arithlist != NULL)
  {
    ListNode *ptr = malloc(sizeof(ListNode));
    ptr->prev = arithlist->tail;     
	ptr->next = NULL;
	if (arithlist->head == NULL)
    	{
        	arithlist->head = ptr;
        }
	else
        {
            arithlist->tail->next = ptr;
        }
  	arithlist->tail = ptr;
    strcpy(ptr->word, word);
  }
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
	ListNode *head_ref = arithlist->head;
/* base case */
    if (head_ref == NULL || ln == NULL)
	{
		return false;
	}
    /* If node to be lneted is head node */
    if (head_ref == ln)
	{
		head_ref = ln->next;
	}
    /* Change next only if node to be lneted is NOT the last node */
    if (ln->next != NULL)
	{
		ln->next->prev = ln->prev;
	}
    /* Change prev only if node to be lneted is NOT the first node */
    if (ln->prev != NULL)
	{
		ln->prev->next = ln->next;
	}
    /* Finally, free the memory occupied by ln*/
    free(ln);
    return true;
}
#endif

