What is a Red-Black Tree?

A Red-Black Tree (RBT) is a self-balancing Binary Search Tree that ensures insert, delete, and search operations can be done in O(log n) time.

Red-Black Tree Properties (Important to Know)

Every node is either red or black.

The root node is always black.

All leaves (NULL nodes) are black.

No two red nodes can be consecutive.

Every path from a node to its descendant NULL nodes contains the same number of black nodes.

Insertion Concept (High Level)

Insertion in a Red-Black Tree happens in two main steps:

Step 1: BST Insert

Insert the new node just like a regular BST.

The new node is always colored red.

Step 2: Fix Violations

If the parent node is black, there is no problem.

If the parent node is red, a violation occurs and must be fixed.

This can be done using recoloring.

Or by performing rotations (left or right) to maintain balance.
