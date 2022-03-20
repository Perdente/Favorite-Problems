// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto it: nums) mp[it]++;
        for (auto [key, value]: mp) {
            pq.push({value, key});
        }
        vector<int> ans;
        while ((int) ans.size() < k) {
            pair<int, int> top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};
