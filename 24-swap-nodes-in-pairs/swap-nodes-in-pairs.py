# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        def swap(p1, p2):
            t = p1.val
            p1.val = p2.val
            p2.val = t

        p1 = head
        p2 = head.next

        while p2 or p1:
            swap(p1, p2)
            
            if p2.next:
                p1 = p2.next

            else:
                break

            if p1.next:
                p2 = p1.next
            else:
                break

        return head
    
            
