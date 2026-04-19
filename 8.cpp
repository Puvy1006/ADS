#include <iostream>
using namespace std;

// Node
struct Node {
    string dir;
    int color; // 0 = RED, 1 = BLACK
    Node *left, *right, *parent;

    Node(string name) {
        dir = name;
        color = 0;
        left = right = parent = NULL;
    }
};

class RBTree {
    Node *root;

public:
    RBTree() {
        root = NULL;
    }

    // LEFT ROTATION
    void rotateLeft(Node *x) {
        Node *y = x->right;
        if (y == NULL) return;

        x->right = y->left;

        if (y->left != NULL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // RIGHT ROTATION
    void rotateRight(Node *x) {
        Node *y = x->left;
        if (y == NULL) return;

        x->left = y->right;

        if (y->right != NULL)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node *z) {
        while (z != root && z->parent != NULL && z->parent->color == 0) {
            Node *parent = z->parent;
            Node *grandparent = parent->parent;

            if (grandparent == NULL)
                break;

            if (parent == grandparent->left) {
                Node *uncle = grandparent->right;

                if (uncle != NULL && uncle->color == 0) {
                    parent->color = 1;
                    uncle->color = 1;
                    grandparent->color = 0;
                    z = grandparent;
                }
                else {
                    if (z == parent->right) {
                        z = parent;
                        rotateLeft(z);
                    }

                    parent->color = 1;
                    grandparent->color = 0;
                    rotateRight(grandparent);
                }
            }
            else {
                Node *uncle = grandparent->left;

                if (uncle != NULL && uncle->color == 0) {
                    parent->color = 1;
                    uncle->color = 1;
                    grandparent->color = 0;
                    z = grandparent;
                }
                else {
                    if (z == parent->left) {
                        z = parent;
                        rotateRight(z);
                    }

                    parent->color = 1;
                    grandparent->color = 0;
                    rotateLeft(grandparent);
                }
            }
        }

        if (root != NULL)
            root->color = 1;
    }

    // INSERT
    void insert(string name) {
        Node *z = new Node(name);
        Node *y = NULL;
        Node *x = root;

        while (x != NULL) {
            y = x;
            if (name < x->dir)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;

        if (y == NULL)
            root = z;
        else if (name < y->dir)
            y->left = z;
        else
            y->right = z;

        fixInsert(z);
    }

    // DISPLAY (LEVEL ORDER)
    void display() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return;
        }

        Node* queue[100];
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Node* temp = queue[front++];

            cout << temp->dir << " ("
                 << (temp->color == 0 ? "R" : "B") << ") ";

            if (temp->left != NULL)
                queue[rear++] = temp->left;

            if (temp->right != NULL)
                queue[rear++] = temp->right;
        }

        cout << endl;
    }
};

int main() {
    RBTree fs;
    int choice;
    string name;

    do {
        cout << "\n--- FILE SYSTEM MENU ---\n";
        cout << "1. Insert Directory\n";
        cout << "2. Display Directories\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter directory name: ";
            cin >> name;
            fs.insert(name);
            cout << "Directory inserted!\n";
            break;

        case 2:
            cout << "Directory Structure:\n";
            fs.display();
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}

