import time 

class Solution:
    def partitionString(self, s: str) -> int:
        if s == '': 
            return 0
        letterdict = [0] * 26
        ans = 1
        for letter in s: 
            id = ord(letter) - ord('a')
            if letterdict[id] == 0:
                letterdict[id] += 1
            else:
                letterdict = [0] * 26
                letterdict[id] += 1
                ans += 1
        return ans

class Solution2:
    def partitionString(self, s: str) -> int:
        seen = set()
        partition = 1
        for letter in s: 
            if letter in seen: 
                seen.clear()
                partition += 1
            seen.add(letter)
        return partition

start_time1 = time.time()
test = Solution()
sol1 = test.partitionString("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")
end_time1 = time.time()
runtime1 = (end_time1 - start_time1) * 1e6
print(f"approach 1: num of min substrings: {sol1} with runtime {runtime1} µs")

start_time2 = time.time()
test = Solution2()
sol2 = test.partitionString("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")
end_time2 = time.time()
runtime2 = (end_time2 - start_time2) * 1e6
print(f"approach 2: num of min substrings: {sol2} with runtime {runtime2} µs")
