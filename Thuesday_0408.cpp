#pragma region 중위표기법을 후위표기법으로 변환
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//
//#define MAX 100
//
//typedef struct {
//	int data[MAX];
//	int top;
//} Stack;
//
//void initStack(Stack* s) {
//	s->top = -1;
//}
//
//int isEmpty(Stack* s) {
//	return s->top == -1;
//}
//
//void push(Stack* s, int value) {
//	s->data[++(s->top)] = value;
//}
//
//int pop(Stack* s) {
//	if (isEmpty(s)) return'\0';
//	return s->data[(s->top)--];
//}
//
//int peek(Stack* s) {
//	if (isEmpty(s)) return '\0';
//	return s->data[s->top];
//}
//
//int precedence(char op) {
//	if (op == '+' || op == '-') return 1;
//	if (op == '*' || op == '/') return 2;
//	return  -1;
//}
//
// //중위표기식을 후위표기식으로 변환
//void infixToPostfix(char* infix) {
//	Stack s;
//	initStack(&s);
//	char postfix[MAX] = "";
//	int j = 0;
//
//	for (int i = 0; infix[i] != '\0'; i++) {
//		char ch = infix[i];
//
//		if (isalpha(ch) || isdigit(ch)) {
//			postfix[j++] = ch;
//		}
//
//		else if (ch == '(') {
//			push(&s, ch);
//		}
//
//		else if (ch == ')') {
//			while (!isEmpty(&s) && peek(&s) != '(') {
//				postfix[j++] = pop(&s);
//			}
//			pop(&s);
//		}
//		else {
//			while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
//				postfix[j++] = pop(&s);
//			}
//			push(&s, ch);
//		}
//	}
//
//	while (!isEmpty(&s)) {
//		postfix[j++] = pop(&s);
//	}
//	postfix[j] = '\0';
//
//	printf("후위표기식: %s\n", postfix);
//}
//
//int main() {
//	char infix[MAX];
//	printf("중위표기식을 입력하세요: ");
//	scanf("%s", infix);
//	
//	infixToPostfix(infix);
//	return 0;
//}
#pragma endregion
#pragma region 후위표기법 계산
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
	int data[MAX];
	int top;
} Stack;

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, int value) {
	s->data[++(s->top)] = value;
}

int pop(Stack* s) {
	if (isEmpty(s)) return'\0';
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) return '\0';
	return s->data[s->top];
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return  -1;
}

//후위표기식을 계산하는 함수
int evaluatePostfix(char* postfix) {
	Stack s;
	initStack(&s);

	for (int i = 0; postfix[i] != '\0'; i++) {
		char ch = postfix[i];

		if (isdigit(ch)) {
			push(&s, ch - '0');
		}
		else {
			int b = pop(&s);
			int a = pop(&s);
			int result;

			switch (ch) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			default:
				printf("Invalid operator emcountered.\n");
				exit(1);
			}
			push(&s, result);
		}
	}
	return pop(&s);
}
int main() {
	char postfix[MAX] = "12+5*";
	printf("후위표기식 계산결과: &d\n", evaluatePostfix(postfix));
	return 0;
}
#pragma endregion
