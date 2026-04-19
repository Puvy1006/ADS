#include <iostream>
using namespace std;
class Node {
public:
    string word, meaning;
    Node *left, *right;

    Node(string w, string m) {
        word = w;
        meaning = m;
        left = right = NULL;
    }
};

class LLNode {
public:
    Node* data;
    LLNode* next;

    LLNode(Node* d) {
        data = d;
        next = NULL;
    }
};

class Dictionary {
    Node* root;

public:
    Dictionary() {
        root = NULL;
    }

    // Insert Word 
    void insert(string w, string m) {
        Node* newNode = new Node(w, m);

        if (root == NULL) {
            root = newNode;
            cout << "Word inserted.\n";
            return;
        }

        Node *curr = root, *parent = NULL;

        while (curr != NULL) {
            parent = curr;

            if (w == curr->word) {
                curr->meaning = m;     
                delete newNode;
                cout << "Duplicate found. Meaning updated.\n";
                return;
            }
            else if (w < curr->word)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (w < parent->word)
            parent->left = newNode;
        else
            parent->right = newNode;

        cout << "Word inserted.\n";
    }

    // Search Word
    void search(string w) {
        Node* curr = root;

        while (curr != NULL) {
            if (w == curr->word) {
                cout << "Found: " << curr->meaning << endl;
                return;
            }
            else if (w < curr->word)
                curr = curr->left;
            else
                curr = curr->right;
        }

        cout << "Word not found.\n";
    }

    // Delete Word
    void deleteWord(string w) {
        Node *curr = root, *parent = NULL;

        while (curr && curr->word != w) {
            parent = curr;
            if (w < curr->word)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (!curr) {
            cout << "Word not found.\n";
            return;
        }

        // Case 1: 0 or 1 child
        if (!curr->left || !curr->right) {
            Node* child = curr->left ? curr->left : curr->right;

            if (!parent)
                root = child;
            else if (parent->left == curr)
                parent->left = child;
            else
                parent->right = child;

            delete curr;
        }
        else {
            // Case 2: Two children 
            Node *succParent = curr;
            Node *succ = curr->right;

            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }

            curr->word = succ->word;
            curr->meaning = succ->meaning;

            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            delete succ;
        }

        cout << "Word deleted.\n";
    }

    // Display Dictionary
    void display() {
        LLNode* top = NULL;
        Node* curr = root;

        while (curr || top) {
            while (curr) {
                LLNode* temp = new LLNode(curr);
                temp->next = top;
                top = temp;
                curr = curr->left;
            }

            LLNode* temp = top;
            top = top->next;

            curr = temp->data;
            delete temp;

            cout << curr->word << " : " << curr->meaning << endl;

            curr = curr->right;
        }
    }

    // Mirror Image of Dictionary
    void mirror() {
        if (!root) return;

        LLNode* head = new LLNode(root);

        while (head) {
            Node* curr = head->data;

            Node* t = curr->left;
            curr->left = curr->right;
            curr->right = t;

            if (curr->left) {
                LLNode* n = new LLNode(curr->left);
                n->next = head;
                head = n;
            }
            if (curr->right) {
                LLNode* n = new LLNode(curr->right);
                n->next = head;
                head = n;
            }

            LLNode* del = head;
            head = head->next;
            delete del;
        }

        cout << "Mirror created.\n";
    }

    // Copy Dictionary
    void copyTo(Dictionary &d2) {
        if (!root) return;

        LLNode* head = new LLNode(root);

        while (head) {
            Node* curr = head->data;
            d2.insert(curr->word, curr->meaning);

            if (curr->left) {
                LLNode* n = new LLNode(curr->left);
                n->next = head;
                head = n;
            }
            if (curr->right) {
                LLNode* n = new LLNode(curr->right);
                n->next = head;
                head = n;
            }

            LLNode* del = head;
            head = head->next;
            delete del;
        }

        cout << "Dictionary copied.\n";
    }

    // Level-wise Display 
    void levelWise() {
        if (!root) return;

        LLNode *front = new LLNode(root);
        LLNode *rear = front;

        while (front) {
            Node* curr = front->data;
            cout << curr->word << " ";

            if (curr->left) {
                rear->next = new LLNode(curr->left);
                rear = rear->next;
            }
            if (curr->right) {
                rear->next = new LLNode(curr->right);
                rear = rear->next;
            }

            LLNode* del = front;
            front = front->next;
            delete del;
        }
        cout << endl;
    }
};


int main() {
    Dictionary dict, copyDict;
    int choice;
    string word, meaning;

    do {
        cout << "\n DICTIONARY MENU \n";
        cout << "1. Insert Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Search Word\n";
        cout << "4. Display Dictionary\n";
        cout << "5. Mirror Dictionary\n";
        cout << "6. Create Copy\n";
        cout << "7. Level-wise Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            dict.insert(word, meaning);
            break;

        case 2:
            cout << "Enter word to delete: ";
            cin >> word;
            dict.deleteWord(word);
            break;

        case 3:
            cout << "Enter word to search: ";
            cin >> word;
            dict.search(word);
            break;

        case 4:
            dict.display();
            break;

        case 5:
            dict.mirror();
            break;

        case 6:
            dict.copyTo(copyDict);
            break;

        case 7:
            dict.levelWise();
            break;
        }

    } while (choice != 8);

    return 0;
}
