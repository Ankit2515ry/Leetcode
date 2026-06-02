class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=(char)('0'+i);
        }
        int x=k-1;
        while(x--){
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};