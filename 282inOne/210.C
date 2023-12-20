#include <stdio.h>
#define STACK_SIZE 100 							/*�ٶ�Ԥ�����ջ�ռ����Ϊ100��Ԫ��*/
typedef char DataType;								/*�趨DataType�Ĵ�������������Ϊ�ַ���*/

typedef struct									/*����ṹ��*/
{
	DataType *base;								/*����ջ��ָ��*/
	DataType *top;								/*����ջ��ָ��*/
	int stacksize;								/*����ջ�Ĵ�С*/
} SeqStack;										/*SeqStackΪ�ýṹ������*/

void Initial(SeqStack *S) /*��ʼ��ջ*/
{
	S->base = (DataType*)malloc(STACK_SIZE *sizeof(DataType));
	if (!S->base)
		exit( - 1);
	S->top = S->base;								/*ջΪ��ʱջ��ջ��ָ��ָ��ͬһ��*/
	S->stacksize = STACK_SIZE;
}

int IsEmpty(SeqStack *S)							/*��ջ��*/
{
	return S->top == S->base;
}

int IsFull(SeqStack *S)									/*��ջ��*/
{
	return S->top - S->base == STACK_SIZE - 1;
}

void Push(SeqStack *S, DataType x)						/*��ջ*/
{
	if (IsFull(S))
	{
		printf("overflow");								/*����,�˳�����*/
		exit(1);
	}
	else
		*S->top++ = x;								/*ջ��ָ���1��x��ջ*/
}

void Pop(SeqStack *S)									/*��ջ*/
{
	if (IsEmpty(S))
	{
		printf("NULL");								/*����,�˳�����*/
		exit(1);
	}
	else
		--S->top;									/*ջ��Ԫ�ط��غ�ջ��ָ���1*/
}

DataType Top(SeqStack *S)								/* ȡջ��Ԫ��*/
{
	if (IsEmpty(S))
	{
		printf("empty");								/*����,�˳�����*/
		exit(1);
	}
	return *(S->top - 1);
}

int match(SeqStack *S, char *str)
{
	char x;
	int i, flag = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
			Push(S, '(');
			break;
		case '[':
			Push(S, '[');
			break;
		case '{':
			Push(S, '{');
			break;
		case ')':
			x = Top(S);
			Pop(S);
			if (x != '(')
				flag = 0;
			break;
		case ']':
			x = Top(S);
			Pop(S);
			if (x != '[')
				flag = 0;
			break;
		case '}':
			x = Top(S);
			Pop(S);
			if (x != '{')
				flag = 0;
			break;
		}
		if (!flag)
			break;
	}
	if (IsEmpty(S) == 1 && flag)
		return 1;
	else
		return 0;
}

void main()
{
	SeqStack *st;
	char str[100];
	Initial(st);
	gets(str);
	if (match(st, str))
		printf("matching\n");
	else
		printf("no matching\n");
}