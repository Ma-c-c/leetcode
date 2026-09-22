/*
 * 59. 螺旋矩阵 II
 * https://leetcode.cn/problems/spiral-matrix-ii/
 *
 * ── 题目要求 ──
 * 给你一个正整数 n，生成一个包含 1 到 n² 所有元素，
 * 且元素按顺时针顺序螺旋排列的 n × n 正方形矩阵。
 * ── 解法：边界收缩法（四条边 + 四个边界变量）──
 * 用一个「框」框住当前还没填的区域，框有四条边：top / bottom / left / right。
 * 每填完一条边，就把这条边往里推一格，框越来越小，直到填满 n² 个数。
 *
 *   ① 上边 左→右：填 res[top][·]，列 left→right      →  top++
 *   ② 右边 上→下：填 res[·][right]，行 top→bottom     →  right--
 *   ③ 下边 右→左：填 res[bottom][·]，列 right→left    →  bottom--
 *   ④ 左边 下→上：填 res[·][left]，行 bottom→top      →  left++
 *   时间 O(n²)，空间 O(1)（不计返回的矩阵本身）
 * ── 我踩过的坑 ──
 *  1. while 条件写成 num < n*n，少了一个等号
 *     → num 指向「下一个要填的数」，num == n² 时表示还有数没填，必须用 <=
 *     → 后果：奇数 n 会漏掉最中间的格子（n=1 时整个矩阵全空）
 *  2. *returnColumnSizes 只 malloc 了，没有填值
 *     → malloc 只给空间、不初始化，评测系统读到垃圾数据 → 判错
 *     → 教训：malloc 之后一定要初始化（循环赋值 或 memset/calloc）
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** res=(int**)malloc(n*sizeof(int*));
    for (int i = 0;i<n;i++)
    {
        res[i]=(int*)malloc(n*sizeof(int));
    }
    *returnSize=n;*returnColumnSizes=(int*)malloc(n*sizeof(int));
    for (int i = 0;i<n;i++)
    {
        (*returnColumnSizes)[i]=n;
    }
    int top = 0,bottom = n-1,left = 0,right = n-1;int num = 1;
    while (num <=n*n)
    {
        for (int i=left;i<=right;i++)
        {
            res[top][i] = num++;
        }   top ++;
        for (int i=top;i<=bottom;i++)
        {
            res[i][right] = num++;
        }   right--;
        for (int i=right;i>=left;i--)
        {
            res[bottom][i] = num++;
        }   bottom--;
        for (int i=bottom;i>=top;i--)
        {
            res[i][left] = num++;
        }   left++;
    }
    return res;
}
