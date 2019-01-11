#!/usr/bin/env python

# method 1. merge and find  O(m+n)
# method 2. binary search   O(log(m) + log(n))
class Solution:
    # method 1: O(len(nums1) + len(nums2))
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        from sys import maxsize as MAXINT
        MININT = -MAXINT
        tlen = len(nums1)+len(nums2)
        itercnt = tlen // 2
        pos1, pos2 = 0, 0
        for _ in range(itercnt):
            if pos1 < len(nums1):
                if pos2 < len(nums2):
                    if nums1[pos1] < nums2[pos2]:
                        pos1 += 1
                    else:
                        pos2 += 1
                else:
                    pos1 += 1
            else:
                pos2 += 1

        if tlen%2 is 0:
            lmax = MININT
            rmin = MAXINT
            if pos1 >= 1:
                lmax = max(lmax, nums1[pos1-1])
            if pos2 >= 1:
                lmax = max(lmax, nums2[pos2-1])
            if pos1 < len(nums1):
                rmin = min(rmin, nums1[pos1])
            if pos2 < len(nums2):
                rmin = min(rmin, nums2[pos2])
            return (lmax+rmin)/2
        else:
            if pos1 < len(nums1) and pos2 < len(nums2):
                return min(nums1[pos1], nums2[pos2])
            elif pos1 < len(nums1):
                return nums1[pos1]
            else:
                return nums2[pos2]

if __name__ == '__main__':
    from json import loads
    from sys import stdin
    nums = list()
    for line in stdin:
        nums.append(loads(line))
    for i in range(0, len(nums), 2):
        print(Solution().findMedianSortedArrays(nums[i], nums[i+1]))
