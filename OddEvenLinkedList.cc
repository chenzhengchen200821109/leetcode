#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<int>& SortOddEvenList(vector<int>& v)
        {
            size_t size = v.size();
            vector<int>::iterator it = v.begin();
            vector<int>::iterator prev;

            if (size <= 2)
                return v;
            
            prev = it + 1;
            for (size_t i = 2; i < size; i++) {
                if (i % 2 == 0) {
                    int value = v[i];
                    v.erase(it + i);
                    v.insert(prev, value);
                } else {
                    prev++;
                }
            } 
            return v;
        }
};

int main()
{
    Solution s;
    vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    for (int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    s.SortOddEvenList(v);
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
