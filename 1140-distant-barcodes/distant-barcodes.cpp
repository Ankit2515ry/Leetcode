class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        for(auto it:barcodes)mp[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            int n=it.first;
            int f=it.second;
            pq.push({f,n});
        }
        int idx=0;
        vector<int>res(barcodes.size());
        while(!pq.empty()){
            int f=pq.top().first;
            int n=pq.top().second;
            pq.pop();
            while(f>0){
                res[idx]=n;
                idx+=2;
                f--;
                if(idx>=res.size())idx=1;
            }
        }
        return res;
    }
};