//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
        vector<pair<double,int>>v(n);
        for(int i=0;i<n;++i){
            double x=(arr[i].value*1.0)/(arr[i].weight*1.0);
            v[i]={x,i};
        }
        sort(v.begin(),v.end(),[](const pair<double,int>&a,const pair<double,int>&b){return a.first>b.first;});
        double ans=0.0,sum=0.0;
        for(int i=0;i<n;++i){
            if(sum+arr[v[i].second].weight<W){
                sum+=arr[v[i].second].weight;
                ans+=arr[v[i].second].value;
            }else{
                double x=(W-sum)*1.0;
                ans+=v[i].first*x;
                break;
            }
        }
        return ans;
/*

// Topic: Fractional Knapsack
// https://www.interviewbit.com/blog/fractional-knapsack-problem/
// Given a set of N items each having value V with weight W and the total capacity of a knapsack.
// The task is to find the maximal value of fractions of items that can fit into the knapsack.

// Examples:
// Input: A[] = {{60, 20} , {100, 50}, {120, 30}}, Total_capacity  = 50
// Output: 180.00
// Explanation: Take the first item and the third item. Total value = 60 + 120 = 180 with a total capacity of 20 + 30 = 50


#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool comp(pair<int, int> &a, pair<int, int> &b) {
    double x = (double) a.first / a.second;
    double y = (double) b.first / b.second;
    return (x > y);
}

void malena() {
    int n, capacity; cin >> n >> capacity;
    vector<pair<int, int>> items(n);
    for (auto &[value, weight]: items) {
        cin >> value >> weight;
    }
    sort(items.begin(), items.end(), comp);
    int cur_weight = 0;
    double sum = 0.0;
    for (auto [value, weight]: items) {
        if (cur_weight + weight <= capacity) {
            sum += value;
            cur_weight += weight;
        } else {
            int remain = capacity - cur_weight;
            sum += value * ((double) remain / weight);
            break;
        }
    }
    cout << sum << '\n';
    // for (auto [value, weight]: items) {
    //     cout << value << " " << weight << '\n';
    // }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}

*/
