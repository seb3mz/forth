/* 
    功能:删除顺序表中所有值为 x 的数据元素
    输入:顺序表
    输出:删除特定值后的顺序表
    时间复杂度要求: O(n) 
    空间复杂度要求: O(1)
*/

void DeleteSpecElement(SqList &L, int x)
{
    // 遍历每个元素值与 x 进行对比，需要注意删除元素后，要进行元素向前移动
    // 记录每次需要填充的起始位置 startpos 即可; cnt 记录有多少个 x
    int startpos = 0, cnt = 0;
    bool firstx = false;
    for(int pos = 1; pos <= L.length; pos++)
    {
        //记录第一个 x 的位置到 startpos
        if(L.data[pos-1] == x)
        {
            if(firstx == false)
            {
                startpos = pos;
                firstx = true;
            }
            cnt++;
        }
        //找到第一个非 x 的值，把它移动到元素可以覆盖的位置
        if(L.data[pos-1] != x && firstx == true)
        {
            L.data[startpos-1] = L.data[pos-1];
            startpos++;
       }
    }
    //将表长度减调 x 的个数
    L.length-=cnt;
}