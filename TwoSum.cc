#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<int> TwoSum(vector<int>& nums, int target)
        {
            vector<int> result;
            int size = nums.size();

            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (target == (nums[i] + nums[j])) {
                        result.push_back(i);
                        result.push_back(j);
                        break;
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<int> nums;
    vector<int> result;
    Solution s;

    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    result = s.TwoSum(nums, 26);
    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}
