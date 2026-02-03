#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int d) {
        data = d;
        color = RED;
        left = right = parent = NULL;
    }
};

class RedBlackTree {
private:
    Node* root;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left)
            y->left->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right)
            y->right->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* z) {
        while (z != root && z->parent->color == RED) {
            Node* parent = z->parent;
            Node* grand = parent->parent;

            if (parent == grand->left) {
                Node* uncle = grand->right;

                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grand->color = RED;
                    z = grand;
                } else {
                    if (z == parent->right) {
                        z = parent;
                        rotateLeft(z);
                    }
                    parent->color = BLACK;
                    grand->color = RED;
                    rotateRight(grand);
                }
            } else {
                Node* uncle = grand->left;

                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grand->color = RED;
                    z = grand;
                } else {
                    if (z == parent->left) {
                        z = parent;
                        rotateRight(z);
                    }
                    parent->color = BLACK;
                    grand->color = RED;
                    rotateLeft(grand);
                }
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() {
        root = NULL;
    }

    void insert(int data) {
        Node* z = new Node(data);
        Node* y = NULL;
        Node* x = root;

        while (x) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;

        if (!y)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        fixInsert(z);
    }
};

int main() {
    RedBlackTree t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(15);

    cout << "Red-Black Tree insertion completed\n";
    return 0;
}
