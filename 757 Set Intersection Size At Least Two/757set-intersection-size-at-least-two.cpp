class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<int> temp;  
        for (auto &in : intervals) {
            int L = in[0], R = in[1];
            int cnt = 0;
            for (int i = temp.size()-1; i >= 0 && cnt < 2; i--) {
                if (temp[i] >= L && temp[i] <= R) cnt++;
                else if (temp[i] < L) break;
            }
            if (cnt == 2) continue;
            if (cnt == 1) {
                
                int p = R; 
                if (temp.back() == R) p = R - 1;
                temp.push_back(p);
            } else {
                temp.push_back(R-1);
                temp.push_back(R);
            }
        }
        return temp.size();
    }
};