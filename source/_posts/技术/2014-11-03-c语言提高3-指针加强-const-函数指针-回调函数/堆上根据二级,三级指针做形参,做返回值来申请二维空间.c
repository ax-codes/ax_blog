#include <stdlib.h>
#include <stdlib.h>

void   param2dPointer_3(int *** p,int size, int row, int line)
{
	*p = (void**)malloc(4*row);
	for (int i = 0; i < row; i++)
	{
		*(*p + i) = (void*)malloc(4 * line);
	}
}

//3:����ָ����������� ���ض�ά�ռ�
int main()
{
	//1:һ��ָ������ֵ���   ��Ϊ��һ��ָ��������ֵ ����ֻ�ܿ���ָ������  ���Ƿ��ػ��Ƿ���һά��  �������ǿ��Խ���Ϊָ������
	int row = 3;
	int line = 4;
	int ** p = NULL;
	param2dPointer_3(&p,sizeof(int),row, line);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			*(*(p + i) + j) = i + j;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d\t",*(*(p+i)+j));
		}
		putchar(10);
	}
	return 0;
}

//2:����ָ������ֵ���  ���ض�ά�ռ�
void ** param2dPointer_2(int size, int row, int line)
{
	void ** p = (void**)malloc(4*row);
	for (int i = 0; i < row; i++)
	{
		*(p+i) = (void*)malloc(4 * line);
	}
	return p;
}

int main2()
{
	//1:һ��ָ������ֵ���   ��Ϊ��һ��ָ��������ֵ ����ֻ�ܿ���ָ������  ���Ƿ��ػ��Ƿ���һά��  �������ǿ��Խ���Ϊָ������
	int row = 3;
	int line = 4;
	int ** arr = param2dPointer_2(sizeof(int),row,line);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< row; j++)
		{
			*(*(arr + i) + j) = i + j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< row; j++)
		{
			printf("%d\t", *(*(arr + i) + j));
		}
		putchar(10);
	}
	return 0;
}

//1:һ��ָ������ֵ���  ���ض�ά�ռ�
void * param2dPointer(int size,int row,int line)
{
	void * p = (void*)malloc(size*row*line);
	return p;
}

int main1()
{
	//1:һ��ָ������ֵ���   ��Ϊ��һ��ָ��������ֵ ����ֻ�ܿ���ָ������  ���Ƿ��ػ��Ƿ���һά��  �������ǿ��Խ���Ϊָ������
	int row = 3;
	int line = 4;
	int (*p)[4]=(int (*)[4])param2dPointer(sizeof(int),row,line);//int [4] *  ��ν��ָ������  ��ʵ���Ƕ�ά���߶�ά������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < line; j++)
		{
			*(*(p + i)+j)= i + j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j< line; j++)
		{
			printf("%d\t", *(*(p + i) + j));
		}
		putchar(10);
	}
	return 0;
}