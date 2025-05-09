/* 
    功能:删除顺序表中所有值处于 [s,t] 的数据元素
    输入:顺序表
    输出:删除特定值后的顺序表)
*/

void DeleteSpecRangeElement(SqList &L, int s, int t)
{
    // 判断范围是否合理
    if(s >= t)
    {
        cout << "范围不合理" << endl;
        return;
    }
    // 判断表空
    if(L.length == 0)
    {
        cout << "表为空" << endl;
        return;
    }

    int startpos = 0, cnt = 0;
    bool firstx = false;
    for(int pos = 1; pos <= L.length; pos++)
    {
        //记录第一个 x 的位置到 startpos
        if(L.data[pos-1] >= s && L.data[pos-1] <= t)
        {
            if(firstx == false)
            {
                startpos = pos;
                firstx = true;
            }
            cnt++;
        }
        //找到第一个非 x 的值，把它移动到元素可以覆盖的位置
        if((L.data[pos-1] < s ||  L.data[pos-1] > t) && firstx == true)
        {
            L.data[startpos-1] = L.data[pos-1];
            startpos++;
       }
    }
    //将表长度减调 x 的个数
    L.length-=cnt;
}