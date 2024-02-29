class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        num = str(x)
        for i in range(len(num)):
            if num[i] != num[len(num)-i-1]:
                return False

        return True