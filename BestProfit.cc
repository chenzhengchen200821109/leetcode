#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int BestProfit(const vector<int>& prices, int fee)
        {
            int profit = 0;
            int begin = prices[0];
            size_t i = 1;

            for ( ; i < prices.size(); ++i) {
                if (prices[i] - begin > fee) {
                    profit += prices[i] - begin - 2;
                    begin = prices[i];
                } else if (prices[i] - begin > 0) {
                    continue;
                } else {
                    begin = prices[i];
                }
            }

            return profit;
        }
};

int main()
{
    Solution s;
    vector<int> prices;
    int fee = 2;

    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(9);
    std::cout << s.BestProfit(prices, fee) << std::endl;

    prices.clear();
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(9);
    std::cout << s.BestProfit(prices, fee) << std::endl;

    prices.clear();
    prices.push_back(9);
    prices.push_back(6);
    prices.push_back(4);
    std::cout << s.BestProfit(prices, fee) << std::endl;

    prices.clear();
    prices.push_back(3);
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(7);
    prices.push_back(4);
    prices.push_back(7);
    std::cout << s.BestProfit(prices, fee) << std::endl;

    return 0;
}
