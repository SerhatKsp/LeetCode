from collections import defaultdict
from typing import List

#LEETCODE 49

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #approach: use a dictionary with lists (arrays) as default values) keys non existent yet.
        #use keys as uniqueidentifier of an anagram
        #when appending the values to the according key in the dictionary we first have to convert the keys to tuples since 
        #constraints: strs[i] consists of lowercase english letters

        anagrams = defaultdict(list)

        for substring in strs:
            key = [0] * 26
            for characters in substring:
                key[ord(characters) - ord('a')] += 1 #converting index from ASCII ('a' has index 97)
            #created keys id --> add to dict
            key = tuple(key) #make tuple (unchangeable structure) of it so it an be used as a key. datatype list is not hashable btw
            anagrams[key].append(substring)
        
        return list(anagrams.values())

anagrams = Solution()
ans = anagrams.groupAnagrams(["abd","bad","bah","hab"])
for lists in ans: 
    print(lists)

############

a, b = 4, 5
a, b = b, a
print(f"a: {a}, b: {b}") #no tmp variable needed for swaps in python