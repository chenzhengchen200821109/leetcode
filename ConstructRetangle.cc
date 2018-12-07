#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

class Solution
{
    public:
        pair<int, int> ConstructRetangle(int area)
        {
            int length = sqrt(area);
            int width = length;

            while (length * width != area) {
                length += 1;
                width = area / length;
            }
            return make_pair(length, width);
        }
};

int main()
{
    pair<int, int> result;
    Solution s;

    for (int i = 4; i < 17; i++) {
        result = s.ConstructRetangle(i);
        std::cout << "[" << result.first << ", " << result.second << "]" << std::endl;
    }

    return 0;
}
