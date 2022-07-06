//Problem 8
#include<bits/stdc++.h>
using namespace std;
//Create struct to declare node
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    //default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    //parameterized  constructor take value as a parameter
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}

    //parameterized  constructor take value and left and right as a parameter
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};
//counter to search in pre order.
int counter = 0;
//function that create tree by inorder and preorder
TreeNode* createTree(string pre,string in,int begin,int end) {

    // base case
    if (begin > end)
        return nullptr;

    //create node take char as a val from preorder
    TreeNode *node = new TreeNode(pre[counter++]);

    //when current node is the root
    if (begin == end)
        return node;

    //show index that left of index is the left of the node and right this index is the right of this node
    int range = 0;
    for (int i = 0; i <= end; ++i) {
        if (in[i] == pre[counter - 1])
            range = i;
    }
    //recursive call to set the left of the node
    node->left = createTree(pre, in, begin, range - 1);

    //recursive call to set the right of the node
    node->right = createTree(pre, in, range + 1, end);
    return node;
}
//fuction to print the tree in post order
void printPost(TreeNode* tree) {
    //base class
    if (tree == NULL)
        return;
    printPost(tree->left);
    printPost(tree->right);
    cout << tree->val << ' ';
}
//function that takes preorder and inorder and print the tree in the Postorder
void printPostOrder(string pre,string in) {
    //reset the counter after each test case
    counter = 0;

    //create the tree
    TreeNode *tree = createTree(pre, in, 0, pre.size() - 1);

    //call this function to print the tree in postorder
    printPost(tree);
    cout << '\n';
}
int main() {
    //1st case
    printPostOrder("ABFGC", "FBGAC");

    //2nd case
    printPostOrder("ABCDE", "CBDAE");

    //3rd case
    printPostOrder("ABEFG", "BAFEG");

    //4th case
    printPostOrder("BCFGDE", "FCGBED");

    //5th case
    printPostOrder("12453", "42513");
}


