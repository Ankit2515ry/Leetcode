// class Solution {
// public:
//     int n;
//     string s;
//     int memo[20][20][2]; 
//     int dfs(int pos, int count, int tight) {
//         if(pos == s.size()) return count;
//         if(memo[pos][count][tight] != -1) return memo[pos][count][tight];
//         int limit = tight ? s[pos] - '0' : 9;
//         int res = 0;
//         for(int d = 0; d <= limit; d++) {
//             int newTight = tight && (d == limit);
//             int newCount = count + (d == 1 ? 1 : 0);
//             res += dfs(pos + 1, newCount, newTight);
//         }
//         return memo[pos][count][tight] = res;
//     }
//     int countDigitOne(int n_) {
//         s = to_string(n_);
//         memset(memo, -1, sizeof(memo));
//         return dfs(0, 0, 1);
//     }
// };
class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        long long factor = 1; 
        int current, higher, lower; 
        while(n / factor != 0) {
            lower = n % factor;
            current = (n / factor) % 10;
            higher = n / (factor * 10);    
            if(current == 0) {
                count += higher * factor;
            } else if(current == 1) {
                count += higher * factor + (lower + 1);
            } else {
                count += (higher + 1) * factor;
            }    
            factor *= 10;
        }  
        return count;
    }
};
