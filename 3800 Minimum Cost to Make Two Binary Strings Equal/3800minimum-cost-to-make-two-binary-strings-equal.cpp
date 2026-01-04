class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int a = 0, b = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1') a++;
            if (s[i] == '1' && t[i] == '0') b++;
        }
        long long res = 1LL * (a + b) * flipCost; 
        for (int k = -b; k <= a; k++) {
            int na = a - k;
            int nb = b + k;
            long long cost = 1LL * abs(k) * crossCost 
                           + 1LL * min(na, nb) * swapCost 
                           + 1LL * abs(na - nb) * flipCost;
            res = min(res, cost);
        }
        
        return res;
    }
};