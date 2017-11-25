#include<stdio.h>   //EOF,NULL
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  char    ElemType;
typedef struct  LNode{
	ElemType   data;
	struct  LNode  *next;
}LNode, *LinkList;

Status InitList_L (LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)   exit(0);
	L->next = NULL;
	return  OK;
}// InitList_L  

Status DestroyList_L (LinkList &L)  {
	LinkList p,q;
 	p=L;
 	q=p->next;
 	while(q!=NULL){
	 	free(p);
  		p=q;
  		q=p->next;
 	}
	free(p);
	return  OK;
}

Status EmptyList_L (LinkList L){
	if(L->next==NULL) 
		return OK;
 	return ERROR;
}

Status LengthList_L(LinkList L){
	LinkList p=L;
 	int i=0;
 	while(p->next!=NULL){
	 	i++;
  		p=p->next;
 	}
 	return i;
}

Status DisplayList_L ( LinkList L) {
	LinkList p=L->next;
 	while(p!=NULL){
	 	printf("%c",p->data);
 		p=p->next;
 	}
	printf("\n");
 	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
 	LinkList l1=(LinkList)malloc(sizeof(LNode)) ;
  	LinkList  p = L;
  	int j;
	for(j = 0; j<i-1;j++){
	p = p->next;     
	}	   
   	if(!p||j>i-1)   
	   	return ERROR;      
	l1->data = e;
    l1->next = p->next;
    p->next = l1;
    return OK; 
}//ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    LinkList q ,p = L;	
	int j;
	for(j = 0; j<i-1;j++)
		p =p->next;
	if(!p->next|| j>i-1)   
		return ERROR;  
	q= p->next;
	p->next = q->next;
	e =q->data;
	free(q);
	return OK;
}//ListDelete_L

Status ListAdd (LinkList L , ElemType e){
	LinkList p=L;
	while(p->next){
	 	p=p->next;
	}
	LinkList l1  = (LinkList)malloc(sizeof(LNode));
	l1->data = e;
	l1->next = NULL; 	
	p->next = l1; 
	return OK;
} 

Status ListInverted(LinkList L,LinkList IL){
	LinkList p=L->next;
 	while(p!=NULL){ 
		ElemType e = p->data; 
		ListInsert_L(IL, 1, e); 
		p = p->next ;
	} 
	return OK;	
} 

Status GetElemList_L (LinkList L, int i, ElemType &e) {
	int j=0;
    LinkList p=L;
	while(j<i&&p){
		++j;
	 	p=p->next;
	}
    if(!p||j>i)  
		return ERROR;
	e=p->data;
	return OK;
}

Status  LocateElemList_L(LinkList L,ElemType e) {	
	int i=0;
    LinkList p=L;
    while(p!=NULL&&p->data!=e) {
		++i;
	 	p=p->next;
	}
    if(p==NULL) 
		return 0;
    else 
		return i;
}

int main(){
	LinkList L,IL;
 	ElemType e;
 	printf("(1)��ʼ��������\n");
 	InitList_L(L);
  	InitList_L(IL);
 	printf("(2)���β���a,b,c,d,eԪ��\n");
 	ListInsert_L(L,1,'a');
 	ListInsert_L(L,2,'b');
 	ListInsert_L(L,3,'c');
 	ListInsert_L(L,4,'d');
 	ListInsert_L(L,5,'e');
	ListInsert_L(L,1,'b');//ͷ���뷨
 	ListAdd(L,'q');//β���뷨 
 	printf("(3)���������:");
 	DisplayList_L(L);
  	ListInverted(L,IL);//���� 
  	printf("(3.5)������õ�����:");
   	DisplayList_L(IL);
 	printf("(4)������ĳ���=%d\n",LengthList_L(L));
 	printf("(5)������Ϊ%s\n",(EmptyList_L(L)?"��":"�ǿ�"));
 	GetElemList_L(L,3,e);
 	printf("(6)������ĵ�����Ԫ����%c\n",e);
 	printf("(7)Ԫ��a��λ��=%d\n",LocateElemList_L(L,'a'));
 	printf("(8)�ڵ��ĸ�Ԫ�ز���Ԫ��f\n");
 	ListInsert_L(L,4,'f');
 	printf("(9)���������:");
 	DisplayList_L(L);
	printf("(10)ɾ��������Ԫ��\n");
	ListDelete_L(L,3,e);
	printf("(11)���������:");
	DisplayList_L(L);
	printf("(12)�ͷŵ�����\n");
	DestroyList_L(L);
}
