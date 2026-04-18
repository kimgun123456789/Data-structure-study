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



int main(void) {
	/*ListNode* head = NULL;

	head = insert_first(head, 0);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);


	if (search_list(head, 30) != NULL) {
		printf("리스트에서 30을 찾았습니다. \n");
	}
	else {
		printf("리스트에서 30을 찾지 못했습니다.\n");
	}*/

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	ListNode* combined_head = NULL;

	for (int i = 0; i < 5; i++) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);

	for (int i = 0; i < 3; i++) {
		head2 = insert_first(head2, i + 3);
	}
	print_list(head2);

	combined_head = concat_list(head1, head2);
	print_list(combined_head);



	return 0;
}
