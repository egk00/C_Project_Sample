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
	// 메모리 할당
	new_Node = (ListNode *)malloc(sizeof(ListNode));
	if (new_Node == NULL)
		printf("메모리 할당 에러");

	// 데이터
	new_Node->data = data;
	// 링크 설정
	new_Node->link = link;
	return (new_Node);
}

// phead : 리스트의 헤드 포인터의 포인터
// tail : 노드의 꼬리
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *tail, ListNode *new_node)
{
	// 공백 리스트 인 경우
	if (*phead == NULL)
	{
		// 새로운 노드에 link는 null로 설정
		new_node->link = NULL;
		*phead = new_node;
	}

	// tail이 NULL이면 첫 번째 노드로 삽입
	else if (tail == NULL)
	{
		new_node->link = (*phead)->link;
		(*phead)->link = new_node;
	}
	// 리스트의 꼬리에 연결
	else
	{
		new_node->link = tail->link;
		tail->link = new_node;
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