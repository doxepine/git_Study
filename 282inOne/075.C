#include <stdio.h>

void main()
{
    float x, m1, m2, m;
    char y, z;
    scanf("%f,%c,%c", &x, &y, &z); 					/*����ѡ���͵�ǧ���������༰����*/
    switch (y)										/*ѡ����������*/
    {
        case 'a':
            m1 = 3.25;
            break;
        case 'b':
            m1 = 3.00;
            break;
        case 'c':
            m1 = 2.75;
            break;
    }
    switch (z)										/*ѡ���������*/	
    {
        case 'a':									/*����Ҫ�ṩ����*/
            m2 = 0;
            break;
        case 'm':
            m2 = 0.05;
            break;
        case 'e':
            m2 = 0.1;
            break;
    }
    m = x * m1 - x * m1 * m2; 						/*����Ӧ����Ǯ��*/
    printf("����������:%c\n", y);
    printf("����ȼ���:%c\n", z);
    printf("�û�Ӧ�������:%.3f\n", m);
}