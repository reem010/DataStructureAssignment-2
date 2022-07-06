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

    bool isSymmetric(TreeNode* root) {
        return  isMirror(root->left,root->right);
    }
private:
    // simply traverse and compare each each node in the tree with the inverse one in the other tree
    bool isMirror(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr)return false;
        if (t2 == nullptr)return false;
        return (t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
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
    vector<string>vec1={"1","2","2","3","4","4","3"};
    TreeNode* root1= levelOrderCreation(vec1);
    if(solve.isSymmetric(root1))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    vector<string>vec2={"1","2","2","null","3","null","3"};
    TreeNode* root2= levelOrderCreation(vec2);
    if(solve.isSymmetric(root2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 3
    cout<<endl<<"Test # 3"<<endl;
    vector<string>vec3={"5","6","6","null","8","8","null"};
    TreeNode* root3= levelOrderCreation(vec3);
    if(solve.isSymmetric(root3))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    vector<string>vec4={"10","20","20","1","2","2","9"};
    TreeNode* root4= levelOrderCreation(vec4);
    if(solve.isSymmetric(root4))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    vector<string>vec5={"19","4","4","null","20","20","5"};
    TreeNode* root5= levelOrderCreation(vec5);
    if(solve.isSymmetric(root5))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}

