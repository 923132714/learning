#include<stdio.h>
#include<stdlib.h>
#include <string> 
#define OVERFLOW 0
#define OK 1
#define ERROR 0

typedef  int  Status;
typedef  char TElemType;
char ch[] = {'A', 'B', 'D','#','#','E','H','J','#','#','K','L','#','#','M','#','N','#','#','#','C','F','#','#','G','#','I','#','#'};
int j =0 ;

typedef   struct   BiTNode{
    TElemType    data;
    struct   BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


	
Status CreateBiTree(BiTree &T){

	if(ch[j]=='#') {
		T=NULL;
		j++;
	}else{
		if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) 
			exit(OVERFLOW);
		T->data=ch[j];
		j++;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
} 

Status PreOrderTraverse(BiTree  T){ 
	if(T) {  
		printf("%c",T->data);
      	PreOrderTraverse(T->lchild);
      	PreOrderTraverse(T->rchild);
      	return  OK;
   	}else   
   		return  ERROR; 
}//PreOrderTraverse

Status InOrderTraverse(BiTree T){ 
	if(T) { 
		InOrderTraverse(T->lchild); 
     	printf("%c",T->data); 
     	InOrderTraverse(T->rchild); 
        return  OK;
    }else   
   		return  ERROR; 
}

Status PostOrderTraverse(BiTree T){ 
	if(T) { 
		PostOrderTraverse(T->lchild);
     	PostOrderTraverse(T->rchild); 
     	printf("%c",T->data); 
        return  OK;
   }else   
   		return  ERROR; 
}

Status DestroyBiTree (BiTree &T) {     
 	if (!T)  
	 	return ERROR; 
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	if(!T)    
    	return OK;
}

main(){

	int i;
	BiTree T;
	CreateBiTree(T);
	printf("输入1进行先序遍历\n输入2进行中序遍历\n输入3进行后序遍历\n");
	scanf("%d",&i);
	if(T){
		switch(i){
			case 1:
				PreOrderTraverse(T);
				break;
			case 2:
				InOrderTraverse(T);	
				break;
			case 3:
				PostOrderTraverse(T);
				break;
			default:	
				printf("error\n");
		}
	}
	DestroyBiTree(T);	
}
