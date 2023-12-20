#include <stdio.h>
struct student_score										/*����ṹ��洢ѧ���ɼ���Ϣ*/
{
    char name[10];
    int num;
    int China;
    int Math;
    int English;
} score[100];
void save(char *name, int n)									/*�Զ��庯��save*/
{
    FILE *fp;											/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    int i;
    if ((fp = fopen(name, "wb")) == NULL)						/*��ֻд��ʽ��ָ���ļ�*/
    {
        printf("cannot open file\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
        if (fwrite(&score[i], sizeof(struct student_score), 1, fp) != 1)	/*��һ�����������fp��ָ���ļ���*/
            printf("file write error\n");							/*���д���ļ����ɹ������������*/
    fclose(fp);											/*�ر��ļ�*/
}
void show(char *name, int n)									/*�Զ��庯��show*/
{
    int i;
    FILE *fp;											/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    if ((fp = fopen(name, "rb")) == NULL)						/*��ֻ����ʽ��ָ���ļ�*/
    {
        printf("cannot open file\n");
        exit(0);
    } for (i = 0; i < n; i++)
    {
        fread(&score[i], sizeof(struct student_score), 1, fp);			/*��fp��ָ����ļ��������ݴ浽����score��*/
        printf("%-10s%4d%4d%4d%4d\n", score[i].name, score[i].num,
            score[i].China, score[i].Math, score[i].English);
    }
    fclose(fp);											/*��ֻд��ʽ��ָ���ļ�*/
}
main()
{
    int i, n;											/*��������Ϊ��������*/
    char filename[50];										/*����Ϊ�ַ���*/
    printf("how many students in your class?\n");
    scanf("%d", &n);										/*����ѧ����*/
    printf("please input filename:\n");
    scanf("%s", filename);									/*�����ļ�����·��������*/
    printf("please input name,number,China,math,English:\n");
    for (i = 0; i < n; i++)									/*����ѧ���ɼ���Ϣ*/
    {
        printf("NO%d", i + 1);
        scanf("%s%d%d%d%d", score[i].name, &score[i].num, &score[i].China,
            &score[i].Math, &score[i].English);
        save(filename, n);									/*���ú���save*/
    } show(filename, n);									/*���ú���show*/
}