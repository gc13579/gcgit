Skip to content
 
Search or jump to��

Pull requests
Issues
Marketplace
Explore
 @gc13579 Sign out
0
0 0 gc13579/gcgit
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Insights  Settings
gcgit/gcgit/student.c
6b596c8  9 days ago
@gc13579 gc13579 commit student manager system
     
296 lines (290 sloc)  5.79 KB
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
#include<malloc.h>
//#pragma warning(disable:4996) 
typedef struct
{
	char name[8];
	int number;
	int score[3];
	double ave;
}student;
void show()
{
	printf("----------ѧ����Ϣ����ϵͳ-------------\n");
	printf("-------�밴1-6������Ӧ�Ĳ���---------\n");
	printf("1:���ѧ����Ϣ       2:����ѧ����Ϣ\n");
	printf("3:ѧ����Ϣ����       4:����ѧ����Ϣ\n");
	printf("5:�˳� \n");
}

void init()
{
	FILE *fp;
	fp = fopen("score.txt", "w");
	fclose(fp);
}

int putin(student *list,int n)
{
	FILE *fp;
	int all = 0;
	int choice;
	int choice1=1;
	char name[8];
	char filename[20];
	int number;
	int score[3];
	double ave;
	printf("����1���ļ�������Ϣ����2�ֶ������Ϣ\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("��������Ҫ�򿪵��ļ�����·������temp.txt\n");
		scanf("%s", filename);
		if ((fp = fopen(filename, "r")) == NULL) 
		{
			printf("���ļ�%s���ִ���\n", filename);
			system("pause");
			return n;
		}
		while (!feof(fp))
		{
			int i;
			fscanf(fp, "%d", &number);
			fscanf(fp, "%s", name);
			for (i = 0; i < 3; i++)
				fscanf(fp, "%d", &score[i]);
				fscanf(fp, "%lf", &ave);
			strcpy(list[n].name, name);
			list[n].number = number;
			list[n].ave = ave;
			for (i = 0; i < 3; i++)
				list[n].score[i] = score[i];
			n++;
		}
		n--;
		printf("�������\n");
		system("pause");
		fclose(fp);
	}
	else
	{
			while (choice1 == 1)
			{
				int i;
			    printf("����ѧ��\n");
			    scanf("%d", &number);
			    printf("��������\n");
		     	scanf("%s", name);
			    printf("�������ųɼ�\n");
     			for (i = 0; i < 3; i++)
				{
			    	scanf( "%d",&score[i]);
			    	all += score[i];
				}
		    	ave = all / 3.0;
		     	all = 0;
		    	strcpy(list[n].name, name);
		    	list[n].number = number;
			    list[n].ave = ave;
		    	for (i = 0; i < 3; i++)
				   list[n].score[i] = score[i];
		     	n++;
		    	printf("����1�����������2ֹͣ���\n");
		    	scanf("%d", &choice1);
			}
	}
	return n;
}
void query(student *list, int n)
{
	int choice;
	char name[8];
	int number,i;
	printf("����1��������������2��ѧ�Ų���\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("��������\n");
		scanf("%s", name);
		for(i = 0;i < n;i++)
			if (!strcmp(list[i].name, name))
			{
				printf("��ѯ�����\n");
				printf("name:%s number:%d score:%d %d %d ave:%lf\n",list[i].name, list[i].number, list[i].score[0], list[i].score[1], list[i].score[2],list[i].ave);
				system("pause");
				break;
			}
			if (i == n)
				printf("��ѯʧ��");
				system("pause");
	}
	else
	{
		printf("����ѧ��\n");
		scanf("%d", &number);
		for (i = 0; i < n; i++)
			if (list[i].number==number)
			{
				printf("��ѯ�����\n");
				printf("name:%s number:%d score:%d %d %d ave:%lf\n", list[i].name, list[i].number, list[i].score[0], list[i].score[1], list[i].score[2], list[i].ave);
				system("pause");
				break;
			}
		if (i == n)
		{
			printf("��ѯʧ��");
			system("pause");
		}
	}
}
void showall(student *list, int n)
{
	student temp;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
			if (list[j].ave < list[j + 1].ave)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
	}
	for(i = 0; i < n; i++)
		printf("name:%s number:%d score:%d %d %d ave:%lf\n", list[i].name, list[i].number, list[i].score[0], list[i].score[1], list[i].score[2], list[i].ave);
	system("pause");
}
int add(student *list, int n)
{
	student temp;
	int i, j;
	char name[8];
	int number;
	int score[3];
	double ave;
	int all = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
			if (list[j].ave < list[j + 1].ave)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}

	}
	n++;//Ϊ�˲���һ����ѧ��
	printf("����ѧ��\n");
	scanf("%d", &number);
	printf("��������\n");
	scanf("%s", name);
	printf("�������ųɼ�\n");
	for ( i = 0; i < 3; i++)
	{
		scanf("%d", &score[i]);
		all += score[i];
	}
	ave = all / 3.0;
	all = 0;
	strcpy(temp.name, name);
	temp.number = number;
	temp.ave = ave;
	for (i = 0; i < 3; i++)
		temp.score[i] = score[i];
	for (i = 0; i < n - 1; i++)//��Ӧn++
	{
		if (temp.ave > list[i].ave)
		{
			for (j = n - 2; j >= i; j--)
				list[j + 1] = list[j];
			list[i] = temp;
			for (i = 0; i < n; i++)
				printf("name:%s number:%d score:%d %d %d ave:%lf\n", list[i].name, list[i].number, list[i].score[0], list[i].score[1], list[i].score[2], list[i].ave);
			system("pause");
			return n;
		}
	}
	list[i] = temp;
	for (i = 0; i < n; i++)
		printf("name:%s number:%d score:%d %d %d ave:%lf\n", list[i].name, list[i].number, list[i].score[0], list[i].score[1], list[i].score[2], list[i].ave);
	system("pause");
	return n;
}
void write(student *list,int n)
{
	FILE *fp;
	int i,j;
	fp = fopen("score.txt", "w");
	if (fp == NULL)
		printf("open error");
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", list[i].number);
		fprintf(fp, "%s ", list[i].name);
		for (j = 0; j < 3; j++)
			fprintf(fp, "%d ", list[i].score[j]);
		fprintf(fp, "%lf", list[i].ave);
		fprintf(fp, "%c", '\n');
	}
	fclose(fp);
}
int main()
{
	FILE *fp;
	student list[100];
	int n=0,choice;
	char name[8];
	int number;
	int score[3];
	double ave=0;
	init();
	fp=fopen("score.txt", "r");
	while (!feof(fp))
	{
		int i;
		show();
		fscanf(fp, "%d", &number);
		fscanf(fp, "%s", name);
		for (i = 0; i < 3; i++)
			fscanf(fp, "%d", &score[i]);
		fscanf(fp, "%lf", &ave);
		strcpy(list[n].name, name);
		list[n].number = number;
		list[n].ave = ave;
		for (i = 0; i < 3; i++)
			list[n].score[i] = score[i];
		n++;
	}
	n--;
	fclose(fp);
	while (1)
	{

		
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
				n = putin(list,n);
				break;
		case 2:
			query(list,n);
			break;
		case 3:
			showall(list, n);
			break;
		case 4:
			n = add(list, n);
			break;
		case 5:
			write(list, n);
			printf("��лʹ��");
			system("pause");
			return 0;
		default:
			break;
		}
		system("cls");//����
	}
}
? 2018 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
Press h to open a hovercard with more details.