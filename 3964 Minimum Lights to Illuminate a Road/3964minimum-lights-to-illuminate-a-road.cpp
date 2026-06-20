class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>temp(n+1,0);
        for(int i=0;i<n;i++){
            int v=lights[i];
            if(v==0)continue;
            int l=max(0,i-v);
            int r=min(n,i+v+1);
            temp[l]+=1;
            temp[r]-=1;
        }
        for(int i=1;i<=n;i++){
            temp[i]+=temp[i-1];
        }
        int res=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(temp[i]!=0){
                int d=c/3;
                int m=c%3;
                c=0;
                res+=d;
                if(m!=0)res++;
            }
            else c++;
        }
        int d=c/3;
        int m=c%3;
        res+=d;
        if(m)res++;
        return res;
    }
};