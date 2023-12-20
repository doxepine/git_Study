#include<stdio.h>

int bin_dec(int x, int n) 									/*�Զ��庯������������ת����ʮ������*/
{
    if (n == 0)
     /*�ݹ��������*/
    {
        return 1;
    }
    return x *bin_dec(x, n - 1); 								/*�ݹ����bin_dec()����*/
}

void main()
{
    int i;
    int ip[4] ={0};
    char a[33]; 											/*�������Ķ�������*/
    printf("�����������:\n");
    scanf("%s", a); 										/*�����������ַ�����ʽ����*/

    for (i = 0; i < 8; i++)
    {
        if (a[i] == '1')
        {
            ip[0] += bin_dec(2, 7-i); 							/*����0-7ת���Ľ��*/
        }
    }
    for (i = 8; i < 16; i++)
    {
        if (a[i] == '1')
        {
            ip[1] += bin_dec(2, 15-i); 						/*����8-15ת���Ľ��*/
        }
    }
    for (i = 16; i < 24; i++)
    {
        if (a[i] == '1')
        {
            ip[2] += bin_dec(2, 23-i); 							/*����16-23ת���Ľ��*/
        }
    }
    for (i = 24; i < 32; i++)
    {
        if (a[i] == '1')
        {
            ip[3] += bin_dec(2, 31-i); 							/*����24-31ת���Ľ��*/
        }
        if (a[i] == '\0')
        {
            break;
        }
    }
    printf("IP:\n");
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);				/*�����ս����IP��ʽ���*/
}