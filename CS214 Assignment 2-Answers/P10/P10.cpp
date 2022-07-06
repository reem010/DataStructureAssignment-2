#include<bits/stdc++.h>
using namespace std;

class BSTNode {
public:
    int val;
    BSTNode* left;
    BSTNode* right;

    BSTNode() : val(0), left(nullptr), right(nullptr) {  }

    BSTNode(int x) : val(x), left(nullptr), right(nullptr) { }

    BSTNode(int x, BSTNode* left, BSTNode* right) : val(x), left(left), right(right) {}
};


class BSTFCI
{
public:
    BSTNode* root; // root of the tree

    BSTFCI() {
        root = NULL;
    }

    BSTFCI(int val)
    {
        root = new BSTNode(val);
    }

    void insert(int val)
    {
        insertNode(val, root);
    }
    BSTNode* insertNode(int val, BSTNode*& root)
    {
        if (root == nullptr)
        {
            root = new BSTNode(val);
            return root;
        }
        if (val < root->val) {
            root->left = insertNode(val, root->left);

        }
        else {
            root->right = insertNode(val, root->right);
        }
        return root;
    }
    void erase(int val)
    {
        eraseNode(root, val);
    }
    BSTNode* eraseNode(BSTNode*& root, int val)
    {
        if (root == NULL)return NULL;

        // look left
        if (val < root->val)
            root->left = eraseNode(root->left, val);
        // look right
        else  if (val > root->val)
            root->right = eraseNode(root->right, val);
        // delete the node
        else
        {
            // leaf
            if (root->left == NULL and root->right == NULL) {
                delete root;
                return NULL;
            }
            //have only right child
            else if (root->left == NULL)
            {
                BSTNode* temp = root->right;
                delete root;
                return temp;
            }
            // have only left child
            else if (root->right == NULL)
            {
                BSTNode* temp = root->left;
                delete root;
                return temp;
            }
            // have 2 child
            else
            {
                BSTNode * temp = root;
                // go left then right most
                temp = temp->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = eraseNode(root->left, temp->val);
            }

        }
        return root;
    }

    BSTNode* search(int val, BSTNode* root)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)return root;
        if (val < root->val)
        {
            return search(val, root->left);
        }
        else
        {
            return search(val, root->right);
        }
    }
    void printInorder(BSTNode* root)
    {
        if(root==nullptr)return;
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
};

int calculateSum(int &k, BSTNode* root)
{
    // base cases
    if (root == NULL)
        return 0;
    //it's not enough to check if K==0 because if the inserted K is less than zero then the function will calculate all the nodes so instead we check if k<=0 to return 0 in such a case
    if (k<=0)
        return 0;

    int temp = calculateSum(k, root->left); // start from most left (smallest element)

    if (k<=0)return temp; // check before adding the left node if we can add it

    // add left node
    temp += root->val;
    k--;

    if (k<=0)return temp;// check before adding the right node if we can add it

    // add right node
    return temp + calculateSum(k, root->right);
}
int KsmallestSumOfElements(int k, BSTNode* root)
{
    int tempK = k;
    return calculateSum(tempK, root);
}

int main()
{
    //test 1
    cout<<endl<<"Test # 1"<<endl;
    BSTFCI tree1;
    tree1.insert(4);
    tree1.insert(9);
    tree1.insert(7);
    tree1.insert(2);
    cout<<"the tree in order: ";
    tree1.printInorder(tree1.root);cout<<endl;
    cout<<"k=2"<<endl; cout<<"ans= "<< KsmallestSumOfElements(2,tree1.root)<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    BSTFCI tree2;
    tree2.insert(100);
    tree2.insert(41);
    tree2.insert(80);
    tree2.insert(40);
    cout<<"the tree in order: ";
    tree2.printInorder(tree2.root);cout<<endl;
    cout<<"k=3"<<endl; cout<<"ans= "<< KsmallestSumOfElements(3,tree2.root)<<endl;

    //test 3 (sample)
    cout<<endl<<"Test # 3"<<endl;
    BSTFCI tree3;
    tree3.insert(54);
    tree3.insert(51);
    tree3.insert(75);
    tree3.insert(49);
    tree3.insert(52);
    tree3.insert(74);
    tree3.insert(85);
    cout<<"the tree in order: ";
    tree3.printInorder(tree3.root);cout<<endl;
    cout<<"k=3"<<endl; cout<<"ans= "<< KsmallestSumOfElements(3,tree3.root)<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    BSTFCI tree4;
    tree4.insert(11);
    tree4.insert(1);
    tree4.insert(5);
    tree4.insert(4);
    tree4.insert(10);
    tree4.insert(7);
    tree4.insert(8);
    cout<<"the tree in order: ";
    tree4.printInorder(tree4.root);cout<<endl;
    cout<<"k=5"<<endl; cout<<"ans= "<< KsmallestSumOfElements(5,tree4.root)<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    BSTFCI tree5;
    tree5.insert(2);
    tree5.insert(3);
    tree5.insert(1);
    tree5.insert(4);
    cout<<"the tree in order: ";
    tree5.printInorder(tree5.root);cout<<endl;
    cout<<"k=1"<<endl; cout<<"ans= "<< KsmallestSumOfElements(1,tree5.root)<<endl;
}
