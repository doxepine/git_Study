#include <stdio.h>

void main()
{
    unsigned result;
    int a, b, c, d;
    a = 2;
    b = 4;
    c = 6;
    d = 8;
    printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);						/*�������a��b��c��d�ĸ�����ֵ*/
    result = a &c;											/*a��c�Ľ������result*/
    printf("\na&c=%u\n", result);									/*��������*/
    result = b | d; 											/*b|d�Ľ������result*/
    printf("b|d=%u\n", result);									/*��������*/
    result = a ^ d;											/*a^d�Ľ������result*/
    printf("a^d=%u\n", result);									/*��������*/
    result = ~a;												/*~a�Ľ������result*/
    printf("~a=%u\n", result);									/*��������*/
}