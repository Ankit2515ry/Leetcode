class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        long long c=w;
        vector<pair<int,int>>p;
        for(int i=0;i<profits.size();i++){
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end());
        priority_queue<int>pq;
        for(auto it:p){
            int prof=it.second;
            int cap=it.first;
            if(cap<=c)pq.push(prof);
            else{
                while(!pq.empty()&&k>0&&c<cap){
                    c+=pq.top();
                    pq.pop();
                    k--;
                }
                if(k<=0||c<cap)return c;
                pq.push(prof);
            }
        }
        while(!pq.empty()&&k>0){
            c+=pq.top();
            pq.pop();
            k--;
        }
        return c;
    }
};