/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int length = nums.size();
        unordered_map<int,int> Umap;
        for (int i = 0; i < length; ++i )
        {   
                if(Umap.find(nums[i])!=Umap.end())
                {
                    return true;
                }
                Umap.emplace(nums[i],i);
        }
        return false;
    }

};
// @lc code=end

