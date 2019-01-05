#! /bin/python

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        if "" == s:
            return 0
        
        sub_lens = []
        maxlen = 0

        def sub_len(i,c,s):
            sub_str = "" + c;
            while i < len(s) - 1:
                if s[i+1] not in sub_str:
                    sub_str += s[i+1]
                else:
                    break
                i += 1
            return len(sub_str)

        for i,c in enumerate(s):
            tmp = sub_len(i,c,s)
            maxlen = tmp if tmp > maxlen else maxlen

        return maxlen

