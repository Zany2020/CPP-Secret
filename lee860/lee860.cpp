#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

class Solution
{
public:
	bool lemonadeChange(std::vector<int>& bills)
	{
		if (bills[0] == 10 || bills[1] == 20 || bills[0] == 20)
			return false;

		int five = 0, ten = 0;
		for (int i = 0; i < bills.size(); i++)
		{
			if (bills[i] == 5)
			{
				++five;
				continue;
			}
			if (bills[i] == 10)
			{
				if (five)
				{
					++ten;
					--five;
					continue;
				}
				else
					return false;
			}
			if (bills[i] == 20)
			{
				if (five)
				{
					if (ten)
					{
						--ten;
						--five;
						continue;
					}
					else
					{
						five -= 3;
						if (five < 0)
						{
							std::cout << "false";
							return false;
						}
						continue;
					}
				}
				else
				{
					std::cout << "false";
					return false;
				}

			}

		}

		std::cout << "true";
		return true;
	}
};


		std::cout << "true";
		return true;
	}
};

int main()
{
	Solution s;
	std::vector<int> bills = { 5,5,10,10,20};
	return s.lemonadeChange(bills);	
}