# nums = [3, 2, 4]


# def ans(nums, target):
#     for i in range(len(nums)):
#         for j in range(i+1, len(nums)):
#             if nums[i] + nums[j] == target:
#                 return [i, j]


# print(ans(nums, 6))

def lengthOfLongestSubstring(s: str) -> int:
    if len(s) == 0:
        return 0
    maxAt = [1, ]
    start = 0
    for i in range(1, len(s)):
        cur = 1
        for j in range(start, i):
            if s[i] == s[j]:
                cur = 1
            else
                cur += 1
        target = cur if maxAt[i-1] >= cur else maxAt[i-1] + 1
        maxAt.append(cur)

    return max(maxAt)


print(lengthOfLongestSubstring("dvdf"))
