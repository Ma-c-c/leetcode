/*
 * 27. 移除元素
 * https://leetcode.cn/problems/remove-element/
 *
 * ── 题目要求 ──
 * 原地移除数组中所有等于 val 的元素，返回「剩余元素的个数」
 * 注意：返回的是剩余个数，不是删除个数！
 *
 * ── 解法一：暴力（双层循环）──
 * 遇到 nums[i] == val 时，把它后面的元素整体左移一位，
 * 有效长度 numsSize 减一，并且 i-- 回退，重新检查当前位置。
 *   时间 O(n^2)，空间 O(1)
 */
int removeElement(int* nums, int numsSize, int val) {
    for (int i = 0;i < numsSize;i++)
    {
        if (nums[i] == val)
        {
            for (int j = i;j < numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize ;
}
