#include <stdio.h>
#include <math.h>

int ss(int i)												/*�Զ��庯���ж��Ƿ�Ϊ����*/
{
    int j;
    if (i <= 1) 											/*С��1������������*/
        return 0;
    if (i == 2) 											/*2������*/
        return 1;
    for (j = 2; j < i; j++)									/*�Դ���2���������ж�*/
    {
        if (i % j == 0)
            return 0;
        else if (i != j + 1)
            continue;
        else
            return 1;
    }
}

void main()
{
    int i, n = 0, n1, n2, n3, n4;
    for (i = 1000; i < 10000; i++)
    if (ss(i) == 1)
    {
        n4 = i % 10;										/*ȡ��λ��*/
        n3 = (i % 100) / 10; 								/*ȡʮλ��*/
        n2 = (i / 100) % 10; 								/*ȡǧλ��*/
        n1 = i / 1000;										/*ȡ��λ��*/
        if (ss(1000 *n4 + 100 * n3 + 10 * n2 + n1) == 1 && 1000 *n4 + 100 * n3
            + 10 * n2 + n1 > i)								/*���������ж�*/
        {
            printf("%d,", i);
            n++;										/*��¼����*/
            if (n % 10 == 0)								/*10��һ����*/
                printf("\n");
        }
    }
}