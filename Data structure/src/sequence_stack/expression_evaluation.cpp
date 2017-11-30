#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//�������� 
double calculate(char *, Stack* ,Stack*);//�������㲿�� 
double get_result(double ,Stack* ,Stack*);//��ȡ��� 
double accumulate(Stack* ,Stack* );// 

//����
double calculate(char *s, Stack* num_stack,Stack* opr_stack){
	int i= 0; 
	int j = 0;// С��λ��
	int length = strlen(s);
	int flag =0 ; //�ж� -1������ȡ����  0������ 1����һ������ 
	double tempnumber=0;//���ֻ���
	double spot=-0;//С������ 
	while(i<length){
		
		//����
		if(isdigit(s[i])){
			tempnumber =  (s[i]-'0');//�ַ�ת���� 
			while(i<length&&isdigit(s[i+1])){//��λ��ת�� 
				tempnumber =tempnumber*10 +(s[++i]-'0');
			}
			if(s[i+1]=='.'){//С������ 
				i++;
				spot=-0;
				while(i<length&&isdigit(s[i+1])){
					j++; 
					spot =spot*10 +(s[++i]-'0');
				}
	
				for(;j>0;j--){//ת��С������ 
					spot /=10;
				}
				tempnumber += spot;//�ϳ�һ���� 
			}
			
			//��������ջ 
			if(flag==-1){
				flag = 0;
				PushStack(*num_stack,-tempnumber);
			}else if(flag == 0){//����������
				PushStack(*num_stack,tempnumber);
			}else if(flag == 1){//����һ������
				flag =0;
				PushStack(*num_stack,	get_result(tempnumber,num_stack,opr_stack));
			}
			
			//�����ǰ�ַ��������.
		}else{
			switch(s[i]){
				case '+'://����ǼӺ�.
					PushStack(*opr_stack,'+');
					break;
				case '-'://����Ǽ���.
					flag = -1;
					PushStack(*opr_stack,'-');
					break;
					
				//�˳������ȼ�������ֱ�Ӿ������ 
				case '*'://����ǳ˺�.
					flag=1;
					PushStack(*opr_stack,'*');
					break;
				case '/'://����ǳ���.
					flag=1;
					PushStack(*opr_stack,'/');
					break;
					
				//��������˳��������žͲ������� 
				case '('://�����������.
					flag = 0;
					PushStack(*opr_stack,	'(');
					break;
				case ')'://�����������.��ʱ��ȡ��һ���Ľ������ʱ��Ҫ��������ǰ����ǳ˳�Ҳ��Ҫ������� 
					//���㵱ǰ��ջ��Ԫ��ֵ.
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
		//��������ǰΪ�˳������ 
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
	printf("����ǣ�%f",calculate(s,&num_stack,&opr_stack));
	return 0;
}
