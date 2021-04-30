#include<iostream>
using namespace std;
 
#define MaxNum 100            //线性表最大长度
typedef int DataType;         //线性表数据类型，简单起见设为int
 
class SeqList{                //线性表
    public:
    DataType data[MaxNum];    //数据  由于是开的数组，所以存储空间连续
    int length=0;             //长度  用于记录现有数据量，其次防止溢出
    bool empty();                        //检查线性表是否为空   
    void insert(int i,DataType data);    //在线性表的第i个位置插入数据，线性表从1开始计数
    void del(int i);                     //删除表的第i个位置数据
    void dis();                          //输出所有数据
};
 
bool SeqList::empty()
{
    if(SeqList::length == 0)
        return true;
    return false;
}
 
void SeqList::insert(int i,DataType insert_data)
{
    //插入先检查是否还有空间
    if(SeqList::length == MaxNum)
    {
        cout<<"插入检查错误：表已满！"<<endl;
        return;
    }
    //再检查非法插入位置（比如现表一共10个数据，在第12个位置插入）
    if(i>SeqList::length+1||i<1)
    {
        cout<<"插入检查错误：插入位置不合法！"<<endl;
        return;
    }
    //插入位置i后的所有数据后移，实现的时候是从后向前的
    //这里for里面的index以线性表逻辑确定，即从1开始，对应数组下标应减1
    for(int index=SeqList::length;index>=i;index--)
    {
        SeqList::data[index]=SeqList::data[index-1];   //将第index个数据移动到index+1位置
    }
    //在i位置写入新的数据
    SeqList::data[i-1]=insert_data;
    SeqList::length++;
    cout<<"成功在位置"<<i<<"插入数据"<<insert_data<<"."<<endl;
}
 
void SeqList::del(int i)
{
    //检查输入位置是否合法
    if(i<1||i>SeqList::length)
    {
        cout<<"删除检查错误：删除位置不合法！"<<endl;
        return;
    }
    //删除第i个数据，即将位置i后的所有数据前移，直接覆盖掉第i个数据即可
    for(int index=i;index<=SeqList::length;index++)
    {
        SeqList::data[index-1]=SeqList::data[index];
    }
    //删除收尾
    SeqList::length--;
    cout<<"成功删除第"<<i<<"个数据."<<endl;
}
 
void SeqList::dis()
{
    if(SeqList::length == 0)
        cout<<"表输出：表为空！"<<endl;
    else
    {
        cout<<"表输出：("<<SeqList::length<<")"<<endl;
        for(int index=1;index<=SeqList::length;index++)
        {
            cout<<SeqList::data[index-1]<<" ";
        }
        cout<<endl;
    }
}
//运行具体步骤检查
int main() 
{
    SeqList seq1;
    seq1.insert(1,1);
    seq1.insert(2,2);
    seq1.insert(3,3);
    seq1.insert(4,4);
    seq1.insert(5,5);
    seq1.del(1);
    seq1.del(2);
    seq1.del(3);
    seq1.insert(3,33);
    seq1.dis();
    cout <<"123" << endl;
    return 0;
}