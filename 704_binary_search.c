/*
 * 704. 二分查找
 * https://leetcode.cn/problems/binary-search/
 *
 * 思路：闭区间 [left, right]
 *   先定死区间定义，所有边界操作服从它：
 *   - nums[mid] < target → 目标在右 → left = mid + 1
 *   - nums[mid] > target → 目标在左 → right = mid - 1
 *   - 区间为空（left > right）时退出 → return -1
 *
 * 复杂度：时间 O(log n)，空间 O(1)
 */
int search(int* nums, int numsSize, int target)
 {
    int left = 0,right = numsSize-1;
    
   while (left <= right)
   {
    int mid = (left + right)/2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
   }
   return -1;
}
