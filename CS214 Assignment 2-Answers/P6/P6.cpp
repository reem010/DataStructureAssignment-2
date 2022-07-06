#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val("0"), left(nullptr), right(nullptr) {}

    TreeNode( string  x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(string x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class solution {
public:

    // cast a string to an integare
    int toInt(string s)
    {
        int num = 0;
        if (s[0] == '-')
        {
            for (int i = 1; i < s.size(); ++i) {
                num *= 10; num += (s[i] - '0');
            }
            num *= -1;
        }
        else
        {
            for (int i = 0; i < s.size(); ++i) {
                num *= 10; num += (s[i] - '0');
            }
        }return num;
    }

    // function that takes a prefix expression tree and returns the answer
    int evaluate(TreeNode* root)
    {
        // not an operator
        if (root->val != "*" && root->val != "/" && root->val != "+" && root->val != "-")
        {
            return toInt(root->val);
        }
        if (root->val == "+")
        {
                return evaluate(root->left) + evaluate(root->right);
        }
        if (root->val == "-")return evaluate(root->left) - evaluate(root->right);
        if (root->val == "/")return evaluate(root->left) / evaluate(root->right);
        if (root->val == "*")return evaluate(root->left) * evaluate(root->right);
    }
};
int main()
{
    solution solve;
    //test 1
    cout<<endl<<"Test # 1"<<endl;
    cout<<"the prefix expression : + 3 * 4 / 8 2"<<endl;
    TreeNode* root=new TreeNode("+");
    root->right=new TreeNode("*");
    root->left=new TreeNode("3");
    root->right->left=new TreeNode("4");
    root->right->right=new TreeNode("/");
    root->right->right->right=new TreeNode("2");
    root->right->right->left=new TreeNode("8");
    cout<<"answer: "<<solve.evaluate(root)<<endl;

    //test 2
    cout<<endl<<"Test # 2"<<endl;
    cout<<"the prefix expression : * + 4 5 + 3 1"<<endl;
    TreeNode* root2=new TreeNode("*");
    root2->left=new TreeNode("+");
    root2->left->left=new TreeNode("4");
    root2->left->right=new TreeNode("5");
    root2->right=new TreeNode("-");
    root2->right->left=new TreeNode("3");
    root2->right->right=new TreeNode("1");
    cout<<"answer: "<<solve.evaluate(root2)<<endl;

    //test 3
    cout<<endl<<"Test # 3"<<endl;
    cout<<"the prefix expression : + + 4 2 * 3 - 15 1"<<endl;
    TreeNode* root3=new TreeNode("+");
    root3->left=new TreeNode("+");
    root3->left->left=new TreeNode("4");
    root3->left->right=new TreeNode("2");
    root3->right=new TreeNode("*");
    root3->right->left=new TreeNode("3");
    root3->right->right=new TreeNode("-");
    root3->right->right->right=new TreeNode("1");
    root3->right->right->left=new TreeNode("15");
    cout<<"answer: "<<solve.evaluate(root3)<<endl;

    //test 4
    cout<<endl<<"Test # 4"<<endl;
    cout<<"the prefix expression : + 10 - 1 3"<<endl;
    TreeNode* root4=new TreeNode("*");
    root4->left=new TreeNode("10");
    root4->right=new TreeNode("-");
    root4->right->right=new TreeNode("3");
    root4->right->left=new TreeNode("1");
    cout<<"answer: "<<solve.evaluate(root4)<<endl;

    //test 5
    cout<<endl<<"Test # 5"<<endl;
    cout<<"the prefix expression : - - 4 2 2 "<<endl;
    TreeNode* root5=new TreeNode("-");
    root5->left=new TreeNode("-");
    root5->left->right=new TreeNode("2");
    root5->left->left=new TreeNode("4");
    root5->right=new TreeNode("2");
    cout<<"answer: "<<solve.evaluate(root5)<<endl;
}
