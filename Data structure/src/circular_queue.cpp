#include "stdio.h"
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  char    QElemType;

#define  QUEUE_INIT_SIZE  100    //  存储空间初始分配量
#define  QUEUE_INCREAMENT  2  //  分配增量

typedef struct{
    QElemType  *base;           //存储数据元素的数组
    int front;                     //头指针，若队列不空，指向队列头元素前一个元素 
    int rear;                      //尾指针，指向队尾元素
    int queuesize;                 //当前分配的存储容量
}SqQueue;

Status InitQueue(SqQueue &que){
	que.base = (QElemType*)malloc( QUEUE_INIT_SIZE*sizeof(QElemType));
	if (!que.base )   
		exit(0);
	que.queuesize = QUEUE_INIT_SIZE;
	que.rear = 0;
	que.front = 0; 
	return OK; 
}

Status EmptyQueue (SqQueue que) { 
	if(que.front == que.rear)  
		return TRUE;
  	else 
	  	return FALSE;
}//

Status PushQueue(SqQueue &que , QElemType e ){
	if((que.rear+1)%que.queuesize!=que.front){
		que.rear = ++que.rear%que.queuesize;
		que.base[que.rear] = e;
		return OK;
	}
	return ERROR;
}
Status OutQueue(SqQueue &que , QElemType &e){
	if(que.front == que.rear) 
		return ERROR;
	else{
 		que.front = (que.front+1)% que.queuesize; 
		e= que.base[que.front];
		return OK;
	} 
	return ERROR; 
}
Status GetLength(SqQueue que){
	return (que.rear-que.front+que.queuesize)%que.queuesize;
}

Status DestroyQueue ( SqQueue &que) {     
 	if (!que.base)  
	 	return ERROR; 
    free (que.base);    
	que.queuesize= 0;
    return OK;
}

int main(){
	SqQueue que;
	QElemType e;
	printf("1)初始化循环加头队列；\n");
	InitQueue(que);	
	printf("2)判断循环加头队列是否为空；");
	printf(EmptyQueue(que)?"ture\n":"flase\n");
	printf("3)依次进队元素a,b,c；\n");
	PushQueue(que,'a');
	PushQueue(que,'b');	
	PushQueue(que,'c');
	printf("4)出队一个元素，并输出该元素；");
	OutQueue(que,e); 
	printf("%c\n",e);
	printf("5)输出循环队列的长度；");
	printf("%d\n",GetLength(que));
	printf("6)依次进队元素d,e,f；\n");
	PushQueue(que,'d');
	PushQueue(que,'e');	
	PushQueue(que,'f');
	printf("7)输出循环队列的长度；");
	printf("%d\n",GetLength(que));
	printf("8)输出出队序列；");
	while(OutQueue(que,e)==1)
	 	printf("%c",e);
	printf("\n"); 
	printf("9)释放队列。");	
	DestroyQueue(que);
}
