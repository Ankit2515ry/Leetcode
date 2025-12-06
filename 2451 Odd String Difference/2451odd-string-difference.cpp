class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        map<vector<int>,int>mp;
        map<vector<int>,string>mpp;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<m-1;j++){
                temp.push_back(words[i][j+1]-words[i][j]); 
            }
            mp[temp]++;
            mpp[temp]=words[i];
        }
        for(auto &it:mp){
            const vector<int>&v=it.first;
            int num=it.second;
            if(num==1){
                return mpp[v];
            }
        }
        return "";
    }
};