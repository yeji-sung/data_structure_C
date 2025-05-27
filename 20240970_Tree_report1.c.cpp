#pragma region 트리1
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    int data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//TreeNode* createNode(int data) {
//    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
//    if (node == NULL) {
//        printf("메모리 할당 오류\n");
//        exit(1);
//    }
//    node->data = data;
//    node->left = NULL;
//    node->right = NULL;
//    return node;
//}
//
//void preorder(TreeNode* node) {
//    if (node == NULL) return;
//
//    printf("%d ", node->data);
//    preorder(node->left);
//    preorder(node->right);
//}
//
//void inorder(TreeNode* node) {
//    if (node == NULL) return;
//
//    inorder(node->left);
//    printf("%d ", node->data);
//    inorder(node->right);
//}
//
//void postorder(TreeNode* node) {
//    if (node == NULL) return;
//
//    postorder(node->left);
//    postorder(node->right);
//    printf("%d ", node->data);
//}
//
//void freeTree(TreeNode* node) {
//    if (node == NULL) return;
//
//    freeTree(node->left);
//    freeTree(node->right);
//    free(node);
//}
//
//int getHeight(TreeNode* node) {
//    if (node == NULL) return -1;
//
//    int leftHeight = getHeight(node->left);
//    int rightHeight = getHeight(node->right);
//
//    if (leftHeight > rightHeight) return leftHeight + 1;
//    else return rightHeight + 1;
//}
//
//int countNodes(TreeNode* node) {
//    if (node == NULL) return 0;
//
//    return 1 + countNodes(node->left) + countNodes(node->right);
//}
//
//int countLeaves(TreeNode* node) {
//    if (node == NULL) return 0;
//
//    if (node->left == NULL && node->right == NULL)
//        return 1;
//
//    return countLeaves(node->left) + countLeaves(node->right);
//}

//int main() { //3
//    TreeNode* root = createNode(1);
//
//    root->left = createNode(2);
//    root->right = createNode(3);
//
//    root->left->left = createNode(4);
//    root->left->right = createNode(5);
//
//    printf("트리의 높이 : %d\n", getHeight(root));
//    printf("노드의 개수 : %d\n", countNodes(root));
//    printf("리프노드 수 : %d\n", countLeaves(root));
//    freeTree(root);
//    return 0;
//}

//int main() { //2
//    // 루트 노드 생성
//    TreeNode* root = createNode(1);
//
//    // 자식 노드 생성 및 연결
//    root->left = createNode(2);
//    root->right = createNode(3);
//
//    root->left->left = createNode(4);
//    root->left->right = createNode(5);
//
//    root->right->left = createNode(6);
//    root->right->right = createNode(7);
//		
//		preorder(root);
//		printf("\n");
//		inorder(root);
//		printf("\n");		
//		postorder(root);
//		freeTree(root);
//    return 0;
//}

//int main() { //1
//
//    TreeNode* root = createNode(1);
//
//    root->left = createNode(2);
//    root->right = createNode(3);
//
//    root->left->left = createNode(4);
//    root->left->right = createNode(5);
//
//    root->right->left = createNode(6);
//    root->right->right = createNode(7);
//
//    printf("루트 노드: %d\n", root->data);
//    printf("왼쪽 자식: %d\n", root->left->data);
//    printf("오른쪽 자식: %d\n", root->right->data);
//
//    return 0;
//}
#pragma endregion

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(TreeNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void freeTree(TreeNode* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int getHeight(TreeNode* node) {
    if (node == NULL) return -1;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int countLeaves(TreeNode* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int getSum(TreeNode* node) {
    if (node == NULL) return 0;
    return node->data + getSum(node->left) + getSum(node->right);
}

int getMax(TreeNode* node) {
    if (node == NULL) return -2147483648;
    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);
    int max = node->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}
void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL) return;
    if (node->data > min) searchRange(node->left, min, max);
    if (node->data > min && node->data < max)
        printf("%d ", node->data);
    if (node->data < max) searchRange(node->right, min, max);
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    printf("전위 순회: ");
    preorder(root);
    printf("\n");

    printf("중위 순회: ");
    inorder(root);
    printf("\n");

    printf("후위 순회: ");
    postorder(root);
    printf("\n");

    printf("트리 높이: %d\n", getHeight(root));
    printf("전체 노드 수: %d\n", countNodes(root));
    printf("리프 노드 수: %d\n", countLeaves(root));

    printf("노드 값 총합: %d\n", getSum(root));
    printf("최댓값: %d\n", getMax(root));

    printf("값이 6 이상 20 이하인 노드: ");
    searchRange(root, 6, 20);
    printf("\n");

    freeTree(root);
    return 0;
}
