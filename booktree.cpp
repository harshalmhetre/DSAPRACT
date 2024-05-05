#include <iostream>
#include <string>
using namespace std;

struct Node {
    string chp;
    int count;
    Node* child[10];
};

Node* createNode(string name, int sections) {
    Node* newNode = new Node;
    newNode->chp = name;
    newNode->count = sections;
    return newNode;
}


void getBookInfo(Node* &root) {
    string book, ch;
    int n;
    cout << "\nEnter name of book: ";
    cin >> book;
    root = createNode(book, 0);

    cout << "\nEnter number of chapters: ";
    cin >> n;
    root->count = n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of chapter " << i + 1 << ": ";
        cin >> ch;
        root->child[i] = createNode(ch, 0);

        cout << "How many sections does chapter " << root->child[i]->chp << " have? ";
        cin >> root->child[i]->count;

        for (int j = 0; j < root->child[i]->count; j++) {
            root->child[i]->child[j] = createNode("", 0);
            cout << "\nEnter name of section " << j + 1 << ": ";
            cin >> root->child[i]->child[j]->chp;
        }
    }
}

void displayIndex(Node* root) {
    cout << "\nName of book: " << root->chp;
    cout << "\nNumber of chapters: " << root->count << endl;

    for (int i = 0; i < root->count; i++) {
        cout << "\nChapter " << i + 1 << ": " << root->child[i]->chp << ":\n";
        for (int j = 0; j < root->child[i]->count; j++) {
            cout << "\tSection " << i + 1 << "." << j + 1 << ": " << root->child[i]->child[j]->chp << endl;
        }
    }
}

int main() {
    Node* root = nullptr;

    
    getBookInfo(root);

    
    displayIndex(root);

    return 0;
}
