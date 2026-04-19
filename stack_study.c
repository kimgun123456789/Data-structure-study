#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stacktype;


void init_stack(Stacktype* s) {//처음 스택을 초기화해줌
	s->top = -1;
}

int is_empty(Stacktype* s) {
		return (s->top == -1);//공백인지 아닌지를 top값으로 판단
}

int is_full(Stacktype* s) {
	return (s->top == MAX_STACK_SIZE-1);
}


void push(Stacktype* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	else {
		s->data[++(s->top)] = item;//초기값이 -1이기 떄문에 ++해주고 넣어줌
	}
}

element pop(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러"); return;
	}
	else {
		return s->data[(s->top)--];
	}
}

int check_matching(const char* in) {//괄호 검사 키트
	
	Stacktype s;
	init_stack(&s);

	char ch; char open_ch;

	for (int i = 0; i < strlen(in); i++) {
		ch = in[i];

		switch (ch) {
			case '(':	case'{':	case '[':
				push(&s, ch); break;

			case ')': case']' : case'}':
				if (is_empty(&s)) {
					return 0;
				}
				else {//현재 ch가 ) , ] , } 3개중 하나인 상황
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

int reverse_check(char* a) {
	Stacktype s;
	init_stack(&s);
	int len = strlen(a);
	char b;
	int num = 0;
	// 1단계: 알파벳만 소문자로 변환하여 스택에 push
	for (int i = 0; i < len; i++) {
		b = a[i];
		if (isalpha(b)) { // 알파벳인지 확인하는 표준 함수
			push(&s, tolower(b));
		}
	}
	for (int i = 0; i < len; i++) {
		b = a[i];
		if (isalpha(b)) {
			if (tolower(b) != pop(&s)) { return 0; }
		}
	}
	return 1;
}


int HTML_check(const char* in) {
	Stacktype s;
	init_stack(&s);
	int len = strlen(in);

	for (int i = 0; i < len; i++) {
		if (in[i] == '<') {
			// 1. 여는 태그인 경우 (예: <div>)
			if (in[i + 1] != '/') {
				push(&s, in[i + 1]); // 첫 글자(d, p 등)를 넣음
			}
			// 2. 닫는 태그인 경우 (예: </div>)
			else {
				if (is_empty(&s)) return 0; // 짝이 안 맞으면 실패

				// pop한 글자와 </ 다음 글자(index i+2) 비교
				if (pop(&s) != in[i + 2]) {
					return 0;
				}
			}
			// 3. 태그 하나를 다 읽었으니 '>'를 만날 때까지 i를 넘김
			while (in[i] != '>') { i++; }
		}
	}
	return is_empty(&s);
}
int main(void) {
	//Stacktype s;

	//init_stack(&s);//스택 초기화

	//push(&s, 1);
	//push(&s, 2);
	//push(&s, 3);

	//printf("%d\n",pop(&s));
	//printf("%d\n", pop(&s));
	//printf("%d\n", pop(&s));


	//char* p = "{A[(i+1)] = 0;}";
	//if (check_matching(p)) { printf("%s 괄호 검사 성공\n",p); }
	//else { printf("괄호 검사 실패\n", p); }
	char* tests[] = {
		"<div><p></p></div>",      // YES
		"<div><p></div></p>",      // NO
		"<html><body></body></html>", // YES
		"<div><span></div></span>", // NO
		"<div><p></p>"             // NO
	};

	for (int i = 0; i < 5; i++) {
		printf("%s -> %s\n", tests[i], HTML_check(tests[i]) ? "YES" : "NO");
	}

	return 0;
}
