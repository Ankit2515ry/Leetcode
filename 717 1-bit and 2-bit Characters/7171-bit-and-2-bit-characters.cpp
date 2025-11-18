class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i<bits.size()-1){
            i+=bits[i]+1;
        }
        if(i==bits.size()-1)return true;
        return false ;
    }
};