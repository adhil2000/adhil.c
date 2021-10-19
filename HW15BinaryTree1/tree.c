// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

TreeNode * buildHelper(int * inArray, int inSize, int * postArray, int postSize);

Tree * buildTree(int * inArray, int * postArray, int size)
{
	Tree * binarytree = malloc(sizeof(Tree)); //allocate tree
 	binarytree->root = buildHelper(inArray, size, postArray, size); //buildHelper
	return binarytree;
}

TreeNode * buildHelper(int* inArray, int inSize, int* postArray, int postSize)
{
	//avoids invalid memory read of size 4.
	if(inArray == NULL || postArray == NULL) 
	{
		return NULL;
	}

	if( inSize == 0 || postSize == 0)
	{
		return NULL;
	}

	TreeNode * root = malloc(sizeof(TreeNode)); //allocate memory
	root->value = postArray[postSize - 1]; //store root

	//variables
	int i;
    int index;    
    int logic = 1;
    int rootval = postArray[postSize -1];
    
	//find location of root
	while(logic)
	{
        for (i = 0; i < inSize; i++) 
        {
            if (rootval == inArray[i]) 
            {
                index = i;
                logic = 0;
            }
        }
	
        if (logic == 1) //did we find it?
        {
            index = -1;
            logic = 0;
        }
	}
 
    if (index == -1) 
    {
        return NULL;
    }
    
	//rinse and repeat.
    root->left = buildHelper(inArray, index, postArray, index);
    root->right = buildHelper(inArray + index + 1, inSize - index - 1, postArray + index, inSize - index - 1);

    return root;
}
#endif



