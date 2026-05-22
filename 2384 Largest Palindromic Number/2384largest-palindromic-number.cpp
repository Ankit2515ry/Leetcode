class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>f(10,0);
        for(auto &it:num)f[it-'0']++;
        string res="";
        for(int i=9;i>=0;i--){
            int x=f[i]/2;
            if(i==0&&res.size()==0)break;
            while(x--){
                char y='0'+i;
                res+=y;
                f[i]-=2;
            }
        }
        string temp=res;
        reverse(temp.begin(),temp.end());
        bool fl=false;
        char ch='0';
        for(int i=9;i>=0;i--){
            if(f[i]!=0){
                fl=true;
                ch+=i;
                break;
            }
        }
        if(fl)res+=ch;
        res+=temp;
        return res;
    }
};