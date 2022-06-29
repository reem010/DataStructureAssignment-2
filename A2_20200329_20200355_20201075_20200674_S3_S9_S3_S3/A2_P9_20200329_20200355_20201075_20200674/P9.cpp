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

class Solution
{
public:
    bool isFoldable(TreeNode* root)
    {
        return root ==nullptr || look(root->left, root->right);
    }
    bool look(TreeNode* root, TreeNode* root2)
    {
        if (root == nullptr && root2 == nullptr)
            return true;
        if (root != nullptr && root2 != nullptr)
            return (look(root->left, root2->right) && look(root->right, root2->left));
        return false;

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
        Solution solve;

    //test 1
    cout<<endl<<"Test # 1"<<endl;
    vector<string>vec1={"1","2","2","3","4","4","3"};
    TreeNode* root1= levelOrderCreation(vec1);
    if(solve.isFoldable(root1))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    vector<string>vec2={"1","2","2","null","3","null","3"};
    TreeNode* root2= levelOrderCreation(vec2);
    if(solve.isFoldable(root2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 3
    cout<<endl<<"Test # 3"<<endl;
    vector<string>vec3={"5","6","6","null","8","8","null"};
    TreeNode* root3= levelOrderCreation(vec3);
    if(solve.isFoldable(root3))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    vector<string>vec4={"5","6","6","null","null","8","null"};
    TreeNode* root4= levelOrderCreation(vec4);
    if(solve.isFoldable(root4))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    vector<string>vec5={"19","4","4","null","20","20","5"};
    TreeNode* root5= levelOrderCreation(vec5);
    if(solve.isFoldable(root5))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
