/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int> &v, int &i, int bound) {
        if(i==v.size() || v[i]>bound)
            return NULL;
        
        TreeNode* root=new TreeNode(v[i++]);
        root->left=buildTree(v,i,root->val);
        root->right=buildTree(v,i,bound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildTree(preorder,i,INT_MAX);
    }
};