#include <iostream>
using namespace std;

class Node {
public:
    int score;
    int player_id;
    Node *left, *right;
    int height;

    Node(int id, int s) {
        player_id = id;
        score = s;
        left = right = NULL;
        height = 1;
    }
};

int height(Node *N) {
    return (N == NULL) ? 0 : N->height;
}

int getBalance(Node *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

// Right Rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left Rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// INSERT PLAYER
Node* insert(Node* root, int id, int score) {
    if (root == NULL)
        return new Node(id, score);

    if (score < root->score)
        root->left = insert(root->left, id, score);
    else if (score > root->score)
        root->right = insert(root->right, id, score);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // AVL Rotations
    if (balance > 1 && score < root->left->score)
        return rightRotate(root);

    if (balance < -1 && score > root->right->score)
        return leftRotate(root);

    if (balance > 1 && score > root->left->score) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && score < root->right->score) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// FIND MIN
Node* minValueNode(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// DELETE PLAYER (by score)
Node* deleteNode(Node* root, int score) {
    if (root == NULL)
        return root;

    if (score < root->score)
        root->left = deleteNode(root->left, score);
    else if (score > root->score)
        root->right = deleteNode(root->right, score);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                delete root;
                return NULL;
            } else {
                Node* t = temp;
                delete root;
                return t;
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->score = temp->score;
            root->player_id = temp->player_id;
            root->right = deleteNode(root->right, temp->score);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Balance again
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// LEADERBOARD (Descending Order)
void displayLeaderboard(Node* root) {
    if (root != NULL) {
        displayLeaderboard(root->right);
        cout << "Player ID: " << root->player_id
             << " Score: " << root->score << endl;
        displayLeaderboard(root->left);
    }
}

// MAIN MENU
int main() {
    Node* root = NULL;
    int choice, id, score;

    do {
        cout << "\n GAME MENU \n";
        cout << "1. Register Player\n";
        cout << "2. Display Leaderboard\n";
        cout << "3. Remove Player (by score)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Player ID: ";
            cin >> id;
            cout << "Enter Score: ";
            cin >> score;
            root = insert(root, id, score);
            break;

        case 2:
            cout << "\n Leaderboard \n";
            displayLeaderboard(root);
            break;

        case 3:
            cout << "Enter Score to remove: ";
            cin >> score;
            root = deleteNode(root, score);
            break;

        case 4:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}



