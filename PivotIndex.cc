#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int PivotIndex(const vector<int>& v)
    {
        int sum = 0;
        int total = 0;
        for (int i = 0; i < (int)v.size(); i++)
            total += v[i];

        sum = v[0];
        for (int i = 1; i < (int)v.size() - 1; i++) {
            if ((sum + v[i]/2) == total/2) {
                return i;
            } else if ((sum + v[i]/2) > total/2) {
                return -1;
            } else
                sum += v[i];
        }
        return -1;
    }
};

int main()
{
    vector<int> v;
    Solution s;

    v.push_back(1);
    v.push_back(7);
    v.push_back(3);
    v.push_back(6);
    v.push_back(5);
    v.push_back(5);

    std::cout << s.PivotIndex(v) << std::endl;
    return 0;
}

