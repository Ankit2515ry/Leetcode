class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long mod=1e9+7;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({efficiency[i],speed[i]});
        }
        sort(p.rbegin(),p.rend());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long res=LLONG_MIN;
        long long sum=0;
        long long eff=0;
        for(auto [e,s]:p){
            if(pq.size()>k){
                sum-=pq.top().first;
                pq.pop();
            }
            long long temp=sum*eff;
            res=max(res,temp);
            pq.push({s,e});          
            sum+=s;
            eff=e;
        }
        if(pq.size()>k){
            sum-=pq.top().first;
            pq.pop();
        }
        long long temp=sum*eff;
        res=max(res,temp);
        return res%mod;
    }
};