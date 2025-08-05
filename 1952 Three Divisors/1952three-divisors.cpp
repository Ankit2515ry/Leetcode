class Solution {
public:
    bool isThree(int n) {
        vector<bool>seive(n+1,true);
        seive[0]=seive[1]=false;
        for(int i=2;i<=n;i++){
            if(seive[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    seive[j]=false;
                }
            }
        }
        unordered_set<int>p;
        for(int i=2;i<n+1;i++){
            if(seive[i]){
                //cout<<i*i<<" ";
                p.insert(i*i);
            }
        }
        if(p.find(n)!=p.end())return true;
        return false;
    }
};