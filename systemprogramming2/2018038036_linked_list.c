#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6011)

typedef struct node {
	long long key;
	struct node* link;
} Node;

void make_linked_list(Node** h);
int check_linked_list(Node* h, long long key);
void insert_linked_list(Node* h, long long key);

int over_Fk = 0;
int node_cnt = 0;
int aaa = 0;
int bbb = 0;

int main(void)
{
	FILE* fp = fopen("input.txt", "r");

	if (fp == NULL)
	{
		printf("File does not exist");
		return 0;
	}


	long long intTemp = -1; 
	Node* head = NULL;

	make_linked_list(&head);

	int count = 0;
	long long Fk = 5000;
	while (1)
	{
		if (fscanf_s(fp, "%lld", &intTemp) == EOF)
			break;
		printf("%lld", intTemp);
		insert_linked_list(head, intTemp);
		
		if (intTemp > Fk)
			over_Fk++;
		printf("\t%d", node_cnt);
		printf("\t%d", over_Fk);
		count++;
		printf("\t%d\n", count);
		
	}
	printf("The total number of nodes: %d\n", node_cnt);
	printf("More than 5000 values: %d\n", over_Fk);

	fclose(fp);
	return 0;
}

void make_linked_list(Node** h)
{
	*h = (Node*)malloc(sizeof(Node));
	(*h)->link = *h;
	(*h)->key = -52;	
}

int check_linked_list(Node* h, long long tmp)
{
	Node* p = h->link;
	while(1)
	{
		if(p->key == tmp)
		{
			aaa++;
			printf("\t%d",aaa);
			return 0;
			
		}
		if (p->link != NULL)
		{
			p = p->link;
		}
		else
		{
			printf("\t");
			return 1;
		}
		
	}
}
void insert_linked_list(Node* h, long long tmp)
{
	if (h->link == h)
	{
		Node* n = (Node*)malloc(sizeof(Node));
		n->key = tmp;
		n->link = NULL;
		h->link = n;
		node_cnt++;
		return;
	}

	if (check_linked_list(h, tmp) != 1)
		return;
		
	Node* p = h->link;
		
	while (1)
	{	
		while (1)
		{
			if (p->link != NULL)
				p = p->link;
			else
				break;
		}
		Node* n = (Node*)malloc(sizeof(Node));
		n->key = tmp;
		n->link = NULL;
		p->link = n;
		node_cnt++;
		return;
	}
}
