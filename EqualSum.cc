#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool IsEqualSum(const vector<int>& nums)
    {
        vector<size_t> result;
        size_t index;
        size_t start;
        size_t sum = 0;

        if (nums.size() < 7)
            return false;

        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            start = 0;
            while (CanMakeEqualSum(nums, start, index, sum)) {
                index++;
                if (index < nums.size())
                    result.push_back(index);
                start = index + 1;
            }
            if (result.size() == 3 && index == nums.size())
                return true;
            result.clear();
        }
        return false;

    }
    bool CanMakeEqualSum(const vector<int>& nums, size_t start, size_t& index, size_t target) {
        size_t sum = 0;

        for (size_t i = start; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == target) {
                index = i;
                return true;
            }
            else if (sum > target)
                return false;    
        }
        return false;
    }
};

int main()
{
    vector<int> nums;
    Solution s;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    std::cout << s.IsEqualSum(nums) << std::endl;

    return 0;
}

