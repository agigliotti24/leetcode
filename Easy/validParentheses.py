class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        symbols = {
            ']': '[',
            '}': '{',
            ')': '(',
        }

        stack = []

        for sym in s:
            if sym == '(' or sym == '{' or sym == '[':
                stack.append(sym)
            if sym == ')' or sym == '}' or sym == ']':
                if len(stack) == 0:
                    return False
                if stack[-1] == symbols[sym]:
                    stack.pop()
                else:
                    return False

        if len(stack) == 0:
            return True

        return False