#include<stdio.h>
#include<string.h>
#define MAX 101

struct aa/*����ṹ��aa�洢�����͵绰����*/
{
	char name[15];
	char tel[15];
};

int readin(struct aa *a)/*�Զ��庯��readin�������洢�������绰����*/
{
	int i=0,n=0;
	while(1)
	{
		scanf("%s",a[i].name);/*��������*/
		if(!strcmp(a[i].name,"#"))
			break;
		scanf("%s",a[i].tel);/*����绰����*/
		i++;
		n++;/*��¼������*/
	}
	return n;/*��������*/
}

void search(struct aa *b,char *x,int n)/*�Զ��庯��search��������������Ӧ�ĵ绰����*/
{
	int i;
	i=0;
	while(1)
	{
		if(!strcmp(b[i].name,x))/*����������������ƥ��ļ�¼*/
		{
			printf("����:%s  �绰:%s\n",b[i].name,b[i].tel);/*������ҵ�����������Ӧ�ĵ绰����*/
			break;
		}
		else
			i++;
		n--;
		if(n==0)
		{
			printf("û���ҵ�!");/*��û���ҵ���¼�����ʾ��Ϣ*/
			break;
		}
	}
}

void main()
{
	struct aa s[MAX];/*����ṹ������s*/
	int num;
	char name[15];
	num=readin(s);/*���ú���readin*/
	printf("��������:");
	scanf("%s",name);/*����Ҫ���ҵ�����*/
	search(s,name,num);/*���ú���search*/
}