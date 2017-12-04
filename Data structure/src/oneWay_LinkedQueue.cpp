#include "stdio.h"
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  char    QElemType;


typedef struct QNode{  //�����н������Ͷ���
    QElemType  data;     
    struct QNode *next; 
}QNode,*QueuePtr;
typedef struct {       //�����еı�ͷ���ĵ����Ͷ���
     QueuePtr front;   //��ͷָ�룬ָ�������ͷ���
     QueuePtr rear;    //��βָ�룬ָ���β���
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
	 printf("1)��ʼ��ѭ����ͷ���У�\n");
	InitQueue(que);	
	printf("2)�ж�ѭ����ͷ�����Ƿ�Ϊ�գ�");
	printf(EmptyQueue(que)?"ture\n":"flase\n");
	printf("3)���ν���Ԫ��a,b,c��\n");
	PushQueue(que,'a');
	PushQueue(que,'b');	
	PushQueue(que,'c');
	printf("4)����һ��Ԫ�أ��������Ԫ�أ�");
	OutQueue(que,e); 
	printf("%c\n",e);
	printf("5)���ѭ�����еĳ��ȣ�");
	printf("%d\n",GetLength(que));
	printf("6)���ν���Ԫ��d,e,f��\n");
	PushQueue(que,'d');
	PushQueue(que,'e');	
	PushQueue(que,'f');
	printf("7)���ѭ�����еĳ��ȣ�");
	printf("%d\n",GetLength(que));
	printf("8)����������У�");
	while(OutQueue(que,e)==1)
	 	printf("%c",e);
	printf("\n"); 
	printf("9)�ͷŶ��С�");	
	DestroyQueue(que);
} 
