#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool PredictWinner(const vector<int>& v)
        {
            if (CanWin(v, 0, int(v.size() - 1), true, 0))
                return true;
            else
                return false;

        }

        bool CanWin(const vector<int>& a, int i, int j, bool who, int diff)
        {
            if (i == j) {
                if (who) {
                    diff += a[i];
                    return diff > 0;
                } else {
                    diff -= a[i];
                    return diff > 0;
                }
            } else {
                if (who) { // ONE
                    if (CanWin(a, i + 1, j, false, diff + a[i])) {
                        if (CanWin(a, i, j - 1, false, diff + a[j]))
                            return false;
                        else 
                            return true;
                    }
                    else 
                        return true;
                } 
                else { // TWO
                    if (CanWin(a, i + 1, j, true, diff - a[i])) {
                        if (CanWin(a, i, j - 1, true, diff - a[j]))
                            return true;
                        else
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
};

int main()
{
    Solution s;
    vector<int> v;

    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    std::cout << s.PredictWinner(v) << std::endl;

    return 0;
}


