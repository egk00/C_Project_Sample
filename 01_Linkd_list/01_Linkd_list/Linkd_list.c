#include <stdio.h>

// 구조체
typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

// 리스트 생성
ListNode *create_node(int data, ListNode *link)
{
	ListNode *new_Node;
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	if (new_Node == NULL)
		printf("메모리 할당 에러");

	new_Node->data = data;
	new_Node->link = link;
	return (new_Node);
}

// phead : 리스트의 헤드 포인터의 포인터
// node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *node)
{
	// 처음인 경우
	if (*phead == NULL)
	{
		*phead = node;
		node->link = node;
	}

	// p가 NULL이면 첫 번째 노드로 삽입
	else if ( p == NULL)
	{
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
	// p 다음에 삽입
	else
	{
		node->link = p->link;
		p->link = node;
	}
}

// 출력
void display(ListNode *head)
{
	ListNode *p = head;
	// 헤더가 NULL이 아닐때 까지 출력
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