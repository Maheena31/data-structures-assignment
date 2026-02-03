#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* makeNode(int val) {
    TreeNode* temp = new TreeNode();
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNode* addValue(TreeNode* root, int val) {
    if (root == NULL)
        return makeNode(val);

    if (val <= root->value)
        root->left = addValue(root->left, val);
    else
        root->right = addValue(root->right, val);

    return root;
}

bool findValue(TreeNode* root, int val) {
    if (root == NULL)
        return false;

    if (root->value == val)
        return true;

    if (val <= root->value)
        return findValue(root->left, val);
    else
        return findValue(root->right, val);
}

int main() {
    TreeNode* root = NULL;

    root = addValue(root, 15);
    root = addValue(root, 10);
    root = addValue(root, 20);
    root = addValue(root, 25);
    root = addValue(root, 8);
    root = addValue(root, 12);

    int key;
    cout << "Enter number be searched:\n";
    cin >> key;

    if (findValue(root, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
