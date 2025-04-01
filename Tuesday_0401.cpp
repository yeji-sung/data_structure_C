#pragma region ���� �⺻ ���� �ڵ�
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	int data[MAX];
	int top;
}Stack;

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

int isFull(Stack* s) {
	return s->top == MAX - 1;
}

void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack overflow! Cannot push %d\n", value);
		return;
	}
	s->data[++(s->top)] = value;
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack underflow! Cannot pop %d\n");
		return -1;
	}
	return s->data[(s->top)--];
}

int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty! Cannot peek\n");
		return -1; 
	}
	return s->data[s->top];
}

void display(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack contents: ");
	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

int main() {
	Stack s;
	initStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	display(&s);

	printf("Popped value: %d\n", pop(&s));
	display(&s);

	printf("Peeked value: %d\n", peek(&s));
	display(&s);

	return 0;
}
#pragma endregion
#pragma region ���� �⺻ ���� Ȯ��
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int* data;
//    int top;
//    int capacity;
//} Stack;
//
//void initStack(Stack* s, int initialSize) {
//    s->data = (int*)malloc(initialSize * sizeof(int));
//    if (s->data == NULL) {
//        printf("�޸� �Ҵ� ����!\n");
//        exit(1);
//    }
//    s->top = -1;
//    s->capacity = initialSize;
//}
//
//int isEmpty(Stack* s) {
//    return s->top == -1;
//}
//
//int isFull(Stack* s) {
//    return s->top == s->capacity - 1;
//}
//
//void expandStack(Stack* s) {
//    int newCapacity = s->capacity + 5;
//    int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
//    if (newData == NULL) {
//        printf("�޸� ���Ҵ� ����!\n");
//        exit(1);
//    }
//    s->data = newData;
//    s->capacity = newCapacity;
//    printf("���� �뷮�� %d�� �����߽��ϴ�.\n", s->capacity);
//}
//
//void push(Stack* s, int value) {
//    if (isFull(s)) {
//        expandStack(s);
//    }
//    s->data[++(s->top)] = value;
//    printf("%d��(��) ���ÿ� �߰��߽��ϴ�.\n", value);
//}
//
//int pop(Stack* s) {
//    if (isEmpty(s)) {
//        printf("���� ����÷ο�! ������ ��Ұ� �����ϴ�.\n");
//        return -1;
//    }
//    printf("���ŵ� ��: %d\n", s->data[s->top]);
//    return s->data[(s->top)--];
//}
//
//int peek(Stack* s) {
//    if (isEmpty(s)) {
//        printf("������ ��� �ֽ��ϴ�! Ȯ���� ���� �����ϴ�.\n");
//        return -1;
//    }
//    printf("�ֻ�� ��: %d\n", s->data[s->top]);
//    return s->data[s->top];
//}
//
//void display(Stack* s) {
//    if (isEmpty(s)) {
//        printf("������ ��� �ֽ��ϴ�!\n");
//        return;
//    }
//    printf("���� ����: ");
//    for (int i = 0; i <= s->top; i++) {
//        printf("%d ", s->data[i]);
//    }
//    printf("\n");
//}
//
//void freeStack(Stack* s) {
//    free(s->data);
//    printf("���� �޸𸮸� �����߽��ϴ�.\n");
//}
//
//int main() {
//    Stack s;
//    initStack(&s, 5);
//
//    int choice, value;
//    while (1) {
//        printf("\n--- ���� �޴� ---\n");
//        printf("1. �߰� (Push)\n");
//        printf("2. ���� (Pop)\n");
//        printf("3. �ֻ�� �� Ȯ�� (Peek)\n");
//        printf("4. ���� ���� ���\n");
//        printf("5. ����\n");
//        printf("�޴��� �����ϼ���: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("���ÿ� �߰��� ���� �Է��ϼ���: ");
//            scanf("%d", &value);
//            push(&s, value);
//            break;
//        case 2:
//            pop(&s);
//            break;
//        case 3:
//            peek(&s);
//            break;
//        case 4:
//            display(&s);
//            break;
//        case 5:
//            freeStack(&s); 
//            printf("���α׷��� �����մϴ�.\n");
//            return 0;
//        default:
//            printf("�߸��� �����Դϴ�! 1���� 5 ������ ���ڸ� �Է����ּ���.\n");
//        }
//    }
//}
#pragma endregion
