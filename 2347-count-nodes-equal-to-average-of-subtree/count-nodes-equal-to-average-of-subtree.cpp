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
    int ans = 0;

    bool isLeaf(TreeNode* node){
        if(!node->left && !node->right) return true;
        return false;
    }

    // vector<int> sum_cnt(TreeNode* node, unordered_map<TreeNode*, vector<int>> &dp){
    vector<int> sum_cnt(TreeNode* node){
        // if(!node->left && !node->right) return {node->val, 1};

        if(isLeaf(node)){
            ans++;
            return {node->val, 1};
        }

        // if(dp.contains(node)) return dp[node];

        vector<int> l = {0, 0}, r = {0,0};

        if(node->left){
            l = sum_cnt(node->left);
            // l = sum_cnt(node->left, dp);
        }

        if(node->right){
            r = sum_cnt(node->right);
            // r = sum_cnt(node->right, dp);
        }

        int sum = l[0] + r[0] + node->val;
        int cnt = l[1] + r[1] + 1;

        if(sum/cnt == node->val){
            ans++;
            cout<<node->val;
        }

        // return dp[node] = {sum, cnt};
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        stack<TreeNode*> q;

        // unordered_map<TreeNode*, vector<int>> dp;
        ans = 0;
        sum_cnt(root);

        return ans;


        // q.push(root);

        // int cnt = 0;

        // while(!q.empty()){
        //     TreeNode* node = q.top();
        //     q.pop();

        //     if(node->left != NULL){
        //         q.push(node->left);
        //     }

        //     if(node->right!=NULL){
        //         q.push(node->right);
        //     }

        //     vector<int> v = sum_cnt(node, dp);

        //     if(v[0]/v[1] == node->val) cnt++;
        // }

        // return cnt;
    }
};