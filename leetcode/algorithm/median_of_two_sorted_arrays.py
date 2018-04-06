#! /bin/python

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        n1,n2 = len(nums1),len(nums2)

        if n1 == 0 and n2 == 0:
            raise Exception('null median')
        elif n1 == 0:
            return nums2[int((n2-1)/2)] if 1 == n2%2 else (nums2[int(n2/2-1)]+nums2[int(n2/2)])/2
        elif n2 == 0:
            return nums1[int((n1-1)/2)] if 1 == n1%2 else (nums1[int(n1/2-1)]+nums1[int(n1/2)])/2

        left_1 = 0
        left_2 = 0
        
        if 0 == (n1+n2)%2 :
            # even
            mid1 = 0
            mid2 = 0
            mid_index = (n1+n2)/2-1
            for i in range(int(mid_index)+2):
                if nums1[left_1] < nums2[left_2]:
                    if i == mid_index:
                        mid1 = nums1[left_1]
                    if i == mid_index + 1:
                        mid2 = nums1[left_1]
                        return (mid1+mid2)/2
                    if left_1 < n1-1:
                        left_1+=1
                    elif left_2 < n2-1:
                        left_2+=1
                else:
                    if i == mid_index:
                        mid1 = nums2[left_2]
                    if i == mid_index + 1:
                        mid2 = nums2[left_2]
                        return (mid1+mid2)/2
                    if left_2 < n2-1:
                        left_2+=1
                    elif left_1 < n1-1:
                        left_1+=1

        else:
            # odd
            mid_index = (n1+n2-1)/2
            for i in range(int(mid_index)+1):
                if nums1[left_1] < nums2[left_2]:
                    if i == mid_index:
                        return nums1[left_1]
                    if left_1 < n1-1:
                        left_1+=1
                    elif left_2 < n2-1:
                        left_2+=1
                else:
                    if i == mid_index:
                        return nums2[left_2]
                    if left_2 < n2-1:
                        left_2+=1
                    elif left_1 < n1-1:
                        left_1+=1



s = Solution()
s.findMedianSortedArrays([1],[1])
