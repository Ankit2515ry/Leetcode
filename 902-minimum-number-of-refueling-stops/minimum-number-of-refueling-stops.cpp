class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res=0;
        long long s=startFuel;
        sort(stations.begin(),stations.end());
        priority_queue<int>pq;
        for(auto it:stations){
            int p=it[0];
            int f=it[1];
            while(!pq.empty()&&s<p){
                s+=pq.top();
                pq.pop();
                res++;
            }
            if(s<p)return -1;
            pq.push(f);
        }
        while(!pq.empty()&&s<target){
            s+=pq.top();
            pq.pop();
            res++;
        }
        if(s<target)return -1;
        return res;    
    }
};