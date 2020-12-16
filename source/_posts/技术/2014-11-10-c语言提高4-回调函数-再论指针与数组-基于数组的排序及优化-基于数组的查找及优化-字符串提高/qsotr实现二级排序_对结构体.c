#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[30];
	float score;
}Stu;
 
int callBackStuSort(void * stu1, void * stu2)//������βζ���void*��   ������Ҫ����ת��Ϊ������Ҫ������
{
	if (strcmp((*(Stu*)stu1).name, (*(Stu*)stu2).name) > 0)
		return 1;
	else if (strcmp((*(Stu*)stu1).name, (*(Stu*)stu2).name) < 0)
	{
		if ((*(Stu*)stu1).score>(*(Stu*)stu1).score)
			return 1;
		else if ((*(Stu*)stu1).score < (*(Stu*)stu1).score)
			return -1;
	}
}
 
//�Խṹ�����ݽ��ж�������
int main()
{
	Stu  stu[] = { { "aaa", 23.5 }, { "xxx", 45.6 }, { "bbb", 89 }, { "xxx", 23.4 }, { "yyy", 100 } };
	qsort(stu, sizeof(stu) / sizeof(stu[0]), sizeof(stu), callBackStuSort);//��һ����Ҫ����Ķ���  �ڶ�����Χ  ����������  ���ĸ��ص����� 
	for (int i = 0; i < 5; i++)
	{
		printf("name=%s\score=%f\n", stu[i].name, stu[i].score );
	}
	return 0;
}

int callBackFunc1(void * pa, void * pb)  //�����Ĳ�����char** ����������char* ����qsortȡ����ȡ���Ǳ������ݵĵ�ַ ����������������char**
{ 
	return strcmp(*(char**)pa , *(char**)pb)>0 ? 1 : -1;//��Ҫת��Ϊ
}

//�Լ�ʵ�ֵĶ�ָ�������������deep����
void myStrSort(char ** strArr, int len)//����ָ���ö���ָ�����
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (callBackFunc1(*(strArr + j), *(strArr + j + 1))>0)
			{
				 //ָ�벻��������
				char*temp = *(strArr + j);
				*(strArr + j) = *(strArr + j + 1);//ֱ�Ӹı�����ĵ�ַ   �ַ������׵�ַ�����ƶ�  ����*(strArr+j)����arr[0] ���Ǳ�����arr[0]�ĵ�ַ�Ŀռ�
				*(strArr + j + 1) = temp;
			}
		}
	}
}

//��ָ�������������
int main2()
{
	char * arr[6] = {"apple","micsoft","goole","taobao","jindon","baidu"};
	myStrSort(arr, 6);
	//qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), callBackFunc1);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s\n", *(arr + i));
	}
	return 0;
}

int callBackFunc(void * pa,void * pb)//qsort�����������&int  
{
	return *((int*)pa) < *((int*)pb) ? 1 : -1;
}

int main1()
{
	int arr[10] = {9,2,4,5,3,2,4,4,6,7};
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), callBackFunc);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", *(arr + i));
	}
	return 0;
}