#include <stdio.h>

void result(int a, int b, int c, int *x2, int *y2) 								/*�Զ��庯����*/
{
    int x[100], y[100], z[100];
    int i, j, d, t, gcd;
    x[0] = 0;
    y[0] = 1;
    for (i = 0; i < 100; i++)
    {
        z[i] = a / b; 											/*��a/b��ֵ*/
        d = a % b; 											/*��a��bȡ���ֵ*/
        a = b;
        b = d;
        if (d == 0)
        {
            gcd = a; 										/*շת�������Լ��*/
            break;
        }
        if (i == 0)											/*�ж�a�Ƿ��ܱ�b����*/
        {
            x[1] = 1;
            y[1] = z[0];
        }
        else
        {
            x[i + 1] = z[i] *x[i] + x[i - 1];
            y[i + 1] = z[i] *y[i] + y[i - 1];
        }
    }
    for (t =  - 1, j = 1; j < i; j++)
        t =  - t;
    *x2 =  - t * x[i];
    *y2 = t * y[i]; 											/*���ax+by=gcd(a��b)��һ���*/
    if (c % gcd != 0)											/*���c�ܷ�����a��b�����Լ��*/
    {
        printf("�޽�!\n"); 							/*�粻��������������޽����ʾ��Ϣ*/
        exit(0);
    }
    t = c / gcd; 												/*���������򽫽������t*/
    *x2 =  *x2 * t;
    *y2 =  *y2 * t;
}

void test(int a, int b, int c, int x, int y) 								/*�Զ��庯���������Ľ��*/
{
    if (a *x + b * y == c)										/*��x��y������ʽ���Ƿ����c*/
        printf("�����ȷ!\n");
    else
        printf("�������!\n");
}

void main()
{
    int a, b, c, x2, y2;
    printf("����a,b,c:\n"); 										/*����a��b��c��ֵ*/
    scanf("%d%d%d", &a, &b, &c);
    result(a, b, c, &x2, &y2); 									/*���ú��������*/
    test(a, b, c, x2, y2); 										/*�������Ƿ���ȷ*/
    printf("x=%d,y=%d\n", x2, y2); 								/*��x��y��ֵ���*/
}