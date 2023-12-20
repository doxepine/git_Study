#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#define Maxsize 30
#define TRUE 1
#define FALSE 0
char queue[Maxsize];
int front, rear;

void init()											 /*���׶�βָ���ʼ��*/
{
	front = rear =  - 1;
}

int enqueue(char x) 									/*Ԫ�������*/
{
	if (front ==  - 1 && (rear + 1) == Maxsize)
		/*ֻ��Ԫ�����û��Ԫ�س����ж��Ƿ������������*/
	{
		printf("overflow!\n");
		return 0;
	}
	else if ((rear + 1) % Maxsize == front)					/*�ж��Ƿ����*/
	{
		printf("overflow!\n");
		return 0;
	}
	else
	{
		rear = (rear + 1) % Maxsize;						 /*rearָ����һλ��*/
		queue[rear] = x;								 /*Ԫ�����*/
		return 1;
	}
}

void dequeue() 										/*Ԫ�س�����*/
{
	if (front == rear)
		/*�ж϶����Ƿ�Ϊ��*/
		printf("NULL\n");
	else
		front = (front + 1) % Maxsize;
	/*����ָ��ָ����һ��λ��*/
}

char gethead() 										/*ȡ����Ԫ��*/
{
	if (front == rear)
		/*�ж϶����Ƿ�Ϊ��*/
		printf("NULL\n");
	else
		return (queue[(front + 1) % Maxsize]);
	/*ȡ������Ԫ��*/
}

void main()
{
	char ch1, ch2;
	init(); 											/*���г�ʼ��*/
	for (;;)
	{
		for (;;)
		{
			printf("A");
			if (kbhit())
			{
				ch1 = bdos(7, 0, 0);							 /*ͨ��dos�������һ���ַ�*/
				if (!enqueue(ch1))
				{
					printf("IS FULL\n");
					break;
				}
			}
			if (ch1 == ';' || ch1 == ',')
				/*�ж������ַ��Ƿ��ǷֺŻ򶺺�*/
				break;
		}
		while (front != rear)
			/*�ж϶����Ƿ�Ϊ��*/
		{
			ch2 = gethead(); /*ȡ����Ԫ��*/
			dequeue(); /*Ԫ�س�����*/
			putchar(ch2); /*�����Ԫ��*/
		}
		if (ch1 == ';')
			/*�ж�������Ƿ��Ƿֺ�*/
			break;
		/*����ѭ��*/
		else
			ch1 = '';
	}
}
