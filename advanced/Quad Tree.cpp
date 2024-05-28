/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>

class Point {
public:
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class Quad {
public:
    Point *topLeft, *botRight;
    Point *point;
    Quad *topLeftTree, *topRightTree, *botLeftTree, *botRightTree;

    Quad(Point *topL, Point *botR) {
        topLeft = topL;
        botRight = botR;
        point = nullptr;
        topLeftTree = topRightTree = botLeftTree = botRightTree = nullptr;
    }

    bool inBoundary(Point *p) {
        return (p->x >= topLeft->x && p->x <= botRight->x &&
                p->y >= topLeft->y && p->y <= botRight->y);
    }

    void insert(Point *p) {
        if (!inBoundary(p)) {
            return;
        }

        if (abs(topLeft->x - botRight->x) <= 1 && abs(topLeft->y - botRight->y) <= 1) {
            if (point == nullptr) {
                point = p;
            }
            return;
        }

        if ((topLeft->x + botRight->x) / 2 >= p->x) {
            if ((topLeft->y + botRight->y) / 2 >= p->y) {
                if (topLeftTree == nullptr) {
                    topLeftTree = new Quad(
                        new Point(topLeft->x, topLeft->y),
                        new Point((topLeft->x + botRight->x) / 2,
                                  (topLeft->y + botRight->y) / 2));
                }
                topLeftTree->insert(p);
            } else {
                if (botLeftTree == nullptr) {
                    botLeftTree = new Quad(
                        new Point(topLeft->x, (topLeft->y + botRight->y) / 2),
                        new Point((topLeft->x + botRight->x) / 2, botRight->y));
                }
                botLeftTree->insert(p);
            }
        } else {
            if ((topLeft->y + botRight->y) / 2 >= p->y) {
                if (topRightTree == nullptr) {
                    topRightTree = new Quad(
                        new Point((topLeft->x + botRight->x) / 2, topLeft->y),
                        new Point(botRight->x, (topLeft->y + botRight->y) / 2));
                }
                topRightTree->insert(p);
            } else {
                if (botRightTree == nullptr) {
                    botRightTree = new Quad(
                        new Point((topLeft->x + botRight->x) / 2,
                                  (topLeft->y + botRight->y) / 2),
                        new Point(botRight->x, botRight->y));
                }
                botRightTree->insert(p);
            }
        }
    }

    Point *search(Point *p) {
        if (!inBoundary(p)) {
            return nullptr;
        }

        if (point != nullptr) {
            return point;
        }

        if ((topLeft->x + botRight->x) / 2 >= p->x) {
            if ((topLeft->y + botRight->y) / 2 >= p->y) {
                if (topLeftTree == nullptr) {
                    return nullptr;
                }
                return topLeftTree->search(p);
            } else {
                if (botLeftTree == nullptr) {
                    return nullptr;
                }
                return botLeftTree->search(p);
            }
        } else {
            if ((topLeft->y + botRight->y) / 2 >= p->y) {
                if (topRightTree == nullptr) {
                    return nullptr;
                }
                return topRightTree->search(p);
            } else {
                if (botRightTree == nullptr) {
                    return nullptr;
                }
                return botRightTree->search(p);
            }
        }
    }

    void printTree() {
        if (point != nullptr) {
            std::cout << "Point(" << point->x << ", " << point->y << ")\n";
        }

        if (topLeftTree != nullptr) {
            topLeftTree->printTree();
        }
        if (topRightTree != nullptr) {
            topRightTree->printTree();
        }
        if (botLeftTree != nullptr) {
            botLeftTree->printTree();
        }
        if (botRightTree != nullptr) {
            botRightTree->printTree();
        }
    }
};

int main() {
    Quad center(new Point(0, 0), new Point(8, 8));
    Point p1(1, 1);
    Point p2(2, 5);
    Point p3(7, 6);
    Point p4(6, 3);
    center.insert(&p1);
    center.insert(&p2);
    center.insert(&p3);
    center.insert(&p4);
    center.printTree();
    Point p5(7, 7);
    Point *res = center.search(&p5);
    if (res == nullptr) {
        std::cout << "Point not found\n";
    } else {
        std::cout << "Point found: (" << res->x << ", " << res->y << ")\n";
    }
    return 0;
}
