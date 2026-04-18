#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//insert insert last insert first delete clear find get


#define Max_list_Size 100
typedef int element;

typedef struct {
	element array[Max_list_Size];//L->arr[0] = ~~
	int size;
}Arraylisttype;


void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(Arraylisttype* L) {
	L->size = 0;//사이즈 초기화 함수
}

int is_empty(Arraylisttype* L) {
	return L->size == 0;
}

int is_full(Arraylisttype* L) {//리스트가 가득차있다 (max size와 동일) - > 1을 반환
	return L->size == Max_list_Size;
}

element get_entry(Arraylisttype* L, int pos) {
	if (pos < 0 || pos >= L->size) { error("위치오류\n"); }
	
	return L->array[pos];
}

void print_list(Arraylisttype* L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d-> ", L->array[i]);
	}
	printf("\n");
}

void insert_last(Arraylisttype* L, element item) {
	if (L->size >= Max_list_Size) { error("리스트 오버플로우"); }

	L->array[L->size ++] = item;
}

void insert(Arraylisttype* L, int pos, element item) {//맨 뒤에서 부터 한칸식 미루고 그 후에 원하는 자리에 넣는 방식
	
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delete(Arraylisttype* L, int pos) {
	
	if (pos < 0 || pos >= L->size) { error("위치 오류"); }
	int check = 0;
	element item = L->array[pos];
	for (int i = pos; i < L->size-1; i++) {
		L->array[i] = L->array[i + 1];
		check++;
	}
	L->size -=1;
	return item;
}


int main(void) {


	Arraylisttype list;
	init(&list);//새로운 list 초기화

	insert(&list, 0, 10);
	print_list(&list);
	insert(&list, 0, 20);
	print_list(&list);
	insert(&list, 0, 30);
	print_list(&list);
	insert_last(&list, 40);
	print_list(&list);
	delete (&list, 0);
	print_list(&list);
	return 0;
	
}
