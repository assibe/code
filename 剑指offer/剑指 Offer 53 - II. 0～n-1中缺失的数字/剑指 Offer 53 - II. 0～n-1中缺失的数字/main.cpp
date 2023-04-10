//
//  main.cpp
//  剑指 Offer 53 - II. 0～n-1中缺失的数字
//
//  Created by 周仁玺 on 2023/4/10.
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            set.insert(nums[i]);
        }
        int missing = -1;
        for (int i = 0; i <= n - 1; i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};
