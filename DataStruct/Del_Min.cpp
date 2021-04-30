

/*
搜索整个顺序表，查找最小值并返回，将表中最后一个元素代替最小值的位置
*/

bool Del_Min(Sqlist &L, ElemType value){


//laptop =============
    if(L.length == 0)
        return false;
    value = L.data[0];
    int pos = o;//假设第一个时最小值
    for(int i = 1; i<L.length;i++)
    {
        if(L.data[i] < value)
        
            {value = L.data[i];
            pos = i;
            }
        
    }
    value = L.data[pos];
    L.data[pos] = L.data[L.length-1];
    L.length--;
    return true;
}