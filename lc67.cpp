#include <iostream>
#include <string>
#include <algorithm>

class Solution {
private:
    int min(int a, int b){
        if(a < b) return a;
        return b;
    }
public:
    std::string addBinary(std::string a, std::string b) {
        std::string ans = "";
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int carry = 0;
        int sum = 0;
        int aint = 0;
        int bint = 0;
        for(int i = 0; i < min(a.length(), b.length()); ++i){//implement switch case!
            aint = a[i] - '0';
            bint = b[i] - '0';
            sum = aint + bint + carry;            
            switch(sum){
                case 0:
                    ans += '0';
                    break;
                case 1:
                    ans += '1';
                    carry = 0;
                    break;
                case 2:
                    ans += '0';
                    carry = 1;
                    break;
                case 3:
                    ans += '1';
                    carry = 1;
                    break;
            }
        }
        if(a.length() > b.length()){
            for(int i = b.length(); i < a.length(); ++i){
                aint = a[i] - '0';
                sum = aint + carry;
                switch(sum){
                    case 0:
                        ans += '0';
                        break;
                    case 1:
                        ans += '1';
                        carry = 0;
                        break;
                    case 2:
                        ans += '0';
                        carry = 1;
                        break;
                }
            }
        }
        if(b.length() > a.length()){
            for(int i = a.length(); i < b.length(); ++i){
                bint = b[i] - '0';
                sum = bint + carry;
                switch(sum){
                    case 0:
                        ans += '0';
                        break;
                    case 1:
                        ans += '1';
                        carry = 0;
                        break;
                    case 2:
                        ans += '0';
                        carry = 1;
                        break;
                }
            }
        }

        if(carry != 0) ans += '1';

        std::reverse(ans.begin(), ans.end());
        return ans; 
    }
};

int main(){
    std::string a = "1010";
    std::string b = "1011";

    Solution solution;
    std::string ans = solution.addBinary(a,b);
    std::cout << "the sum is: " << ans << std::endl;
    //std::string proof = "";
    //std::cout << "correct result: " << (proof == ans) << std::endl;
    return 0;
}