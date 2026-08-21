class Solution {
public:
    int solve(vector<string>& arr,int i,int mask){
        int n=arr.size();
        if(i==n)return 0;
        int temp=0;
        bool f=true;
        for(auto it:arr[i]){
            if(temp&1<<(int)(it-'a'))f=false;
            temp=temp|1<<(int)(it-'a');
        }
        int x=solve(arr,i+1,mask);
        int y=0;
        if(f&&(mask&temp)==0){
            y=temp|solve(arr,i+1,mask|temp);
        }
        int a=__builtin_popcount(x);
        int b=__builtin_popcount(y);
        if(a>b)return x;
        return y;
    }
    int maxLength(vector<string>& arr) {
        int res=solve(arr,0,0);
        int ans=__builtin_popcount(res);
        return ans;
    }
};