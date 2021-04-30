#include<iostream>
#include<algorithm>

using namespace std;
#define MaxSize 10

	//顺序表的建立 
	 typedef struct{
	 	int data[MaxSize];					// 	存储空间的基地址
		int length;							//当前长度 
	 }SqList;
	 
	 
	 // 顺序表的初始化
	void InitList(SqList &L){
	L.length = 0;
	cout<<"顺序表初始化完成"<<endl; 
	} 
		
	// 顺序表传值 
	void CreatList(SqList &L,int n)
	{
		
		cout<<"请传入数值"<<endl; 
		for(int i=0;i<n;i++)
		{
			
			cin>>L.data[i];
			L.length++;
		}
	}
	
	//打印顺序表 
	int Print(SqList L)
	{
		cout<<"目前顺序表为："<<endl;
	    if (L.length == 0)
	    {
	        return 0;
	    }
	    for (int k = 0; k < L.length; k++)		//输出顺序表 
	    {
	    		cout<<L.data[k]<<"\t";	
	    }
	    cout<<endl;
	}
	//查找元素
	int getElem(SqList L)
	{
		int p;
		int e;
		cout<<"请输入要查找元素的位置"<<endl;
		cin>>p;
		if(p<0||p>L.length-1)
		{
			return 0;
		}else
		{
			e=L.data[p-1];							// 第p个元素对应数组中的L.data[p-1]
			cout<<"你要查找的元素为："<<e<<endl;
		}
	 }
	 
	 //插入元素
	  int insertElem(SqList &L)
	  {
	  	int p,e,i;
	  	cout<<"请输入要插入的位置及元素"<<endl;
		cin>>p>>e;
		if(p<0||p>L.length||L.length==MaxSize)		//判断要插入的位置是否合法并且判断线性表是否达到了最大 
		{
			cout<<"插入地址不合法"<<endl; 
			return 0;
		 } 
		 for(i=L.length-1;i>=p-1;i--)
		 {
		 	L.data[i+1]=L.data[i];					//从后往前，逐个将元素后移 
		 	
		 }
		 L.data[p-1]=e;								//第p个元素对应数组中的L.data[p-1] 
		 L.length++;
		 cout<<"插入成功"<<endl; 
	  }
	  
	  //删除元素
	  int deleteElem(SqList &L)
	  {
	  	int p;
	  	cout<<"请输入要删除的元素位置"<<endl;
		cin>>p;
		if(p<0||p>L.length-1)						//判断地址是否合法 
		{
			cout<<"地址不合法"<<endl;
			return 0;
		}
		for(int j = p;j<=L.length;j++)
		{
		L.data[j-1] = L.data[j];					//从p位置开始，后面的依次前移 
		}
		L.length--;
		cout<<"删除成功"<<endl; 

	   } 

	int main(){
		int n , e;
		cout<<"请输入顺序表长度"<<endl;
		cin>>n;									//输入数组的长度n
	    SqList L;
	    InitList(L);							//顺序表的初始化
		CreatList(L,n);							//顺序表传值 
		Print(L);								//打印顺序表
		getElem(L);								//查找相应位置元素 
		insertElem(L);							//插入元素 
		Print(L);								//再次打印顺序表 
		deleteElem(L);							//删除元素
		Print(L);								//再次打印顺序表  
		return 0;
	}


