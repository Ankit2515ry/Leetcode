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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        bool f=false;
        while(!q.empty()){
            int k=q.size();
            vector<int>temp;
            while(k--){
                TreeNode* a=q.front();
                q.pop();
                if(a!=nullptr){
                    temp.push_back(a->val);
                    q.push(a->left);
                    q.push(a->right);
                }
            }
            if(f)reverse(temp.begin(),temp.end());
            if(temp.size()!=0)res.push_back(temp);
            // cout<<f<<" ";
            f=!f;
        }
        return res;
    }
};