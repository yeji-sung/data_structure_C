#pragma region Ʈ��1
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
//        printf("�޸� �Ҵ� ����\n");
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
//    printf("Ʈ���� ���� : %d\n", getHeight(root));
//    printf("����� ���� : %d\n", countNodes(root));
//    printf("������� �� : %d\n", countLeaves(root));
//    freeTree(root);
//    return 0;
//}

//int main() { //2
//    // ��Ʈ ��� ����
//    TreeNode* root = createNode(1);
//
//    // �ڽ� ��� ���� �� ����
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
//    printf("��Ʈ ���: %d\n", root->data);
//    printf("���� �ڽ�: %d\n", root->left->data);
//    printf("������ �ڽ�: %d\n", root->right->data);
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
        printf("�޸� �Ҵ� ����\n");
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

    printf("���� ��ȸ: ");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    postorder(root);
    printf("\n");

    printf("Ʈ�� ����: %d\n", getHeight(root));
    printf("��ü ��� ��: %d\n", countNodes(root));
    printf("���� ��� ��: %d\n", countLeaves(root));

    printf("��� �� ����: %d\n", getSum(root));
    printf("�ִ�: %d\n", getMax(root));

    printf("���� 6 �̻� 20 ������ ���: ");
    searchRange(root, 6, 20);
    printf("\n");

    freeTree(root);
    return 0;
}
