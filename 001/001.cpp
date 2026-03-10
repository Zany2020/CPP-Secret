#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>


class Solution {
public:
    std::string mergeAlternately(char* word1, char* word2)
    {
        int l1 = strlen(word1), l2 = strlen(word2);
        int l = l1 + l2 + 1;

        char* a = (char*)calloc(l, sizeof(char));
        int p = 0, q = 0, k = 0;
        while (p < l1 && q < l2)
        {
            a[k++] = word1[p++];
            a[k++] = word2[q++];
        }
        while (p < l1) a[k++] = word1[p++];
        while (q < l2) a[k++] = word2[q++];

		std::string result(a);
		free(a); // Don't forget to free the allocated memory
		a = nullptr;

        return result;
    }
};

int main()
{
    //std::string w1;
    //std::string w2;
    //std::cout >> "word1 =" >> w1
    char word1[100];
    char word2[100];
	std::cout << "word1 = ";
	std::cin >> word1;
	std::cout << "word2 = ";
	std::cin >> word2;

    //std::string word = mergeAlternately(word1, word2);
    //std::cout << word << std::endl;

	Solution solution;
	std::string word = solution.mergeAlternately(word1, word2);

    std::cout << word << std::endl;
    return 0;
}