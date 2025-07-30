class Solution {
public:
    string addBinary(string a, string b) {
        bool carry=false;
        int al=a.size();
        int bl=b.size();
        int n=min(al,bl);
        al--;
        bl--;
        string res="";
        for(int i=0;i<n;i++){
            if(carry){
                if(a[al]=='0'&&b[bl]=='0'){
                    res+='1';
                    carry=false;
                }
                else if(a[al]=='1'&&b[bl]=='1'){
                    res+='1';
                    carry=true;
                }
                else{
                    res+='0';
                    carry=true;
                }
            }else{
                if(a[al]=='0'&&b[bl]=='0'){
                    res+='0';
                    carry=false;
                }
                else if(a[al]=='1'&&b[bl]=='1'){
                    res+='0';
                    carry=true;
                }
                else{
                    res+='1';
                    carry=false;
                }
            }
            al--;
            bl--;
        }
        while(al>=0){
            if(carry){
                if(a[al]=='0'){
                    res+='1';
                    carry=false;
                }else res+='0';
            }else{
                res+=a[al];
            }
            al--;
        }
        while(bl>=0){
            if(carry){
                if(b[bl]=='0'){
                    res+='1';
                    carry=false;
                }else res+='0';
            }else{
                res+=b[bl];
            }
            bl--;
        }
        if(carry)res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};