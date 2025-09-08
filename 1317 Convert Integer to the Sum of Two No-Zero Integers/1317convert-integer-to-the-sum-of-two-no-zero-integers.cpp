class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // int a=1;
        // int b=n-1;
        // for(int i=1;i<n;i++){
        //     a=i;
        //     b=n-i;
        //     bool f=false;
        //     string sa=to_string(a);
        //     for(auto &it:sa)if(it=='0')f=true;
        //     string sb=to_string(b);
        //     for(auto &it:sb)if(it=='0')f=true;
        //     if(!f)return {a,b};
        // }
        // return {a,b};
        string s=to_string(n);
        string a="";
        bool f=false;
        for(int i=s.size()-1;i>=0;i--){
            if(f==true){
                if(s[i]>'2'){
                    a+=s[i]-2;
                    f=false;
                }
                else if(s[i]<='2'&&i!=0){
                    a+=s[i]+1;
                    f=true;
                }
            }else{
                if(s[i]>'1'){
                    a+=s[i]-1;
                }
                else if(s[i]<='1'&&i!=0){
                    a+=s[i]+1;
                    f=true;
                }
            }
        }
        reverse(a.begin(),a.end());
        int x=stoi(a);
        int y=n-x;
        return {x,y};
    }
};