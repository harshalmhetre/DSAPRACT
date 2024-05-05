#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

class BST{
    public :
    Node* root =NULL;

    void insert(int val){
        Node* temp =new Node;
        temp->data=val;

        if(this->root==NULL){
            this->root=temp;

        }
        else{
            Node* cur =this->root;
            while(true){
                if(val > cur->data){
                    if(cur->right==NULL){
                        cur->right=temp;
                        break;
                    }
                    cur=cur->left;

                }else{
                    if(cur->left==NULL){
                        cur->left=temp;
                        break;
                    }        
                    cur=cur->left;
                }
            }
        }

    }
void  inorder(Node *root)
{
    
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<"\t"<<root->data;
        inorder(root->right);
    }    
}
void  search(int val,Node* root){
    
    Node* temp=root;
    int c=0;
    while(temp!=NULL){
        if(temp->data==val){
            c=1;
            break;
        }
        else if(val> temp->data){
                temp=temp->right;
            }
        else{
                temp=temp->left;
        }
        }
    if(c==1){
        cout<<"\nElement is present";
    }
    else{
        cout<<"\nElement is Absent";
    }
}

void minimum(){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;

    }
    cout<<"\nMinimum value is :"<<temp->data;
}
void maximum(){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;

    }
    cout<<"\nMaximum value is  :"<<temp->data;
}

void mirror(Node* root){
    Node* temp=root;
    if(temp!=NULL){
        swap(temp->left,temp->right);
        mirror(temp->left);
        mirror(temp->right);
    }
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int hl=height(root->left);
    int hr =height(root->right);

    return max(hl,hr)+1 ;
}
};

int main (){
    BST t;
    t.insert(10);
    t.insert(4);
    t.insert(15);
    
    cout<<"\nInorder of tree";
    t.inorder(t.root);
    int n, i ,h;
    
    cout<<"\nEnter the 1st no. to search :";
    cin>>n;
    t.search(n,t.root);
    cout<<"\nEnter the 2nd no. to search :";
    cin>>i;
    t.search(i,t.root);

    t.maximum();
    t.minimum();
    t.mirror(t.root);
    cout<<"\nInorder after transversal";
    t.inorder(t.root);

    h=t.height(t.root);
    cout<<"\nHeight of the tree"<<h;



    
    return 0;
}