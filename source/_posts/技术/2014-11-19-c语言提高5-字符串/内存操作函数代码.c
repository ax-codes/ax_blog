#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h> 

int delChar(char * str,int n ,int  len)
{
	memmove(str+n,str+n+1,(len-(n+1))*sizeof(*str));//1��Ŀ��Դ  ��ʾ��Ҫ���Ƶ���   2������Դ����ʾ��Ҫ�����︴��  3�������ֽ�������ʾ��Ҫ����Դ���ݵ��ֽڸ���
	return len - 1;
}
 
//�ڴ�������������������ݵĽ�����ʶ �� ÿ�����������һ����������һ��length��ʾ��Ҫ�������ֽ��� ��ס  �ڴ�������������ֽ�Ϊ��λ��������
int main()
{
	//mempy 
	//int a[10] = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 }; //���������Ŀ���
	//int b[10];
	//memcpy(b, a, 10*sizeof(a[0]));//��ס �ڴ�������������ֽ�Ϊ��λ��
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n",b[i]);
	//}
	//char a[100] = "dfewfew\0fw"; //���������Ŀ���
	//char b[100];
	//memcpy(b, a,sizeof(a));//��ס �ڴ�������������ֽ�Ϊ��λ��   ���һὫ\0��Щ�����ַ������п���  
	//printf("%s\n", b);

	//memmove 
	//char a[100] = "1234567890"; //���������Ŀ���
	//int len = strlen(a);
	//int num = delChar(a,2,len);
	//printf("%s\n",a);

	//memcmp
	//	�Ƚ����οռ��ǰ n ���ֽڣ������߼���ͬ�� strcmp��
	//	memchr
	//	����һ�οռ��е�һ���ַ����������򷵻أ������ҵ��ַ���ָ�룬���ޣ�����

	//memset :��ʼ��һ�οռ��ڵ�����  ע����Щ�ڴ�������� ��������С��Ԫ�����ֽ�

	int arr[10];
	memset(arr, 1, sizeof(arr));//��ʾ��ÿһλ����Ϊ01   ���� //hex 01010101 -> dec 16843009
	for (int i = 0; i <10; i++)
	{
		printf("%d\n",*(arr+i));
	}
	return 0;
}
