#include <iostream>
#include <vector>
#include <chrono>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
private: 
    void printList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void reverse(ListNode* &ptr){//recursive
        if(ptr == NULL || ptr->next == NULL) return; 
        ListNode* help = ptr->next; 
        reverse(ptr->next);
        help->next = ptr; 
        ptr = ptr->next; //previous pointer points to next pointer (memory address changed)
        help->next->next = NULL; 
    }

    ListNode* reversesub(ListNode* &ptr, int k, int count, ListNode* &nextsub){//
        if(count == k) return ptr; 
        ListNode* help = ptr->next; 
        reversesub(ptr->next, k, count + 1, nextsub);
        help->next = ptr;
        ptr = ptr->next;
        help->next->next = nextsub;
        return ptr; 
    }

    int getlength(ListNode* &ptr){//recursive
        if(ptr == NULL) return 0; 
        return 1 + getlength(ptr->next); 
    }

public:
    ListNode* reverseKGroup(ListNode* &head, int k) {
        int len = getlength(head);
        ListNode* dummy = new ListNode(0); 
        ListNode* last = new ListNode(0);
        ListNode* end = new ListNode(0);
        end->next = head; 
        last->next = head;
        for(int i = 0; i < len/k; ++i){
            for(int j = 0; j < k; ++j){
                last->next = last->next->next; 
            }
            ListNode* newhead = reversesub(head, k, 1, last->next);
            end->next = newhead; 
            printList(dummy->next); //pointer to head pointer -> therefore == head pointer
            if(i == 0) dummy->next = head;
            printList(dummy->next);
            for(int j = 0; j < k; ++j){
                head = head->next;
                end = end->next; 
            }
        }
        return dummy->next; 
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

class Solution2{
public:
    	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* after = head;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        while(true){
            ListNode* cursor = after;
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for(int i = 0; i < k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }
    }
};

int main() {
    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = createList(values);

    std::cout << "Original list: ";
    printList(head);

    auto start = std::chrono::high_resolution_clock::now(); 
    Solution2 solution;
    int k = 3; // Reverse every k nodes
    head = solution.reverseKGroup(head, k);
    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Reversed in groups of " << k << ": ";
    printList(head);
    std::cout << "runtime: " << duration.count() << " microseconds" << std::endl; 

    // Cleanup memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



