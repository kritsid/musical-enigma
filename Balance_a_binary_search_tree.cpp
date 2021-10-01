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
    void inorder_traversal(TreeNode *root,vector<int> &sorted)
    {
        if(root==NULL)
            return;
        //cout<<root->val<<" ";
        
        inorder_traversal(root->left,sorted);
        sorted.push_back(root->val);
        inorder_traversal(root->right,sorted);
    }
    TreeNode* construct_balance_search_tree(vector<int> sorted)
    {
        if(sorted.size()==0)
            return NULL;
        int mid=sorted.size()/2;
        vector<int> left(sorted.begin(),sorted.begin()+mid);
        vector<int> right(sorted.begin()+mid+1,sorted.end());
        TreeNode *root=new TreeNode(sorted[mid]);
        root->left=construct_balance_search_tree(left);
        root->right=construct_balance_search_tree(right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder_traversal(root,sorted);
        //sort(sorted.begin(),sorted.end());
        return construct_balance_search_tree(sorted);
    }
};
