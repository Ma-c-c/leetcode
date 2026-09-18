/*
 * 977. 有序数组的平方
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
 *
 * ── 题目要求 ──
 * 给你一个按「非递减顺序」排序的整数数组 nums，
 * 返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 *
 * ── 解法：双指针（左右指针 · 从后往前填）──
 * 关键洞察：原数组已经有序 → 绝对值最大的元素一定在两端
 *           → 平方后的最大值也一定在两端
 * 所以：每次比较两端的平方值，取较大的那个，从 result 的「末尾」往前填。
 *   时间 O(n)，空间 O(n)（结果数组）
 *
 * ── 我踩过的坑 ──
 *  1. 返回局部数组 int result[numsSize]
 *     → 栈内存，函数一返回就失效（悬垂指针）。必须用 malloc 放到堆上
 *  2. 忘记写 *returnSize = numsSize
 *     → 评测系统不知道数组有多长，直接判错
 *  3. 只把两端的平方都塞进去，漏了「比较取较大值」这一步
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0;int right = numsSize-1;
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;  
    int k = numsSize-1;
    while (left<=right)
    {
        int lv = nums[left]*nums[left];
        int rv = nums[right]*nums[right];
        if (lv > rv)
        {
            result[k] = lv;
            left++;
        }
        else
        {
            result[k] = rv;
            right--;
        }
        k--;
    }
    return result;
}
