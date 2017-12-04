#include "stdio.h"
#include<malloc.h>  //malloc()
#include<process.h>  //exit()

#define  OK  1
#define  ERROR  0
#define  TRUE  1
#define  FALSE  0

typedef  int  Status;
typedef  char    QElemType;

#define  QUEUE_INIT_SIZE  100    //  �洢�ռ��ʼ������
#define  QUEUE_INCREAMENT  2  //  ��������

typedef struct{
    QElemType  *base;           //�洢����Ԫ�ص�����
    int front;                     //ͷָ�룬�����в��գ�ָ�����ͷԪ��ǰһ��Ԫ�� 
    int rear;                      //βָ�룬ָ���βԪ��
    int queuesize;                 //��ǰ����Ĵ洢����
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
