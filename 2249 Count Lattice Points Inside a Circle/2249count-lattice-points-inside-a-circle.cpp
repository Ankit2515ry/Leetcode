#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<long long> seen; 
        int res = 0;
        for (auto& c : circles) {
            int x = c[0], y = c[1], r = c[2];
            int r2 = r * r;
            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {
                    int dx = x - i, dy = y - j;
                    if (dx * dx + dy * dy <= r2) {
                        long long key = ((long long)i << 32) | (unsigned int)j;
                        if (seen.insert(key).second) res++;
                    }
                }
            }
        }
        return res;
    }
};
