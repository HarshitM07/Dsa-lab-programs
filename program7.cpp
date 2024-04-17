#include<iostream>
#include<queue>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }

};

node* buildTree(node* root){
    cout<<"Enter the data : "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inerting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void preorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
void inorderTraversal(node* root){
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            //old level is completed
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
    }
}
int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"preorder traversal"<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"postorder traversal"<<endl;
    postorderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal"<<endl;
    inorderTraversal(root);

    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;
}