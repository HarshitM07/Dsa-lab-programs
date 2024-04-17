#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node *insertInBinaryTree(Node *&head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }
    if (val < head->data)
    {
        head->left = insertInBinaryTree(head->left, val);
    }
    else
    {
        head->right = insertInBinaryTree(head->right, val);
    }
    return head;
}
void inOrder(Node *&head)
{
    if (head == nullptr)
        return;
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}
void preOrder(Node *&head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}
void postOrder(Node *&head)
{
    if (head == nullptr)
        return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}
Node *inOrderSucc(Node *h)
{
    while (h->left != nullptr)
    {
        h = h->left;
    }
    return h;
}
Node* helper(Node* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        Node* rightChild = root->right;
        Node* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    Node* findLastRight(Node* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
// public:
    Node* deleteNode(Node* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->data == key){
            return helper(root);
        }

        Node* dummy = root;

        while(root !=  NULL){
            if(root->data >= key){
                if(root->left !=NULL && root->left->data == key ){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right !=NULL && root->right->data == key ){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
        }
int main()
{
    Node *head = nullptr;
    while (true)
    {
        cout << "Enter 1 to insert in Binary Tree\nEnter 2 for inorder Traversal\nEnter 3 for preorder Traversal\nEnter 4 for postorder Traversal\nEnter 5 for deleting a node\nEnter 6 to exit" << endl;
        int k;
        cin >> k;
        if (k == 1)
        {
            cout << "Enter Number of element to insert in tree " << endl;
            int n;
            cin >> n;
            cout
                << "Enter elements " << endl;
            for (int
                     i = 0;
                 i < n; i++)
            {
                int x;
                cin >> x;
                head = insertInBinaryTree(head, x);
            }
        }
        else if (k == 2)
        {
            inOrder(head);
            cout << endl;
        }
        else if (k == 3)
        {
            preOrder(head);
            cout << endl;
        }
        else if (k == 4)
        {
            postOrder(head);
            cout << endl;
        }
        else if (k == 5)
        {
            cout << "Enter value to delete" << endl;
            int a;
            cin >> a;
            head = deleteNode(head, a);
        }
        else if (k == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
}