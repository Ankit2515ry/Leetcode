class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto it:points){
            int d=(it[0]*it[0])+(it[1]*it[1]);
            int x=it[0];
            int y=it[1];
            pq.push({d,{x,y}});
            while(pq.size()>k)pq.pop();
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            res.push_back({x,y});
        }
        return res;
    }
};