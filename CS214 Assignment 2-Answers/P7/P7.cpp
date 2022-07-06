#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Tree
{
public:
    TreeNode* root;
    void printPreOrder(TreeNode* root)
    {
        if (root == nullptr)return;
        cout << root->val << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    void flip()
    {
        flip(root);
    }

    // swap to nodes
    void swap(TreeNode* &n1, TreeNode* &n2)
    {
        TreeNode *temp;
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    void flip(TreeNode * &node)
    {
        if (node == NULL)return;
        flip(node->left);
        flip(node->right);
        swap(node->right,node->left);
    }

};
void create(TreeNode* root , int i, vector<string> &vec ) {

    if (root != nullptr) {
        if (2 * i + 1 <  vec.size()) {
            if ( vec[2 * i + 1] == "null")
                root->left = nullptr;
            else
                root->left = new TreeNode(stoi( vec[2 * i + 1]));
            create(root->left, 2 * i + 1,  vec);
        }


        if (2 * i + 2 <  vec.size()) {
            if ( vec[2 * i + 2] == "null")
                root->right = nullptr;
            else
                root->right = new TreeNode(stoi( vec[2 * i + 2]));
            create(root->right, 2 * i + 2,  vec);
        }
    }
}
TreeNode* levelOrderCreation(vector<string>& vec) {
    if (vec.size() == 0)
        return nullptr;
    TreeNode* root = new TreeNode(stoi( vec[0]));
    create(root, 0,  vec);
    return root;
}
int main()
{
   //test 1
    cout<<endl<<"Test # 1"<<endl;
    vector<string>vec1={"1","2","1","3","4","4","7"};
    Tree tree1;tree1.root= levelOrderCreation(vec1);
    cout<<"printing the tree in pre order: ";
    tree1.printPreOrder(tree1.root);cout<<endl;
    tree1.flip(tree1.root);
    cout<<"printing the tree in pre order after the flip operation: ";
    tree1.printPreOrder(tree1.root);cout<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    vector<string>vec2={"10","20","4","3","4","4","null"};
    Tree tree2;tree2.root= levelOrderCreation(vec2);
    cout<<"printing the tree in pre order: ";
    tree2.printPreOrder(tree2.root);cout<<endl;
    tree2.flip(tree2.root);
    cout<<"printing the tree in pre order after the flip operation: ";
    tree2.printPreOrder(tree2.root);cout<<endl;

    //test 3
    cout<<endl<<"Test # 3"<<endl;
    vector<string>vec3={"10","20","4","null","null","14","8"};
    Tree tree3;tree3.root= levelOrderCreation(vec3);
    cout<<"printing the tree in pre order: ";
    tree3.printPreOrder(tree3.root);cout<<endl;
    tree3.flip(tree3.root);
    cout<<"printing the tree in pre order after the flip operation: ";
    tree3.printPreOrder(tree3.root);cout<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    vector<string>vec4={"7","2","3"};
    Tree tree4;tree4.root= levelOrderCreation(vec4);
    cout<<"printing the tree in pre order: ";
    tree4.printPreOrder(tree4.root);cout<<endl;
    tree4.flip(tree4.root);
    cout<<"printing the tree in pre order after the flip operation: ";
    tree2.printPreOrder(tree4.root);cout<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    vector<string>vec5={"10","20","5","7","7","null","null"};
    Tree tree5;tree5.root= levelOrderCreation(vec5);
    cout<<"printing the tree in pre order: ";
    tree5.printPreOrder(tree5.root);cout<<endl;
    tree5.flip(tree5.root);
    cout<<"printing the tree in pre order after the flip operation: ";
    tree5.printPreOrder(tree5.root);cout<<endl;
}
