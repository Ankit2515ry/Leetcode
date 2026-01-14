class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            double y, x1, x2;
            int type; // +1 = add, -1 = remove
        };

        vector<Event> events;
        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) {
                 return a.y < b.y;
             });

        multiset<pair<double,double>> active;

        auto unionX = [&]() {
            if (active.empty()) return 0.0;
            vector<pair<double,double>> segs(active.begin(), active.end());
            sort(segs.begin(), segs.end());

            double total = 0;
            double curL = segs[0].first, curR = segs[0].second;
            for (int i = 1; i < segs.size(); i++) {
                if (segs[i].first > curR) {
                    total += curR - curL;
                    curL = segs[i].first;
                    curR = segs[i].second;
                } else {
                    curR = max(curR, segs[i].second);
                }
            }
            total += curR - curL;
            return total;
        };

        // First pass: compute total union area
        double totalArea = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            auto &e = events[i];
            if (e.type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            double dy = events[i + 1].y - e.y;
            if (dy > 0)
                totalArea += unionX() * dy;
        }

        // Second pass: find y where area = totalArea / 2
        active.clear();
        double half = totalArea / 2.0;
        double curArea = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            auto &e = events[i];
            if (e.type == +1)
                active.insert({e.x1, e.x2});
            else
                active.erase(active.find({e.x1, e.x2}));

            double dy = events[i + 1].y - e.y;
            if (dy <= 0) continue;

            double width = unionX();
            double area = width * dy;

            if (curArea + area >= half) {
                double need = half - curArea;
                return e.y + need / width;
            }
            curArea += area;
        }

        return events.back().y; // fallback
    }
};
