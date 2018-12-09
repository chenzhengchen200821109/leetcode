#include <iostream>
#include <vector>
#include <cassert>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        int PrimeNumberBits(int left, int right)
        {
            vector<int> target;
            vector<int> prime;
            int counter = 0;

            for (int i = left; i <= right; i++) {
                target.push_back(CountBits(i));
            }
            prime = MakePrimes(64);
            
            for(vector<int>::iterator it = target.begin(); it != target.end(); ++it) {
                if (binary_search(prime.begin(), prime.end(), *it))
                    counter++;
            }
            return counter;
        }

        int CountBits(int n)
        {
            bitset<32> b(n);
            return b.count();
        }

        /**
        vector<int> MakePrimes(int n)
        {
            assert(n >= 2);
            vector<int> v;
            vector<int> result;
            int prime;
            size_t pos = 0;
            size_t size = 0;
            
            if (n == 2) {
                v.push_back(n);
                return v;
            }

            for (int i = 2; i <= n; i++) {
                v.push_back(i);
            }

            size = v.size();
            while (pos < size) {
                if (v[pos] != 0) {
                    prime = v[pos];
                    result.push_back(prime);
                    size_t i = v[pos] + pos;
                    while (i < size) {
                        v[i] = 0;
                        i += v[pos];
                    }
                }
                pos++;
            }

            return result;
        }*/
    private:
        vector<int> MakePrimes(int n)
        {
            assert(n >= 2);
            vector<int> v;
            vector<int>::iterator begin;
            vector<int>::iterator end;
            vector<int>::iterator it;
            //size_t i;

            if (n == 2) {
                v.push_back(n);
                return v;
            }

            for (int i = 2; i <= n; i++) 
                v.push_back(i);

            begin = v.begin();
            end = v.end();
            while (begin < end) {
                if (*begin != 0) {
                    it = begin + *begin;
                    while (it < v.end()) {
                        *it = 0;
                        it += *begin;
                    }
                }
                begin++;
            }
            
            for (begin = v.begin(); begin != v.end(); ++begin) {
                if (*begin == 0) {
                    v.erase(begin);
                    begin--; /* stuck */
                }
            }
            return v;
        }

};

int main()
{
    Solution s;
    int left = 10;
    int right = 15;

    std::cout << s.PrimeNumberBits(left, right) << std::endl;

    return 0;
}

