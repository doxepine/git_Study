#include <stdio.h>

void main()
{
    int i, j, k, sum1, sum2;										/*�������Ϊ��������*/
    for (i = 1; i <= 10000; i++)									/*��10000���ڵ����������*/
    {
        sum1 = 0;
        sum2 = 0;
        for (j = 1; j < i; j++)
            if (i % j == 0) 									/*�ж�j�Ƿ���i������*/
                sum1 += j; 									/*�����ӵĺ�*/
        for (k = 1; k < sum1; k++)
            if (sum1 % k == 0)									/*�ж�k�Ƿ���sum1������*/
                sum2 += k; 									/*�����Ӻ�*/
        if (sum2 == i && i != sum1 && i < sum1)
            printf("%5d=>%5d\n", i, sum1); 						/*�����������*/
    }
}