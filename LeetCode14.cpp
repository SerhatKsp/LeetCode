#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    std::string longestCommonPrefix(vector<string>& strs) {
        std::string curr = strs[0];
        std::string tmp = "";
        for(int i = 1; i < strs.size(); i++){
            int longest = max(strs[i].size(),curr.size());
            tmp = "";
            for(int letter = 0; letter < longest; ++letter){
                if(curr[letter] != strs[i][letter] && letter == 0) return tmp;
                else if(curr[letter] != strs[i][letter]){
                    curr = tmp;
                    break;
                }
                else{
                    tmp += curr[letter];
                }
            }
        }
        return curr;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    std::cout << sol.longestCommonPrefix(strs) << std::endl;
    return 0;
}
