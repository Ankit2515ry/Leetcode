class Solution {
public:
    string reverseByType(string s) {
        string sp="";
        string si="";
        for(auto it:s){
            if(it-'a'<26&&it-'a'>=0)si+=it;
            else sp+=it;
        }
        reverse(sp.begin(),sp.end());
        reverse(si.begin(),si.end());
        string res="";
        int i=0,j=0;
        //cout<<si<<" "<<sp;
        for(auto it:s){
            if(it-'a'<26&&it-'a'>=0){
                res+=si[i];
                i++;
            }else{
                res+=sp[j];
                j++;
            }
        }
        return res;
    }
};