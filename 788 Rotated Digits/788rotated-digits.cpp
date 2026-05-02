class Solution {
public:
    int rotatedDigits(int n) {
        int res=0;
        unordered_map<int,int>mp={{0,0},{1,1},{8,8},{2,5},{5,2},{6,9},{9,6}};
        for(int i=1;i<=n;i++){
            string a=to_string(i);
            int m=a.size();
            string b="";
            int j=0;
            while(j<m){
                char ch=a[j];
                if(!mp.count(ch-'0'))break;
                int d=mp[ch-'0'];
                b+='0'+d;
                j++;
            }
            cout<<a<<" "<<b<<endl;
            if(j<m)continue;
            if(a!=b)res++;
        }
        return res;
    }
};