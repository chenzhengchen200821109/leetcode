#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int MaxProduct(const vector<int>& v)
        {
            int CurMax = 0;
            for (size_t i = 0; i < v.size(); i++) {
                int Cur = v[i];
                MakeMax(v, i + 1, v.size(), CurMax, Cur); 
            }
            return CurMax;
        }

        void MakeMax(const vector<int>& v, int start, int last, int& CurMax, int Cur)
        {
            int product = 1;
            for (int i = start; i < last; i++) {
                product *= v[i];
                if (product * Cur > CurMax) {
                    CurMax = product * Cur;
                }
            }
        }
};

int main()
{
    vector<int> v;
    Solution s;

    v.push_back(2);
    v.push_back(-3);
    v.push_back(6);
    v.push_back(4);

    std::cout << s.MaxProduct(v) << std::endl;

    return 0;
}
