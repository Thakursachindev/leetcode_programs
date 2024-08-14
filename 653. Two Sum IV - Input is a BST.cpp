/**

 * Definition for a binary tree node.

 * struct TreeNode {

 * int val;

 * TreeNode *left;

 * TreeNode *right;

 * TreeNode() : val(0), left(nullptr), right(nullptr) {}

 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 * };

 */

class Solution {

public:

  void preOrder(TreeNode* &node, vector<int> &v){

    if(node != NULL) {

      v.push_back(node->val);

      preOrder(node->left, v);

      preOrder(node->right, v);

    }

  }

  bool findTarget(TreeNode* root, int k) {

    vector<int> v;

    preOrder(root, v);

    int n = v.size();

    sort(v.begin(), v.end());

    for(int i = 0;i < n; i++){

      if (k != 2*v[i]) {

        if(find(v.begin(), v.end(), k-v[i]) != v.end())

          return true;

      }

    }

    return false;

  }

};
