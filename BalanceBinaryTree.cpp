/**
 * Balance Binary Tree https://oj.leetcode.com/problems/balanced-binary-tree/
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in 
 * which the depth of the two subtrees of every node never differ by more than 1.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        
        if(abs(checkHeight(root->left) - checkHeight(root->right)) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int checkHeight(TreeNode *curr){
        if(curr == NULL)
            return -1;
            
        if(curr->left == NULL){
            if(curr->right == NULL)
                return 0;
            else
                return 1+checkHeight(curr->right);
        }
        else{
            if(curr->right == NULL)
                return 1+checkHeight(curr->left);
            else{
                int left = checkHeight(curr->left);
                int right = checkHeight(curr->right);
                if(left>=right)
                    return 1+left;
                else
                    return 1+right;
            }
        }
    }
};
