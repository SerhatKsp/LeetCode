from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def DFS(queens, xy_dif, xy_sum):
            p = len(queens)
            if p==n:
                result.append(queens)
                return None
            for q in range(n):
                if q not in queens and p-q not in xy_dif and p+q not in xy_sum: 
                    DFS(queens+[q], xy_dif+[p-q], xy_sum+[p+q])  
        result = []
        DFS([],[],[])
        return [ ["."*i + "Q" + "."*(n-i-1) for i in sol] for sol in result]    

test = Solution()
board_size = int(input("Enter the board size (int): "))
print(f"ans = {test.solveNQueens(board_size)}")

#c++:
# #include <iostream>
#using namespace std;
#
#int main() {
#    string userInput;
#    cout << "Enter something: ";
#    cin >> userInput; // Takes input up to the first space
#    cout << "You entered: " << userInput << endl;
#
#    int userNumber;
#    cout << "Enter a number: ";
#    cin >> userNumber;
#    cout << "You entered the number: " << userNumber << endl;
#
#    return 0;
#}