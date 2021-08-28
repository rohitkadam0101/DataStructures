#include <iostream>
using namespace std;


struct Node{  // or class Node and make everything public to access it outside the class
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){ //constructor
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    struct Node *root  = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    return 0;
}