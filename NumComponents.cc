#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

class Solutions
{
    public:
        int NumComponents(list<int>* head, vector<int>& G)
        {
            int result = 0;
            unordered_set<int> nodeSet(G.begin(), G.end());

            list<int>::iterator iter;
            unordered_set<int>::const_iterator citer;
            for (iter = head->begin(); iter != head->end(); ++iter) {
                if ((citer = nodeSet.find(*iter)) == nodeSet.end())
                    continue;
                else {
                    /* found one */
                    result++;
                    iter++;
                    nodeSet.erase(citer);
                    for( ; iter != head->end(); ++iter) {
                        if ((citer = nodeSet.find(*iter)) != nodeSet.end()) {
                            nodeSet.erase(citer);
                            continue;
                        }
                        else
                            break;
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<int> G;
    G.push_back(0);
    G.push_back(3);
    G.push_back(1);
    G.push_back(4);

    list<int> Head;
    for (int i = 0; i < 5; i++) {
        Head.push_back(i);
    }

    Solutions s;
    std:: cout << "result is " << s.NumComponents(&Head, G) << std::endl;
}

