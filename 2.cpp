#include <iostream>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
    int lth;
    int rth;

    Node(int d)
    {
        data = d;
        left = right = NULL;
        lth = rth = 1;
    }
};

// Insert Function
Node* insert(Node* root, int key)
{
    Node* temp = new Node(key);
    Node* parent = NULL;

    if (root == NULL)
    {
        root = temp;
        return root;
    }

    Node* curr = root;

    while (curr != NULL)
    {
        if (key == curr->data)
        {
            cout << "Duplicate key not allowed\n";
            return root;
        }

        parent = curr;

        if (key < curr->data)
        {
            if (curr->lth == 0)
                curr = curr->left;
            else
                break;
        }
        else
        {
            if (curr->rth == 0)
                curr = curr->right;
            else
                break;
        }
    }

    if (key < parent->data)
    {
        temp->left = parent->left;
        temp->right = parent;
        parent->lth = 0;
        parent->left = temp;
    }
    else
    {
        temp->left = parent;
        temp->right = parent->right;
        parent->rth = 0;
        parent->right = temp;
    }

    return root;
}

// Search Function
bool search(Node* root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            cout << "Node " << key << " found in tree\n";
            return true;
        }
        else if (key < root->data)
        {
            if (root->lth == 0)
                root = root->left;
            else
                break;
        }
        else
        {
            if (root->rth == 0)
                root = root->right;
            else
                break;
        }
    }

    cout << "Node not found\n";
    return false;
}

// Inorder Successor
Node* inorderSuccessor(Node* curr)
{
    if (curr->rth == 1)
        return curr->right;

    curr = curr->right;
    while (curr->lth == 0)
        curr = curr->left;

    return curr;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }

    Node* curr = root;

    while (curr->lth == 0)
        curr = curr->left;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = inorderSuccessor(curr);
    }
    cout << endl;
}

// Main Menu
int main()
{
    Node* root = NULL;
    int choice, value;

    do
    {
        cout << "\n MENU \n";
        cout << "1. Insert\n";
        cout << "2. Display (Inorder)\n";
        cout << "3. Search\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                search(root, value);
                break;

            case 4:
                cout << "Exiting \n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
