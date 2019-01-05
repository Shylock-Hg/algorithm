#! /bin/python

'''
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        '''
        C(n,2)

        |sum      | count|
        |:--|:--|
        |0--[1-n] | n-1 |
        |1--[2-n] | n-2 |
        |...      | ... |
        |n-1--[n] | 1   |
        '''

        #all two sum
        sums = []

        #the right sum index
        indexs = []

        #the pair
        pair = []

        # list[int] --> list[int]
        #compute all sum of sub sequence
        subsum = lambda l:[ l[0]+l[i+1] for i in range(len(l)-1)]

        for i in range(len(nums)-1):
            sums+=subsum(nums[i:])

        #get the target index
        for i,sum in enumerate(sums):
            if(sum == target):
                indexs.append(i)

        #compute index pair
        # index --> index pair
        for index in indexs:
            for i in range(len(nums)-1):
                rest = int(index-(2*len(nums)-i-2)*(i+1)/2+1)
                if(rest <= 0):
                    pair.append(i)
                    pair.append(len(nums)-1+rest)
                    break;
            
        return pair
'''


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        '''
        nums [--di---dj---]
        diff [--dj---]  `target-nums[i]`
        '''
        
        diff = {}  #diff:index
        
        for i,n in enumerate(nums):
            diff[target - nums[i]] = i
            if nums[i+1] in diff:
                return [diff[nums[i+1]],i+1]

