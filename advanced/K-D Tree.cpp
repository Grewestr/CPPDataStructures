/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>

#define K 2 // Number of dimensions

struct Node {
    int point[K];
    Node* left, * right;
};

Node* newNode(int arr[]) {
    Node* temp = new Node;
    for (int i = 0; i < K; i++) {
        temp->point[i] = arr[i];
    }
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insertRec(Node* root, int point[], unsigned depth) {
    if (root == nullptr) {
        return newNode(point);
    }

    unsigned cd = depth % K;
    if (point[cd] < root->point[cd]) {
        root->left = insertRec(root->left, point, depth + 1);
    } else {
        root->right = insertRec(root->right, point, depth + 1);
    }

    return root;
}

Node* insert(Node* root, int point[]) {
    return insertRec(root, point, 0);
}

bool arePointsSame(int point1[], int point2[]) {
    for (int i = 0; i < K; i++) {
        if (point1[i] != point2[i]) {
            return false;
        }
    }
    return true;
}

bool searchRec(Node* root, int point[], unsigned depth) {
    if (root == nullptr) {
        return false;
    }
    if (arePointsSame(root->point, point)) {
        return true;
    }

    unsigned cd = depth % K;
    if (point[cd] < root->point[cd]) {
        return searchRec(root->left, point, depth + 1);
    }
    return searchRec(root->right, point, depth + 1);
}

bool search(Node* root, int point[]) {
    return searchRec(root, point, 0);
}

void printTree(Node* root) {
    if (root == nullptr) return;

    for (int i = 0; i < K; i++) {
        std::cout << root->point[i] << " ";
    }
    std::cout << std::endl;

    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = nullptr;
    int points[][K] = { {3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19} };

    int n = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, points[i]);
    }

    printTree(root);

    int point1[] = {10, 19};
    (search(root, point1)) ? std::cout << "Found\n" : std::cout << "Not Found\n";

    int point2[] = {12, 19};
    (search(root, point2)) ? std::cout << "Found\n" : std::cout << "Not Found\n";

    return 0;
}
