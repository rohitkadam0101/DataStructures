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
        right =  NULL;
    }

};

int search(int  inorder[],int start, int end ,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
Node *constructTree(int preorder[], int inorder[],int start,int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[idx]; // first element will be root similarly create next nodes from preorder array which will act as root for each call
    idx++;
    Node *node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos  = search(inorder,start,end,curr); // search position of that node in inorder array to find its left subarray and right subarray
    node->left = constructTree(preorder,inorder,start,pos-1);
    node->right = constructTree(preorder,inorder,pos+1,end);

    return node;

}

void preorderPrint(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node *root = constructTree(preorder,inorder,0,4);
    preorderPrint(root);
    return 0;
}