/* 
    功能:在有序顺序表中查找值为 x 的元素，若找到，将其与后继位置元素交换；若未找到，插入顺序表中并维持有序状态
    输入:有序顺序表
    输出:无
    时间复杂度: 最少
    空间复杂度:
*/

void FindXInSeqT(SqList &L, int x)
{
    //1. 若表空
    //2. 若表非空
    int end_pos = L.length;
    int start_pos = 1;
    int mid_pos = (start_pos+end_pos)/2;
    bool found = false;

    //折半查找元素
    while(start_pos <= end_pos)
    {
        if(L.data[mid_pos-1] == x)
        {
            cout << "找到值为 x 的元素，位置为: " << mid_pos << endl;
            found = true;
            break;
        }
        else if(L.data[mid_pos-1] > x)
        {
            end_pos = mid_pos-1;
            mid_pos = (start_pos+end_pos)/2;
        }
        else
        {
            start_pos = mid_pos+1;
            mid_pos = (start_pos+end_pos)/2;
        }
    }
    if(found)
    {
        //mid_pos 即为 x 位置，将 mid_pos 位置和 mid_pos+1 位置元素互换
        int tmp = L.data[mid_pos-1];
        L.data[mid_pos-1] = L.data[mid_pos];
        L.data[mid_pos] = tmp;
    }
    else
    {
        //没找到，移动元素，并在 start_pos 位置插入
        L.data[start_pos-1] = x;
    }

}