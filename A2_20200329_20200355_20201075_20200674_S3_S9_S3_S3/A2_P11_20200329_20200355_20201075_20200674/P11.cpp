#include <iostream>
using namespace std;
template<class T>
class BSTNode {
public:
    T val;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode() : val(0), left(nullptr), right(nullptr) {  }

    BSTNode(T x) : val(x), left(nullptr), right(nullptr) { }

    BSTNode(T x, BSTNode* left, BSTNode* right) : val(x), left(left), right(right) {}
};

template<class T>
class BSTFCI
{
public:
    BSTNode<T>* root; // root of the tree

    BSTFCI() {
        root = NULL;
    }

    BSTFCI(int val)
    {
        root = new BSTNode<T>(val);
    }

    void insert(int val)
    {
        insertNode(val, root);
    }
    BSTNode<T>* insertNode(int val, BSTNode<T>*& root)
    {
        if (root == nullptr)
        {
            root = new BSTNode<T>(val);
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

    void printInOrder(BSTNode<T>* root)
    {
        if (root == NULL)
            return;
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }

    void erase(T val)
    {
        eraseNode(root, val);
    }
    BSTNode<T>* eraseNode(BSTNode<T>* &root,T val)
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
                BSTNode<T>* temp = root->right;
                delete root;
                return temp;
            }
            // have only left child
            else if (root->right == NULL)
            {
                BSTNode<T>* temp = root->left;
                delete root;
                return temp;
            }
            // have 2 childs
            else
            {
                BSTNode < T >* temp = root;
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
    bool isBalanced(BSTNode<T>* root)
    {
        if (root == NULL)
            return true;
        // calc. left and right hight
        int leftHight = height(root->left);
        int rightHight = height(root->right);

        // the diffrence in hight must not be more than 1 and the left sub tree is balanced and the right subtree is balanced (the true case)
        return ( abs(leftHight - rightHight) <= 1 && isBalanced(root->left) && isBalanced(root->right) );
    }
    int height(BSTNode<T>* node)
    {
        if (node == NULL)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    void printRange(T low, T high)
    {
        printInRange(root, low, high);
    }
    void printInRange(BSTNode<T>* root, int low, int high)
    {
        //base case we would reach here if the low isnot in the tree
        if (NULL == root)
            return;

        if (low < root->val)
            printInRange(root->left, low, high);

        if (root->val > high)return; // we out of the range so stop traversing

        if(root->val>=low)
        cout << root->val << " ";

        printInRange(root->right, low, high);

    }
    BSTNode<T>* search(T val,BSTNode<T>*root)
    {
        if (root == NULL)
            return NULL;
        if (root->val == val)return root;
        if ( val<root->val)
        {
            return search(val, root->left);
        }
        else
        {
            return search(val, root->right);
        }
    }
};

template<class T>
bool isSameTree(BSTNode<T>* t1, BSTNode<T>* t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL)return false;
    if (t2 == NULL)return false;
    return (t1->val == t2->val && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
}

template<class T>
bool check(BSTNode<T>* t1, BSTNode<T>* t2)
{
    if (t1 == NULL && t2 == NULL)return true;
    if (t1 == NULL)return false;
    if (isSameTree(t1, t2))return true;
    // do right and left check
    return check(t1->left, t2) || check(t1->right, t2);
}

template<class T>
bool isSubTree(BSTFCI<T> t1, BSTFCI<T> t2)
{
    return check(t1.root, t2.root);
}


int main()
{
    //isBalance testing
    cout << "testing IsBalance function..." << endl;
    //test 1
    cout << endl << "test # 1" << endl;
    BSTFCI<int>tree1;
    tree1.insert(7);
    tree1.insert(4);
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(8);
    if (tree1.isBalanced(tree1.root))
        cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;

    //test 2
    cout << endl << "test # 2" << endl;
    BSTFCI<int>tree2;
    tree2.insert(7);
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(8);
    tree2.insert(2);
    if (tree2.isBalanced(tree2.root))
        cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;


    //test 3
    cout << endl << "test # 3" << endl;
    BSTFCI<int>tree3;
    tree3.insert(15);
    tree3.insert(7);
    tree3.insert(11);
    tree3.insert(8);
    tree3.insert(16);
    tree3.insert(17);
    tree3.insert(18);
    if (tree3.isBalanced(tree3.root))
        cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;

    //test 4
    cout << endl << "test # 4" << endl;
    BSTFCI<int>tree4;
    tree4.insert(15);
    tree4.insert(7);
    tree4.insert(5);
    tree4.insert(11);
    tree4.insert(8);
    tree4.insert(17);
    tree4.insert(16);
    tree4.insert(18);
    if (tree4.isBalanced(tree4.root))
        cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl;

    //test 5
    cout << endl << "test # 5" << endl;
    BSTFCI<int>tree5;
    tree5.insert(1);
    tree5.insert(2);
    tree5.insert(3);
    tree5.insert(4);
    tree5.insert(5);
    if (tree4.isBalanced(tree5.root))
        cout << "Balanced" << endl;
    else cout << "Unbalanced" << endl << endl;

    //isSubTree testing
    cout << "testing isSubTree function..." << endl;
    //test 1
    cout << endl << "test # 1" << endl;
    BSTFCI<int>tre1;
    tre1.insert(7);
    tre1.insert(4);
    tre1.insert(5);
    tre1.insert(3);
    tre1.insert(8);
    BSTFCI<int>subTree1;
    subTree1.insert(4);
    subTree1.insert(3);
    subTree1.insert(5);
    if (isSubTree(tre1, subTree1))
        cout << "It's a sub tree" << endl;
    else cout << "not a sub tree" << endl;

    //test 2
    cout << endl << "test # 2" << endl;
    BSTFCI<int>tre2;
    tre2.insert(7);
    tre2.insert(4);
    tre2.insert(5);
    tre2.insert(3);
    tre2.insert(8);
    BSTFCI<int>subTree2;
    subTree2.insert(4);
    subTree2.insert(3);
    if (isSubTree(tre2, subTree2))
        cout << "It's a sub tree" << endl;
    else cout << "not a sub tree" << endl;

    //test 3
    cout << endl << "test # 3" << endl;
    BSTFCI<int>tre3;
    tre3.insert(15);
    tre3.insert(7);
    tre3.insert(11);
    tre3.insert(8);
    tre3.insert(16);
    tre3.insert(17);
    tre3.insert(18);
    BSTFCI<int>subTree3;
    subTree3.insert(16);
    subTree3.insert(17);
    subTree3.insert(18);
    if (isSubTree(tre3, subTree3))
        cout << "It's a sub tree" << endl;
    else cout << "not a sub tree" << endl;

    //test 4
    cout << endl << "test # 4" << endl;
    BSTFCI<int>tre4;
    tre4.insert(10);
    tre4.insert(5);
    tre4.insert(15);
    tre4.insert(2);
    tre4.insert(7);
    tre4.insert(11);
    tre4.insert(16);
    BSTFCI<int>subTree4;
    subTree4.insert(2);
    if (isSubTree(tre4, subTree4))
        cout << "It's a sub tree" << endl;
    else cout << "not a sub tree" << endl;

    //test 5
    cout << endl << "test # 5" << endl;
    BSTFCI<int>tre5;
    tre5.insert(10);
    tre5.insert(5);
    tre5.insert(15);
    tre5.insert(2);
    tre5.insert(7);
    tre5.insert(11);
    tre5.insert(16);
    BSTFCI<int>subTree5;
    subTree5.insert(15);
    if (isSubTree(tre5, subTree5))
        cout << "It's a sub tree" << endl;
    else cout << "not a sub tree" << endl<<endl;

    //print in range testing
    cout << "testing PrintRange function..." << endl;

    //testing the print is on the first 5 trees (no new trees will be created)
    //test 1
    cout << endl << "test # 1" << endl;
    cout << "printing the tree In order: "; tree1.printInOrder(tree1.root); cout << endl;
    cout << "range: (3,5)" << endl;
    cout << "the print: ";
    tree1.printRange(3, 5); cout << endl;

    //test 2
    cout << endl << "test # 2" << endl;
    cout << "printing the tree In order: "; tree2.printInOrder(tree2.root); cout << endl;
    cout << "range: (8,8)" << endl;
    cout << "the print: ";
    tree2.printRange(8,8); cout << endl;

    //test 3
    cout << endl << "test # 3" << endl;
    cout << "printing the tree In order: "; tree3.printInOrder(tree3.root); cout << endl;
    cout << "range: (12,14)" << endl;
    cout << "the print: ";
    tree3.printRange(12, 14); cout << endl;

    //test 4
    cout << endl << "test # 4" << endl;
    cout << "printing the tree In order: "; tree4.printInOrder(tree4.root); cout << endl;
    cout << "range: (-1,8)" << endl;
    cout << "the print: ";
    tree4.printRange(-1, 8); cout << endl;

    //test 5
    cout << endl << "test # 5" << endl;
    cout << "printing the tree In order: "; tree5.printInOrder(tree5.root); cout << endl;
    cout << "range: (2,20)" << endl;
    cout << "the print: ";
    tree5.printRange(2, 20); cout << endl;

}

