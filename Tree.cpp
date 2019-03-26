
#include "Tree.hpp"
#include <stdexcept>
#include <cstdlib>
using namespace ariel;


         Tree::Tree()
         {
             treeSize=0;
         }
         Tree::~Tree()
         {
             cout << "deconstructing" << endl ;
         }
    //function to insert a new node (based on data)
    void Tree::insert(int i)
    {
         treeSize++;
         //if its a brand new tree
         if (root_node==NULL)
         {
         root_node=create_node(i);
         return;
         }
         
         //recursive insert to make things easier :)
         insert_rec(root_node,i);
    }
    
    //a recursive function to insert - kind of a helper function
    void Tree::insert_rec(Node *curRoot,int i)
    {
       
         
         //create a temp node to go over the tree with
         Node *temp = curRoot;
         int root_data = curRoot->data;
         //go right
         if (i>root_data)
         {
             if (temp->right==NULL)
             {
                 temp->right=create_node(temp,i);
                 return;
             }
            insert_rec(temp->right,i);
            return;
         }
         
         //go left
         else if (i<root_data)
         { 
             if (temp->left==NULL)
             {
                 temp->left=create_node(temp,i);
                 return;
             }
             insert_rec(temp->left,i);
             return;
         }
         else if (i==root_data)
         throw "cant have 2 nodes with the same i";
         else
         throw "unknown exception in insert";
    }
    
    //function to create a new node
    Tree::Node* Tree::create_node(int data)
    {
        Node *newNode=new Node;
        newNode->data=data;
        return newNode;
    }
    Tree::Node* Tree::create_node(Node *temp,int data)
    {
        Node *newNode=new Node;
        newNode->data=data;
        newNode->parent=temp;
        return newNode;
    }
    
    
    void Tree::remove(int i)
    {
        if (treeSize>0)
         treeSize--;
         remove_rec(root_node,i);
    }
    Tree::Node * Tree::remove_rec(Node *temp,int i)
    {
        if (temp==NULL)
        throw "no such node";
        
        if (i<temp->data)
        {
          temp->left = remove_rec(temp->left,i);
        }
        
        else if (i>temp->data)
        {
            temp->right = remove_rec(temp->right,i);
        }
        else
        {
            if (temp->left==NULL)
            {
                Node *temp2 = temp->right;
                free (temp);
                return temp2;
            }
            else if (temp->right==NULL)
            {
                Node *temp2 = temp->left;
                free (temp);
                return temp2;
            }
        
        Node *temp2 = min(temp->right);
        temp->data=temp2->data;
        temp->right=remove_rec(temp->right,temp2->data);
        
      }
      return temp;
      
      }
    
    Tree::Node * Tree::min(Node *temp)
    {
        if (temp==NULL)
        return NULL;
        if (temp->left == NULL)
        return temp;
        return min(temp->left);
    }
    int Tree::size()
    {
        return treeSize;
    }
    bool Tree::contains(int i)
    {
        if (node_at(i)==NULL)
              return false;
        return true;
    }
    
    int Tree::root()
    {
         return root_node->data;
    }
    int Tree::parent(int i)
    {
         Node *temp = node_at(i);
        if (temp==NULL || temp->parent==NULL)
            throw std::invalid_argument( "error in parent function, no such node" );
        return temp->parent->data;

    }
 
   
    int Tree::left(int i)
    {
        Node *temp = node_at(i);
        if (temp==NULL || temp->left==NULL)
            throw std::invalid_argument( "error in left function, no such node" );
        return temp->left->data;

    }
    int Tree::right(int i)
    {
        Node *temp = node_at(i);
        if (temp==NULL || temp->right==NULL)
            throw std::invalid_argument(  "error in right function, no such node");
        return temp->right->data;
    }                       
    
   
    void Tree::print()
    {
        print_rec(root_node);
    }
    void Tree::print_rec(Node *temp)
    {
        if (temp==NULL)
            return;
        print_rec(temp->left);
        cout << temp->data <<",";
        print_rec(temp->right);
    }
    Tree::Node* Tree::node_at(int i)
    {
        return node_at(root_node,i);
    }
       Tree::Node* Tree::node_at(Node *temp,int i)
    {
        if (temp==NULL)
           return NULL;
        if (temp->data==i)
            return temp;
        if (temp->data>i)
           return node_at(temp->left,i);
        if (temp->data<i)
           return node_at(temp->right,i);
        return NULL;
    }
     
    

