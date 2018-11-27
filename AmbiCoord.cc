// Ambiguous Coordinates

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/** Regular Expression
 * for example: for floats that started with zero digit, ^0.[0-9]*[1-9]$
 * otherwise ^[1-9][0-9]*.?[0-9]*[1-9]$
 * for example: for integers ^[1-9][0-9]*$
 */
class Solution
{
    public:
        vector<string> AmbiguousCoordinates(const string& str)
        {
            vector<pair<string, string> > v;
            vector<string> result;

            v = insertComma(str);
            v = insertDot(v);
            for (size_t i = 0; i < v.size(); i++) {
                if ((isValidFloats(v[i].first) || isValidInteger(v[i].first)) && 
                    (isValidFloats(v[i].second) || isValidInteger(v[i].second))) {
                    string s("(");
                    s += v[i].first + ", " + v[i].second + ")";
                    result.push_back(s);
                }
            }
            return result;
        }
    //private:
        bool isValidFloats(const string& str)
        {
            string::size_type n;
            if ((n = str.find('.')) == string::npos)
                return false;
            regex regex0("^0.[0-9]*[1-9]$", std::regex::extended);
            regex regex1("^[1-9][0-9]*.[0-9]*[1-9]$", std::regex::extended);
            return (regex_match(str, regex0) || regex_match(str, regex1));
        }
        bool isValidInteger(const string& str)
        {
            /* zero */
            if (str == "0")
                return true;
            regex regex("^[1-9][0-9]*$", std::regex::extended);
            return regex_match(str, regex);
        }
        vector<pair<string, string> > insertComma(const string& str)
        {
            vector<pair<string, string> > v;
            size_t pos = 1; 
            for ( ; pos < str.size(); pos++) {
                string s1 = str.substr(pos);
                string s0 = str.substr(0, pos);
                v.push_back(make_pair(s0, s1));    
            }
            return v;
        }
        vector<string> addDot(const string& str)
        {
            size_t size = str.size();
            vector<string> v;

            if (size == 1) {
                v.push_back(str);
                return v;
            } 
            for (size_t i = 1; i < size; i++) {
                string s = str.substr(0, i) + "." + str.substr(i);
                v.push_back(s);
            }
            return v;
        }
        vector<pair<string, string> >& insertDot(vector<pair<string, string> >& v)
        {
            size_t sz = v.size();
            string str0;
            string str1;
            vector<string> v0;
            vector<string> v1;

            for (size_t i = 0; i < sz; i++) {
                v0 = addDot(v[i].first);
                v1 = addDot(v[i].second);
                for (size_t j = 0; j < v0.size(); j++) {
                    str0 = v0[j];
                    for (size_t k = 0; k < v1.size(); k++) {
                        str1 = v1[k];
                        if (str0 == v[i].first && str1 == v[i].second)
                            continue;
                        v.push_back(make_pair(str0, str1));
                    }
                }
            }
            return v;
        }
};

int main()
{
    Solution s;
    string str("0123");
    vector<string> v;

    v = s.AmbiguousCoordinates(str);
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    string str0("012");
    std::cout << s.isValidFloats(str0) << std::endl;
    std::cout << s.isValidInteger(str0) << std::endl;

    return 0;
}

