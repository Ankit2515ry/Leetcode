class Solution {
public:
    long long mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, set<int>> mp;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            mp[y].insert(x);
        }
        if (mp.size() < 2) return 0;
        unordered_map<int, long long> mpp;
        long long sum = 0;
        for (auto& it : mp) {
            long long cnt = it.second.size();
            if (cnt >= 2) {
                long long comb = (cnt * (cnt - 1) / 2) % mod;
                mpp[it.first] = comb;
                sum = (sum + comb) % mod;
            }
        }
        long long ans = 0;
        for (auto& it : mpp) {
            long long val = it.second;
            sum = (sum - val + mod) % mod;
            ans = (ans + (val * sum) % mod) % mod;
        }
        return int(ans);
    }
};
