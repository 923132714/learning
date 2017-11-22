#include<stdio.h>   //EOF,NULL
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0
typedef  int  Status;
typedef      char    ElemType;
#define   LIST_INIT_SIZE   100  // 线性表初始存储空间分配量
#define   LISTINCREMENT    10 //线性表存储空间的分配增量
typedef struct{
	ElemType   * elem;     //线性表存储空间基址
	int    length;                 //当前线性表长度
	int    Listsize;                //当前分配的线性表存储空间大小
                                        //（以sizeof(ElemType)为单位）
}SqList;
Status InitList_Sq(SqList &L){
      L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType)); //构造一个空的顺序表L       
      if (! L.elem)        exit(0);  //存储分配失败
      L. length=0;  //空表长度为0
      L.Listsize=LIST_INIT_SIZE; //初始存储容量
      return OK;
}//InitList_Sq 

Status DestroyList_Sq ( SqList &L) {      
	if (!L.elem)  return ERROR; 
      free (L.elem);    
      L.elem = NULL;
      L.length = 0;
      L.Listsize = 0;
      return OK;
}// DestroyList_Sq   
Status EmptyList_Sq ( SqList L) { 
	if(L.length==0)  
		return TRUE;
  	else 
	  	return FALSE;
}
Status LengthList_Sq ( SqList L) { 
	return L.length;
}
Status DisplayList_Sq ( SqList L){  //打印表中元素
 	int i ;
	for(i=0;i<L.length;i++)
   	 	printf("%c" , L.elem[i]); 
    printf("\n");
    return OK;
}
Status ListInsert_Sq(SqList &L, int i , ElemType e) {
	//在顺序表L中第i个位置之后插入新的元素e,
	// i的合法值为1≤i≤L.length+1,当i =L.length+1时
     //  e插在表尾
    if (i<1|| i>L.length+1)   
		return ERROR; // i值不合法
	if (L.length>=L.Listsize)   
		return ERROR; //顺序表已满
	for (int j=L.length-1 ; j>= i-1; --j)     
      	L.elem[j+1] =L.elem[j];        //插入位置及之后的元素后移一个位置
	L.elem[i-1] =e;         //插入e
	L.length++;             //表长增1*/
	return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	//在顺序表L中删除第 i个元素，并用e返回其值
	//   i的合法值为  1≤i≤L.length
    if ((i<1)||(i>L.length)) 
		return ERROR; // i值不合法或表空
    e = L.elem[i-1] ;               // 被删除元素的值赋给e
    for (int j= i; j<= L.length-1; ++j) 
        L.elem[j-1]= L.elem[j];            //被删除元素之后的元素前移
	L.length--;          //表长减1
	return OK;
}//ListDelete_Sq
Status GetElemList_Sq ( SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) 
		return ERROR;
 	e=L.elem[i-1];
	return OK;
}
Status  LocateElemList_Sq( SqList L,ElemType e) {
	int i=0;
 	while(i<L.length&&L.elem[i]!=e) 
	 	i++;
 	if(i>=L.length) return 0;
 	return i+1;
}
int main(){
	SqList L;
 	ElemType e;
 	printf("(1)初始化顺序表\n");
 	InitList_Sq(L);
  	printf("(2)依次插入a,b,c,d,e元素\n");
 	ListInsert_Sq(L,1,'a');
 	ListInsert_Sq(L,2,'b');
 	ListInsert_Sq(L,3,'c');
 	ListInsert_Sq(L,4,'d');
 	ListInsert_Sq(L,5,'e');
 	ListInsert_Sq(L,3,'q');
    ListInsert_Sq(L,1,'q');
 	printf("(3)输出顺序表:"); 
 	DisplayList_Sq(L);
 	printf("(4)顺序表的长度=%d\n",LengthList_Sq(L));
 	printf("(5)顺序表为%s\n",(EmptyList_Sq(L)?"空":"非空"));
 	GetElemList_Sq(L,3,e);
 	printf("(6)顺序表的第三个元素是%c\n",e);
 	printf("(7)元素a的位置=%d\n",LocateElemList_Sq(L,'a'));
	printf("(8)在第四个元素插入元素f\n");
 	ListInsert_Sq(L,4,'f');
 	printf("(9)输出顺序表:");
 	DisplayList_Sq(L);
 	printf("(10)删除第三个元素\n");
 	ListDelete_Sq(L,3,e);
 	printf("(11)f元素第一次出现的位置:");
 	printf("%d\n",LocateElemList_Sq(L,'f'));
 	printf("(12)输出顺序表:");
	DisplayList_Sq(L);
 	printf("(13)释放顺序表\n");
 	DestroyList_Sq(L);
}
