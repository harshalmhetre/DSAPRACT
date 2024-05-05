#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// Node structure representing a node in the binary tree
struct node {
    char op;
    node *left, *right;
};

// Function to perform postorder traversal and print the postfix expression
void postorder(node *top) {
    stack<node*> s1, s2;
    node *t = top;

    // Push the root node onto s1
    s1.push(t);

    // Perform postorder traversal
    while (!s1.empty()) {
        t = s1.top();
        s1.pop();
        s2.push(t);

        // Push left child onto s1 if exists
        if (t->left != NULL) {
            s1.push(t->left);
        }

        // Push right child onto s1 if exists
        if (t->right != NULL) {
            s1.push(t->right);
        }
    }


    // Print the postfix expression
    while (!s2.empty()) {
        t = s2.top();
        s2.pop();
        cout << t->op;
    }
} 

// void postorder(node *top) {
//     if(top!=NULL){
//         postorder(top->left);
//         postorder(top->right);
//         cout<<" "<<top->op;
//     }
// }
//Function to convert prefix expression to binary tree
node* prefixToTree(char prefix[]) {
    int l = strlen(prefix);
    stack<node*> s;
    node *nn, *t1, *t2;

    for (int i = l - 1; i >= 0; i--) {
        nn = new node;
        nn->left = NULL;
        nn->right = NULL;

        // If the character is an operator, pop two nodes from stack
        if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            t1 = s.top();
            s.pop();
            t2 = s.top();
            s.pop();

            // Create a new node with the operator and set its left and right children
            nn->op = prefix[i];
            nn->left = t1;
            nn->right = t2;

            // Push the new node onto the stack
            s.push(nn);
        } else {
            // If the character is an operand, create a new node and push it onto the stack
            nn->op = prefix[i];
            s.push(nn);
        }
    }

    // Return the root node of the binary tree
    return s.top();
}

int main() {
    char prefix[20];
    
    // Input prefix expression from the user
    cout << "Enter the prefix expression: ";
    cin >> prefix;

    // Convert prefix expression to binary tree
    node *root = prefixToTree(prefix);

    // Perform postorder traversal to print the postfix expression
    cout << "Postfix expression: ";
    postorder(root);

    return 0;
}
    