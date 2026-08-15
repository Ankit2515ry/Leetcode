class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>>p;
        for(int i=0;i<n;i++){
            double r=1.0*wage[i]/quality[i];
            p.push_back({r,quality[i]});
        }
        sort(p.begin(),p.end());
        priority_queue<int>pq;
        double res=INFINITY;
        int sum=0;
        for(auto it:p){
            double r=it.first;
            int q=it.second;
            pq.push(q);
            sum+=q;
            while(!pq.empty()&&pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)res=min(res,r*sum);
        }
        return res;
    }
};