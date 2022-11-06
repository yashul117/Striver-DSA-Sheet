/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode* A, vector<int> &path, int B) {
    if(A==NULL) {
        return false;
    }
    
    path.push_back(A->val);
    
    if(A->val==B) {
        return true;
    }
    
    if(findPath(A->left, path, B)||findPath(A->right, path, B)) {
        return true;
    }
    
    path.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    findPath(A, path, B);
    
    return path;    
}
