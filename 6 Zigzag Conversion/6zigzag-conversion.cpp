class Solution {
public:
    string convert(string s, int num) {
        if(num==1)return s;
        string res="";
        vector<vector<char>>ch(num,vector<char>(s.size(),' '));
        int n=s.size();
        int k=0;
        int i=0;
        int j=0;
        while(k<n){
            while(k<n&&i<num){
                ch[i][j]=s[k];
                k++;
                i++;
            }
            i-=2;
            j++;
            while(k<n&&i>=0){
                ch[i][j]=s[k];
                k++;
                i--;
                j++;
            }
            j--;
            i+=2;
        }
        for(auto it:ch){
            for(auto i:it){
                if(i!=' ')res+=i;
                //cout<<i<<" ";
            }
            //cout<<endl;
        }

        return res;
    }
};