#include <stdio.h>
main()
{
    FILE *fp1,  *fp2,  *fp3; /*�����ļ�����ָ��fp1��fp2��fp3*/
    char file1[20], file2[20], file3[20], ch;
    int file_number; /*�رյ��ļ���Ŀ*/
    printf("please input file1:");
    scanf("%s", file1); /*�����ļ�1��·��������*/
    printf("file1:\n");
    if ((fp1 = fopen(file1, "rb")) != NULL)
    {
        ch = fgetc(fp1); /*��ȡ�ļ�1������*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp1);
        }
    }
    else
    {
        printf("can not open!"); /*���ļ�δ�������ʾ��Ϣ*/
        exit(1);
    }
    printf("\nplease input file2:");
    scanf("%s", file2); /*�����ļ�2��·��������*/
    printf("file2:\n");
    if ((fp2 = fopen(file2, "rb")) != NULL)
    {
        ch = fgetc(fp2); /*��ȡ�ļ�2������*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp2);
        }
    }
    else
    {
        printf("can not open!");
        exit(1);
    }
    printf("\nplease input file3:");
    scanf("%s", file3); /*�����ļ�3��·��������*/
    printf("file3:\n");
    if ((fp3 = fopen(file3, "rb")) != NULL)
    {
        ch = fgetc(fp3); /*��ȡ�ļ�3������*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp3);
        }
    }
    else
    {
        printf("can not open!");
        exit(1);
    }
    file_number = fcloseall(); /*����fcloseall()
        �����رմ򿪵��ļ���������ֵ����file_number*/
    printf("\n%d files colsed", file_number);
}