#include<stdio.h>

struct student
{
	/*�ṹ���Ա*/
    int num;
    char name[20];
    float score;
};

void main()
{
    int i, m;
    float maxscore;
    struct student stu[5] =
    {
        {101, "����", 89} ,
        {102, "Է��", 95},
        {103, "���", 89},
        {104, "���Ӵ�", 85},
        {105, "������", 75}
    };										/*�����ṹ����������*/
    m = 0;
    maxscore = stu[0].score;						/*��ʼ�����ɼ�*/
    for (i = 1; i < 5; i++)
    {
        if (stu[i].score > maxscore)
        {
            maxscore = stu[i].score;					/*��¼���ɼ�*/
            m = i;								/*��¼���ɼ��±�*/
        }
    }
    printf("��߷���:%5.1f\n", maxscore);	/*������ɼ�*/
    printf("��߷�ѧ����ѧ��: %d\n", stu[m].num);	/*���ɼ���ѧ��*/
    printf("��߷�ѧ��������: %s\n", stu[m].name);	/*���ɼ�������*/
	
}
