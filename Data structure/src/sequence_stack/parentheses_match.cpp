#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int CheckMatch(char *s,Stack* opr_stack){
	int i= 0; 
	int length = strlen(s);
	while(i<length){
		if(s[i]=='('||s[i]==')'||s[i]=='{'||s[i]=='}'||s[i]=='['||s[i]==']'){//�����ǰ�ַ��������.
			switch(s[i]){
				case '(':
					PushStack(*opr_stack,'(');			
					break;
				case '[':
					PushStack(*opr_stack,'[');
					break;
				case '{':
					PushStack(*opr_stack,'{');
					break;
				case ')':
					if(EmptyStack(*opr_stack)==1&&TopStack(*opr_stack)!='(')
						return 0;
					OutStack(*opr_stack);
					break;
				case ']':
					if(EmptyStack(*opr_stack)==1&&TopStack(*opr_stack)!='[')
						return 0;
					OutStack(*opr_stack);
					break;
				case '}':
					if(EmptyStack(*opr_stack)==1&&TopStack(*opr_stack)!='{')
						return 0;
					OutStack(*opr_stack);
					break;
				default:break;
			}
		}
		i++;	 
	} 
	if(EmptyStack(*opr_stack)==1) 
		return 1;
	return 0; 
}	


int main(){
	Stack opr_stack;
	InitList_stack(opr_stack);
	char s[100] = {0};
	gets(s);	
	printf("����ǣ�%s",CheckMatch(s,&opr_stack)==1?"ƥ��":"��ƥ��");
	return 0;
}
