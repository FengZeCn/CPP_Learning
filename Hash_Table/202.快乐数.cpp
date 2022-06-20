/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> Umap;
        Umap.emplace(0,n);
        int i = 1;
        while(1)
        {
            int final = 0;
            for( ;n>=10; )
            {
                int num = n%10;
                n = n / 10;
                final += num*num;
            } 
            final += n*n;
            for(auto Inter = Umap.begin();Inter!=Umap.end(); ++Inter)
            {
                if(Inter->second == final && Inter->second != 1)
                {
                    return false;
                }
            }
            Umap.emplace(i,final);
            i=i+1;
            n = final;
            if(final == 1)
            {
                break;
            }
        }
        return true;

    }
};
// @lc code=end

