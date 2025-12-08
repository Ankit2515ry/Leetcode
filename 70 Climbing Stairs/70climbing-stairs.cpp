class Solution {
public:
    using ll = long long;
    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
        vector<vector<ll>> C(2, vector<ll>(2));
        C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
        C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
        C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
        C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
        return C;
    }
    vector<vector<ll>> matPow(vector<vector<ll>> M, long long n) {
        vector<vector<ll>> R = {{1,0},{0,1}}; 
        while (n > 0) {
            if (n & 1) 
                R = multiply(R, M);
            M = multiply(M, M); 
            n >>= 1;            
        }
        return R;
    }
    // int res=0;
    vector<int>dp;
    // void solve(int i,int n){
    //     if(i==n)res++;
    //     if(i>=n)return;
    //     solve(i+1,n);
    //     solve(i+2,n);
    // }
    int solve(int i,int n){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        dp[i]=solve(i+1,n)+solve(i+2,n);
        return dp[i];
    }
    int climbStairs(int n) {
        long double d=sqrt(5);
        long double a=(1+sqrt(5))/2;
        long double b=(1-sqrt(5))/2;
        long double f=(pow(a,n+1)-pow(b,n+1))/d;
        int ans=round(f);
        return ans;
        if (n == 0) return 1;
        vector<vector<ll>> M = {{1,1},{1,0}};
        vector<vector<ll>> R = matPow(M, n);
        return R[0][0];
        dp.assign(n+1,-1);
        // solve(0,n);
        // return res;
        int res=solve(0,n);
        return res;
    }
};