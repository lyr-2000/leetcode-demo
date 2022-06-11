/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int,int> mp ;
        for(int u:nums) mp[u]++;

        #define HeapItem pair<int,int>
        #define less(l,r) l.second > r.second 
        struct Compare {
            bool operator() (HeapItem &l,HeapItem &r) {
                return less(l,r);
            };
        };
        priority_queue<HeapItem,vector<HeapItem>,Compare> q;
        for(auto pir:mp) {
            q.push(pir);
            if(q.size() > k) q.pop();
        }
        vector<int> res(k);
        int i=0;
        while(q.size()) {
            auto t = q.top();q.pop();
            res[i++] = t.first;
        }
        return res;
        
        
    }
};
// @lc code=end
