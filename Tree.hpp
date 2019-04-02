
/**
 * Defines the class Tree, that represents a binery 
*/
#include <iostream>
namespace ariel{
using namespace std;  // we need this(?)

class Tree {
    public:
    struct Node
    {
        int data;
        struct Node *parent=NULL;
        struct Node *left=NULL;
        struct Node *right=NULL;
    };
    
    //variables
    Node* root_node=NULL;
    int treeSize;
   
    //constructor
    
    
    // //destructor
    // ~Tree()
    // {
    //   cout << "destructing tree";
    // }
    
    public: 
    
    // outline functions
    Tree();
    ~Tree();
    void insert(int i);
    void insert_rec(Node *temp,int i);
    Node* create_node(int data);
    Node* create_node(Node* temp,int data); // create a node and send the parent node (so we can tell the new node who his daddy is)
    void remove(int i);
    void remove_rec(Node *temp,int i);
    Node* min(Node *temp);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    void print_rec(Node *temp);
    Node* node_at(int i);       //helpful function to return the node that contains data i
    Node* node_at(Node* temp,int i);  
};
}