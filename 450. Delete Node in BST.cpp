/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool preorder(TreeNode* root, int key, vector<int>& vc) {
        static bool flag = false;
        if (root != NULL) {
            if (root->val == key)
                flag = true;
            else
                vc.push_back(root->val);
            preorder(root->left, key, vc);
            preorder(root->right, key, vc);
        }
        return flag;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
           root =  new TreeNode(val);
        else if(val < root->val)
           root->left = insertIntoBST(root->left, val);
        else
          root->right = insertIntoBST(root->right, val);
        return root;         

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
         vector<int> vc; 
         preorder(root, key, vc);
         root = NULL;
         for(int i = 0; i<vc.size(); i++){
            root = insertIntoBST(root, vc[i]);
         }
         return root;
    }
         };
