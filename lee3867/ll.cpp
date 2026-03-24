#define _CRT_SECURE_NO_WARNINGS
//lee3875
//投机过的，有待进步



class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
        for (int i = 1; i < nums1.size(); ++i)
        {
            if (nums1[i] % 2 != nums1[i - 1] % 2)
                break;
            else
                return true;
        }

        vector<int> nums2(nums1.size());

        if (nums1[0] % 2 == 0)
        {
            for (int i = 0; i < nums1.size(); ++i)
            {
                if (nums1[i] % 2 == 0)
                {
                    nums2[i] = nums1[i];
                }
                else
                {
                    for (int j = 0; j < nums1.size(); ++j)
                    {
                        if (i != j)
                        {
                            nums2[j] = nums1[i] - nums1[j];
                            if (nums2[i] % 2 == 0)
                            {
                                break;
                            }
                            else
                                return false;
                        }
                    }
                }
            }
        }

        if (nums1[0] % 2 != 0)
        {
            for (int i = 0; i < nums1.size(); ++i)
            {
                if (nums1[i] % 2 != 0)
                {
                    nums2[i] = nums1[i];
                }
                else
                {
                    for (int j = 0; j < nums1.size(); ++j)
                    {
                        if (i != j)
                        {
                            nums2[j] = nums1[i] - nums1[j];
                            if (nums2[i] % 2 != 1)
                            {
                                break;
                            }
                        }
                        else
                            return false;
                    }
                }
            }
        }

        return true;
    }
};