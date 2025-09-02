class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x=max(0,(min(rec1[2],rec2[2])-max(rec1[0],rec2[0])));
        int y=max(0,(min(rec1[3],rec2[3])-max(rec1[1],rec2[1])));
        if(x==0||y==0)return false;
        return true;
    }
};