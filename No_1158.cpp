#include <stdio.h>
#include <stdlib.h>

typedef struct Node* nodepoint;

typedef struct Node{
	int num;
	nodepoint  nextNode;
}Node;

nodepoint createNode(int value);
void appendNode(nodepoint* Head, nodepoint node);
nodepoint searchNode(nodepoint* Head, int Locate);
void deleteNode(nodepoint* Head, nodepoint remove);
//void destroyNode(nodepoint remove);

int main(int argc, char** argv)
{
	Node* List = NULL;
	
	int n;
	int m;
	scanf("%d", &n);
	scanf("%d", &m);
	
	int i;
	
	for(i = 1; i<=n; i++)
	{
		appendNode(&List, createNode(i));
	}
	Node* temp = List;
	while(temp->nextNode != NULL)
	{
		temp = temp->nextNode;
		
	}

	temp -> nextNode = List;

	
	printf("<%d", m);
	temp = List;
	Node* temp1 = List;
	for(i = 1; i<=n; i++)
	{
	
		temp = searchNode(&temp1, m);
		
		temp1 = temp -> nextNode;
		if(i!= 1)
			printf(", %d", temp->num);
		
		
		deleteNode(&List,  temp);
		
		
		
	}
	
	printf(">");
	
	
	
	return 0;	
}


nodepoint createNode(int value)
{
	nodepoint newNode = (nodepoint)malloc(sizeof(Node));
	newNode->num = value;
	newNode->nextNode = NULL;
		
	return newNode;
}

void appendNode(nodepoint* Head, nodepoint node)
{
	if(*Head == NULL)
	{
		*Head = node;
	}
	
	else
	{
		nodepoint next = *Head;
		while(next->nextNode != NULL)
		{
			next = next->nextNode;
		}

		next->nextNode = node;
		
		
	}
}

nodepoint searchNode(nodepoint* Head, int Locate)
{
	nodepoint search = *Head;
	int i = 0;
	while(search != NULL && i < Locate-1)
	{
		search =search->nextNode;	
		i++;
	}
	
	return search;
}

void deleteNode(nodepoint* Head, nodepoint remove)
{
	if(*Head == remove)
	{
		*Head = remove->nextNode;
	}
	
	
	
	
	else{
			nodepoint search = *Head;
	
		while(search->nextNode != remove && search != NULL)
		{
			search= search->nextNode;
		}
		
		if(search != NULL)
		{
			search -> nextNode = remove -> nextNode;
		}
		
		
	}
	//free(remove);

}

