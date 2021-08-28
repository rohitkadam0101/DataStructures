// inorder preorder and postorder

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    bool l = search(root->left,key);
    if(l){
        return true;
    }
    bool r = search(root->right,key);
    return r; 
    
    }

int main(){
    //     1
    //  2    3
    // 4 5   6  7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right =  new Node(3);
    root->left->left = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);
    cout<<"Preorder Traversal:- "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal:- "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal:- "<<endl;
    postorder(root);
    cout<<endl;
    if(search(root,6)){
        cout<<"It exists in tree";
    }
    else{
        cout<<"It does not exists in tree";
    }
    return 0; 
}