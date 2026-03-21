#include<iostream>
#include<string>
#include<vector>


//class Solution 
//{
//public:
//    int lengthOfLastWord(std::string s)
//    {
//        int count = 0;
//        int length = s.size();
//                   //
//
//        
//
//        for (int i = 0; i < length; ++i)
//        {
//            if (s[i] == ' ')
//            {
//                count = i;
//            }
//        }
//
//        int count_ = length - 1;
//        for (int j = 0; j < length; ++j)
//        {
//            if (s[length - j - 1] == ' ')
//            {
//                --count;
//                count_ = count;
//            }
//			
//            for (int k = 0; k < count_; ++k)
//            {
//                if (s[count] != ' ')
//                    --count;           
//                else
//                    break;
//            }
//            if (s[length - j - 1] != ' ' && s[count] == ' ')
//            {
//                if(count_ - count < 0)
//					return -1 * (count_ - count);
//                else
//					return count_ - count;
//			}
//        }
//        return length;
//    }
//};

/////我放弃我的史山代码了，，，，，
/////‘a ’这种我已经懒得是思考了
/////(ㄒoㄒ)/~~    ┭┮﹏┭┮


class Solution 
{
public:
    int lengthOfLastWord(std::string s) 
    {
        int index = s.size() - 1;

        while (s[index] == ' ')
        {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ')
        {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};


int main()
{
    Solution s;
    std::string str = "hello world";
    std::cout << s.lengthOfLastWord(str) << std::endl;
    return 0;
}