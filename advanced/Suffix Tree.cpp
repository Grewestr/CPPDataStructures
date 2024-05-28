/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <string>

class SuffixTree {
private:
    struct Node {
        std::vector<Node*> children;
        int start;
        int* end;
        int suffixLink;

        Node(int start, int* end) {
            this->start = start;
            this->end = end;
            suffixLink = -1;
        }
    };

    std::string text;
    Node* root;
    int remainingSuffixCount;
    int activeLength;
    int activeEdge;
    Node* activeNode;
    int* leafEnd;

    Node* createNode(int start, int* end);
    void extendSuffixTree(int pos);
    void print(Node* n, int height);

public:
    SuffixTree(const std::string& text);
    void buildSuffixTree();
    void printSuffixTree();
};

SuffixTree::SuffixTree(const std::string& text) {
    this->text = text;
    leafEnd = new int(-1);
    root = createNode(-1, new int(-1));
    activeNode = root;
    remainingSuffixCount = 0;
    activeEdge = -1;
    activeLength = 0;
}

SuffixTree::Node* SuffixTree::createNode(int start, int* end) {
    Node* node = new Node(start, end);
    node->children.resize(256, nullptr);
    return node;
}

void SuffixTree::extendSuffixTree(int pos) {
    (*leafEnd) = pos;
    remainingSuffixCount++;

    Node* lastNewNode = nullptr;

    while (remainingSuffixCount > 0) {
        if (activeLength == 0) activeEdge = pos;

        if (activeNode->children[text[activeEdge]] == nullptr) {
            activeNode->children[text[activeEdge]] = createNode(pos, leafEnd);

            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = nullptr;
            }
        } else {
            Node* next = activeNode->children[text[activeEdge]];
            int edgeLength = *(next->end) - next->start + 1;

            if (activeLength >= edgeLength) {
                activeEdge += edgeLength;
                activeLength -= edgeLength;
                activeNode = next;
                continue;
            }

            if (text[next->start + activeLength] == text[pos]) {
                if (lastNewNode != nullptr && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }

                activeLength++;
                break;
            }

            int* splitEnd = new int(next->start + activeLength - 1);
            Node* split = createNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;

            split->children[text[pos]] = createNode(pos, leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;

            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = split;
            }

            lastNewNode = split;
        }

        remainingSuffixCount--;

        if (activeNode == root && activeLength > 0) {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        } else if (activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

void SuffixTree::buildSuffixTree() {
    for (int i = 0; i < text.size(); i++) {
        extendSuffixTree(i);
    }
}

void SuffixTree::print(Node* n, int height) {
    if (n == nullptr) return;

    if (n->start != -1) {
        for (int k = n->start; k <= *(n->end); k++) {
            std::cout << text[k];
        }
        std::cout << " [" << n->start << ", " << *(n->end) << "] ";
    }

    for (int i = 0; i < 256; i++) {
        if (n->children[i] != nullptr) {
            print(n->children[i], height + 1);
        }
    }
}

void SuffixTree::printSuffixTree() {
    print(root, 0);
}

int main() {
    std::string text = "banana";
    SuffixTree tree(text);

    tree.buildSuffixTree();
    tree.printSuffixTree();

    return 0;
}
