#include<iostream>
using namespace std;

struct node
{
  int data;
  node*left;
  node*right;
  node(int val)
  {
  data=val;
  left=right=NULL;
}};

class BST
{
 node*root;
 public:
 BST()
 {
  root=NULL;
 }
 
void insert(int v)
{
node*temp=new node(v);
if(root==NULL)
 {
 root=temp;
  cout<<"Tree is empty"<<endl;
  return;
 }
 
 node*curr=root;
 while(curr!=NULL)
 {
  if(v < curr-> data)
   {
    if (curr->left==NULL);
     { curr->left=temp;
     }
    curr=curr->left;
    }
    else
    {
     if (curr->right==NULL)
     {
      curr->right=temp;
      break;
     }
      curr=curr->right;
     }
    }
     cout<<temp->data<<endl;
    }
    
//Traversal
//void inorder(node*root)
//{
// if(root==NULL)
//  return;
//  inorder(root->left);
//  cout<<root->data<<"";
//  inorder (root-> right);
//}
    };
int main()
{ char c;
  BST b;
  do
    {
     int val;
     cout<<"enter no: ";
     cin>>val;
     b.insert(val);
     cin>>c;
    }
  while (c=='y');
  
// cout<<"Inorder:";
//  inorder(root);
  
  return 0;
}
     
