#include <vector>
#include <sstream>
#include <iostream>

class Solution {
    public:
        int compareVersion(std::string version1, std::string version2) {
            std::vector<int> v1 = split(version1);
            std::vector<int> v2 = split(version2);

            int n1 = v1.size(), n2 = v2.size();
            int maxLength = std::max(n1, n2);

            for (int i = 0; i < maxLength; ++i) {
                int rev1 = i < n1 ? v1[i] : 0;
                int rev2 = i < n2 ? v2[i] : 0;

                if (rev1 < rev2) return -1;
                if (rev1 > rev2) return 1;
            }

            return 0;
        }

    private:
        std::vector<int> split(const std::string &version) {
            std::vector<int> revisions;
            std::stringstream ss(version);
            std::string item;

            while (std::getline(ss, item, '.')) {
                revisions.push_back(std::stoi(item));
            }

            return revisions;
        }
};

int main(){
    std::string a = "1.02.003";
    std::string b = "1.02.001";

    Solution ans; 
    int comp = ans.compareVersion(a,b);
    switch(comp){
        case -1:
            std::cout << "a < b" << std::endl;
            break;
        case 0:
            std::cout << "a = b" << std::endl;
            break;
        default:
            std::cout << "a > b" << std::endl;
    }
    return 0;
}