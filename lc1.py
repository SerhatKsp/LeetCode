from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}

        for ind, val in enumerate(nums): 
            mp[val] = ind

        for ind, num in enumerate(nums): 
            complement = target - num
            if complement in mp and mp[complement] != ind: 
                return [ind, mp[complement]]
        
class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]: 
        mp = {}

        for ind, val in enumerate(nums): 
            mp[val] = ind #Problem hashkollision -> selber schlüssel für verschiedene Werte -> Lösung wäre z.B. linked list oder list, welche vals speichert
            complement = target - val
            if complement in mp and mp[complement] != ind: 
                return [ind, mp[complement]]
            
test = Solution()
ans = test.twoSum([3,3], 6)
print(ans)