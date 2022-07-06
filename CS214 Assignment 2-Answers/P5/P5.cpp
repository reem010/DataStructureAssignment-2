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

class Solution {
public:

    // simply traverse and compare each  node in the tree with the other one in the other tree once u found a difference return false
    bool isSameTree(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr)return false;
        if (t2 == nullptr)return false;
        return (t1->val == t2->val && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
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

void print(TreeNode* r)
{
    if(r==nullptr)return;
    cout<<r->val<<" ";
    print(r->left);
    print(r->right);
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
    Solution solve;

    //test 1
    cout<<endl<<"Test # 1"<<endl;
    vector<string> vec1={"1,2,3"};
    vector<string> v1={"1,2,3"};
    TreeNode* root1=levelOrderCreation(vec1);
    TreeNode* otherRoot1=levelOrderCreation(v1);
    if( solve.isSameTree(root1,otherRoot1) )
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    vector<string> vec2={"1","2"};
    vector<string> v2={"1","null","2"};
    TreeNode* root2=levelOrderCreation(vec2);
    TreeNode* otherRoot2=levelOrderCreation(v2);
    if( solve.isSameTree(root2,otherRoot2) )
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 3
    cout<<endl<<"Test # 3"<<endl;
    vector<string> vec3={"1","2","1"};
    vector<string> v3={"1","1","2"};
    TreeNode* root3=levelOrderCreation(vec3);
    TreeNode* otherRoot3=levelOrderCreation(v3);
    if( solve.isSameTree(root3,otherRoot3) )
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    vector<string> vec4={"5","16","17","18","null","19","null"};
    vector<string> v4={"5","16","17","18","null","19","null"};
    TreeNode* root4=levelOrderCreation(vec4);
    TreeNode* otherRoot4=levelOrderCreation(v4);
    if( solve.isSameTree(root4,otherRoot4) )
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    vector<string> vec5={"5","16","17","18","null","19","null"};
    vector<string> v5={"5","6","17","18","null","19","null"};
    TreeNode* root5=levelOrderCreation(vec5);
    TreeNode* otherRoot5=levelOrderCreation(v5);
    if( solve.isSameTree(root5,otherRoot5) )
    cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

}
