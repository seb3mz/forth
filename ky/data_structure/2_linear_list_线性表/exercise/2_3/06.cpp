/* 
    功能:合并两个有序顺序表
    输入:两个有序顺序表
    输出:合并后的顺序表
*/

SqList MergeSqList(const SqList& L1, const SqList& L2)
{
    //分析 假设两个顺序表升序排列，当其中一个表遍历完成后，另外一个表的剩余部分直接移到结果表后面
    /*
        思路： 
            1. 用一个变量 pos1 表示遍历表 L1 时的当前位置，只有当前元素小于等于 L2 当前位置的值的时候，才向后移动
            2. 用一个变量 pos2 表示遍历表 L2 时的当前位置，只有当前元素小于 L1 当前位置的值的时候，才向后移动
            3. 用一个变量 pos3 表示结果表 L3 当前位置，每次插入时，都移动
            4. 当比较完成后，如果 L1/L2 还有元素，直接移动到 L3 尾部
    */
    int pos1 = 1, pos2 = 1, pos3 = 1;
    SqList resultL;
    while(pos1 <= L1.length && pos2 <= L2.length)
    {
        if(L1.data[pos1-1] <= L2.data[pos2-1])
        {
            ListInsert(resultL, pos3++, L1.data[pos1-1]);
            pos1++;
        }
        else
        {
            ListInsert(resultL, pos3++, L2.data[pos2-1]);
        }
    }
    while(pos1 < L1.length)
    {
        ListInsert(resultL, pos3++, L1.data[pos1-1]);
    }

    while(pos2 < L2.length)
    {
        ListInsert(resultL, pos3++, L2.data[pos2-1]);
    }

    return resultL;
}