class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        min_len = len(strs[0])
        for s in strs:
            if len(s) < min_len:
                min_len = len(s)

        res = ""
        for j in range(min_len):
            tmp = strs[0][j]
            match = True
            for i in range(len(strs)):
                if strs[i][j] != tmp:
                    match = False
            if match:
                res = res + tmp
            else:
                break
        
        return res
        