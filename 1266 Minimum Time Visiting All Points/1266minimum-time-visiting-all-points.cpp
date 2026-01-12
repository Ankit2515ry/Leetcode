class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int j=1;j<n;j++){
            int x=abs(points[j-1][0]-points[j][0]);
            int y=abs(points[j-1][1]-points[j][1]);
            res+=max(x,y);
        } 
        return res;
    }
};