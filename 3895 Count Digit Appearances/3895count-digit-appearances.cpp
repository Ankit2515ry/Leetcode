class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int res=0;
        char ch=('0'+digit);
        
        for(auto it:nums){
            string s=to_string(it);
            for(auto i:s)if(i==ch)res++;
        }
        return res;
    }
};