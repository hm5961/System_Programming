#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include <time.h> // ����ð� ������

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;
// Ʈ���� ��� �� ���

void make_clean_tree(Node** h, int tmp); // Ʈ���� ��带 �����ϴ� �Լ�
void insert_node_small_root(Node* h, int tmp); // tmp�� Ű������ ������ ��带 Ʈ���� �����ϴ� �Լ�
void insert_node_big_root(Node* h, int tmp); // tmp�� Ű������ ������ ��带 Ʈ���� �����ϴ� �Լ�
// small : ���������� �� ���� ����, big : ���������� �� ���� ����
void search(Node* h, int tmp); // ��ǲ���� tmp�� �˻��ϴ� �Լ�

/* �ð� ���� ������ ��õǾ� ���� �ʾ� �� ����� ��� ���� �����ϴ� �������� �߽��ϴ�. */
/* ���� ������ Ʈ�� �ʱ�ȭ�� ���� ���� �� �ٸ� ��� ���� ������� �ʾҽ��ϴ�.*/

int main(void)
{
	double start, end; // ����ð� ������
	start = (double)clock() / CLOCKS_PER_SEC; // ����ð� ������
	FILE* pFile = fopen("input.txt", "r"); //read mode 

	if (pFile == NULL)
	{
		printf("File does not exist");
		return 0;
	} //���� ���� �� ����

	int num[2] = { 0 };

	int intTemp = -1; // �ؽ�Ʈ ���Ͽ��� ������ �ӽ����� �� �Ѱ��ִ� ����
	Node* head = NULL; // �����

	// ���� �б� ����

	//for(int i = 0; i<2; i++)

	fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
	num[0] = intTemp;
	if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
	{
		printf("ù ���� -1 �Դϴ�.");
		return 0;
	}
	make_clean_tree(&head, intTemp); // ����� Ʈ�����·� �ʱ�ȭ

	fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
	num[1] = intTemp;
	if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
	{
		printf("ù ���� -1 �Դϴ�.");
		return 0;
	}
	insert_node_small_root(head, intTemp); // Ʈ���� intTemp����
	if (num[0] > num[1])
	{
		if ((num[0] / num[1]) >= 2)
			while (1)
			{
				fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
				if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
					break;
				insert_node_small_root(head, intTemp); // Ʈ���� intTemp����
			}
		else
			while (1)
			{
				fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
				if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
					break;
				insert_node_big_root(head, intTemp); // Ʈ���� intTemp����
			}
	}
	else
	{
		if ((num[1] / num[0]) >= 3 / 2)
			while (1)
			{
				fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
				if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
					break;
				insert_node_small_root(head, intTemp); // Ʈ���� intTemp����
			}
		else
			while (1)
			{
				fscanf_s(pFile, "%d", &intTemp); // ���Ͽ��� �������� intTemp�� ����
				if (intTemp == -1) // ���� ������ ��Ұ� -1�̱� ������ -1�� ������ ����
					break;
				insert_node_big_root(head, intTemp); // Ʈ���� intTemp����
			}
	}

	end = (((double)clock()) / CLOCKS_PER_SEC); // ����ð� ������
	printf("���α׷� ���� �ð� :%lf\n", (end - start)); // ����ð� ������

	printf("�˻��� ���� �Է��ϼ��� : ");
	scanf_s("%d", &intTemp);
	search(head, intTemp);
	// ����ڷκ��� ���� ��ǲ�޾� ��ġ �Լ��� �Ѱ��ش�.

	fclose(pFile);          //close file  //����ð� ������ ���� �ּ�ó��
	return 0;
}

void make_clean_tree(Node** h, int tmp)
{
	*h = (Node*)malloc(sizeof(Node)); // ��带 Node*������ ���� �޸� �Ҵ� 
	(*h)->right = *h; // ����� ������ ������ ��� 
	(*h)->key = -52; // ����� Ű�� ���� ���� 	

	Node* n = (Node*)malloc(sizeof(Node));
	n->key = tmp;
	n->left = NULL;
	n->right = NULL;

	(*h)->left = n;
}

