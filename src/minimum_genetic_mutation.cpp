#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    char dict[4]{'A', 'C', 'G', 'T'};
    int minMutation(string start, string end, vector<string>& bank) {
        int step = 0;
        bool isEnd = false;
        queue<string> nodes;
        unordered_set<string> visited;
        unordered_set<string> bank_set;
        for_each(bank.begin(), bank.end(), [&bank_set](string s){
            bank_set.insert(s);
        });
        nodes.push(start);
        visited.insert(start);
        while (!nodes.empty()) {
            int len = (int)nodes.size();
            for (int index = 0; index < len; index++) {
                string temp = nodes.front();
                nodes.pop();
                if (temp == end) {
                    isEnd = true;
                    break;
                }
                for (int i = 0; i < temp.size(); i++) {
                    for (int j = 0; j < 4; j++) {
                        string new_str = temp;
                        new_str[i] = dict[j];
                        if (bank_set.find(new_str) != bank_set.end() 
                            && visited.find(new_str) == visited.end()) {
                            nodes.push(new_str);
                            visited.insert(new_str);
                        }
                    }
                }
            }
            if (isEnd) {
                break;
            } else {
                step++;
            }
        }
        return isEnd ? step : -1;
    }
};

int main() {}