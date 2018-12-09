#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool PredictWinner(const vector<int>& v)
        {
            return CanWin(v, 0, 0, 1);
        }

        bool CanWin(const vector<int>& v, int sum1, int sum2, int player)
        {
            if (v.size() == 0)
                return sum1 >= sum2;
            if (v.size() == 1) {
                if (player == 1) return sum1 + v[0] > sum2;
                else if (player == 2) return sum2 + v[0] > sum1;
            }
            vector<int> va = vector<int>(v.begin() + 1, v.end());
            vector<int> vb = vector<int>(v.begin(), v.end() - 1);
            if (player == 1)
                return !CanWin(va, sum1 + v[0], sum2, 2) || !CanWin(vb, sum1 + v.back(), sum2, 2);
            else if (player == 2)
                return !CanWin(va, sum1, sum2 + v[0], 1) || !CanWin(vb, sum1, sum2 + v.back(), 1);
            
        }
};

int main()
{
    Solution s;
    vector<int> v;

    v.push_back(1);
    v.push_back(5);
    v.push_back(233);
    v.push_back(7);

    std::cout << s.PredictWinner(v) << std::endl;

    return 0;
}


