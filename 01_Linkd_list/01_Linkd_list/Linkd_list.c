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

// phead : ����Ʈ�� ��� �������� ������
// new_node : ���Ե� ���
void insert_node(ListNode **phead, ListNode *new_node)
{
	// ���� ����Ʈ �� ���(ù ���)
	if (*phead == NULL)
	{
		// ���ο� ��忡 link�� null�� ����
		new_node->link = NULL;
		// ���ο� ��带 ��忡 ����
		*phead = new_node;
	}
	// ����� ��忡 ����
	else if ( p == NULL)
	{
		new_node->link = tail->link;
		tail->link = new_node;
	}
}

// ����
// phead : ����Ʈ�� ��� �������� ������
// tail : �������� ����Ű�� ���
// new_node : ���Ե� ���
void delete_node(ListNode *head, ListNode *tail, ListNode *removed)
{
	if (tail == NULL)
		*head = *head->link;
	else
		tail->link = removed->link;
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
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;
	ListNode *p;

	// list1 = 30->20->10
	Push_Back(&list1, tail, create_node(10, NULL));
	Push_Back(&head, tail, create_node(20, NULL));
	Push_Back(&head, tail, create_node(30, NULL));

	// ���
	display(head);
}