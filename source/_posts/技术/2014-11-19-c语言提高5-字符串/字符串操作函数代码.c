#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int  myStrLen(const char * str)
{
	int len=0;
	while (*str++)
		len++;
	return len;
}

char * myStrcpy(char * str1,const char * str2)
{
	char * t = str1;
	while (*str1++ = *str2++);
	return t;
}

int myStrcmpy(const char * str1, const char * str2)
{
	for (; *str1&&*str2; str1++, str2++)
	{
		if (*str1 == *str2)
			continue;
		else
			return *str1 - *str2;
	}
	return *str1 - *str2;
}

char * myStrcat(char * str1, const char * str2)
{
	char * t = str1;
	while (*str1)
		str1++;
	while (*str1++ = *str2++);
	return t;
}

//��ָ֤�����ַ��Ƿ���ָ�����ַ�����
char * myStrchr(char * str,char item)
{
	while (*str)
	{
		if (*str == item)
			return str;
		str++;
	}
	return NULL;
}

//strchr �����ҵ����ַ��Ƿ����ָ�����ַ�����
int main1()
{
	char str[] = "china!"; 
	//char * newStr = myStrchr(str,'!');
	char * newStr = strchr(str,'c');
	if (newStr == NULL)
		printf("find none");
	else
		printf("find");
	return 0;
}

char * myStrstr_1(const char * str1, const char * str2)
{
	//����������ַ�����
	char * temp = str2;
	int len = 0;
	while (*str2)
	{
		str2++;
		len++;
	} 
	while (*str1)
	{
		if (0 == strncmp(str1, temp, len))
			return str1;
		*str1++;
	}
	return NULL;
}

char * myStrstr_2(const char * str1, const char * str2)
{
	//����������ַ�����
	char * temp = str2;
	int len = 0;
	while (*temp)
	{
		temp++;
		len++;
	}
	while (*str1)
	{
		for (int i = 0; *(str1 + i) == *(str2 + i); i++) //����������бȽ�  
		{
			if (*(str2 + i + 1) == '\0')
				return str1;
		} 
		str1++;
	}
	return NULL;
}

char * myStrstr(const char * str1, const char * str2)
{
	//����������ַ�����
	char * temp = str2;
	int len = 0;
	while (*temp)
	{
		temp++;
		len++;
	}
	//ֱ�ӻ�ȡstr1���׸���str2�׸�Ԫ����ȵ�Ԫ��
	for (; NULL != (str1 = strchr(str1, *str2)); str1++)
	{
		if (strncmp(str1, str2, len) == 0)
			return  str1;
	}
   	return NULL;
}

//strstr������һ���ַ��Ƿ���ָ���ַ�����
int main2()
{
	char str1[] = "abcd123456efg";
	char str2[] = "1234"; 
	//char * newStr = strstr(str1, str2);
	char * newStr = myStrstr(str1,str2);
	if (newStr == NULL)
		printf("find none");
	else
		printf("find");
	return 0;
}

//strctok : ����ָ��ֵ���и��ַ�
int main()
{
	char buff[] = "34567%0dhbdjdb1hw1%0dhinpwq%0dsdjwid";
	char * temp = strtok(buff, "%0d");
	while (temp)
	{
		printf("%s\n",temp);
		temp=strtok(NULL, "%0d");//strtok  ������ҵ��ַ��������ڣ���ʾ
	}
	return 0;
}