#include <stdio.h>

typedef struct node
{
    char name[20];
    struct node *prior,  *next;
} stud; 						/*˫�����Ľṹ����*/

stud *creat(int n)
{
    stud *p,  *h,  *s;
    int i;
    h = (stud*)malloc(sizeof(stud));			/*������ռ�*/
    h->name[0] = '\0';
    h->prior = NULL;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (stud*)malloc(sizeof(stud));
        p->next = s;						/*ָ����̽��*/
        printf("�����%d��ѧ��������: ", i + 1);
        scanf("%s", s->name);
        s->prior = p;						/*ָ��ǰ�����*/
        s->next = NULL;
        p = s;
    }
    p->next = NULL;
    return (h);
}

/*����*/
stud *search(stud *h, char *x)
{
    stud *p;				/*ָ��ṹ�����͵�ָ��*/
    char *y;
    p = h->next;		
    while (p)
    {
        y = p->name;
        if (strcmp(y, x) == 0)		/*�����Ҫɾ���Ľڵ㣬�򷵻ص�ַ*/
            return (p);
        else
            p = p->next;
    }
    printf("û���ҵ�����!\n");
}

/*ɾ��*/
void del(stud *p)
{
    p->next->prior = p->prior;		/*p����һ������ǰ��ָ��ָ��p��ǰ�����*/
    p->prior->next = p->next;		/*p��ǰ�����ĺ��ָ��ָ��p�ĺ�̽��*/
    free(p);
}

void main()
{
    int number;
    char sname[20];
    stud *head,  *sp;
    puts("�����������Ĵ�С:");
    scanf("%d", &number);					/*�������������*/
    head = creat(number);					/*��������*/
    sp = head->next;
    printf("\n�������˫������:\n");
    while (sp) 							/*�������������*/
    {
        printf("%s ", &*(sp->name));
        sp = sp->next;
    }
    printf("\n������������ҵ�����:\n");
    scanf("%s", sname);
    sp = search(head, sname);				/*����ָ�����*/
    printf("������ҵ�������:%s\n",  * &sp->name);
    del(sp);							/*ɾ�����*/
    sp = head->next;
    printf("\n�������˫������:\n");
    while (sp)
    {
        printf("%s ", &*(sp->name));			/*�����ǰ����������*/
        sp = sp->next;
    }
    printf("\n");
    puts("\n ��������˳�...");
}
