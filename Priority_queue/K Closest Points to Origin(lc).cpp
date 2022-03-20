// https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
    typedef array<double, 3> P;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P> pq;
        for (auto it: points) {
            int x = it[0], y = it[1];
            double dif = sqrt(x * x + y * y);
            pq.push({dif, 1.0 * x, 1.0 * y});
        }
        vector<vector<int>> ans;
        while (pq.size() > k) pq.pop();
        while (!pq.empty()) {
            P top = pq.top();
            ans.push_back({{(int) top[1]}, {(int) top[2]}});
            pq.pop();
        }
        return ans;
    }
};
