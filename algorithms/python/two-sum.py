#!/usr/bin/env python

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = {}
        for idx, num in enumerate(nums):
            rest = target - num
            if rest in table:
                return [table[rest], idx]
            table[num] = idx
        # not found
        return [-1, -1]

if __name__ == '__main__':
    target = int(input())
    nums = [int(x) for x in input().split()]
    ret = Solution().twoSum(nums, target)
    print(ret)
