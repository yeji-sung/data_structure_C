#pragma region 1
//#include <stdio.h>
//#include <stdbool.h>
//
//#define SIZE 30 // 큐의 크기
//
//typedef struct {
//	int data[SIZE]; // 고정된 크기의 배열
//	int front; // 큐의 첫 번째 요소 인덱스
//	int rear; // 큐의 마지막 요소 인덱스
//} LinearQueue;
//
//// 초기화 함수
//void initQueue(LinearQueue* q) {
//	q->front = 0;
//	q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
//}
//
//// 큐가 비어 있는지 확인
//bool isEmpty(LinearQueue* q) {
//	return q->rear < q->front; // rear가 front보다 작으면 비어 있음
//}
//
//// 큐가 가득 찼는지 확인
//bool isFull(LinearQueue* q) {
//	return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
//}
//
//// 삽입 함수
//bool enqueue(LinearQueue* q, int value) {
//	if (isFull(q)) {
//		printf("큐가 가득 찼습니다.\n");
//		return false;
//	}
//	q->rear++;
//	q->data[q->rear] = value; // rear 위치에 데이터 추가
//	return true;
//}
//
//// 삭제 함수
//int dequeue(LinearQueue* q) {
//	if (isEmpty(q)) {
//		printf("큐가 비어있습니다.\n");
//		initQueue(q); // 큐 초기화
//		return -1;  // 큐가 비어 있을 때 -1 반환
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
//	printf("Dequeue: %d\n", dequeue(&q)); // 10 제거
//	printf("Dequeue: %d\n", dequeue(&q)); // 20 제거
//
//	enqueue(&q, 60); // 새 데이터 삽입 안됨
//	enqueue(&q, 70); // 새 데이터 삽입 안됨
//
//	while (!isEmpty(&q)) {
//		printf("Dequeue: %d\n", dequeue(&q));  // 큐가 비어질 때까지 데이터 출력
//	}
//	return 0;
//}
#pragma endregion
#pragma region 2
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 // 큐의 크기

typedef struct {
    int data[SIZE]; // 고정된 크기의 배열
    int front; // 큐의 첫 번째 요소 인덱스
    int rear; // 큐의 마지막 요소 인덱스
} LinearQueue;

// 초기화 함수
void initQueue(LinearQueue* q) {
    q->front = 0;
    q->rear = -1;  // rear를 -1로 설정하여 첫 번째 삽입 시 0이 되도록 함
}

// 큐가 비어 있는지 확인
bool isEmpty(LinearQueue* q) {
    return q->rear < q->front; // rear가 front보다 작으면 비어 있음
}

// 큐가 가득 찼는지 확인
bool isFull(LinearQueue* q) {
    return q->rear == SIZE - 1;  // rear가 배열 끝에 도달하면 가득 참
}

// 삽입 함수
bool enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value; // rear 위치에 데이터 추가
    return true;
}

// 삭제 함수
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        initQueue(q); // 큐 초기화
        return -1;  // 큐가 비어 있을 때 -1 반환
    }
    int value = q->data[q->front];
    q->front++;

    // 큐가 비어있으면 초기화 (front가 rear를 넘어서면 큐 비어 있음)
    if (q->front > q->rear) {
        initQueue(q);
    }

    return value;
}

// 큐의 현재 상태를 출력하는 함수
void printQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다.\n");
        return;
    }
    printf("큐의 상태: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q); // 큐 초기화
    int choice, value;

    while (1) {
        // 메뉴 출력
        printf("\n----- 메뉴 -----\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // 삽입
            printf("삽입할 값: ");
            scanf("%d", &value);
            if (enqueue(&q, value)) {
                printf("%d가 큐에 삽입되었습니다.\n", value);
            }
            break;

        case 2: // 삭제
            value = dequeue(&q);
            if (value != -1) {
                printf("%d가 큐에서 삭제되었습니다.\n", value);
            }
            break;

        case 3: // 큐 데이터 출력
            printQueue(&q);
            break;

        case 4: // 종료
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}

#pragma endregion
