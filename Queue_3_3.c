#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_Stack(StackType* s) {

	s->top = -1; //포인터 변수의 주솟값에 해당하는 값의 top값을 -1로 초기화
}

int is_empty(StackType* s) {
	return (s->top == -1); //true false 반환 true면 1 false면 0
}
int is_full(StackType* s) {

	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {

	if (is_full(s)) {
		fprintf(stderr, "스텍 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스텍 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}
int check_mathing(const char* in) {
	StackType s;
	char ch, open_ch;
	int  n = strlen(in);

	init_stack(&s);
	for (int i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case'[':case'{':
			push(&s, ch);
			break;
		case ')':case ':':case '}':
			if (is_empty(&s)) {
				return 0;
			}//만약 비어있다면
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')')
					|| (open_ch == '[' && ch != ']')
					|| (open_ch == '{' && ch != '}')) {
					return 0;
				}
			}
			break;

		}
	}
	if (!is_empty(&s)) { return 0; }
	return 1;
}
int main(void) {









	return 0;
}
