class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s=to_string(n);
        while(s[s.size()-1]=='0')s.pop_back();
        reverse(s.begin(),s.end());
        int r=stoi(s);
        int mini=min(n,r);
        int maxi=max(n,r);
        vector<bool>sei(1e4+1,true);
        sei[1]=false;
        sei[0]=false;
        for(int i=2;i<=1e2;i++){
            if(sei[i]==true){
                for(int j=i*i;j<=1e4;j+=i){
                    sei[j]=false;
                }
            }
        }
        int res=0;
        for(int i=mini;i<=maxi;i++){
            if(sei[i])res+=i;
        }
        return res;
    }
};