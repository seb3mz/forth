/* 
    功能:从顺序表中删除最小值元素，并把空出的位置由最后一个元素填充
    输入:顺序表
    输出:被删除的值
*/


int DeleteSmallestElement(SqList &L)
{
    //1. 判断表是否为空，为空直接返回
    if(L.length == 0)
    {
        cout << "表为空，无法删除任何元素" << endl;
        return -1;
    }
    
    //2. 如果表中就 1 个元素，直接返回该元素，表长减一
    if(L.length == 1)
    {
        L.length--;
        return L.data[0];
    }

    //3. 如果表中多于 1 个元素，找到最小的元素，并记录下位序
    int min = L.data[0];
    int rank = 1;
    for(int pos = 2; pos <= L.length; pos++)
    {
        if(L.data[pos-1] < min)
        {
            min = L.data[pos-1];
            rank = pos;
        }
    }
    //4. 判断 min 位序如果在最后一位，则只需要表长减一；如果不在最后一位，用最后一位替换掉 min
    if(rank == L.length)
    {
        L.length--;
        return L.data[rank-1];
    }
    else
    {
        L.data[rank-1] = L.data[L.length-1];
        L.length--;
        return min;
    }
}