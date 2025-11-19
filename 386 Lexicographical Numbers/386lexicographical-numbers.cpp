class Solution {
public:
    void dfs(int cur,int n,vector<int>&res){
        if(cur>n)return;
        res.push_back(cur);
        for(int i=cur*10;i<cur*10+10;i++){
            if(i>n)return;
            dfs(i,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        // vector<string>temp;
        // for(int i=0;i<n;i++){
        //     string s=to_string(i+1);
        //     temp.push_back(s);
        // }
        // sort(temp.begin(),temp.end());
        // vector<int>res;
        // for(auto &it:temp){
        //     int a=stoi(it);
        //     res.push_back(a);
        // }
        // return res;
        //second method;
        // vector<int>res;
        // for(int i=1;i<=9;i++){
        //     dfs(i,n,res);
        // }
        // return res;
        vector<int>res;
        int cur=1;
        for(int i=0;i<n;i++){
            res.push_back(cur);
            if(cur*10<=n){
                cur*=10;
            }else{
                while(cur%10==9||cur+1>n){
                    cur/=10;
                }
                cur++;
            }      
        }
        return res;
    }
};