#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����Լ��༶ָ��Ĳ���  ���е�ָ��Ĳ�������4
int main5()
{
    int  * p;
    int ** pp;
    int *** ppp;
    printf("%p\t%p\n",p,p+1);
    printf("%p\t%p\n",pp,pp+1);
    printf("%p\t%p\n",ppp,ppp+1);
    return 0;
}

//��ʼ��һ��ָ��  Ҳ�з��ض���ָ��
void initPointer(char ** str)//��дchar* ����ָ�����Լ���*
{
    *str=(char*)malloc(100);
}

int main4()
{
    char * str=NULL;
    initPointer(&str);//��Ҫ�޸���������ݱ��봫��ַ
    strcpy(str,"china!");
    printf("%s\n",str);
    return 0;
}

//�ı�ָ��  n��ָ����Ըı�n-1�����е�ָ���ָ��
int main3()
{
    int a=100;
    int * b=&a;
    int **c = &b;//c=&b  *c=b=&a **c=*b=a
    int d = 200;
    printf("%d\n",*b);
    //ͨ��c���ı�b��ָ��
    *c=&d;
    printf("%d\n",*b);
}


//����ָ��
int main2()
{
    int a=100;
    int * b=&a;
    int **c = &b;//c=&b  *c=b=&a **c=*b=a
    printf("%d\n",a);
    *b=200;
    printf("%d\n",a);
    **c=300;
    printf("%d\n",a);
    return 0;
}

//ָ�������  1����ַ��������ʵ�Ǽ������ָ�����͵ĸ���  2��ת��Ϊ�����������Ǽ���������ֽ���
int main1(void)
{
    int a[10];
    printf("a = %p\n",a);
    printf("a+1 = %p\n",a+1);
    printf("&a[9] - &a[4] = %d\n",&a[9] - &a[4]);//5
    printf("(int)&a[9]-(int)&a[4] = %d\n",(int)&a[9] -(int)&a[4]);//ת��Ϊint���ǻ�������  ���Ǹ��˶��ٸ��ֽھ��Ƕ���   ����yinӦ����5*4=20
    return 0;
}

