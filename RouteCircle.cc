#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        bool JudgeRouteCircle(const string& str)
        {
            int x = 0, y = 0;
            for (size_t i = 0; i < str.size(); i++) {
                int c = str[i];
                switch(c) {
                    case 'R':
                        x++;
                        break;
                    case 'L':
                        x--;
                        break;
                    case 'U':
                        y++;
                        break;
                    case 'D':
                        y--;
                        break;
                    default:
                        return false;
                }
            }
            return (x == 0 && y == 0);
        }

};

int main()
{
    Solution s;
    string str0("DDUU");
    string str1("LL");
    
    std::cout << s.JudgeRouteCircle(str0) << std::endl;
    std::cout << s.JudgeRouteCircle(str1) << std::endl;

    return 0;
}
