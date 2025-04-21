import heapq
from collections import defaultdict
import time 

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        #greedy, mapping character --> occurences, sorted mapping fits best --> use array
        #building ans: go through mapped array in reverse order and add characters if repcount  <       -repeatLimit, when do i exit the loop: if the repcount > repeatLimit and we reached the     <       character a
        letcount = [0] * 26 #only lowercase english letters
        
        for letter in s: 
            letcount[ord(letter) - ord('a')] += 1

        addedpuf = False
        repcount = 0
        ans = ''
        returnind = 0
        i = 25
        while i in range(len(letcount)): #iterate through array backwards
            if repcount >= repeatLimit and returnind and letcount[i]: #adding puffer letter
                ans += chr(i + ord('a'))
                letcount[i] -= 1
                repcount = 0
                i = returnind
                returnind = 0
            if returnind == 0: 
                repcount = 0
                while letcount[i] and repcount < repeatLimit: #regular case
                    ans += chr(i + ord('a'))
                    letcount[i] -= 1
                    repcount += 1
            if repcount >= repeatLimit and letcount[i]: #saving return point if repeatLimit exceeded
                returnind = i
            i -= 1
        return ans

#test = Solution()
#ans = test.repeatLimitedString('zzzzzyyyzzazcc',3)
#print(f"solution: {ans}")

############# implementation has bad runtime 

class Solution2:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        #greedy, heap (priority queue) (value, store letter, occurunces)
        letterdict = defaultdict(int)
        for letter in s: 
            if letterdict[letter] == 0:
                letterdict[letter] = 1
            else:
                letterdict[letter] += 1

        maxHeap = [(-ord(key), key, value) for key, value in letterdict.items()]

        heapq.heapify(maxHeap)

        ans = ''
        while maxHeap:
            ord1, letter, occ = heapq.heappop(maxHeap)
            if occ <= repeatLimit: #basecase
                ans += letter * occ
            else: 
                ans += letter * repeatLimit
                occ -= repeatLimit
                if not maxHeap:
                    return ans
                ord2, letter2, occ2 = heapq.heappop(maxHeap)
                ans += letter2
                occ2 -= 1
                if occ2 != 0: 
                    heapq.heappush(maxHeap, (ord2, letter2, occ2))
                heapq.heappush(maxHeap, (ord1, letter, occ))
        return ans

start = time.time()
test = Solution2()
ans = test.repeatLimitedString('zzzz',3)
stop = time.time()
runtime = (stop - start) * 1e3
print(f"solution: {ans}, with calculation time of : {runtime}ms")