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


 
class BSTIterator {
public:
    // TreeNode* start;
    int i;
    vector<TreeNode*>vec;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        // start = root;
        inorder(root);
        i = 0;
        
    }
    
    int next() {
        // i = i+1;
        return vec[i++]->val;
        
    }
    
    bool hasNext() {
       return i < vec.size();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */