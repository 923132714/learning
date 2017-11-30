#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//函数声明 
double calculate(char *, Stack* ,Stack*);//核心运算部分 
double get_result(double ,Stack* ,Stack*);//获取结果 
double accumulate(Stack* ,Stack* );// 

//运算
double calculate(char *s, Stack* num_stack,Stack* opr_stack){
	int i= 0; 
	int j = 0;// 小数位数
	int length = strlen(s);
	int flag =0 ; //判断 -1不运算取负数  0不运算 1进行一次运算 
	double tempnumber=0;//数字缓存
	double spot=-0;//小数部分 
	while(i<length){
		
		//数字
		if(isdigit(s[i])){
			tempnumber =  (s[i]-'0');//字符转数字 
			while(i<length&&isdigit(s[i+1])){//多位数转换 
				tempnumber =tempnumber*10 +(s[++i]-'0');
			}
			if(s[i+1]=='.'){//小数部分 
				i++;
				spot=-0;
				while(i<length&&isdigit(s[i+1])){
					j++; 
					spot =spot*10 +(s[++i]-'0');
				}
	
				for(;j>0;j--){//转换小数部分 
					spot /=10;
				}
				tempnumber += spot;//合成一个数 
			}
			
			//运算数入栈 
			if(flag==-1){
				flag = 0;
				PushStack(*num_stack,-tempnumber);
			}else if(flag == 0){//不进行运算
				PushStack(*num_stack,tempnumber);
			}else if(flag == 1){//进行一次运算
				flag =0;
				PushStack(*num_stack,	get_result(tempnumber,num_stack,opr_stack));
			}
			
			//如果当前字符是运算符.
		}else{
			switch(s[i]){
				case '+'://如果是加号.
					PushStack(*opr_stack,'+');
					break;
				case '-'://如果是减号.
					flag = -1;
					PushStack(*opr_stack,'-');
					break;
					
				//乘除法优先级高所以直接就运算掉 
				case '*'://如果是乘号.
					flag=1;
					PushStack(*opr_stack,'*');
					break;
				case '/'://如果是除号.
					flag=1;
					PushStack(*opr_stack,'/');
					break;
					
				//但是如果乘除后是括号就不能运算 
				case '('://如果是左括号.
					flag = 0;
					PushStack(*opr_stack,	'(');
					break;
				case ')'://如果是右括号.这时获取这一级的结果，这时需要考虑括号前如果是乘除也需要运算掉。 
					//计算当前的栈内元素值.
					PushStack(*num_stack,	accumulate(num_stack,opr_stack));
					break;
				default:break;
			}
		}
		i++;
	} 
	return accumulate(num_stack,opr_stack);
}

double accumulate(Stack* num_stack,Stack* opr_stack){
	double acc = OutStack(*num_stack);
	while(TopStack(*opr_stack)!='('&&EmptyStack(*num_stack)!=1){
	
		acc= get_result(acc,num_stack, opr_stack);
	}
	if(EmptyStack(*num_stack)!=1){
		OutStack(*opr_stack);
		//处理括号前为乘除的情况 
		if(TopStack(*opr_stack)==(int)'/'||TopStack(*opr_stack)==(int)'*'){
			acc= get_result(acc,num_stack, opr_stack);
		}else if(TopStack(*opr_stack)==(int)'-')
			acc= -acc;
	}		
	return acc;
}

double get_result(double right,Stack* num_stack,Stack* opr_stack){
	double left=OutStack(*num_stack);
	char oper=OutStack(*opr_stack);
	switch(oper){
		case '+':
			return left+right;
		case '-':
			return left+right;
		case '*':
			return left*right;
		case '/':
			return left/right;
	}
}

int main(){
	Stack num_stack;
	Stack opr_stack;
	InitList_stack(num_stack);
	InitList_stack(opr_stack);
	char s[100] = {0};
	gets(s);	
	printf("结果是：%f",calculate(s,&num_stack,&opr_stack));
	return 0;
}
