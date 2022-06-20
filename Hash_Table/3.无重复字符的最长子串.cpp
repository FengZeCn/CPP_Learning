/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
/* 这种方法最后一个用例没有通过用时，之后对其进行优化。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> Lmap; //序列表
        int length = s.size();
        for(int i = 0; i<length; ++i)
        {
            Lmap[i]=i; //设置初始序列 ，这时长度全为1
        }
        for(int i = 1; i<=length; ++i ) //按照可能出现的个数对序列表进行遍历
        {
            for(int j =0; j<length;++j) //开始进行遍历
            {
                if(Lmap[j]-j==i-1)  //右端减去左端等于可能个数-1，这时候看它的右面是否重复，不重复该列表向右移动，否则不动。
                {
                    //可能满足情况的右端
                    int right = Lmap[j]+1;
                    bool flag = true;
                    if(right==length)
                    {
                        flag = false; //边界检测
                    }
                    else
                    {
                        for(int l = j; l < right; ++l)
                        {
                            if(s[right]==s[l])
                            {
                                flag = false;
                            }
                        }
                    }
                    if(flag)
                    {
                        Lmap[j]=Lmap[j]+1;
                    }
                }
            }
            
        }
        int maxlength = 0;
        for(int i=0;i<length;++i)
        {
            int finallength = Lmap[i]-i+1;
            if(finallength>maxlength)
            {
                maxlength=finallength;
            }
        }
        return maxlength;
    }
};
*/
//优化，通过一个<个数，列表>哈希表进行优化，省去计算环节。
/* 可行是可行，就是内存和时间用的都太多。
//采用滑动窗口的方式创建另外一种解法。
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int,list<int>> Nmap;
        int length = s.size();
        for(int i = 0; i<length; ++i)
        {
            Nmap[1].push_back(i);
        }
        for(int i = 1; i<=length; ++i ) //按照可能出现的个数对序列表进行遍历
        {
            //for(int j =0; j<length;++j) //开始进行遍历
            for(auto p=Nmap[i].begin();p!=Nmap[i].end();p++)//用索引的方式得到的就是本身，不用加second
            {
                //if(Lmap[j]-j==i-1)  //右端减去左端等于可能个数-1，这时候看它的右面是否重复，不重复该列表向右移动，否则不动。
                //{
                    //可能满足情况的右端
                    int right = *p+i;
                    bool flag = true;
                    if(right==length)
                    {
                        flag = false; //边界检测
                    }
                    else
                    {
                        for(int l = *p; l < right; ++l)
                        {
                            if(s[right]==s[l])
                            {
                                flag = false;
                            }
                        }
                    }
                    if(flag)
                    {
                        Nmap[i+1].push_back(*p); //永远不会跨界的，前面就会否掉
                        //Lmap[j]=Lmap[j]+1;
                    }
            }
        }
        int maxlength = 0;
        for(int i=length; i>0; --i)
        {
            if(Nmap[i].size()!=0)
            {
                maxlength = i;
                break;
            }
        }
        return maxlength;
        //return maxlength;
    }
};*/
//滑动窗口时
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int length = s.size();
        int ans = 0;
        unordered_set<char> Uset;
        int right = -1;
        for(int i = 0; i < length; ++i )
        {
            if(i != 0) //左侧指针向右移动，则序列擦除左边的数字
            {
                Uset.erase(s[i-1]);
            }
            while(right+1 < length && !Uset.count(s[right+1]))
            {
                Uset.insert(s[right+1]);
                ++right;
            }
            //这样第i到 第right个字符就是不重复的
            ans = max(ans,right-i+1);
        }
        return ans;
    }

};
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start)
            {
                start = vec[int(tmpChar)] + 1;
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
// @lc code=end

