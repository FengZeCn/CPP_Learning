/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_length = s.size(); //刚开始的时候没有写int
        int t_length = t.size();
        if(s_length != t_length)
        {
            return false;
        }
        unordered_map<char,char> Umap;
        unordered_map<char,char> RUmap;
        for(int i = 0; i < s_length; ++i)
        {
            char s_char = s[i];
            char t_char = t[i];
            if((Umap.count(s_char) != 0 && Umap[s_char] != t_char)||(RUmap.count(t_char) != 0 && RUmap[t_char] != s_char))
            //同时要保证能够找到这个s_char,否则没有也是不相等的
            //同时要保证是一一映射 也要维护另一个表
            {
                return false;
            }
            Umap[s_char]=t_char;
            RUmap[t_char]=s_char;
        }
        return true;
    }
};
// @lc code=end

