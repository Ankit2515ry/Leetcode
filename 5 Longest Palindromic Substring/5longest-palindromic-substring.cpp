class Solution {
public:
    // bool check(string &s){
    //     string k=s;
    //     reverse(k.begin(),k.end());
    //     return (s==k);
    // }
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        // for(int i=0;i<n;i++){
        //     for(int j=n-1;j>=i;j--){
        //         string k=s.substr(i,j-i+1);
        //         reverse(k.begin(),k.end());
        //         if(res.size()<k.size()&&s.substr(i,j-i+1)==k){
        //             res=k;
        //             break;
        //         }
        //     }
        // }
        // return res;
        for(int i=0;i<n;i++){
            int l=i-1;
            int r=i+1;
            while(l>=0&&r<n){
                if(s[l]!=s[r])break;
                l--;
                r++;
            }
            l++;
            r--;
            if(res.size()<r-l+1)res=s.substr(l,r-l+1);
            if(i+1<n&&s[i]==s[i+1]){
                r=i+2;
                l=i-1;
                while(l>=0&&r<n){
                    if(s[l]!=s[r])break;
                    l--;
                    r++;
                }
                l++;
                r--;
                if(res.size()<r-l+1)res=s.substr(l,r-l+1);
            }
        }
        return res;
    }
};