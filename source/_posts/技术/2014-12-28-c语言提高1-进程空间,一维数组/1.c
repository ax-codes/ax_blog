#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void testPointer(int ** num)
{
	**num = 200;
}

int main1()
{
	int a = 100;
	int * b = &a;
	printf("%d\n", a);
	testPointer(&b);
	printf("%d\n", a);
	return 0;
}

char * createOnePointer()
{
	return  (char*)malloc(100);
}

//��������һ��ָ��
int main2()
{
	char * p = createOnePointer();
	if (NULL == p)
		exit(0);
	strcpy(p, "china  !");
	printf("%s", p);
	free(p);
	return -1;
}

void createTowPointer(char ** ch)//�õ�����p�ĵ�ַ
{
	//ch=&p  *ch = p
	*ch = (char*)malloc(100);
}

//��������һ����ָ��
int main3()
{
	char * p = NULL;
	createTowPointer(&p);
	strcpy(p, "china  !");
	printf("%s", p);
	return -1;
}

//���������������ӽ�һ���µ�����  ���ұ�������
int  main4()
{
	int a[3] = { 1, 3, 5 };
	int b[5] = { 2, 5, 6, 8, 10 };
	int c[8];

	int a_index = 0;
	int b_index = 0;
	int c_index = 0;
	while (a_index < 3 && b_index<5)
	{
		if (a[a_index]>b[b_index])
		{
			c[c_index] = b[b_index];
			c_index++;
			b_index++;
		}
		else if (a[a_index] < b[b_index])
		{
			c[c_index] = a[a_index];
			c_index++;
			a_index++;
		}
		else
		{
			c[c_index] = a[a_index];
			c_index++;
			a_index++;
			c[c_index] = b[b_index];
			c_index++;
			b_index++;
		}
	} 

	while (a_index < 3)
	{
		c[c_index++] = a[a_index++];
	}

	while (b_index < 5)
	{
		c[c_index++] = b[b_index++];
	}
	for (int i = 0; i < 8; i++)
		printf("%d\n", *(c + i));
}

//����ֵ
int main5()
{
	int arr[5] = { 2, 5, 6, 8222, 10 };
	//�����һ�������ֵ
	for (int i = 1; i < 5; i++)
	{
		if (arr[0] < arr[i])
			arr[0] = arr[i];
	}
	printf("��������ֵ�ǣ�%d\n",*(arr+0));
	return 0;
}

//�����ֵ
int main()
{
	int arr[5] = { 2, 5, 622, 2, 10 };

	//����arr[0]�������ֵ   arr[1]���Ǵδ�ֵ
	for (int i = 0; i < 5; i++)
	{
		if (arr[i]>arr[0])
		{
			arr[1] ^= arr[0];
			arr[0] ^= arr[1];
			arr[1] ^= arr[0];
			arr[i] ^= arr[0];
			arr[0] ^= arr[i];
			arr[i] ^= arr[0];
		}
		if (arr[i] > arr[1] && arr[i] < arr[0])
		{
			arr[1] ^= arr[i];
			arr[i] ^= arr[1];
			arr[1] ^= arr[i];
		}
	}
	printf("��������ֵ�ǣ�%d\n", *(arr + 0));
	printf("����Ĵδ�ֵ�ǣ�%d\n", *(arr + 1));
	return 0;
}

