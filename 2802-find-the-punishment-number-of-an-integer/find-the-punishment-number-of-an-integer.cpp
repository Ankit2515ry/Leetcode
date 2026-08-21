class Solution {
public:
    int v;
    bool check(string s,int curr,int prev,int sum){
        int n=s.size();
        string sub=s.substr(prev,curr-prev);
        int val=0;
        if(sub!="")val=stoi(sub);
        if(sum+val>v)return false;
        if(curr==n){
            if(sum+val==v)return true;
            return false;
        }
        bool a=check(s,curr+1,curr,sum+val);
        bool b=check(s,curr+1,prev,sum);
        return a||b;
    }
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            v=i;
            string s=to_string(num);
            if(check(s,0,0,0)){
                res+=num;
                // cout<<i<<" ";
            }
        }
        return res;
    }
};