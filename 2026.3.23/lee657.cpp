#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>

class Solution 
{
public:
    bool judgeCircle(std::string moves)
    {
        std::vector<int> stack_1;
        std::vector<int> stack_2;

        for (int i : moves)
        {
            if (i == 'U')
            {
                stack_1.push_back(1);
            }
            else if (i == 'D')
            {
                stack_1.push_back(-1);
            }
            else if (i == 'L')
            {
                stack_2.push_back(1);
            }
            else if (i == 'R')
            {
                stack_2.push_back(-1);
            }
        }

        //      for(int i =0; i < stack_1.size(); i++)
        //      {
        //          for (int j = 0; j < stack_1.size(); j++)
        //          {
        //              if (stack_1[i] + stack_1[j] == 0)
        //              {
        //                  stack_1.erase(stack_1.begin() + i);
        //                  stack_1.erase(stack_1.begin() + j);
        //                  i--;
        //                  break;
        //              }
        //          }
              //}
        int count_1 = 0;
        int count_2 = 0;

        for (int i = 0; i < stack_1.size(); ++i)
        {
            count_1 += stack_1[i];
        }
        for (int i = 0; i < stack_2.size(); ++i)
        {
            count_2 += stack_2[i];
        }

        if (count_1 == 0 && count_2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    std::string str = "LDRRLRUULR";
    std::cout << s.judgeCircle(str) << std::endl;
    return 0;
}