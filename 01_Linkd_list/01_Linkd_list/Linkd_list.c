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
	return (new_Node);
}

// phead : ����Ʈ�� ��� �������� ������
// tail : ����� ����
// new_node : ���Ե� ���
void insert_node(ListNode **phead, ListNode *tail, ListNode *new_node)
{
	// ���� ����Ʈ �� ���
	if (*phead == NULL)
	{
		// ���ο� ��忡 link�� null�� ����
		new_node->link = NULL;
		*phead = new_node;
	}

	// tail�� NULL�̸� ù ��° ���� ����
	else if (tail == NULL)
	{
		new_node->link = (*phead)->link;
		(*phead)->link = new_node;
	}
	// ����Ʈ�� ������ ����
	else
	{
		new_node->link = tail->link;
		tail->link = new_node;
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