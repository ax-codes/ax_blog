#include <stdio.h>



//int(*arr)[4]������  ��������һά����Ӧ���� int [4] * arr �� ��  ����  int [4] * arr=>int * arr[4]��ָ�����飩=>int(*arr)[4]������ָ�룩
void deliver2DArr(int (*arr) [4],int n)//
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",*(*(arr+i)+j));//*(*(array+i)+j)����ȡ���� *(array+i) =array[i] ��ȡ����
        }
        putchar(10);
    }
}

//����ά������Ϊ��������ά���ı����Ǹ�����ָ�룬���Խ���ά������Ϊ�������ݵ��β�ҲӦ���Ǹ�����ָ������
int main5()
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};//
    deliver2DArr(array,3);//��ά����������һ������ָ��  ֻ����������  int [4]  �������һ��һά���� int arr[4] ����int * ��4
    return 0;
}


//������ά����ķ���
int main4()
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",*(*(array+i)+j));//*(*(array+i)+j)����ȡ���� *(array+i) =array[i] ��ȡ����
        }
        putchar(10);
    }
    return 0;
}

//��һά����ķ�ʽ�����ʶ�ά����  ��Ϊ�ڴ�Ĵ洢���������Ե�
int main3(void)
{
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    int * p=(int*)array;//array��ʾ���������Ԫ�ص��׵�ַ
    for(int i=0;i<12;i++)
        printf("%d\n",*(p+i));
    return 0;
}

int main2(void)
{
    //    int array[10]={1,2,3,4,5,5,6,6,4,5};
    //    printf("&array=%p\n",&array);//����
    //    printf("&array+1=%p\n",&array+1);
    //    printf("array=%p\n",array);//һά������  ������int  ��һ�ӵ���int
    //    printf("array+1=%p\n",array+1);
    //    printf("&array[0]=%p\n",&array[0]);//& �� []�պõ���  ����&array[0]=array ����������int ���Լ�һ�ӵ���int����
    //    printf("&array[0]+1=%p\n",&array[0]+1);


    //int [4] array[3]  ���е��������Ӽ�������һά�����������
    int array[3][4]={1,2,3,4,5,5,6,6,4,5,6,7,8,9};
    printf("&array=%p\n",&array);//������
    printf("&array+1=%p\n",&array+1);

    printf("array=%p\n",array);//һ��һά������   ������int[4] ���Լ�һ�ӵ���int[4]
    printf("array+1=%p\n",array+1);

    printf("array[0]=%p\n",array[0]);//һ��һά������  ������int  ���Լ�һ�ӵ���int
    printf("array[0]+1=%p\n",array[0]+1);
    return 0;
}

int main1(void)
{
    int array[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    printf("*(*(&array[0]+1))= %d\n",*(*(&array[0]+1)));//array[0]�൱���Ǹ���ά����ĵ�һ��������  &array��������������һ������ָ��  Ȼ������ָ��Ӽ��ӵ�������   ������ָ������þ���һ��һάָ��  Ȼ���ٶ�һάָ����н����þ���ȡֵ




    printf("*(array[0]+1) = %d\n",*(array[0]+1));//array[0][0]��ָ���������int���Լ���4
    printf("*(array[0]+1) = %d\n",array[0][1]);//2
    //��� array ���ȵ� array[0]
    printf("*array = %p\n",*array);//array = &array[0] *&array[0]����һ��һάָ��  һάָ���һ
    printf("*array + 1 = %p\n",*array + 1);//�ӵ���int���ʹ�С  һάָ��
    printf("array[0] + 1 = %p\n",array[0] +1);//arrar[0]=&array[0][0] �Ǹ�����ָ��  ������int
    return 0;
}

