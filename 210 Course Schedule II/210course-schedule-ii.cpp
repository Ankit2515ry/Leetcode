class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, stack<int>& st, int node) {
        vis[node] = 0;
        for (auto &it : adj[node]) {
            if (vis[it] == -1) {
                if (!dfs(adj, vis, st, it)) return false;
            } else if (vis[it] == 0) {
                return false;
            }
        }
        vis[node] = 1; 
        st.push(node);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(n, -1);
        stack<int> st;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(adj, vis, st, i)) return {};
            }
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
