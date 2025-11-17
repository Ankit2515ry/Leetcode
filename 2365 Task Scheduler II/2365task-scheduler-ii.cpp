class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long res=0;
        unordered_map<int ,long long >mp;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            if(mp.find(tasks[i])!=mp.end()){
                if(mp[tasks[i]]>res)res=mp[tasks[i]];
                res++;
                mp[tasks[i]]=res+space;
            }else{
                res++;
                mp[tasks[i]]=res+space;
            }
        }
        return res;
    }
};