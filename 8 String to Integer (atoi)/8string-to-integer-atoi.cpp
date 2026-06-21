class Solution {
public:
    int myAtoi(string s) {
        string temp="";
        string a="-+0123456789";
        int i=0;
        int n=s.size();
        while(i<n&&(s[i]==' '))i++;
        while(i<n&&a.find(s[i])!=string::npos){
            if(temp.size()>0&&(s[i]=='-'||s[i]=='+'))break;
            temp+=s[i];
            i++;
        }
        bool f=false;
        long long res=0;
        if(temp.size()>0&&temp[0]=='-'){
            f=true;
            temp.erase(0,1);
        }
        if(temp.size()>0&&temp[0]=='+'){
            temp.erase(0,1);
        }
        for(int i=0;i<temp.size();i++){
            res*=10;
            res+=temp[i]-'0';
            if(!f&&res>INT_MAX)return INT_MAX;
            if(f&&res>1LL*INT_MAX+1)return INT_MIN;
        }
        if(f)res*=-1;
        return res;
    }
};