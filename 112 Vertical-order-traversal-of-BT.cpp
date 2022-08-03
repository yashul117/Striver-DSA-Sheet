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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        map<int,map<int,multiset<int>>> nodes;
        
        todo.push({root,{0,0}});
        
        while(!todo.empty()) {
            auto it=todo.front();
            todo.pop();
            
            TreeNode *node=it.first;
            int x=it.second.first,y=it.second.second;
            
            nodes[x][y].insert(node->val);
            
            if(node->left) {
                todo.push({node->left,{x-1,y+1}});
            }
            if(node->right) {
                todo.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto it1:nodes) {
            vector<int> col;
            for(auto it2:it1.second) {
                col.insert(col.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};