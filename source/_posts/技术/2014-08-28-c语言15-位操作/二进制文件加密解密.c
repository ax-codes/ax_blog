#include <stdio.h>
#include <string.h>

void encrypt(char * ch1,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
         unsigned char ch=ch1[i];
         ch=ch<<1|ch>>7;//char  ��λ
         ch1[i]=ch;
    }
}

void decode(char * ch1,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
         unsigned char ch=ch1[i];
         ch=ch>>1|ch<<7;//char  ��λ
         ch1[i]=ch;
    }
}

//�����Ƽ����ļ�
int main(void)
{
    FILE * fpr=fopen("2.wmv","rb+");
    if(NULL==fpr)
        return -1;
    FILE * fpw=fopen("3.wmv","wb+");
    if(NULL==fpw)
        return -1;

    char buff[1024];
    int num=0;//read ����fread��ȡ�����ݵĳ���
    while(num=fread((void*)buff,sizeof(char),1,fpr)>0)
    {
        decode(buff,num);
        fwrite((void*)buff,num,1,fpw);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}

