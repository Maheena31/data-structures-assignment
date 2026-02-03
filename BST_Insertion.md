Concept of Insertion in a Binary Search Tree (BST)

What is a Binary Search Tree (BST)?

A Binary Search Tree is a type of binary tree with some special properties:

Each node can have at most two children.

The left subtree of a node contains values smaller than the node.

The right subtree of a node contains values greater than the node.

Classic BSTs do not allow duplicate values.

BST Rule:
Left < Root < Right

Concept of Insertion in a BST

When inserting a new value into a BST:

Start from the root node.

Compare the new value with the current node:

If the new value is smaller, move to the left child.

If the new value is greater, move to the right child.

Repeat this process until you find an empty position (NULL).

Insert the new node in that position.

Important:
Insertion in a BST always happens at a leaf position.

Example:

Insert values: 50, 30, 70, 20, 40

	50
       /  \
     30    70
    /  \
  20   40
