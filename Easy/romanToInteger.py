def subtract(left, right):
        if left == "I" and right == "V":
            return True
        if left == "I" and right == "X":
            return True
        if left == "X" and right == "L":
            return True
        if left == "X" and right == "C":
            return True
        if left == "C" and right == "D":
            return True
        if left == "C" and right == "M":
            return True

        return False



class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """

        romans = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        sum = 0
        sub = False
        for i in range(len(s)-1, -1, -1):
            left = s[i-1]
            right = s[i]
            
            if sub == True:
                sub = False
                continue
            
            if i == 0:
                sum = sum + romans[s[i]]
            elif subtract(left, right):
                sum = sum + romans[right] - romans[left]
                sub = True
            else:
                sum = sum + romans[s[i]]

        return sum