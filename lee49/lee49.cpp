#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>



//class Solution
//{
//public:
//    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
//    {
//        //std::unordered_map<int, std::vector<std::string>> hash;
//		//应该用排序后的字符串作为key，原字符串作为value，【字符串也可以作为key】
//        std::unordered_map<int, std::vector<std::string>> hash;
//
//        std::vector<std::string> result;
//        std::vector<std::string> mid;
//
//        for (int i = 0; i < strs.size(); ++i)
//        {
//            std::vector<std::string> word;
//			word.push_back(strs[i]);
//            std::sort(word[i].begin(), word[i].end());
//        }
//
//        for (int i = 0; i < strs.size(); ++i)
//        {
//			mid.push_back(strs[i]);
//			std::sort(mid[i].begin(), mid[i].end());
//            auto w = hash.find(mid[i]);
//
//            if(w != hash.end())
//            {
//                result.push_back(strs[i]);
//			}
//
//            hash[i] = strs[i];
//        }
//
//
//    }
//};

class Solution 
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hash;

		for (std::string& s : strs)//一般都要加&，不然每次循环都会复制一个字符串，效率会很低
        {
			std::string key = s;
            std::sort(key.begin(), key.end());
            hash[key].push_back(s);
        }

		std::vector<std::vector<std::string>> result;
        for (auto& pair : hash)
        {
			result.emplace_back(pair.second);
        }

		return result;
    }
};

int main()
{
    std::vector<std::string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution s;
    std::vector<std::vector<std::string>> result = s.groupAnagrams(strs);
    for (const auto& group : result)
    {
        for (const auto& word : group)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}