class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int res=1;
        int n=grades.size();
        if(n<3)return res;
        int i=2;
        n--;
        while(n>=i){
            n-=i;
            res++;
            i++;
        }
        return res;
    }
};