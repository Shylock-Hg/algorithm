#! /bin/python

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        '''
        s = A1+A1+carry
        rest = s%10
        carry = s//10
        '''

        s = 0
        rest = 0
        carry = 0

        node = ListNode(0) 
        tmp = node

        while(True):
            s = l1.val + l2.val + carry
            rest = s % 10
            carry = s // 10
            tmp.val = rest 

            if l1.next == None or l2.next == None:
                # either has no next
                break
            else:
                # both has next
                l1 = l1.next
                l2 = l2.next
                tmp.next = ListNode(0)
                tmp = tmp.next

        while(l1.next != None):
            l1 = l1.next
            tmp.next = ListNode(0)
            tmp = tmp.next

            s = l1.val + 0 + carry
            rest = s % 10
            carry = s // 10
            tmp.val = rest

        while(l2.next != None):
            l2 = l2.next
            tmp.next = ListNode(0)
            tmp = tmp.next

            s = 0 + l2.val + carry
            rest = s % 10
            carry = s // 10
            tmp.val = rest

        if carry != 0:
            tmp.next = ListNode(1)

        return node
