/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>

class Point {
public:
    int x, y, z;
    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

class Octree {
public:
    Point *topLeftFront, *botRightBack;
    Point *point;
    Octree *children[8];

    Octree(Point *topLF, Point *botRB) {
        topLeftFront = topLF;
        botRightBack = botRB;
        point = nullptr;
        for (int i = 0; i < 8; i++) {
            children[i] = nullptr;
        }
    }

    bool inBoundary(Point *p) {
        return (p->x >= topLeftFront->x && p->x <= botRightBack->x &&
                p->y >= topLeftFront->y && p->y <= botRightBack->y &&
                p->z >= topLeftFront->z && p->z <= botRightBack->z);
    }

    void insert(Point *p) {
        if (!inBoundary(p)) {
            return;
        }

        if (abs(topLeftFront->x - botRightBack->x) <= 1 &&
            abs(topLeftFront->y - botRightBack->y) <= 1 &&
            abs(topLeftFront->z - botRightBack->z) <= 1) {
            if (point == nullptr) {
                point = p;
            }
            return;
        }

        int midX = (topLeftFront->x + botRightBack->x) / 2;
        int midY = (topLeftFront->y + botRightBack->y) / 2;
        int midZ = (topLeftFront->z + botRightBack->z) / 2;

        int index = (p->x <= midX) * 4 + (p->y <= midY) * 2 + (p->z <= midZ);
        if (children[index] == nullptr) {
            children[index] = new Octree(
                new Point(index & 4 ? topLeftFront->x : midX, index & 2 ? topLeftFront->y : midY, index & 1 ? topLeftFront->z : midZ),
                new Point(index & 4 ? midX : botRightBack->x, index & 2 ? midY : botRightBack->y, index & 1 ? midZ : botRightBack->z));
        }
        children[index]->insert(p);
    }

    Point *search(Point *p) {
        if (!inBoundary(p)) {
            return nullptr;
        }

        if (point != nullptr) {
            return point;
        }

        int midX = (topLeftFront->x + botRightBack->x) / 2;
        int midY = (topLeftFront->y + botRightBack->y) / 2;
        int midZ = (topLeftFront->z + botRightBack->z) / 2;

        int index = (p->x <= midX) * 4 + (p->y <= midY) * 2 + (p->z <= midZ);
        if (children[index] == nullptr) {
            return nullptr;
        }
        return children[index]->search(p);
    }

    void printTree() {
        if (point != nullptr) {
            std::cout << "Point(" << point->x << ", " << point->y << ", " << point->z << ")\n";
        }

        for (int i = 0; i < 8; i++) {
            if (children[i] != nullptr) {
                children[i]->printTree();
            }
        }
    }
};

int main() {
    Octree center(new Point(0, 0, 0), new Point(8, 8, 8));
    Point p1(1, 1, 1);
    Point p2(2, 5, 5);
    Point p3(7, 6, 6);
    Point p4(6, 3, 3);
    center.insert(&p1);
    center.insert(&p2);
    center.insert(&p3);
    center.insert(&p4);
    center.printTree();
    Point p5(7, 7, 7);
    Point *res = center.search(&p5);
    if (res == nullptr) {
        std::cout << "Point not found\n";
    } else {
        std::cout << "Point found: (" << res->x << ", " << res->y << ", " << res->z << ")\n";
    }
    return 0;
}
