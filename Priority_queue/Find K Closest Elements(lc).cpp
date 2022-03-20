// https://leetcode.com/problems/find-k-closest-elements/
class Solution {
    typedef pair<int, int> P;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<P> pq;
        for (int i = 0; i < (int) arr.size(); ++i) {
            pq.push({abs(arr[i] - x), i});
        }
        vector<int> ans;
        while ((int) pq.size() > k) pq.pop();
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            cout << top.first << " " << top.second << '\n';
            ans.push_back(arr[top.second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
