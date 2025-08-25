class Solution {
public:
    string solve(string s,int c,int l){
        string temp="";
        int sp=l-s.size();
        int es=(sp/c)+1;
        int k=sp%c;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')temp+=s[i];
            else{
                int a=es;
                while(a--)temp+=' ';
                if(k>0){
                    temp+=' ';
                    k--;
                }
            }
        }
        return temp;
    }
    vector<string> fullJustify(vector<string>& words, int l) {
        vector<string>res;
        int n=words.size();
        string temp="";
        int c=0;
        for(int i=0;i<n;i++){
            if(temp.empty()&&temp.size()+words[i].size()<=l){
                temp+=words[i];
            }
            else if(temp.size()+words[i].size()+1<=l){
                if(!temp.empty()){
                    temp+=' '+words[i];
                    c++;
                }
                else{
                    temp+=words[i];
                }
            }
            else{
                if(c>0)temp=solve(temp,c,l);
                if(c==0){
                    while(temp.size()!=l)temp+=' ';
                }
                res.push_back(temp);
                temp="";
                temp+=words[i];
                c=0;
            }
        }
        while(temp.size()!=l)temp+=' ';
        res.push_back(temp);
        return res;
    }
};