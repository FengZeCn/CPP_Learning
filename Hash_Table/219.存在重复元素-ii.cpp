/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int length = nums.size();
        unordered_map<int,int> Umap;
        for(int i = 0; i < length; ++i)
        {   

            if(Umap.find(nums[i])!=Umap.end())
            {
                if(Umap.find(nums[i])->second != i)
                {
                    int d =i - Umap.find(nums[i])->second;
                    if(d <= k)
                    {
                        return true;
                    }
                }
            }
            Umap[nums[i]]=i;
        }
        return false;
    }
};
// @lc code=end

