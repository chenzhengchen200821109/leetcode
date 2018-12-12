#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
    public:
        vector<string> ExpressionAddOperator(string str, int target)
        {
            vector<string> res;
            AddOperatorDFS(str, target, 0, 0, "", res);
            return res;
        }

        void AddOperatorDFS(string str, int target, long long diff, long long curNum, string out, vector<string>& res)
        {
            if (str.size() == 0 && curNum == target)
                res.push_back(out);
            
            for (int i = 1; i <= str.size(); ++i) {
                string cur = str.substr(0, i);
                if (cur.size() > 1 && cur[0] == '0') return;
                string next = str.substr(i);
                if (out.size() > 0) {
                    AddOperatorDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
                    AddOperatorDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
                    AddOperatorDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
                } else 
                    AddOperatorDFS(next, target, stoll(cur), stoll(cur), cur, res);
            }
        }
};

int main()
{
    Solution s;
    vector<string> v;

    string str("123");
    int target = 6;

    v = s.ExpressionAddOperator(str, target);
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << std::endl;

    return 0;
}
