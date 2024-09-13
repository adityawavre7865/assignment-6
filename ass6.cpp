#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node *next;
    Node(int c = 0, int p = 0) : coeff(c), pow(p), next(nullptr) {}
};

class LL {
public:
    Node *head;

    LL() : head(nullptr) {}

    void create_node(int x, int y) {
        Node *nn = new Node(x, y);
        if (!head) {
            head = nn;
        } else {
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    LL polyadd(const LL& l2) const {
        LL result;
        Node *p1 = head;
        Node *p2 = l2.head;
        Node *last = nullptr;

        while (p1 && p2) {
            Node *nn = nullptr;
            if (p1->pow > p2->pow) {
                nn = new Node(p1->coeff, p1->pow);
                p1 = p1->next;
            } else if (p1->pow < p2->pow) {
                nn = new Node(p2->coeff, p2->pow);
                p2 = p2->next;
            } else {
                nn = new Node(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }

            if (!result.head) {
                result.head = nn;
                last = nn;
            } else {
                last->next = nn;
                last = nn;
            }
        }

        while (p1) {
            Node *nn = new Node(p1->coeff, p1->pow);
            if (!result.head) {
                result.head = nn;
                last = nn;
            } else {
                last->next = nn;
                last = nn;
            }
            p1 = p1->next;
        }

        while (p2) {
            Node *nn = new Node(p2->coeff, p2->pow);
            if (!result.head) {
                result.head = nn;
                last = nn;
            } else {
                last->next = nn;
                last = nn;
            }
            p2 = p2->next;
        }

        return result;
    }

    void printpoly() const {
        Node *temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->pow;
            temp = temp->next;
            if (temp) cout << " + ";
        }
    }
};

int main() {
    LL l1, l2;
    l1.create_node(41, 7);
    l1.create_node(12, 5);
    l1.create_node(65, 0);
    l2.create_node(21, 5);
    l2.create_node(15, 2);

    cout << "Polynomial 1: ";
    l1.printpoly();
    cout << "\nPolynomial 2: ";
    l2.printpoly();

    LL l3 = l1.polyadd(l2);
    cout << "\nPolynomial after adding p1 and p2: ";
    l3.printpoly();

    return 0;
}

