class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dx = bfs(adj, x);
        vector<int> dy = bfs(adj, y);
        vector<int> dz = bfs(adj, z);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(dx[i] == -1 || dy[i] == -1 || dz[i] == -1) continue; 
            long long a = dx[i], b = dy[i], c = dz[i];
            vector<long long> p = {a,b,c};
            sort(p.begin(), p.end());
            if(p[0]*p[0] + p[1]*p[1] == p[2]*p[2])res++;
        }
        return res;
    }
};
