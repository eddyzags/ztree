// Author : zagabe.ed@gmail.com (Eddy ZAGABE)
//
// Implementation of Btree which an binary tree. The class use the
// linked list representation.
// (See README.md for more information)
//

#ifndef BTREE_HH_
#define BTREE_HH_

#include <queue> // for queue class template

// Btree class implementation
template <typename zType>
class Btree {
 private:
  // Nodes' representation
  struct Tnodes {
    zType data;
    struct Tnodes *left;
    struct Tnodes *right;
  };

 public:
  // Constructor
  Btree() : root_(nullptr), nodes_count_(0) {}

  // Desctructor
  ~Btree() {}

  // Insert a new node to the binary tree
  void insert(const zType &data);

  // Return the number of nodes
  const int nodes_count() { return nodes_count_; }

 private:
  // Number of nodes
  int nodes_count_;

  // Root node
  struct Tnodes *root_;

  // References to the next empty nodes
  std::queue<struct Tnodes *> queue_;
  

  // Recursive function that adds a new node
  void insert_node(const zType &data);
};

// Recursive function that adds a new node
template <typename zType>
void Btree<zType>::insert_node(const zType &data) {
  struct Tnodes *new_node = new struct Tnodes;
  struct Tnodes *tmp;

  new_node->data = data;
  new_node->left = nullptr;
  new_node->right = nullptr;
  if (!root_) {
    root_ = new_node;
    queue_.push(root_);
  } else {
    tmp = queue_.front();
    if (!tmp->left) tmp->left = new_node;
    else tmp->right = new_node;
    if (tmp->left && tmp->right) queue_.pop();
    queue_.push(new_node);
  }
  nodes_count_++;
}

// Insert a new node to the binary tree
template <typename zType>
void Btree<zType>::insert(const zType &data) {
  insert_node(data);
}

#endif  // BTREE_HH_
