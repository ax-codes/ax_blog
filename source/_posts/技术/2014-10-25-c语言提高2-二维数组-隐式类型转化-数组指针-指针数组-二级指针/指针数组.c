#include <stdio.h>

void traveseArray(char ** array,int n)//array����һ��ʵ�ε����� ʵ���ǵ�ַ ���Ը��β�Ҳ�ǵ�ַ
{
    for(int i=0;i<n;i++)
        printf("%s\n",*(array+i));
}

//�����Ĵ���ָ������ķ���  �������ĩβ����NULL��Ϊ������ʶ
void traveseArray2(char ** array,int n)//array����һ��ʵ�ε����� ʵ���ǵ�ַ ���Ը��β�Ҳ�ǵ�ַ
{
     while(*array)
        printf("%s\n",*(array++));
}
int main(void)
{
    char * pArray[] = {"apple","pear","banana","orange","pineApple",NULL};
    traveseArray2(&pArray,5);//ָ������
    return 0;
}

