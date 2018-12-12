#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        string AddBoldTag(const string& str, const vector<string>& vstr)
        {
            size_t n = str.size();
            vector<bool> bold(n, false);
            string s(str);

            for (size_t i = 0; i < vstr.size(); i++) {
                size_t j = str.find(vstr[i]);
                size_t k;
                if (j != string::npos) {
                    k = j + vstr[i].size();
                    for ( ; j < k; j++) {
                        if (bold[j] == false)
                            bold[j] = true;
                    }
                }
            }

            for (size_t i = 0; i < bold.size(); i++)
                std::cout << bold[i] << std::endl;

            int counter = 0;
            int pos;
            for (size_t i = 0; i < n; i++) {
                if (bold[i] == true) {
                    if (i == 0) { /* first element */
                        pos = i;
                        s.insert(pos, "<b>");
                        counter += 3;
                    } else if (i == n - 1) { /* last element */
                        pos = n;
                        s.insert(pos + counter, "</b>");
                    } else if (bold[i+1] == false) {
                        pos = i + 1;
                        s.insert(pos + counter, "</b>");
                        counter += 4;
                    } else if (bold[i-1] == false) {
                        pos = i;
                        s.insert(pos + counter, "<b>");
                        counter += 3;
                    }
                } 
            }

            return s;
        }
};

int main()
{
    Solution s1;
    string str1("abcxyz123");
    vector<string> vstr1;
    
    vstr1.push_back("abc");
    vstr1.push_back("123");

    std::cout << s1.AddBoldTag(str1, vstr1) << std::endl;

    Solution s2;
    string str2("aaabbcc");
    vector<string> vstr2;

    vstr2.push_back("aaa");
    vstr2.push_back("aab");
    vstr2.push_back("bc");

    std::cout << s2.AddBoldTag(str2, vstr2) << std::endl;

    return 0;
}
