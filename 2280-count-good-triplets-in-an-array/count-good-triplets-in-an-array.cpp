class Solution {
public:
    int sz;
    vector<int>bit1;
    vector<int>bit2;
    int query1(int i){
        int sum=0;
        while(i>0){
            sum+=bit1[i];
            i-=i&(-i);
        }
        return sum;
    }
    int query2(int i){
        int sum=0;
        while(i>0){
            sum+=bit2[i];
            i-=i&(-i);
        }
        return sum;
    }
    void update1(int i,int v){
        while(i<sz){
            bit1[i]+=v;
            i+=i&(-i);
        }
    }
    void update2(int i,int v){
        while(i<sz){
            bit2[i]+=v;
            i+=i&(-i);
        }
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>mp(n);
        for(int i=0;i<n;i++){
            mp[nums1[i]]=i;
        }
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=mp[nums2[i]];
        }
        // for(auto it:mp)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:arr)cout<<it<<" ";
        // cout<<endl;
        sz=n+1;
        bit1.assign(sz,0);
        bit2.assign(sz,0);
        for(int i=0;i<n;i++){
            update2(arr[i]+1,1);
        }
        long long res=0;
        for(int i=0;i<n;i++){
            int l=query1(arr[i]);
            update1(arr[i]+1,1);
            int r=n-query2(arr[i]+1)-i;
            update2(arr[i]+1,-1);
            res+=1LL*l*r;
        }
        return res;
    }
};