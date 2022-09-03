#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Trace() 
// printf("%s: %d\n", __FUNCTION__, __LINE__)

/**********************************************
Declared node blueprint
**********************************************/
struct Node
{
	int value;
  struct Node* prev;
	struct Node* next;
};
typedef struct Node Node;

struct Stack
{
	Node* head;
  Node* tail;
	int size;
};
typedef struct Stack Stack;

/**********************************************
Create a new node from item and returns pointer
to the newly created node
**********************************************/
Node* createNode(int num)
{
	Node* newNode = (Node *)malloc(sizeof(Node));

	if (newNode) // sanity check
	{
		newNode->value = num;
    newNode->prev =  NULL;
		newNode->next = NULL;
	}
	else
	{
		printf("createNode:: could not malloc node !\n");
	}

	return newNode;
}

/**********************************************
Free a node
**********************************************/
void destroyNode(Node* node)
{
	if (node) // sanity check
	{
		free(node);
		return;
	}
	printf("destroyNode:: Not the end of the world but you just tried to free a null pointer !\n");
}

/**********************************************
appends item to list tail
**********************************************/
void push(Stack* stk, int value)
{
	assert(stk != NULL && "Invalid Stack\n");  // idiot proofing
  // this is also not needed - Node* prevNode = NULL; sorry for this again!! :(
  Node* newNode = createNode(value); // litu:: not needed -> ,prevNode);
	assert(newNode != NULL && "Could not allocate Memory\n"); // sanity check

	if (! stk->head) // Appending first node to empty list
	{
		stk->head = newNode;
    stk->tail = stk->head;
		return;
	}

	stk->tail->next = newNode;
  newNode->prev = stk->tail;

  stk->tail = newNode;  // set the new node as the last node
}

Node* pop(Stack* stk)
{
  
}

/**********************************************
Destroys the entire list
**********************************************/
void destroyStack(Stack* stk)
{
	if (!stk)
		return;

	Node* freePos = stk->head;
	for (; freePos != NULL;) // iterate through stk until we reach null (which is end of stk)
	{
		Node* next = freePos->next;
		destroyNode(freePos);
		freePos = next;
	}
	stk->head = NULL;

	free(stk);
}

/**********************************************
Display List contents
**********************************************/
void showStack(Stack* stk)
{
	if (!stk)
	{
		printf("showList:: Integer stk is empty ! First create a new integer\n");
		return;
	}

	for (Node* pickPos = stk->head; pickPos != NULL;)
	{
		printf("%d", pickPos->value);
		pickPos = pickPos->next;
	}
	printf("\n");
}


/**********************************************
Main Entry
**********************************************/
int main(void)
{
	printf("\nProgram to Show Stack operation\n");
	printf("-------------------------------------------\n");

  Stack* myStack = (Stack *)malloc(sizeof(Stack));
  assert (myStack != NULL && "Failed to allocate Stack\n");

  
	// cleanup
	destroyStack(mystack);
  
	return 0;
}
