#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int DegreeArray(const vector<int>& v)
        {
            int max = 0;
            size_t i, j;
            int counter = 0;

            for (i = 1; i < v.size(); i++) {
                int num = 0;
                int diff = 0;
                bool touched = false;
                for (j = 0; j < i; j++) {
                    if (v[j] == v[i]) {
                        if (touched == false) {
                            diff = (i - j);
                            touched = true;
                        }
                        num++;
                    }
                }
                if (num > counter) {
                    max = diff;
                    counter = num;
                }
                touched = false;
            }
            return max + 1;
        }
};

int main()
{
    vector<int> v;
    Solution s;

    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);

    std::cout << s.DegreeArray(v) << std::endl;

    return 0;
}
