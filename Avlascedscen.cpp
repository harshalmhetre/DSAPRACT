#include <iostream>
#include <string>

using namespace std;

struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(string key, string mean) : keyword(key), meaning(mean), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, string key, string mean) {
        if (node == nullptr)
            return new Node(key, mean);

        if (key < node->keyword)
            node->left = insertNode(node->left, key, mean);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, mean);
        else
            node->meaning = mean; // Update meaning for existing keyword

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->keyword)
            return rightRotate(node);

        if (balance < -1 && key > node->right->keyword)
            return leftRotate(node);

        if (balance > 1 && key > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, string key) {
        if (root == nullptr)
            return root;

        if (key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if (key > root->keyword)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->keyword = temp->keyword;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void displayInOrder(Node* node) {
        if (node != nullptr) {
            displayInOrder(node->left);
            cout << node->keyword << ": " << node->meaning << endl;
            displayInOrder(node->right);
        }
    }

    void displayReverseInOrder(Node* node) {
        if (node != nullptr) {
            displayReverseInOrder(node->right);
            cout << node->keyword << ": " << node->meaning << endl;
            displayReverseInOrder(node->left);
        }
    }

    int searchHelper(Node* node, string key, int& comparisons) {
        if (node == nullptr)
            return -1;

        comparisons++;
        if (node->keyword == key)
            return comparisons;

        if (key < node->keyword)
            return searchHelper(node->left, key, comparisons);
        else
            return searchHelper(node->right, key, comparisons);
    }

public:
    AVLTree() : root(nullptr) {}

    void Insert(string key, string mean) {
        root = insertNode(root, key, mean);
    }

    void Delete(string key) {
        root = deleteNode(root, key);
    }

    void DisplayAscending() {
        cout << "Dictionary Contents (Ascending Order):\n";
        displayInOrder(root);
    }

    void DisplayDescending() {
        cout << "Dictionary Contents (Descending Order):\n";
        displayReverseInOrder(root);
    }

    int Search(string key) {
        int comparisons = 0;
        int result = searchHelper(root, key, comparisons);
        cout << "Maximum comparisons required for finding keyword \"" << key << "\": " << comparisons << endl;
        return result;
    }
};

int main() {
    AVLTree dictionary;
    int choice;
    string key, mean;
    int comparisons; // Move the declaration outside the switch block

    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Keyword\n";
        cout << "2. Search Keyword\n";
        cout << "3. Update Meaning of Keyword\n";
        cout << "4. Display (Ascending Order)\n";
        cout << "5. Display (Descending Order)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore(); // Clear buffer
                getline(cin, mean);
                dictionary.Insert(key, mean);
                cout << "Keyword \"" << key << "\" inserted.\n";
                break;
            case 2:
                cout << "Enter keyword to search: ";
                cin >> key;
                comparisons = dictionary.Search(key); // Assign here
                if (comparisons != -1)
                    cout << "Keyword \"" << key << "\" found after " << comparisons << " comparisons.\n";
                else
                    cout << "Keyword \"" << key << "\" not found.\n";
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> key;
                cout << "Enter new meaning: ";
                cin.ignore(); // Clear buffer
                getline(cin, mean);
                dictionary.Insert(key, mean);
                cout << "Meaning of keyword \"" << key << "\" updated.\n";
                break;
            case 4:
                dictionary.DisplayAscending();
                break;
            case 5:
                dictionary.DisplayDescending();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
