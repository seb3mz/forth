/* 
    功能:将顺序表逆置
    输入:顺序表
    输出:逆置后的顺序表
    时空复杂度要求: 空间复杂度 O(1)
*/

void ReverseSeqTable(SqList& L)
{
    //1. 从头遍历到顺序表中间位置，将 [i, L.length-i] 的元素换位
    int tmp = 0;
    /*
        当表为空时，什么也不做
        当表只有 1 个元素时，什么也不做
        当表元素大于1个时
    */
    if(L.length == 0)
    {
        cout << "顺序表为空" << endl;
        return;
    }

    if(L.length == 1)
    {
        cout << "顺序表只有一个元素" << endl;
        return;
    }

    for(int pos = 1; pos <= L.length/2; pos++)
    {
        tmp = L.data[pos-1];
        L.data[pos-1] = L.data[L.length-1];
        L.data[L.length-1] = tmp;
    }
}