/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char u:s) mp[u]++;
        struct Compare {
            bool operator() (pair<int,int>&l,pair<int,int>&r) {
                return l.second < r.second;
            };
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> q;
        for(auto pr:mp) q.push(pr);
        string res;
        while(q.size()) {
            auto pir = q.top();q.pop();
            for(int i=0;i<pir.second;i++) {
                res.push_back(pir.first);
            }
        }
        return res;
    }
};
// @lc code=end

