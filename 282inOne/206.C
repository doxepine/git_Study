#include <stdio.h>

struct student
{
    int num;
    struct student *next;
};

struct student *create(int n)
{
    int i;
    struct student *head,  *p1,  *p2;
    int a;
    head = NULL;
    printf("����Ԫ��:\n");
    for (i = n; i > 0; --i)
    {
        p1 = (struct student*)malloc(sizeof(struct student)); 			/*����ռ�*/

        scanf("%d", &a);
        p1->num = a;											 /*������ֵ*/
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        } 
        else
        {
            p2->next = p1; 									/*ָ�����ָ��*/
            p2 = p1;
        }
    }
    p2->next = NULL;
    return head;												/*����ͷ���ָ��*/
}

struct student *reverse(struct student *head)
{
    struct student *p,  *r;
    if (head->next && head->next->next)
    {
        p = head;						/*��ȡͷ����ַ*/
        r = p->next;
        p->next = NULL;
        while (r)
        {
            p = r;
            r = r->next;
            p->next = head;
            head = p;
        } return head;
    }
    return head;								/*����ͷ���*/
}

void main()
{
    int n, i;
    int x;
    struct student *q;
    printf("�������봴���Ľ�����:");
    scanf("%d", &n);
    q = create(n);						/*����������*/
    q = reverse(q);						/*����������*/
    printf("���ú�ĵ�������:\n");
    while (q)							/*������ú�ĵ�����*/
    {
        printf("%d ", q->num);
        q = q->next;
    } getch();
}