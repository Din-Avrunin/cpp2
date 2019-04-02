
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
            cout <<"creating node "<<root_node <<" with data "<< i << endl;
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
              cout << "creating data" << i << endl;
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
                 cout << "creating data" << i << endl;
				return;
			}
			insert_rec(temp->left,i);
			return;
		}
		else if (i==root_data)
			throw "cant have 2 nodes with the same i";
		else  // this should not happen!!
			throw "unknown exception in insert";
	}

	//function to create a new node
	Tree::Node* Tree::create_node(int data)
	{
		Node *newNode=new Node;
		newNode->data=data;
		return newNode;
	}
	// another function to create a new node
	Tree::Node* Tree::create_node(Node *temp,int data)
	{
		Node *newNode=new Node;
		newNode->data=data;
		newNode->parent=temp;
		return newNode;
	}
	void Tree::remove(int i)
	{
cout <<endl;
		if (root_node==NULL)
        {
            cout << "error";
			throw "the root is empty";
            
    }
		if (treeSize<=0 )
        {

        cout << "error2";
			throw "treesize is 0";    
        }
        
		remove_rec(root_node,i);

	}

	void Tree::remove_rec(Node *temp,int i)
	{
		if (temp==NULL)
		{
            cout << "error3";
			throw "error in remove_rec function: such node does not exist and and thus cannot be removed";
			return;
		}
        if (temp==root_node && temp->data==i)
        {
            if (temp->left!=NULL)
            {
                
                temp->left->parent=NULL;
                temp->left->right=temp->right;
                root_node=temp->left;
            }
            else if (temp->right!=NULL)
            {
                temp->right->parent=NULL;
                root_node=temp->right;
            }
            else if (temp->right==NULL && temp->left == NULL)
            {
              root_node=NULL;
            }
            cout <<  "test 1 removing " << temp->data<< endl;
        delete(temp);
        temp=NULL;
        treeSize--;
        
           return;
        }
		//if we are not on the right node, move to the right node.
		if (temp->data<i)
		{
			remove_rec(temp->right,i);
			return;
		}
		if (temp->data>i)
		{
			remove_rec(temp->left,i);
			return;
		}

		if (temp->data==i)
		{
			// need to check if has children to bind to the others
			if(temp->left == NULL && temp->right == NULL)
			{
                if (temp->parent->right==temp) // means im the right son
                {
                    temp->parent->right=NULL;
                }
                if (temp->parent->left==temp) // means im the left son
                {
                    temp->parent->left=NULL;
                }             
                cout <<  "test 2 removing" << temp->data<< endl;   
				delete(temp);
				treeSize--;
                return;
			}

			else if(temp->left != NULL && temp->right != NULL)
			{
				
			    Node *temp2 = temp->left;
				while(temp2->right != NULL)
				{
					temp2 = temp2->right; 
				}

                //temp2 = 2
                //temp  = 1
			
				
					if(temp->parent->left == temp) // left son
					{
						temp->parent->left = temp2;
						temp2->parent = temp->parent;
						temp2->right = temp->right;
						temp2->left = temp->left;
						temp2->parent->right = NULL; // 
                        temp->right->parent=temp2;
                        temp->left->parent=temp2;
                        cout <<  "test 3 removing" << temp->data<< endl;
						delete(temp);
						treeSize--;
                        return;
					}
					else if (temp->parent->left==temp) // right son
					{
						temp->parent->right = temp2;
						temp2->parent = temp->parent;
						temp2->right = temp->right;
                        temp->right->parent=temp2;
						temp2->left = temp->left;
                        temp->left->parent=temp2;
						temp2->parent->right = NULL; // 
                        cout <<  "test 4 removing" << temp->data<< endl;
						delete(temp);
                        return;
						
					}
				
			}

			else if(temp->left == NULL && temp->right != NULL)
			{
			
				
               temp->parent->right=temp->right;
                temp->right->parent=temp->parent;
                cout <<  "test 5 removing" << temp->data<< endl;
				delete(temp);
				treeSize--;
                return;
			}

			else if(temp->left != NULL && temp->right == NULL)
			{
			
			    temp->parent->left=temp->left;
                temp->left->parent=temp->parent;
				
                cout <<  "test 6 removing" << temp->data << endl;
				delete(temp);
				treeSize--;
                return;
			}
			// else{throw "unknown error in remove_rec func";}

		}
		// return temp;
        throw "number doesnt exist";
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
        if (root_node==NULL) throw "exceptionnn";
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