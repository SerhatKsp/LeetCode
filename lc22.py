from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        for i in range(n):
            par = ""
            while j < i:
                par += '('