void insert_node_small_root(Node* h, int tmp)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->key = tmp;
	n->left = NULL;
	n->right = NULL;
	// tmp�� Ű���� ������ ��� �ű� ���� �� left, right�� �ʱ�ȭ

	Node* p = h->left; // ������ ���� ��� ��ġ Ž����

	while (1) // break�� ���� �� ���� �ݺ�
	{
		if (n->key > p->key) // ��ǲ���� ���� p ������ ū ���
		{
			if (p->right == NULL) // p�� right�� ����ٸ� p->right�� n�� ����Ű�� �� �� ����
			{
				p->right = n;
				return;
			}
			else // ������� �ʴٸ� ���� Ž������ ��ġ�� p->right�� ���� �� �ݺ�
				p = p->right;
		}

		else if (n->key < p->key)// p�� left�� ����ٸ� p->left�� n�� ����Ű�� �� �� ����
		{
			if (p->left == NULL)
			{
				p->left = n;
				return;
			}
			else // ������� �ʴٸ� ���� Ž������ ��ġ�� p->left�� ���� �� �ݺ�
				p = p->left;
		}
		else if (n->key == p->key)
			return;
		//printf("�ߺ��� ���� �����մϴ�.\n");
	}
	return;
}
void insert_node_big_root(Node* h, int tmp)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->key = tmp;
	n->left = NULL;
	n->right = NULL;
	// tmp�� Ű���� ������ ��� �ű� ���� �� left, right�� �ʱ�ȭ

	Node* p = h->left; // ������ ���� ��� ��ġ Ž����

	while (1) // break�� ���� �� ���� �ݺ�
	{
		if (n->key < p->key) // p�� left�� ����ٸ� p->left�� n�� ����Ű�� �� �� ����
		{
			if (p->left == NULL)
			{
				p->left = n;
				return;
			}
			else // ������� �ʴٸ� ���� Ž������ ��ġ�� p->left�� ���� �� �ݺ�
				p = p->left;
		}

		else if (n->key > p->key) // ��ǲ���� ���� p ������ ū ���
		{
			if (p->right == NULL) // p�� right�� ����ٸ� p->right�� n�� ����Ű�� �� �� ����
			{
				p->right = n;
				return;
			}
			else // ������� �ʴٸ� ���� Ž������ ��ġ�� p->right�� ���� �� �ݺ�
				p = p->right;
		}
		else if (n->key == p->key)
			return;
		//printf("�ߺ��� ���� �����մϴ�.\n");
	}
}

void search(Node* h, int tmp)
{
	Node* p = h->left; // ������ ���� ��� ��ġ Ž����

	while (1)
	{
		double start, end; // ����ð� ������
		start = (double)clock() / CLOCKS_PER_SEC; // ����ð� ������

		if (p->key == tmp) // Ž���� �������� ��� �޼��� ��� �� ����
		{
			printf("%d�� �����մϴ�.\n", p->key);
			end = (((double)clock()) / CLOCKS_PER_SEC); // ����ð� ������
			printf("���α׷� ���� �ð� :%lf\n", (end - start)); // ����ð� ������
			return;
		}

		if (tmp > p->key) //tmp�� ���� Ž������ p�� Ű������ Ŭ ��� ���� Ž�� ��ġ�� p->right�� �̵� �� �ݺ�
		{
			p = p->right;
		}

		else if (tmp < p->key) //tmp�� ���� Ž������ p�� Ű������ ���� ��� ���� Ž�� ��ġ�� p->left�� �̵� �� �ݺ�
		{
			p = p->left;
		}

		if ((p->right == NULL) && (p->left == NULL) && (p->key != tmp)) // ���� Ž������ ��ġ�� p���� key���� tmp�� ��ġ���� �ʰ�, �ڽĳ�尡 ������� �����޼��� ��� �� ����
		{
			printf("%d�� �������� �ʽ��ϴ�.\n", tmp);
			end = (((double)clock()) / CLOCKS_PER_SEC); // ����ð� ������
			printf("���α׷� ���� �ð� :%lf\n", (end - start)); // ����ð� ������
			return;
		}
	}
}