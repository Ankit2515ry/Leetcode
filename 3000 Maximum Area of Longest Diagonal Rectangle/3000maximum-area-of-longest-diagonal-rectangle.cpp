class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        // int n=d.size();
        // vector<pair<int,int>>mp;
        // int l=0;
        // int w=0;
        // for(int i=0;i<n;i++){
        //     l=d[i][0];
        //     w=d[i][1];
        //     mp.push_back({((l*l)+(w*w)),l*w});
        // }
        // int res=0;
        // sort(mp.begin(),mp.end());
        // res=mp[n-1].second;
        // return res;
        int n=d.size();
        int dia=0;
        int res=0;
        int temp=0;
        for(int i=0;i<n;i++){
            temp=(d[i][0]*d[i][0])+(d[i][1]*d[i][1]);
            if(d[i][0]>0&&d[i][1]>0&&temp>dia){
                dia=temp;
                res=d[i][0]*d[i][1];
            }
            else if(d[i][0]>0&&d[i][1]>0&&temp==dia)res=max(res,d[i][0]*d[i][1]);
        }
        return res;
    }
};