#include <stdio.h>

void main()
{
    float salary=500;										/*Ա���Ļ�������*/
    int k;												/*����������洢���۶�ϵ��*/
    int profit ;											/*�������ͱ������洢���۶�*/
    printf("����Ա������µ����۶");					/*�����ʾ��Ϣ*/
    scanf("%d",&profit);									/*����������۶�洢��������*/
    if (profit%1000==0)									/*�����1000��������*/
        k=profit/1000;									/*�������ϵ��*/
    else												/*����*/
        k=profit/1000+1;									/*������ϵ����һ*/
    switch (k)
    {
    case 0:											/*����ϵ����0-2֮���û�����*/
    case 1:         
    case 2: break;
    case 3: 											/*����ϵ����3-5�����Ϊ8%*/
    case 4:
    case 5:
        salary+=profit*0.08;								/*���㹤��*/
        break;
    case 6:											/*����ϵ��Ϊ6-10�����Ϊ10%*/
    case 7:
    case 8:
    case 9:
    case 10:
        salary+=profit*0.1;								/*���㹤��*/
        break;
    default:											/*�������������ϵ������10�����Ϊ12%*/
        salary+=profit*0.12;								/*���㹤��*/
        break;
    }
    printf("Ա������µĹ���Ϊ��%5.2f\n",salary); 			/*���Ա������µĹ���*/
}