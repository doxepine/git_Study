#include "stdio.h"
#include <malloc.h>

struct LNode
{
    int data;
    struct LNode *next;
};

struct LNode *create(int n)
{
    int i;
    struct LNode *head,  *p1,  *p2;
    int a;
    head = NULL;
    printf("��������:\n");
    for (i = n; i > 0; --i)
    {
        p1 = (struct LNode*)malloc(sizeof(struct LNode)); 		/*����ռ�*/
        scanf("%d", &a);								/*��������*/
        p1->data = a;									 /*������ֵ*/
        if (head == NULL)  							/*ָ��ͷ���*/
        {
            head = p1;
            p2 = p1;
        } 
        else
        {
            p2->next = p1; 							/*ָ�����ָ��*/
            p2 = p1;
        }
    }
    p2->next = NULL;
    return head;
}

void main()
{
    int n;
    struct LNode *q;
    printf("�������봴���Ľ�����:");
    scanf("%d", &n);								/*��������������*/
    q = create(n);
    printf("�����:\n");
    while (q)
    {
        printf("%d  ", q->data);						/*�������*/
        q = q->next;
    };
	printf("\n");
}