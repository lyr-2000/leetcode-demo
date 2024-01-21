#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s{};
        int n = nums.size();
        for (int i=0;i<k && i<n;i++) s.insert(nums[i]);
        vector<int> res{};
        res.push_back(*prev(s.end()));
        for (int i=k;i<n;i++) {
            if(i>=k) s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            auto maxi = prev(s.end() );
            if(maxi!=s.begin()) {
                res.push_back(*maxi);
            }

        }
        return res;
        
    }
};

int main() {

    Solution k;
    vector<int> nums{1,3,-1,-3,5,3,6,7}; 
    auto v = k.maxSlidingWindow(nums,3);
    for (int u:v) cout << u << " ";
    cout <<endl;
}