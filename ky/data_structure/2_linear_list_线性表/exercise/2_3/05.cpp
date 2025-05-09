/* 
    功能:删除有序顺序表中值重复的元素
    输入:顺序表
    输出:删除特定值后的顺序表
*/

void DeleteDupElement(SqList &L)
{
    //分析:有序顺序表，重复元素存储在相邻位置
    /*
        思路:
            1. 用一个临时变量 tmp 存储当前值，遍历元素与该元素比较，当出现不同于该值的元素后，将新值覆盖掉 tmp 值
            2. 用一个变量 duppos 存储可以插入的位序，当出现与 tmp 不同的元素时，将新值覆盖掉 duppos 位置的值，并将 duppos 值加一
            3. 用一个变量 dupcnt 存储当前有多少个相同的值，当出现与 tmp 值相同的值后，自动加一
            4. 用一个变量 FirstDup 存储当前是否第一次出现重复值，来确定覆盖位置 duppos 的值，该值在第一次出现重复值时更改，后续不变
    */
    if(L.length == 0)
    {
        cout << "表为空" << endl;
        return;
    }
    int tmp = L.data[0];
    int duppos = 1;
    int dupcnt = 0;
    bool FirstDup = false;

    for(int pos = 2; pos <= L.length; pos++)
    {
        //出现相同的元素，直接跳过
        if(L.data[pos-1] == tmp)
        {
            if(FirstDup == false)
            {
                FirstDup = true;
                duppos = pos;
            }
            dupcnt++;
        }
        //出现不同的元素，更换 tmp 值，并将该值移动
        else
        {
            tmp = L.data[pos-1];
            L.data[duppos-1] = L.data[pos-1];
            duppos++;
        }
    }

    L.length -= dupcnt;
}