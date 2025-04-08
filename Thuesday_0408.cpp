#pragma region ����ǥ����� ����ǥ������� ��ȯ
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
// //����ǥ����� ����ǥ������� ��ȯ
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
//	printf("����ǥ���: %s\n", postfix);
//}
//
//int main() {
//	char infix[MAX];
//	printf("����ǥ����� �Է��ϼ���: ");
//	scanf("%s", infix);
//	
//	infixToPostfix(infix);
//	return 0;
//}
#pragma endregion
#pragma region ����ǥ��� ���
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

//����ǥ����� ����ϴ� �Լ�
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
	printf("����ǥ��� �����: &d\n", evaluatePostfix(postfix));
	return 0;
}
#pragma endregion
