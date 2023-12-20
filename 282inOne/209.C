#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define STACK_SIZE 100 /*�ٶ�Ԥ�����ջ�ռ����Ϊ100��Ԫ��*/  
char PASSWORD[10]= "13579";	
typedef char DataType;/*�ٶ�ջԪ�ص���������Ϊ�ַ�*/  	
typedef struct{
	DataType *base;
	DataType *top;
	int stacksize;
	int length;
}SeqStack;   
/* ��ջ��*/

void Initial(SeqStack *s)
{
	s->base=(DataType *)malloc(STACK_SIZE * sizeof(DataType));
	if(!s->base) exit (-1);
	s->top=s->base;
	s->stacksize=STACK_SIZE;
	s->length=0;
} 
/*��ջ��*/
int IsEmpty(SeqStack *S)
{
	return S->top==S->base;
}
/*��ջ��*/
int IsFull(SeqStack *S)
{
	return S->top-S->base==STACK_SIZE-1;
}
/*��ջ*/
void Push(SeqStack *S,DataType x)
{
	if (IsFull(S))
	{
		printf("ջ����"); /*����,�˳�����*/
		exit(1);
	}
	*(S->top++) =x;/*ջ��ָ���1��x��ջ*/
	++S->length;
	/* printf("%c",*S->top);*/
}
/*��ջ*/
DataType Pop(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("ջΪ��"); /*����,�˳�����*/
		exit(1);
	}
	--(S->length);	
	
	return *--S->top;/*ջ��Ԫ�ط��غ�ջ��ָ���1*/
}
/* ȡջ��Ԫ��*/
DataType GetTop(SeqStack *S,DataType *e)
{
	if(IsEmpty(S))
	{
		printf("ջΪ��"); /*����,�˳�����*/
		exit(1);
	}
	*e= *(S->top-1);
	S->top--;
}
void change(SeqStack *s,char *a)
{
	int n=s->length-1;
	while(!IsEmpty(s))
	{
		GetTop(s,&a[n--]);}
}
void clearstack(SeqStack *s)
{
	s->top=s->base;
	s->length=0;
}

void PwdSet(SeqStack *s)
{
	int i=0,k,j=0;
	DataType ch,*a;
	k=strlen(PASSWORD);
	printf("input password ");
	for(;;)
	{
		if(i>=3)
		{
			i++;
			break;
		}
		else if(i>0 && i<3)
		{
			
			for(j=1;j<=s->length;j++)printf(" ");
			clearstack(s);	
		}
		for(;;)
		{
			ch=getch();
			if(ch!=13)
			{
				if(ch==8){
					Pop(s);
					gotoxy(4+j,2);
					printf(" ");
					gotoxy(4+j,2);
				}
				else{printf("*");Push(s,ch);}
				j=s->length;
				
			}
			else 
			{printf("\n");
			break;}
		}
		i++;
		if(k!=j)continue;
		else
		{
			a=(DataType *)malloc(s->length * sizeof(DataType));
			change(s,a);
			
			for(j=1;j<=s->length;)
			{
				
				if(*(a+j-1)==PASSWORD[j-1]) j++;	
				else
				{
					
					j=s->length+2;
					printf("\n passwrod wrong!\n");
					break;
				}	
			}
			if(j==s->length+2)continue;
			else break;
		}
	}
	if(i==4)printf("\n Have no chance,It will quit!");
	else printf("\n password right!\n");
	free(a);
}

void main()
{
	SeqStack *s;
	clrscr();
	Initial(s);
	PwdSet(s);
	
	getch();
	
}