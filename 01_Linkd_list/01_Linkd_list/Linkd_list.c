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
	return new_Node;
}

// phead : 리스트의 헤드 포인터의 포인터
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *new_node)
{
	// 공백 리스트 인 경우(첫 노드)
	if (*phead == NULL)
	{
		// 새로운 노드에 link는 null로 설정
		new_node->link = NULL;
		// 새로운 노드를 헤드에 연결
		*phead = new_node;
	}
	// 노드의 헤드에 삽입
	else if ( p == NULL)
	{
		new_node->link = tail->link;
		tail->link = new_node;
	}
}

// 삭제
// phead : 리스트의 헤드 포인터의 포인터
// tail : 마지막을 가리키는 노드
// new_node : 삽입될 노드
void delete_node(ListNode *head, ListNode *tail, ListNode *removed)
{
	if (tail == NULL)
		*head = *head->link;
	else
		tail->link = removed->link;
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

// head : 헤드 포인터에 대한 포인터
// tail : 노드의 선행 노드
// removed : 삭제될 노드
void remove_node(ListNode **phead, ListNode *tail, ListNode *removed)
{
	//선행 노드가 
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

	// 출력
	display(head);
}