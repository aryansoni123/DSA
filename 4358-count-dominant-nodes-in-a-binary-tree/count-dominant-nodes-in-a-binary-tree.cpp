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

    int isLeaf(TreeNode* node){
        if (!node->left && !node->right) return true;
        return false;
    }

    int trav(TreeNode* node, int &ans){
        if (isLeaf(node)){
            ans+=1;
            return node->val;
        }

        if (!node) return INT_MIN;
        int l = 0, r = 0;

        if(node->left) l = trav(node->left, ans);
        if(node->right) r = trav(node->right, ans);

        if (node->val >= max(l,r)){
            ans+=1;
            return node->val;
        } else return max(l,r);
    }

    int countDominantNodes(TreeNode* root) {
        int ans = 0;

        trav(root, ans);

        // if no

        return ans;

    }
};