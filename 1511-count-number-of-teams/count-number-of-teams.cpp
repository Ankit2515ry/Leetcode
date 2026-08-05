class Solution {
public:
    int sz;
    vector<int>bit1;
    vector<int>bit2;
    void update1(int i,int v){
        while(i<sz){
            bit1[i]+=v;
            i+=i&(-i);
        }
    }
    void update2(int i,int v){
        while(i<sz){
            bit2[i]+=v;
            i+=i&(-i);
        }
    }
    int query1(int i){
        int sum=0;
        while(i>0){
            sum+=bit1[i];
            i-=i&(-i);
        }
        return sum;
    }
    int query2(int i){
        int sum=0;
        while(i>0){
            sum+=bit2[i];
            i-=i&(-i);
        }
        return sum;
    }
    int numTeams(vector<int>& rating) {
        sz=1e5+2;
        bit1.assign(sz,0);
        bit2.assign(sz,0);
        int res=0;
        for(auto it:rating){
            update2(it,1);
        }
        int n=rating.size();
        for(int i=0;i<rating.size();i++){
            int ls=query1(rating[i]-1);
            int lg=i-ls;
            int rs=query2(rating[i]-1);
            int rg=n-i-rs-1;
            res+=(ls*rg)+(lg*rs);
            update1(rating[i],1);
            update2(rating[i],-1);
        }
        return res;
    }
};