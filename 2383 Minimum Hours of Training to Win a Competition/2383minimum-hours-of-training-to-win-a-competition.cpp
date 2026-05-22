class Solution {
public:
    int minNumberOfHours(int en, int ex, vector<int>& energy, vector<int>& experience) {
        int te=0;
        for(auto &it:energy)te+=it;
        int res=0;
        if(te>=en)res+=te-en+1;
        for(auto &it:experience){
            if(it>=ex){
                res+=it-ex+1;
                ex=it+1;
            }
            ex+=it;
        }
        return res;
    }
};