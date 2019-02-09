#include <stdio.h>

// ����ü
typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

// ����Ʈ ����
ListNode *create_node(int data, ListNode *link)
{
	ListNode *new_Node;
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	if (new_Node == NULL)
		printf("�޸� �Ҵ� ����");

	new_Node->data = data;
	new_Node->link = link;
	return (new_Node);
}

// phead : ����Ʈ�� ��� �������� ������
// node : ���Ե� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *node)
{
	// ó���� ���
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}

	// p�� NULL�̸� ù ��° ���� ����
	else if ( p == NULL)
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
	// p ������ ����
	else
	{
		node->link = p->link;
		p->link = node;
	}
}

// ���
void display(ListNode *head)
{
	ListNode *p = head;
	// ����� NULL�� �ƴҶ� ���� ���
	while ( p != NULL)
	{
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

int main(void)
{
	ListNode *list = NULL;

	// list1 = 30->20->10
	insert_node(&list, NULL, create_node(10, NULL));
	insert_node(&list, NULL, create_node(20, NULL));
	insert_node(&list, NULL, create_node(30, NULL));

	display(list);
}