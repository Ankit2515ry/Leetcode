class Solution {
public:
    int sz;
    vector<int>bit;
    void update(int i,int v){
        while(i<sz){
            bit[i]+=v;
            i+=i&(-i);
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }
    int reversePairs(vector<int>& nums) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int n=st.size();
        sz=n+2;
        bit.assign(sz,0);
        vector<long long>f(n);
        int idx=0;
        for(auto it:st){
            long long val=1LL*it*2;
            f[idx]=val;
            idx++;
        }
        for(auto it:nums){
            long long val=1LL*it*2;
            int i=lower_bound(f.begin(),f.end(),val)-f.begin()+1;
            update(i,1);
        }
        int res=0;
        for(auto it:nums){
            long long val=1LL*it*2;
            int i=lower_bound(f.begin(),f.end(),val)-f.begin()+1;
            update(i,-1);
            val/=2;
            i=lower_bound(f.begin(),f.end(),val)-f.begin()+1;
            res+=query(i-1);  
        }
        return res;
    }
};

























// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// template<typename T>
// using ordered_set = tree<
//     pair<long long,int>,
//     null_type,
//     less<pair<long long,int>>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>;

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         //O(n2) time complexity
//         // int n=nums.size();
//         // int res=0;
//         // for(int i=0;i<n;i++){
//         //     int k=(nums[i]/2) + (nums[i]%2);
//         //     for(int j=i+1;j<n;j++){
//         //         if(k>nums[j])res++;
//         //     }
//         // }
//         // return res;
        
//         //using ordered set O(nlog(n)) need to include 
//         //-->
//         /*
//         #include <bits/stdc++.h>
//         #include <ext/pb_ds/assoc_container.hpp>
//         #include <ext/pb_ds/tree_policy.hpp>

//         using namespace std;
//         using namespace __gnu_pbds;

//         template<typename T>
//         using ordered_set = tree<
//             pair<long long,int>,
//             null_type,
//             less<pair<long long,int>>,
//             rb_tree_tag,
//             tree_order_statistics_node_update>;
//         */
//         ordered_set<long long>st;
//         int n=nums.size();
//         int res=0;
//         for(int i=n-1;i>=0;i--){
//             long long v=nums[i];
//             res+=st.order_of_key({v,-1});
//             st.insert({2LL*v,i});
//         }
//         return res;
//     }
// };