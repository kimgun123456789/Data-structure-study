#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef int element;

typedef struct ListNode { // data list
	element data;
	struct ListNode* link;
}ListNode;

ListNode *insert_first (ListNode *head , int value){
	
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
	
	for (ListNode* p = head; p != NULL; p = p->link) { printf("%d ->",p->data); }
	printf("NULL\n");
}

int main(void) {
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
