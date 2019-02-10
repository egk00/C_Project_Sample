#include <stdio.h>

/*
 10, 20, 30�� ���ڸ� ���� ���� ������ �����ϼ���
*/

// ����ü
typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

// ����Ʈ ����
ListNode *create_node(int data, ListNode *link)
{
	ListNode *new_Node;
	// �޸� �Ҵ�
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	if (new_Node == NULL)
		printf("�޸� �Ҵ� ����");

	// ������
	new_Node->data = data;
	// ��ũ ����
	new_Node->link = link;
	return new_Node;
}

// ����
// phead : ����Ʈ�� ��� �������� ������
// p : ���� ���
// new_node : ���Ե� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	// ���� ����Ʈ �� ���
	if (*phead == NULL)
	{
		// ���ο� ��忡 link�� null�� ����
		new_node->link = NULL;
		*phead = new_node;
	}

	// p�� NULL�̸� ù ��° ���� ����
	else if (p == NULL)
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	// ����Ʈ�� ������ ����
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

// ����
// phead : ����Ʈ�� ��� �������� ������
// p : ���� ���
// new_node : ���Ե� ���
void delete_node(ListNode *head, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*head = *head->link;
	else
		p->link = removed->link;
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

// head : ��� �����Ϳ� ���� ������
// tail : ����� ���� ���
// removed : ������ ���
void remove_node(ListNode **phead, ListNode *tail, ListNode *removed)
{
	//���� ��尡 
	if (tail == NULL)
		*phead = (*phead)->link;
}

int main(void)
{
	ListNode *list = NULL;

	// list1 = 30->20->10
	insert_node(&list, NULL, create_node(10, NULL));
	insert_node(&list, NULL, create_node(20, NULL));
	insert_node(&list, NULL, create_node(30, NULL));

	// ���
	display(list);
}