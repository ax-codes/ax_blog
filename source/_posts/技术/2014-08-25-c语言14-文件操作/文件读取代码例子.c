#include <stdio.h>


void myfgetc()
{
    //���ַ�
    /*
      1:�ȸ�ֵ�ٶ�ȡ  ��Ϊ�ļ�����λ���ȶ��Ż���λ�ģ���ʾ�Ѿ���ȡ���ˣ�����feof�Ǹ��ݱ�־λ�Ƿ���λ�ģ�����������Ҫ�ȶ�������feof���ж��Ƿ��ȡ���
   */
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff;
    //����Ķ�ȡ����  ����ɶ��һ����Ч��
    //    while(!feof(fp))//fgetc��fgets���Ƿ���
    //    {
    //    buff=fgetc(fp);
    //        printf("%c",buff);
    //    }

    //1����һ����֤�����ķ���
    //    while((buff=fgetc(fp))&&!feof(fp))//fgetc��fgets���Ƿ���
    //    {
    //        printf("%c",buff);
    //    }

    //2:�ڶ�����֤�����ķ���
    //    while((buff=fgetc(fp))!=EOF)//fgetc��fgets���Ƿ���
    //    {
    //        printf("%c",buff);
    //    }

    fclose(fp);
}

void myfgets()
{
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff[1024];
    while(fgets(buff,1024,fp)!=NULL) //�жϽ��������Ƿ�Ϊnull  ����'\0'
    {
        printf("%s",buff);
    }
    return 0;
}

void myfread()
{
    FILE * fp=fopen("1.txt","r+");
    if(!fp)
        return -1;
    char buff[1024];
    while(fread((void*)buff,1,1,fp)>0) //ע��ÿ�ζ�ȡ���ֽ�������������С��Ԫ����Ȼ���ĳ�ζ�ȡ��ʱ��û�ж����᷵��0 Ҳ��˵�����ٴ�ӡ
    {
        printf("%s",buff);
    }
}

int main(void)
{

    return 0;
}
