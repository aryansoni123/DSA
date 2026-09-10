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

    vector<int> sum_cnt(TreeNode* node){
        if(!node->left && !node->right) return {node->val, 1};

        // if(!node) return {-1, -1};

        // int l_cnt= 0, r_cnt = 0, l_sum = 0, r_sum= 0;

        vector<int> l = {0, 0}, r = {0,0};

        if(node->left){
            l = sum_cnt(node->left);
        }

        if(node->right){
            r = sum_cnt(node->right);
        }

        return {l[0] + r[0] + node->val, l[1] + r[1] + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        stack<TreeNode*> q;

        q.push(root);

        int cnt = 0;

        while(!q.empty()){
            TreeNode* node = q.top();
            q.pop();

            if(node->left != NULL){
                q.push(node->left);
            }

            if(node->right!=NULL){
                q.push(node->right);
            }

            vector<int> v = sum_cnt(node);

            if(v[0]/v[1] == node->val) cnt++;
        }

        return cnt;
    }
};