/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
/*注意区别和四数之和的不同之处*/
// @lc code=start
//别人的范例代码
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};*/
//我自己编写的代码，时间复杂度高
/*
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums,int target)
        {
            int number = nums.size();
            for(int i = 0; i < number; i++)
            {
                for(int j = i+1; j<number;j++)
                {
                    if(nums[j]==target-nums[i])
                    {
                        return {i,j};
                    }
                }
            }
            return {};
        }
};
*/
//备注
//尝试使用hash table的方法解决问题
class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            unordered_map<int,int> umap;
            for(int i = 0; i<nums.size();i++)
            {
                if(umap.find(target-nums[i])!=umap.end())
                {
                    return{i,umap.find(target-nums[i])->second};
                }
                umap.emplace(nums[i],i);
            }
            return{};
        }
};



// @lc code=end

