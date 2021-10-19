// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }

  List *output = malloc(sizeof(arithlist));
  output->head = NULL;
  output->tail = NULL;

  List *stack = malloc(sizeof(arithlist));
  stack->head = NULL;
  stack->tail = NULL;

  ListNode *head = arithlist->head;
  while(head != NULL)
  {
	  if(isOperator(head->word) == 3)
	  {
		  addNode(stack,head->word);
	  }
	  else if(isOperator(head->word) == -1)
	  {
		  addNode(output,head->word);
	  }
	  else if((isOperator(head->word) > -1) && (isOperator(head->word) < 3))
	  {
		  if(stack->head == NULL)
		  {
		  	addNode(stack,head->word);
		  }
		  else if(isOperator(head->word) < isOperator(stack->tail->word))
		  {
			ListNode *stacktail = stack->tail;
		  	while(stacktail != NULL)
			{
				if(isOperator(head->word) <= isOperator(stacktail->word))
				{
					addNode(output,stacktail->word);
					deleteNode(stack,stacktail);
				}
				stacktail = stacktail->prev;
			}
		//	addNode(stack,head->word);
		  }
		  else
		  {
		  addNode(stack,head->word);
		  }
	  }
	  else if(isOperator(head->word) == 4)
	  {
		  ListNode *tailpop = stack->tail;
		  while(isOperator(tailpop->word) != 3)
		  {
			  addNode(output,tailpop->word);
			  deleteNode(stack,tailpop);
			  tailpop = tailpop->prev;
		  }
		  deleteNode(stack,tailpop);
	  }
	  head = head->next;
  }

  ListNode *stackhead = stack -> head;
  while(stackhead != NULL)
  {
	  addNode(output,stackhead->word);
	  stackhead = stackhead->next;
  }
  
  ListNode *finalhead = arithlist->head;
  ListNode *finalout = output->head;
  while(finalhead != NULL)
  {
	  finalhead->word = finalout->word;
	  finalhead = finalhead->next;
	  finalout = finalout->next;
  }
  /*
  printf("list is %s\n",arithlist->head->word);
  printf("list is %s\n",arithlist->head->next->word);
  printf("list is %s\n",arithlist->head->next->next->word);
  printf("list is %s\n",arithlist->head->next->next->next->word);
  printf("list is %s\n",arithlist->head->next->next->next->next->word);
 
  printf("output is %s\n",output->head->word);
  printf("output is %s\n",output->head->next->word);
  printf("output is %s\n",output->head->next->next->word);
  printf("output is %s\n",output->head->next->next->next->word);
  printf("output is %s\n",output->head->next->next->next->next->word); 

  printf("stack is %s\n",stack->head->word);
  printf("stack is %s\n",stack->head->next->word);
 */

  // printf("value is %s\n",stack->head->next->next->word);
  // printf("value is %s\n",stack->head->next->next->next->word);
  
 return true;
}
#endif












