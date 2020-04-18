#include<bits/stdc++.h>
using namespace std;

class node
{
public:

    int key;
    node *right = NULL;
    node* left = NULL;
};
//creating new node

node* newNode(node *temp, int item)
{
    temp = new node();
    temp ->key = item;
    temp->left = temp ->right = NULL;
    return temp;

}
//inserting new node
node* insertNode(node *root, int key)
{
    if(root == NULL) return newNode(root,key);
    else
    {
        if(key < root->key)
            root->left = insertNode(root->left,key);
        else
        {
            root->right = insertNode(root->right, key);
        }
        return root;
    }

}
//in order traversal
void inorder(node *root)
{

    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);

    }
}
//checking for the minimum value
node* minValue(node *root)
{
    node *current = root;

    while(current && current->left != NULL){
        current = current->left;
    }
    return current;

}
//deleting node
node* deleteNode(node *root, int key)
{
    if(root == NULL)
        return root;
    if(key < root->key)
        root->left = deleteNode(root->left,key);

    else if(key > root->key)
    {
        root->right = deleteNode(root->right,key);
    }
    //if the key == root->key
    else{
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;

        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        //setting the root node
        node *temp = minValue(root->right);

        root->key = temp->key;
        root->right = deleteNode(root->right , temp ->key);
    }
    return root;
}
//driver method
int main()
{
    node *root;
    cout<<"Enter the no of node to be present in the BST:"<<endl;
    int n;
    cin>>n;
    for(int i =0; i<n; i++)
    {
        int key;
        cout<<"Enter the "<<i<<"th key"<<endl;
        cin>>key;
        root = insertNode(root,key);
    }
    inorder(root);
    int temp = 0;
    while(temp != 1)
    {
    cout<<"Enter the node key you want to delete:"<<endl;
    int DelKey;
    cin>>DelKey;
    root = deleteNode(root,DelKey);

    cout<<"after deleting node the BST is:"<<endl;
    inorder(root);

    cout<<"Enter 1 to exit:"<<endl;
    cin>>temp;
    }
    return 0;

}
