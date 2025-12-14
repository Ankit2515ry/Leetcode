class Solution {
public:
    string reverseWords(string s) {
        int c=0;
        int n=s.size();
        int i=0;
        string res="";
        while(i<n&&s[i]!=' '){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                c++;
            }
            res+=s[i];
            i++;
        }
        if(i<n&&s[i]==' ')res+=' ';
        i++;
        while(i<n){
            string temp="";
            int count=0;
            while(i<n&&s[i]!=' '){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    count++;
                }
                temp+=s[i];
                i++;
            }
            if(c==count)reverse(temp.begin(),temp.end());
            res+=temp;
            if(i<n&&s[i]==' ')res+=' ';
            i++;
        }
        return res;
    }
};