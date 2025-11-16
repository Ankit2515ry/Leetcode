class Solution {
public:
    int minLengthAfterRemovals(string s) {
        string a="";
        int n=s.size();
        //int ca=0;
        //int cb=0;
        for(int i=0;i<n;i++){
            //if(s[i]=='a')ca++;
            //if(s[i]=='b')cb++;
            if(!a.empty()&&s[i]!=a[a.size()-1]){
                a.pop_back();
            }else{
                a.push_back(s[i]);
            }
            
        }
        return a.size();
    }
};