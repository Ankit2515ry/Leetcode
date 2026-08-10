class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<int>temp(n,1);
        int s=newInterval[0];
        int e=newInterval[1];
        for(int i=0;i<n;i++){
            if(s<=intervals[i][1]&&e>=intervals[i][0]){
                temp[i]=0;
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        int f=false;
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(temp[i]==1){
                res.push_back(intervals[i]);
            }else if(!f&&temp[i]==0){
                f=true;
                res.push_back(newInterval);
            }
        }
        int x=0;
        for(auto it:temp)if(it==1)x++;
        if(x==n){
            res.push_back(newInterval);
        }
        sort(res.begin(),res.end());
        return res;
    }
};