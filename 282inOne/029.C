#include<stdio.h>

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
    int i, j, k, flag1, flag2, n = 0;
    for (i = 6; i < 100; i += 2)
    for (k = 2; k <= i / 2; k++)
    {
        j = i - k;
        flag1 = ss(k);										/*�жϲ�ֳ������Ƿ�������*/
        if (flag1)
        {
            flag2 = ss(j);
            if (flag2)									/*�����ֳ����������������������*/
            {
                printf("%3d=%3d+%3d,", i, k, j);
                n++;
                if (n % 5 == 0)
                    printf("\n");
            }
		
        }
    }
	printf("\n");
}