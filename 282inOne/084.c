#include<stdio.h>
main()
{
	int i, j, a[11][11]; 							/*����i��j��a[11][11]Ϊ��������*/
	for (i = 1; i < 11; i++)						/*forѭ��i�ķ�Χ��1��10*/
	{
		a[i][i] = 1; 							/*�Խ���Ԫ��ȫΪ1*/
		a[i][1] = 1; 							/*ÿ�е�һ��Ԫ��ȫΪ1*/
	}
	for (i = 3; i < 11; i++)						/*forѭ����Χ�ӵ�3�п�ʼ����10��*/
		for (j = 2; j <= i - 1; j++)					/*forѭ����Χ�ӵ�2�п�ʼ������������һ��Ϊֹ*/
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];	/*��i��j�е��ڵ�i-1��j-1�е�ֵ���ϵ�i-1��j�е�ֵ*/
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%4d", a[i][j]);				/*ͨ����������forѭ������ά����a��Ԫ�����*/
		printf("\n"); 							/*ÿ�����һ�н���һ�λ���*/
	}
}