class Solution {
public:
    vector<int>vis;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.assign(n,-1);
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            res.push_back(a);
            for(auto &it:adj[a]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};