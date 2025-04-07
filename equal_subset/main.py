class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        x = 0
        for num in nums:
            x += num
        if (x % 2 == 1):
            return False
        else:
            target = x // 2
            dp = [False] * (target + 1)
            dp[0] = True
            for num in nums:
                for i in range(target, num - 1, -1): 
                    if dp[i - num] is True:
                        dp[i] = True
                if dp[target]:
                    return True
            return dp[target]


