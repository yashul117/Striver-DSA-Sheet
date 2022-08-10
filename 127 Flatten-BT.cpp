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
    // TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
// 1st method: using recursion: O(N),O(N)
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right=prev;
//         root->left=NULL;
        
//         prev=root;
        
// 2nd method: using stack: O(N),O(N)
//         stack<TreeNode*> st;
//         TreeNode* cur;
        
//         st.push(root);
//         while(!st.empty()) {
//             cur=st.top();
//             st.pop();
            
//             if(cur->right) {
//             st.push(cur->right);
//             }           
            
//             if(cur->left) {
//                 st.push(cur->left);
//             }
            
//             if(!st.empty()) {
//                 cur->right=st.top();
//                 cur->left=NULL;
//             }
//         }

// 3rd Method: similar to morris traversal
        TreeNode* cur=root;
        
        while(cur!=NULL) {
            if(cur->left!=NULL) {
                TreeNode* prev=cur->left;
                
                while(prev->right!=NULL) {
                    prev=prev->right;
                }
                
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            
            cur=cur->right;
        }
    }
};