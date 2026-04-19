#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//특정한 값 탐색

typedef int element;

typedef struct ListNode { // data list
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;

	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {//원래 있던 애 그 전에 애
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;//그 전에 있던애가 연결하고 있는 주솟값을 넣어줌
	pre->link = p;//pre가 p를 가르키게 만든다

	return head;
}


ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) { return NULL; }

	removed = head;
	head = removed->link;//head와 그 뒤에 꺼 (2번째꺼를 연결)
	free(removed);//첫번째가 free

	return head;
}


ListNode* delete_pre(ListNode* head, ListNode* pre) {//pre가 가르키는 그 다음노드 삭제

	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) { printf("%d ->", p->data); }
	printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		else {
			p = p->link;
		}
		return NULL;
	}
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) { return head2; }
	if (head2 == NULL) { return head1; }

	else {
		ListNode* p = head1;
		while (p->link != NULL) {
			p = p->link;
		}//p가 null을 가르키고 있음
		p->link = head2;
	}
	return head1;

}


void MinMaxfromLIst(ListNode* head) {
	ListNode* p = head;
	int max = p->data;
	int min = p->data;
	while (p != NULL) {
		if ((p->data) >= max) { max = p->data; }
		else if ((p->data) <= min) { min = p->data; }
		p = p->link;
	}
	printf("최댓값 : %d\n", max);
	printf("최솟값 : %d\n", min);
}


ListNode* delete_node(ListNode* head, int value) {
	ListNode* p = head;
	ListNode* prev = NULL;

	// 1. 삭제할 노드와 그 이전 노드를 찾음
	while (p != NULL && p->data != value) {
		prev = p;      // 현재 노드를 이전 노드로 저장
		p = p->link;   // 다음 노드로 이동
	}

	// 2. 값을 못 찾은 경우
	if (p == NULL) return head;

	// 3. 삭제할 노드가 첫 번째 노드인 경우
	if (prev == NULL) {
		head = p->link;
	}
	// 4. 중간이나 끝 노드인 경우
	else {
		prev->link = p->link; // 이전 노드가 삭제할 노드의 다음을 가리키게 함
	}

	free(p); // 5. 메모리 해제
	return head; // 바뀐 head 반환
}



int main(void) {


	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);

	MinMaxfromLIst(head);


	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);


	int value;
	printf("삭제할 값을 입력하시오:");
	scanf("%d", &value);

	head = delete_node(head, value);
	print_list(head);

	return 0;
}
