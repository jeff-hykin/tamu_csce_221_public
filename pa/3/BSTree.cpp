#include "BSTree.h"

#include <iostream>

using namespace std;

////////////////////////////////////////////////////
// A few functions are already implemented for you
// and you can use them (but do not change them).
//
// SCROLL BELOW TO SEE THE FUNCTIONS THAT YOU HAVE
// TO IMPLEMENT.
/////////////////////////////////////////////////////


// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      Take input from the input stream, and build your tree.
      Input should look like this (one int in a line):
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
// If you try to use it without care, you will get a memory leak.
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function (start from root)
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time +
      get_total_search_time(node->left) +
      get_total_search_time(node->right);
  }
  return 0;
}

// 
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1; // special case
	
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//
//     FUNCTIONS TO IMPLEMENT
//
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or
// create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other)
{
}

// copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other)
{
}

// destructor
BSTree::~BSTree()
{
    // Make sure to call delete on every node of the tree
    // You can use a recursive helper function to do this
}

Node* BSTree::insert(int val)
{
  // insert a node into the tree:
  // first find where the node should go
  // then modify pointers to insert your new node 
}

Node* BSTree::search(int val)
{
  // recursively search down the tree to find 
  // the node that contains val,
  // if you don't find anything return nullptr
}

void BSTree::update_search_times()
{
  // Do a BFS or DFS of your tree and
  // update the search times of all nodes at once
  // The root has a search time of 1,
  // and each child is 1 more than its parent
  /* Example:
     For this tree:
         4
       2    6
      1 3  5 7

      we have this search time for each node 
      (starting from root):
        1
      2   2
     3 3 3 3 
   */
}

void BSTree::inorder(ostream& out)
{
  /* 
     Print your nodes in infix order.
     If the tree looks like this (starting from root):

         4
       2    6
      1 3  5 7

     then it should give this output:
     1[3] 2[2] 3[3] 4[1] 5[3] 6[2] 7[3]

     You can use operator<< to print the nodes 
     in the format shown above
  */
}

void BSTree::print_level_by_level(ostream& out)
{
    /* Print the tree using a BFS so that each level 
       contains the values for this level of the tree.
       Use . to mark empty positions. 
    
       If the tree looks like this:

              4
	    2   6
           1   5 7
                  9

       it should output:

       4[1]
       2[2] 6[2]
       1[3] . 5[3] 7[3]
       . . . . . . . 9[4]

       It might be helpful to do this part with the 
       std::queue data structure.
       HINT: the Nth level contains 2^(N-1) nodes 
       (with a value or with an . (dot)). 
    
       Watch out for nodes like the left child of 6 above, 
       and print the descendents of an empty node also as empty.  
       You can use operator<< to print nodes in the format 
       shown.
    */
}
