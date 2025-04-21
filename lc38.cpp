#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        cout << "Calling countAndSay with n = " << n << endl;  // Debugging-Ausgabe
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);  // Rekursive Funktionsaufrufe
        cout << "prev for n = " << n << ": " << prev << endl;  // Debugging-Ausgabe

        string ans = "";
        int iter = 0;
        int len = prev.size();
        while (iter < len) {
            int count = 1;
            while (iter + 1 < len && prev[iter] == prev[iter + 1]) {
                count++;
                iter++;
            }
            ans += to_string(count) + prev[iter];
            iter++;  // Move to the next character
        }
        
        cout << "Final result for n = " << n << ": " << ans << endl;  // Debugging-Ausgabe
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 1;
    
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "You entered: " << n << endl;  // Debugging-Ausgabe
    
    string result = solution.countAndSay(n);
    
    cout << "The " << n << "th term of the Count and Say sequence is: " << result << endl;
    
    return 0;
}
