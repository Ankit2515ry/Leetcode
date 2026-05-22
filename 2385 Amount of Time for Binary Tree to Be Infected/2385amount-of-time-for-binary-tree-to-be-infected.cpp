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
    unordered_map<int,vector<int>>mp;
    void built(TreeNode* root){
        if(!root)return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            built(root->left);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            built(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        built(root);
        unordered_set<int>st;
        queue<int>q;
        st.insert(start);
        q.push(start);
        int res=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
               int v=q.front();
                q.pop();
                auto x=mp[v];
                for(auto &it:x){
                    if(st.count(it))continue;
                    st.insert(it);
                    q.push(it);
                }
            }
            res++;
        }
        return res;
    }
};