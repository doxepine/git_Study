#include <stdio.h>

typedef struct student
{
    int num;
    struct student *next;
} LNode,  *LinkList;

LinkList create(void)
{
    LinkList head;
    LNode *p1,  *p2;
    char a;
    head = NULL;
    a = getchar();
    while (a != '\n')
    {
        p1 = (LNode*)malloc(sizeof(LNode));		 /*����ռ�*/
        p1->num = a;							 /*������ֵ*/
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        a = getchar();
    }
    p2->next = NULL;
    return head;
}

LinkList coalition(LinkList L1, LinkList L2)
{
    LNode *temp;
    if (L1 == NULL)
        return L2;
    else
    {
        if (L2 != NULL)
        {
            for (temp = L1; temp->next != NULL; temp = temp->next);
            temp->next = L2; 							/*����L1�нڵ�ֱ��β�ڵ�*/
        }
    }
    return L1;
}

void main()
{
    LinkList L1, L2, L3;
    printf("��������������:\n");
    printf("��һ��������:\n");
    L1 = create();								/*����һ������*/
    printf("�ڶ���������:\n");
    L2 = create();								/*�����ڶ�������*/
    coalition(L1, L2);								/*������������*/
    printf("�ϲ����������:\n");
    while (L1)									/*����ϲ��������*/
    {
        printf("%c", L1->num);
        L1 = L1->next;
    }
    getch();
}