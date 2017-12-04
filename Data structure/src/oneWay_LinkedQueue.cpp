#include "stdio.h"
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  char    QElemType;


typedef struct QNode{  //链队列结点的类型定义
    QElemType  data;     
    struct QNode *next; 
}QNode,*QueuePtr;
typedef struct {       //链队列的表头结点的的类型定义
     QueuePtr front;   //队头指针，指向链表的头结点
     QueuePtr rear;    //队尾指针，指向队尾结点
     int size; 
}LinkQueue;


Status InitQueue(LinkQueue &LinkQueue){
	LinkQueue.front = (QueuePtr)malloc(sizeof(QElemType));
	if (!LinkQueue.front )   
		exit(0);
	LinkQueue.size =  1; 
	LinkQueue.front->next = NULL; 
	LinkQueue.rear =LinkQueue.front; 
	return OK; 
}

Status EmptyQueue (LinkQueue &LinkQueue) { 
	if(LinkQueue.front == LinkQueue.rear)  
		return TRUE;
  	else 
	  	return FALSE;
}//

Status PushQueue(LinkQueue &LinkQueue , QElemType e ){
	LinkQueue.rear->data = e; 
	LinkQueue.rear->next = (QueuePtr)malloc(sizeof(QElemType));
	LinkQueue.rear = LinkQueue.rear->next ; 
	LinkQueue.rear->next =NULL; 
	LinkQueue.size++; 
	return OK;

}

Status OutQueue(LinkQueue &LinkQueue , QElemType &e ){
	if(LinkQueue.front == LinkQueue.rear) 
		return ERROR;
	else{
		e= LinkQueue.front->data;
 		LinkQueue.front =  LinkQueue.front->next; 
		LinkQueue.size--; 
		return OK;
	} 
	return ERROR; 
}

Status GetLength(LinkQueue &LinkQueue){
	return 	LinkQueue.size;
}

Status DestroyQueue ( LinkQueue &LinkQueue) { 
    if (!LinkQueue.front) 
		return ERROR; 
	LinkQueue.rear == NULL; 
    free (LinkQueue.front);    
    LinkQueue.size= 0;
    return OK;
}

int main(){
	LinkQueue que;
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
