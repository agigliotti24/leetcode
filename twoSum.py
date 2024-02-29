class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        nums_map = {}
        for i in range(len(nums)):
            val = nums_map.get(nums[i])
            if val is None:
                nums_map[nums[i]] = [i]
            else:
                nums_map[nums[i]].append(i)

        print(nums_map)
        for num, i in nums_map.items():
            print(i)
            val = nums_map.get(target-num)
            if val is not None:
                if i[0] == val[-1]:
                    continue
                return(i[0], val[-1])