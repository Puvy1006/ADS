#include<iostream>
using namespace std;

struct Node
  {
   int data;
   Node*left;
   Node*right;
  };
  
Node*createNode(int value)
 {
  Node*newNode=new Node;
  newNode->data=value;
  newNode->left=newNode->right=NULL;
 return newNode;
 }
 
//Insert Node
Node*insert(Node*root,int value)
 {
  if(root==NULL)
  return createNode(value);
  
  if(value<root->data)
  root->left=insert(root->left,value);
  
  else if(value>root->data)
  root->right=insert(root->right,value);
  
  return root;
 }
 
Node*findMin(Node*root)
 {
  while(root->left!=NULL)
  root=root->left;
  return root;
 }

//Delete Node
Node*deleteNode(Node*root,int value)
 {
  if(root==NULL)
    return NULL;
    
  if(value<root->data)
    root->left=deleteNode(root->left,value);
    
  else if(value>root->data)
    root->right=deleteNode(root->right,value);
    
  else
      {
       //case 1 : no child
       if(root->left==NULL && root->right==NULL)
         {
          delete root;
          return NULL;
         }
         
       //case 2 : one child
       else if (root->left==NULL)
               {
                Node*temp=root->right;
                delete root;
                return temp;
               }
               
        else if (root->right==NULL)
               {
                Node*temp=root->left;
                delete root;
                return temp;
               } 
       
       //case 3 : Two children
       Node*temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
      }     
       return root;
 }   
//Search element
bool search(Node*root,int value)
 {
  if (root == NULL)
     return false;
    
  if (root->data==value)
     return true;
     
  else if (value<root->data)
     return search(root->left,value);
     
  else 
     return search(root->right,value);
 }   
 
//Display
void display (Node*root)
 {
  if (root==NULL)
     return;
     
   display(root->left);
   cout<<root->data<<" " ;
   display(root->right);
 } 
 
//Mirror image 
void mirrorimage (Node*root)
 {
  if (root==NULL)
     return;
     
   mirrorimage(root->left);
   mirrorimage(root->right);
   cout<<root->data<<" " ;
 } 
 
 
int main()
{
 Node*root=NULL;
 int choice,value;
 
do {
    cout<<"\n BINARY SEARCH TREE MENU \n";
    cout<<"\n 1. Add element :";
    cout<<"\n 2. Delete element : ";
    cout<<"\n 3. Search element : ";
    cout<<"\n 4. Display elements : ";
    cout<<"\n 5. Display mirror elements : ";
    cout<<"\n 6. Exit : \n";
    cout<<"Enter choice : ";
    cin>>choice;
    
    switch(choice)
    {
     case 1 :
          cout<<"Enter value to insert :";
          cin>>value;
          root=insert(root,value);
          break;
          
     case 2 :
          cout<<"Enter value to delete :";
          cin>>value;
          root=deleteNode(root,value);
          break;
          
     case 3 :
          cout<<"Enter value to search :";
          cin>>value;
          if(search(root,value))
             cout<<"Element found!\n";
          else
             cout<<"Element not found!\n";
          break;
              
     case 4 :
          cout<<"Binary search tree elements : ";
          display (root);
          cout<<endl;
          break;
     
     case 5 :
          cout<<"Binary search tree mirror elements : ";
          mirrorimage (root);
          cout<<endl;
          break;
          
     case 6 :
          cout<<"Exiting!";
          break;     
     
    default :
          cout<<"Invalid choice\n";
    }
   } while (choice!=6);
      return 0;
}   
