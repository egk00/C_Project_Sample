#include <stdio.h>

// ����ü
typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

// ����Ʈ ����
ListNode *create_node(int data, ListNode *link)
{
	ListNode *new_node;
	// �޸� �Ҵ�
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		printf("�޸� �Ҵ� ����");

	// ������
	new_node->data = data;
	// ��ũ ����
	new_node->link = link;
	return new_node;
}

// phead : ����Ʈ�� ��� �������� ������
// new_node : ���Ե� ���
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
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
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

// ����
// phead : ����Ʈ�� ��� �������� ������
// p : ������ ����� ���� ���
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
// p : ����� ���� ���
// removed : ������ ���
void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	//���� ��尡
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
		{
			p = p->link;
			p->link = head2;
			return head1;
		}
	}
}

void display_recur(ListNode *head)
{
	ListNode *p = head;
	if (p != NULL)
	{
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
			p = p->link;
		}
	}
	return p;
}

ListNode *reverse(ListNode *head)
{
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main(void)
{
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;
	ListNode *p;

	// list1 = 30->20->10
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));

	// ���
	display(list1);

	// list1 = 20->10
	remove_node(&list1, NULL, list1);
	display(list1);

	// list2 = 80->70->60
	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);


	// list1 = list1 + list2
	list1 = concat(list1, list2);
	display(list1);

	// list1�� ��������
	printf("�������� ���");
	list1 = reverse(list1);
	display(list1);

	// list1���� 20 Ž��
	p = search(list1, 20);
	printf("Ž�� ����: %d\n", p->data);
}