#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[]="\0373xei";//037��һ���ֽ�  ���������ÿ���ַ���һ���ֽ�
    //char str1[]="\0383xei";//03��һ���ֽ� ���������ÿ���ַ���һ���ֽ�
    //char str2[]="\x2aet76543";//x2ae ��һ���ֽ�  ���������ÿ���ַ���һ���ֽ�
    char str2[]="\x3456aeccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//����ֻ��һ���ֽ���Ϊȫ������ʮ�����Ƶ�����
	printf("%d\n",strlen(str1));
    printf("%d\n",strlen(str2));
    return 0;
}

