#include<stdio.h>   //EOF,NULL
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0
typedef  int  Status;
typedef      char    ElemType;
#define   LIST_INIT_SIZE   100  // ���Ա��ʼ�洢�ռ������
#define   LISTINCREMENT    10 //���Ա�洢�ռ�ķ�������
typedef struct{
	ElemType   * elem;     //���Ա�洢�ռ��ַ
	int    length;                 //��ǰ���Ա���
	int    Listsize;                //��ǰ��������Ա�洢�ռ��С
                                        //����sizeof(ElemType)Ϊ��λ��
}SqList;
Status InitList_Sq(SqList &L){
      L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType)); //����һ���յ�˳���L       
      if (! L.elem)        exit(0);  //�洢����ʧ��
      L. length=0;  //�ձ���Ϊ0
      L.Listsize=LIST_INIT_SIZE; //��ʼ�洢����
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
Status DisplayList_Sq ( SqList L){  //��ӡ����Ԫ��
 	int i ;
	for(i=0;i<L.length;i++)
   	 	printf("%c" , L.elem[i]); 
    printf("\n");
    return OK;
}
Status ListInsert_Sq(SqList &L, int i , ElemType e) {
	//��˳���L�е�i��λ��֮������µ�Ԫ��e,
	// i�ĺϷ�ֵΪ1��i��L.length+1,��i =L.length+1ʱ
     //  e���ڱ�β
    if (i<1|| i>L.length+1)   
		return ERROR; // iֵ���Ϸ�
	if (L.length>=L.Listsize)   
		return ERROR; //˳�������
	for (int j=L.length-1 ; j>= i-1; --j)     
      	L.elem[j+1] =L.elem[j];        //����λ�ü�֮���Ԫ�غ���һ��λ��
	L.elem[i-1] =e;         //����e
	L.length++;             //����1*/
	return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	//��˳���L��ɾ���� i��Ԫ�أ�����e������ֵ
	//   i�ĺϷ�ֵΪ  1��i��L.length
    if ((i<1)||(i>L.length)) 
		return ERROR; // iֵ���Ϸ�����
    e = L.elem[i-1] ;               // ��ɾ��Ԫ�ص�ֵ����e
    for (int j= i; j<= L.length-1; ++j) 
        L.elem[j-1]= L.elem[j];            //��ɾ��Ԫ��֮���Ԫ��ǰ��
	L.length--;          //����1
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
 	printf("(1)��ʼ��˳���\n");
 	InitList_Sq(L);
  	printf("(2)���β���a,b,c,d,eԪ��\n");
 	ListInsert_Sq(L,1,'a');
 	ListInsert_Sq(L,2,'b');
 	ListInsert_Sq(L,3,'c');
 	ListInsert_Sq(L,4,'d');
 	ListInsert_Sq(L,5,'e');
 	ListInsert_Sq(L,3,'q');
    ListInsert_Sq(L,1,'q');
 	printf("(3)���˳���:"); 
 	DisplayList_Sq(L);
 	printf("(4)˳���ĳ���=%d\n",LengthList_Sq(L));
 	printf("(5)˳���Ϊ%s\n",(EmptyList_Sq(L)?"��":"�ǿ�"));
 	GetElemList_Sq(L,3,e);
 	printf("(6)˳���ĵ�����Ԫ����%c\n",e);
 	printf("(7)Ԫ��a��λ��=%d\n",LocateElemList_Sq(L,'a'));
	printf("(8)�ڵ��ĸ�Ԫ�ز���Ԫ��f\n");
 	ListInsert_Sq(L,4,'f');
 	printf("(9)���˳���:");
 	DisplayList_Sq(L);
 	printf("(10)ɾ��������Ԫ��\n");
 	ListDelete_Sq(L,3,e);
 	printf("(11)fԪ�ص�һ�γ��ֵ�λ��:");
 	printf("%d\n",LocateElemList_Sq(L,'f'));
 	printf("(12)���˳���:");
	DisplayList_Sq(L);
 	printf("(13)�ͷ�˳���\n");
 	DestroyList_Sq(L);
}
