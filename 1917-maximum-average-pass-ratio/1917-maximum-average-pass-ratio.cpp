class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int q) {
            return (double)(p + 1) / (q + 1) - (double)p / q;
        };

        priority_queue<tuple<double,int,int>> pq;
        for (auto &row : classes) {
            int p = row[0], q = row[1];
            pq.push({gain(p, q), p, q});
        }

        while (extraStudents--) {
            auto [g, p, q] = pq.top(); 
            pq.pop();
            p++; q++;
            pq.push({gain(p, q), p, q});
        }

        double sum = 0;
        while (!pq.empty()) {
            auto [g, p, q] = pq.top();
            pq.pop();
            sum += (double)p / q;
        }

        return sum / classes.size();
    }
};
