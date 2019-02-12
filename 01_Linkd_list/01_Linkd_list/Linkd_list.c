#include <stdio.h>

// 구조체
typedef struct ListNode {
	int data;
	struct ListNode *link;
} ListNode;

// 리스트 생성
ListNode *create_node(int data, ListNode *link)
{
	ListNode *new_node;
	// 메모리 할당
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		printf("메모리 할당 에러");

	// 데이터
	new_node->data = data;
	// 링크 설정
	new_node->link = link;
	return new_node;
}

// phead : 리스트의 헤드 포인터의 포인터
// new_node : 삽입될 노드
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
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
		new_node->link = *phead;
		*phead = new_node;
	}
	else
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

// 삭제
// phead : 리스트의 헤드 포인터의 포인터
// p : 삭제될 노드의 선행 노드
// new_node : 삽입될 노드
void delete_node(ListNode *head, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*head = *head->link;
	else
		p->link = removed->link;
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
// p : 노드의 선행 노드
// removed : 삭제될 노드
void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	//선행 노드가
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

	// 출력
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

	// list1을 역순으로
	printf("역순으로 출력");
	list1 = reverse(list1);
	display(list1);

	// list1에서 20 탐색
	p = search(list1, 20);
	printf("탐색 성공: %d\n", p->data);
}