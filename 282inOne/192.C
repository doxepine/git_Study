#include<stdio.h>
#include<string.h>

struct candidate 										/*����ṹ������*/
{
	char name[20]; 										/*�洢����*/
	int count;    										/*�洢��Ʊ��*/
} cndt[3]={{"��",0},{"��",0},{"��",0}};					/*����ṹ������*/

void main()
{
    int i,j;												/*��������*/
	char Ctname[20];									/*��������*/
	for(i=1;i<=10;i++)									/*����10��ͶƱ*/
	{
		scanf("%s",&Ctname);							/*�����ѡ������*/
		for(j=0;j<3;j++)
		{
			if(strcmp(Ctname,cndt[j].name)==0)			/*�ַ����Ƚ�*/
				cndt[j].count++;							/*����Ӧ�ĺ�ѡ��Ʊ����һ*/
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%s : %d\n",cndt[i].name,cndt[i].count);			/*���ͶƱ���*/
	}
}