#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node {
    char word[10], mean[10];
    node *left;
    node *right;
    int ht;

   
};

class AVL {
public:
    node* create(node* root);
    node* insert(node* root, char word[], char mean[]);
    void display(node* root);
    int height(node* root);
    node* rotateright(node* x);
    node* rotateleft(node* x);
    int bf(node* root);
    node* RR(node* T);
    node* LL(node* T);
    node* LR(node* T);
    node* RL(node* T);
    node* minValueNode(node* root);
    node* deleteNode(node* root,  char word[]);
    node*balanceNode(node*root); 
    node*update(node*root,char word[],char newMean[]);
    node*search(node*root,char word[]);
};

node* AVL::create(node* root) {
    int n, i;
    char w[20], m[50];
    cout << "\n Enter total number of words:";
    cin >> n;		
    for (i = 0; i < n; i++) {
        cout << "\n Enter word " << i + 1 << " : ";
        cin >> w;
        cout << "\n Enter meaning : ";
        cin >> m;
        root = insert(root, w, m);
    }
    return root;
}

node* AVL::insert(node* root, char w[], char m[]) {
    if (root == NULL) {
        root = new node;
        strcpy(root->word, w);
        strcpy(root->mean, m);
        root->left = NULL;
        root->right = NULL;
        return root;
    } 
	else {
        if (strcmp(w, root->word) > 0) 
            root->right = insert(root->right, w, m);

	else
                root->left = insert(root->left, w, m);

        }
    root=balanceNode(root);
    root->ht = height(root);
    return root;
}

void AVL::display(node* root) {
    if (root == NULL)
        return ;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
   
            node* temp= q.front();
            q.pop();
            cout << "\nRoot: " << temp->word << "-" << temp->mean;

            if (temp->left) {
                cout << "\nLeft child of " << temp->word << ": " << temp->left->word << "-" << temp->left->mean;
                q.push(temp->left);
            } else {
                cout << "\nLeft child of " << temp->word << " is NULL";
            }

            if (temp->right) {
                cout << "\nRight child of " << temp->word << ": " << temp->right->word << "-" << temp->right->mean;
                q.push(temp->right);
            } else {
                cout << "\nRight child of " << temp->word << " is NULL";
            }
    }
}

int AVL::height(node* root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh>rh)
        return (lh+1);
    else 
        return (rh+1);
}

node*AVL::update(node*root,char word[],char newMean[])
{

	root=deleteNode(root,word);
	root=insert(root,word,newMean);
	return(root);
}

node* AVL::rotateright(node* x) {
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* AVL::rotateleft(node* x) {
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

int AVL::bf(node* root) {
   int lh,rh;
	if(root==NULL)
		return(0);
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
	if(root->right==NULL)
	  rh=0;
	else
		rh=1+root->right->ht;
	int z=lh-rh;
	return(z);
}

node* AVL::RR(node* T) {
    T = rotateleft(T);
    return T;
}

node* AVL::LL(node* T) {
    T = rotateright(T);
    return T;
}

node* AVL::LR(node* T) {
    T->left = rotateleft(T->left);
    T = rotateright(T);
    return T;
}

node* AVL::RL(node* T) {
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return T;
}

 node* AVL::search(node* root,  char word[]) {
    if (root == NULL || strcmp(root->word, word) == 0)
        return root;

    if (strcmp(word,root->word) <0)
        return search(root->left, word);

    return search(root->right, word);
} 

node* AVL::minValueNode(node* root) {
    node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node* AVL::balanceNode(node* root) {	
    if (root == NULL)
        return root;

    root->ht = height(root);
    int balance = bf(root);

    if (balance > 1 && bf(root->left) >= 0)
        return LL(root);
	
    if (balance > 1 && bf(root->left) < 0) {
        root->left = LR(root->left);
        return LL(root);
    }

    if (balance < -1 && bf(root->right) <= 0)
        return RR(root);

    if (balance < -1 && bf(root->right) > 0) {
        root->right = RL(root->right);
        return RR(root);
    }

    return root;
}

node* AVL::deleteNode(node* root,  char word[]) {
    if (root == NULL)
        return root;
// # delt from left sub tree 
    if (strcmp(word, root->word) < 0)
        root->left = deleteNode(root->left, word);
    // # delt from right sub tree 
    else if (strcmp(word, root->word) > 0)
        root->right = deleteNode(root->right, word);
    else {

	// node with only 1 child or no child
        if (root->left == NULL || root->right == NULL) {
            node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
		return root;

            } else
                *root = *temp;
            delete temp;
        } else {
            node* temp = minValueNode(root->right);
            strcpy(root->word, temp->word);
            strcpy(root->mean, temp->mean);
            root->right = deleteNode(root->right, temp->word);
        }
    }

 root = balanceNode(root);
 return(root);
}


int main() {
    AVL tree;
    node* root = NULL;
    int choice;
    char searchWord[10], deleteWord[10], updateWord[10], newMeaning[10];

    do {
        cout << "\n1. Create AVL tree";
        cout << "\n2. Display AVL tree";
        cout << "\n3. Search word";
        cout << "\n4. Delete word";
        cout << "\n5. Update meaning";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        node* searchedNode = NULL; 

        switch(choice) {
            case 1:
                root = tree.create(root);
                break;
            case 2:
                cout << "\nAVL Tree:";
                tree.display(root);
                break;
             case 3:
                cout << "\nEnter the word to search: ";
                cin >> searchWord;
                searchedNode = tree.search(root, searchWord);
                if (searchedNode)
                    cout << "\nMeaning of " << searchWord << " is: " << searchedNode->mean;
                else
                    cout << "\nWord not found.";
                break;
            case 4:
                cout << "\nEnter the word to delete: ";
                cin >> deleteWord;
                root = tree.deleteNode(root, deleteWord);
                cout << "\nAVL Tree after deletion:";
                tree.display(root);
                break;
           case 5:
                cout << "\nEnter the word to update: ";
                cin >> updateWord;
                cout << "\nEnter the new meaning: ";
                cin >> newMeaning;
                root = tree.update(root, updateWord, newMeaning);
                cout << "\nAVL Tree after update:";
                tree.display(root);
		break;
                		                                                                                                                                                                                    
            case 6:
                cout << "\nExited Sucessfully !!"<<endl;
                break;
            default:
                cout << "\nInvalid choice!"<<endl;
        }
    } while(choice != 6);

    return 0;
}

