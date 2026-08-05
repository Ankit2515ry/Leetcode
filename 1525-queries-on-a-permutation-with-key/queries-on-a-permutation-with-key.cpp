class Solution {
public:
    int sz;
    vector<int>bit;
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
    void update(int i,int v){
        while(i<sz){
            bit[i]+=v;
            i+=i&(-i);
        }
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        int n=queries.size();
        sz=m+n+2;
        bit.assign(sz,0);
        unordered_map<int,int>mp;
        for(int i=1;i<=m;i++){
            mp[i]=n+i;
            update(n+i,1);
        }
        vector<int>res;
        int front=n;
        for(int i=0;i<queries.size();i++){
            int curr=mp[queries[i]];
            int v=query(curr-1);
            res.push_back(v);
            update(curr,-1);
            update(front,1);
            mp[queries[i]]=front;
            front--;
        }
        return res;
    }
};