#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int a, b, c, sign, max;								 /*����������ͱ���*/
    char sign1;										 /*�����ַ��ͱ���*/
    printf("��ѡ�������(1 or other,1:-,other:+):\n");
    scanf("%d", &sign);							 /*���뺯�����������ݸ���sign*/
    printf("��ѡ��������(<10000):\n");
    scanf("%d", &max);								 /*���뺯�����������ݸ���max*/
    srand((unsigned long)time(0));							 /*ϵͳʱ���趨����*/
    a = rand() % max;									 /*����С��max���漴��������a*/
    b = rand() % max;									 /*����С��max���漴��������b*/
    while ((a < b) && (sign == 1))							 /*ѡ���������ʱ���aС��b�����²����漴��*/
    {
        a = rand() % max;
        b = rand() % max;
    }
    sign1 = (sign == 1 ? '-' : '+');							 /*��ѡ��ķ��Ÿ���sign1*/
    printf("\n%d%c%d=", a, sign1, b);
    scanf("%d", &c);									 /*����������*/
    if ((sign == 1) && (a - b == c) || (sign != 1) && (a + b == c))	 /*�ж��������Ƿ������ȷ��*/
        printf("������ȷ!\n");								 /*������ȷ�����ok*/
    else
        printf("�������!\n");					 /*��������ȷ���������*/
}