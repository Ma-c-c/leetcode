/*
 * 209. 长度最小的子数组
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 */
int minSubArrayLen(int target, int* nums, int numsSize) {
    int left=0;
    int sum = 0;
    int minlen = numsSize + 1;
    for (int right=0;right<numsSize;right++)
    {
        sum += nums[right];
        while (sum >=target)
        {
            int len = right - left + 1;
            if (len < minlen)
            {
                minlen = len;
            }
            sum -= nums[left];
            left++;
        }
    }
    return (minlen == numsSize+1) ? 0 : minlen;
}
