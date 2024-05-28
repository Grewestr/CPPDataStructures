/***********************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 ***********************************************/
 
#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

/***********************************************
 * Binary Search Tree (BST)
 ***********************************************/
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BSTNode* root;
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    BSTNode* insertRec(BSTNode* node, int val) {
        if (!node) return new BSTNode(val);
        if (val < node->data) node->left = insertRec(node->left, val);
        else node->right = insertRec(node->right, val);
        return node;
    }
};

/***********************************************
 * AVL Tree Node and Functions
 ***********************************************/
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLNode* root;
    AVLTree() : root(nullptr) {}

    int height(AVLNode* N) {
        return N ? N->height : 0;
    }

    int getBalance(AVLNode* N) {
        return N ? height(N->left) - height(N->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);
        if (key < node->data) node->left = insert(node->left, key);
        else if (key > node->data) node->right = insert(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data) return rightRotate(node);
        if (balance < -1 && key > node->right->data) return leftRotate(node);
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};

/***********************************************
 * Red-Black Tree Node and Functions
 ***********************************************/
enum Color { RED, BLACK };

struct RBNode {
    int data;
    Color color;
    RBNode* left, * right, * parent;
    RBNode(int data) : data(data) {
        parent = left = right = nullptr;
        color = RED;
    }
};

class RBTree {
private:
    RBNode* root;
protected:
    void rotateLeft(RBNode*&, RBNode*&);
    void rotateRight(RBNode*&, RBNode*&);
    void fixViolation(RBNode*&, RBNode*&);
public:
    RBTree() { root = nullptr; }
    void insert(const int& n);
    void inorder();
    void levelOrder();
};

/***********************************************
 * Splay Tree Node and Functions
 ***********************************************/
struct SplayNode {
    int data;
    SplayNode* left;
    SplayNode* right;
    SplayNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class SplayTree {
public:
    SplayNode* root;
    SplayTree() : root(nullptr) {}

    SplayNode* rightRotate(SplayNode* x) {
        SplayNode* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    SplayNode* leftRotate(SplayNode* x) {
        SplayNode* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    SplayNode* splay(SplayNode* root, int key) {
        if (!root || root->data == key) return root;
        if (root->data > key) {
            if (!root->left) return root;
            if (root->left->data > key) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            else if (root->left->data < key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right) root->left = leftRotate(root->left);
            }
            return (root->left == nullptr) ? root : rightRotate(root);
        }
        else {
            if (!root->right) return root;
            if (root->right->data > key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left) root->right = rightRotate(root->right);
            }
            else if (root->right->data < key) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }
            return (root->right == nullptr) ? root : leftRotate(root);
        }
    }

    SplayNode* insert(SplayNode* root, int key) {
        if (!root) return new SplayNode(key);
        root = splay(root, key);
        if (root->data == key) return root;
        SplayNode* newNode = new SplayNode(key);
        if (root->data > key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        }
        else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }
        return newNode;
    }
};

/***********************************************
 * Segment Tree Node and Functions
 ***********************************************/
class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(2 * n);
        build(arr);
    }

    void build(vector<int>& arr) {
        for (int i = 0; i < n; i++) tree[n + i] = arr[i];
        for (int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int pos, int value) {
        for (tree[pos += n] = value; pos > 1; pos >>= 1) tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

/***********************************************
 * Fenwick Tree (Binary Indexed Tree)
 ***********************************************/
class FenwickTree {
    vector<int> BIT;
    int n;
public:
    FenwickTree(int n) {
        this->n = n;
        BIT.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) BIT[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
        return sum;
    }
};

/***********************************************
 * Trie (Prefix Tree)
 ***********************************************/
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string key) {
        TrieNode* pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string key) {
        TrieNode* pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCcrawl->children[index]) return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
};

/***********************************************
 * B-Tree Node and Functions
 ***********************************************/
class BTreeNode {
    int* keys;
    int t;
    BTreeNode** C;
    int n;
    bool leaf;
public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
    void traverse();

    friend class BTree;
};

class BTree {
    BTreeNode* root;
    int t;
public:
    BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    void insert(int k);
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    keys = new int[2 * t - 1];
    C = new BTreeNode * [2 * t];
    n = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false) C[i]->traverse();
        cout << " " << keys[i];
    }
    if (leaf == false) C[i]->traverse();
}

void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k) i++;
            s->C[i]->insertNonFull(k);
            root = s;
        }
        else root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;
    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && keys[i] > k) i--;
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);
            if (keys[i + 1] < k) i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if (y->leaf == false) {
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n = n + 1;
}

/***********************************************
 * Min Heap
 ***********************************************/
class MinHeap {
    vector<int> heap;
public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void extractMin() {
        if (heap.size() <= 0) return;
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }
};

/***********************************************
 * Max Heap
 ***********************************************/
class MaxHeap {
    vector<int> heap;
public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void extractMax() {
        if (heap.size() <= 0) return;
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }
};

int main() {
    // Binary Search Tree (BST)
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    cout << "Binary Search Tree created with elements 10, 5, 20." << endl;

    // AVL Tree
    AVLTree avl;
    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 30);
    cout << "AVL Tree created with elements 10, 20, 30." << endl;

    // Red-Black Tree
    RBTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    cout << "Red-Black Tree created with elements 10, 20, 30." << endl;

    // Splay Tree
    SplayTree splay;
    splay.root = splay.insert(splay.root, 10);
    splay.root = splay.insert(splay.root, 20);
    splay.root = splay.insert(splay.root, 30);
    cout << "Splay Tree created with elements 10, 20, 30." << endl;

    // Segment Tree
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);
    cout << "Segment Tree created with array [1, 3, 5, 7, 9, 11]. Sum of range (1, 3): " << segTree.query(1, 3) << endl;

    // Fenwick Tree (Binary Indexed Tree)
    FenwickTree fenwick(arr.size());
    for (int i = 0; i < arr.size(); i++) fenwick.update(i + 1, arr[i]);
    cout << "Fenwick Tree created with array [1, 3, 5, 7, 9, 11]. Sum of first 5 elements: " << fenwick.query(5) << endl;

    // Trie (Prefix Tree)
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    cout << "Trie created and words 'hello' and 'world' inserted. Search 'hello': " << trie.search("hello") << endl;

    // B-Tree
    BTree btree(3);
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);
    cout << "B-Tree created with elements 10, 20, 5, 6, 12, 30, 7, 17." << endl;
    btree.traverse();

    // Min Heap
    MinHeap minHeap;
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(7);
    minHeap.insert(8);
    minHeap.insert(4);
    minHeap.insert(10);
    cout << "\nMin Heap created with elements 3, 2, 1, 7, 8, 4, 10." << endl;

    // Max Heap
    MaxHeap maxHeap;
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(7);
    maxHeap.insert(8);
    maxHeap.insert(4);
    maxHeap.insert(10);
    cout << "Max Heap created with elements 3, 2, 1, 7, 8, 4, 10." << endl;

    return 0;
}
