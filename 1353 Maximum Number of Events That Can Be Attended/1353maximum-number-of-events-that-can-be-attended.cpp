class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int j=0;
        int d=0;
        for(auto &it:events)d=max(d,it[1]);
        priority_queue<int,vector<int>,greater<int>>pq;
        int res=0;
        int n=events.size();
        for(int i=1;i<=d;i++){
            while(j<n&&events[j][0]==i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty()&&pq.top()<i)pq.pop();
            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};