// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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
	Tree * binarytree = (Tree*)malloc(sizeof(Tree)); //allocate tree
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
    
	TreeNode * root = (TreeNode*)malloc(sizeof(TreeNode)); //allocate memory
	root->value = postArray[postSize - 1]; //store root

	//variables
    int index;    
    int i;
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

#ifdef TEST_PRINTPATH
int printHelper(TreeNode * root, int val);
int printNode(TreeNode * root);

void printPath(Tree * tr, int val)
{
	TreeNode * root = tr->root;
	printHelper(root, val);
}

int printHelper(TreeNode * root, int val)
{
	int control; 

	if(root != NULL)
	{
	if(val == root->value)
	{
		control = printNode(root);
	}
	else if(printHelper(root->left, val))
	{
		control = printNode(root);
	}
	else if(printHelper(root->right, val))
	{
		control = printNode(root);
	}
	}
	else
	{
		control = 0;
	}
	return control;
}
int printNode(TreeNode * root)
{
	printf("%d\n", root->value);
	return 1;
}
#endif                                           
                        
