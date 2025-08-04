class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>temp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            temp.push_back({s,i});
        }
        sort(temp.begin(),temp.end());
        vector<vector<string>>res;
        vector<string>x;
        string s=temp[0].first;
        for(int i=0;i<strs.size();i++){
            if(temp[i].first==s)x.push_back(strs[temp[i].second]);
            else{
                res.push_back(x);
                x.erase(x.begin(),x.end());
                s=temp[i].first;
                x.push_back(strs[temp[i].second]);
            }
        }
        res.push_back(x);
        return res;
        // unordered_map<string, vector<string>> mp;
        // for (const string& str : strs) {
        //     string key = str;
        //     sort(key.begin(), key.end()); 
        //     mp[key].push_back(str);       
        // }
        // vector<vector<string>> res;
        // for (auto& it : mp) {
        //     res.push_back(move(it.second));
        // }
        // return res;
    }
};