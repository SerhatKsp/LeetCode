class MaxHeap:
    def __init__(self):
        self.heap = []
    
    def _parent(self, i):
        return (i - 1) // 2
    
    def _left_child(self, i):
        return 2 * i + 1
    
    def _right_child(self, i):
        return 2 * i + 2
    
    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def push(self, item):
        # Push the item to the end of the heap
        self.heap.append(item)
        self._heapify_up(len(self.heap) - 1)
    
    def _heapify_up(self, i):
        # Move the element at index i up to maintain heap property
        while i > 0 and self.heap[i][0] > self.heap[self._parent(i)][0]:
            self._swap(i, self._parent(i))
            i = self._parent(i)
    
    def pop(self):
        # Remove the root (maximum) and return it
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root
    
    def _heapify_down(self, i):
        # Move the element at index i down to maintain heap property
        largest = i
        left = self._left_child(i)
        right = self._right_child(i)
        
        if left < len(self.heap) and self.heap[left][0] > self.heap[largest][0]:
            largest = left
        if right < len(self.heap) and self.heap[right][0] > self.heap[largest][0]:
            largest = right
        
        if largest != i:
            self._swap(i, largest)
            self._heapify_down(largest)
    
    def peek(self):
        # Get the root (maximum) without removing it
        if len(self.heap) > 0:
            return self.heap[0]
        return None
    
    def is_empty(self):
        return len(self.heap) == 0

# Example usage:
if __name__ == "__main__":
    max_heap = MaxHeap()
    
    # Example: (negative profit, a, b) to simulate max heap behavior
    max_heap.push((-0.5, 1, 2))
    max_heap.push((-0.3, 3, 5))
    max_heap.push((-0.6, 2, 2))

    # Pop the maximum element (class with the largest profit)
    print("Max heap root:", max_heap.pop())  # Will return (-0.3, 3, 5)

    # Peek the next element (after popping the root)
    print("Next max heap root:", max_heap.peek())  # Will return (-0.5, 1, 2)


class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        # Define the profit function to calculate the improvement in passing ratio
        def profit(a, b):
            return (a + 1) / (b + 1) - a / b
        
        # Initialize the max-heap
        max_heap = MaxHeap()
        
        # Push all classes into the max-heap
        for a, b in classes:
            a, b = float(a), float(b)  # Convert to float for precision
            max_heap.push((-profit(a, b), a, b))  # Negate profit to simulate max-heap //library implements min-heap

        # Distribute extra students
        for _ in range(extraStudents):
            _, a, b = max_heap.pop()  # Pop the class with the maximum profit
            max_heap.push((-profit(a + 1, b + 1), a + 1, b + 1))  # Add one extra student
        
        # Calculate the final average ratio
        return sum(a / b for d, a, b in max_heap.heap) / len(classes)

# Example usage:
classes = [[1, 2], [3, 5], [2, 2]]
extraStudents = 2
solution = Solution()
result = solution.maxAverageRatio(classes, extraStudents)
print(f"Maximum average pass ratio: {result}")
