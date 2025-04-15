#pragma region 1
//#include <stdio.h>
//#include <stdbool.h>
//
//#define SIZE 30 // ť�� ũ��
//
//typedef struct {
//	int data[SIZE]; // ������ ũ���� �迭
//	int front; // ť�� ù ��° ��� �ε���
//	int rear; // ť�� ������ ��� �ε���
//} LinearQueue;
//
//// �ʱ�ȭ �Լ�
//void initQueue(LinearQueue* q) {
//	q->front = 0;
//	q->rear = -1;  // rear�� -1�� �����Ͽ� ù ��° ���� �� 0�� �ǵ��� ��
//}
//
//// ť�� ��� �ִ��� Ȯ��
//bool isEmpty(LinearQueue* q) {
//	return q->rear < q->front; // rear�� front���� ������ ��� ����
//}
//
//// ť�� ���� á���� Ȯ��
//bool isFull(LinearQueue* q) {
//	return q->rear == SIZE - 1;  // rear�� �迭 ���� �����ϸ� ���� ��
//}
//
//// ���� �Լ�
//bool enqueue(LinearQueue* q, int value) {
//	if (isFull(q)) {
//		printf("ť�� ���� á���ϴ�.\n");
//		return false;
//	}
//	q->rear++;
//	q->data[q->rear] = value; // rear ��ġ�� ������ �߰�
//	return true;
//}
//
//// ���� �Լ�
//int dequeue(LinearQueue* q) {
//	if (isEmpty(q)) {
//		printf("ť�� ����ֽ��ϴ�.\n");
//		initQueue(q); // ť �ʱ�ȭ
//		return -1;  // ť�� ��� ���� �� -1 ��ȯ
//	}
//	int value = q->data[q->front];
//	q->front++;
//
//	if (q->front > q->rear) {
//		initQueue(q);
//	}
//	return value;
//}
//
//int main()
//{
//	LinearQueue q;
//	initQueue(&q);
//
//	enqueue(&q, 10);
//	enqueue(&q, 20);
//	enqueue(&q, 30);
//	enqueue(&q, 40);
//	enqueue(&q, 50);
//
//	printf("Dequeue: %d\n", dequeue(&q)); // 10 ����
//	printf("Dequeue: %d\n", dequeue(&q)); // 20 ����
//
//	enqueue(&q, 60); // �� ������ ���� �ȵ�
//	enqueue(&q, 70); // �� ������ ���� �ȵ�
//
//	while (!isEmpty(&q)) {
//		printf("Dequeue: %d\n", dequeue(&q));  // ť�� ����� ������ ������ ���
//	}
//	return 0;
//}
#pragma endregion
#pragma region 2
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 // ť�� ũ��

typedef struct {
    int data[SIZE]; // ������ ũ���� �迭
    int front; // ť�� ù ��° ��� �ε���
    int rear; // ť�� ������ ��� �ε���
} LinearQueue;

// �ʱ�ȭ �Լ�
void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;  // rear�� -1�� �����Ͽ� ù ��° ���� �� 0�� �ǵ��� ��
}

// ť�� ��� �ִ��� Ȯ��
bool isEmpty(LinearQueue* q) {
    return q->rear < q->front; // rear�� front���� ������ ��� ����
}

// ť�� ���� á���� Ȯ��
bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;  // rear�� �迭 ���� �����ϸ� ���� ��
}

// ���� �Լ�
bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("ť�� ���� á���ϴ�.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value; // rear ��ġ�� ������ �߰�
    return true;
}

// ���� �Լ�
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("ť�� ����ֽ��ϴ�.\n");
        initQueue(q); // ť �ʱ�ȭ
        return -1;  // ť�� ��� ���� �� -1 ��ȯ
    }
    int value = q->data[q->front];
    q->front++;

    // ť�� ��������� �ʱ�ȭ (front�� rear�� �Ѿ�� ť ��� ����)
    if (q->front > q->rear) {
        initQueue(q);
    }

    return value;
}

// ť�� ���� ���¸� ����ϴ� �Լ�
void printQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("ť�� ����ֽ��ϴ�.\n");
        return;
    }
    printf("ť�� ����: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q); // ť �ʱ�ȭ
    int choice, value;

    while (1) {
        // �޴� ���
        printf("\n----- �޴� -----\n");
        printf("1. ����\n");
        printf("2. ����\n");
        printf("3. ť ������ ���\n");
        printf("4. ����\n");
        printf("����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // ����
            printf("������ ��: ");
            scanf("%d", &value);
            if (enqueue(&q, value)) {
                printf("%d�� ť�� ���ԵǾ����ϴ�.\n", value);
            }
            break;

        case 2: // ����
            value = dequeue(&q);
            if (value != -1) {
                printf("%d�� ť���� �����Ǿ����ϴ�.\n", value);
            }
            break;

        case 3: // ť ������ ���
            printQueue(&q);
            break;

        case 4: // ����
            printf("���α׷��� �����մϴ�.\n");
            return 0;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}

#pragma endregion
