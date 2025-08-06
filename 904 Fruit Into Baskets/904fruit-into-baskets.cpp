class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res=0;
        int j=0;
        int n=fruits.size();
        unordered_map<int,int>mp;
        for (int i = 0; i < n; i++) {
            mp[fruits[i]]++;
            while (mp.size() > 2) {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};