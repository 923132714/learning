#include<stdio.h>   //EOF,NULL
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  double    SElemType;
#define STACK_INIT_SIZE  100   //栈存储空间的初始分配量
#define STACKINCREMENT  10   //存储空间分配增量
typedef struct{
   SElemType  *base;             //存储数据元素的数组
   SElemType  *top;              //栈顶指针
   int stacksize;                   //当前分配的栈空间大小
                                 //（以sizeof(SElemType)为单位）
}Stack;


Status InitList_stack (Stack &s) {
	s.base = (SElemType*)malloc( STACK_INIT_SIZE*sizeof(SElemType));
	if (!s.base )   exit(0);
s.stacksize = STACK_INIT_SIZE;
s.top = s.base;

 return OK;
}// InitList_stack
Status EmptyStack (Stack s) 
{ if(s.base == s.top)  return TRUE;
  else return FALSE;
}//
Status PushStack(Stack &s , SElemType e ){
if(s.stacksize<(s.top-s.base) )return ERROR;
if(s.stacksize==(s.top-s.base) )
s.base = (SElemType*)malloc(( s.stacksize+STACKINCREMENT)*sizeof(SElemType));

		*(s.top) = e;
		s.top++;

	return OK;
	
}
Status GetLength(Stack s){
	return s.top-s.base;
}
Status DisplayStack(Stack &s){

	while(s.base != s.top){
		
		printf("%c ",*--(s.top));

	}
	printf("\n");
}
SElemType OutStack(Stack &s ){
 SElemType	e;
	if(s.top != s.base)

 e= *(--s.top);
	
	return e;
}
SElemType TopStack(Stack &s ){
 SElemType	e;
	if(s.top != s.base)

 e= *(s.top-1);
	
	return e;
}
Status DestroyStack ( Stack s) 
{      if (!s.base)  return ERROR; 
      free (s.base);    
      s.base = NULL;
      s.top = NULL;
      s.stacksize= 0;
      return OK;
}// DestroyList_Sq 
