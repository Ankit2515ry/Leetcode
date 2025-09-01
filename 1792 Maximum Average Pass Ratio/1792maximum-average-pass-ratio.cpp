class Solution {
public:
    double p(int p, int t) {
        double b = (double)p / t;
        double a  = (double)(p + 1) / (t + 1);
        return a - b;
    }
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < (int)c.size(); i++) {
            double gain = p(c[i][0], c[i][1]);
            pq.push({gain, i});
        }
        for (int i = 0; i < e; i++) {
            auto [gain, idx] = pq.top();
            pq.pop();
            c[idx][0]++;
            c[idx][1]++;
            double newGain = p(c[idx][0], c[idx][1]);
            pq.push({newGain, idx});
        }
        double sum = 0.0;
        for (auto& c : c) {
            sum += (double)c[0] / c[1];
        }
        return sum / c.size();
    }
};
