#include <stdio.h>
#define Listsize 100

struct sqlist
{
    int data[Listsize];
    int length;
};

void InsertList(struct sqlist *l, int t, int i)
{
    int j;
    if (i < 0 || i > l->length)
    {
        printf("λ�ô���");
        exit(1);
    } 
    if (l->length >= Listsize)					/*�������˳�����Χ�������*/
    {
        printf("���");
        exit(1);
    }
    for (j = l->length - 1; j >= i; j--)				/*����Ԫ��*/
        l->data[j + 1] = l->data[j];
    l->data[i] = t;
    l->length++;
}

void main()
{
    struct sqlist *sq;
    int i, n, t;
    sq = (struct sqlist*)malloc(sizeof(struct sqlist));				/*����ռ�*/
    sq->length = 0;
    printf("������������С:");
    scanf("%d", &n);
    printf("������������Ԫ��:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        InsertList(sq, t, i);								/*����Ԫ��*/
    } printf("�������������:\n");
    for (i = 0; i < sq->length; i++)
    {
        printf("%d ", sq->data[i]);
    }
    getch();
}