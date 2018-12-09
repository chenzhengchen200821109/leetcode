#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        vector<int> PartitionLabels(const string& str)
        {
            vector<int> res;
            int n = str.size();
            int start = 0;
            int last = 0;
            unordered_map<char, int> map;
            for (int i = 0; i < n; i++) 
                map[str[i]] = i;
            for (int i = 0; i < n; i++) {
                last = max(last, map[str[i]]);
                if (i == last) {
                    res.push_back(i - start + 1);
                    start = i + 1;
                }
            }
            return res;
        }            
};

int main()
{
    string str("ababcbacadefegdehijhklij");
    vector<int> v;
    Solution s;

    v = s.PartitionLabels(str);
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}

