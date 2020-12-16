#include <stdlib.h>
#include <stdio.h>


//�����������  ����ȷ��һ������λ  Ȼ��ȷ���λ��ķ��ұ�   �ȷ���λС�ķ����
void quickSort(int * p, int low, int high)
{
	if (low < high)//����ݹ�Ľ�����ʶ
	{
		int flag = p[low];
		int  l = low;
		int h = high;
		while (l<h)
		{
			//���ұ߿�ʼ�Ƚ� ��Ϊ��ߵĿ�ͷλ�Ѿ�ȷ��Ϊ��ʶλ
			while (flag<=p[h]&&l<h)
				h--;
			p[l] = p[h];//���ȷ���λС�ķŵ�����λ
			while (flag >= p[l] && l < h)
				l++;
			p[h] = p[l];
		}
		p[l] = flag;//������λ���ݷŵ����ȷ�ϵ�λ��
		//���ƶ�
		quickSort(p, low, h-1);
		quickSort(p, l+1, high);//����
	}
}
 
//1��ѡ������ ������  :ÿ��Ԫ�ظ���������еıȽ�
void xzSort(int * arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i]>arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}

//2��ѡ�������Ż���    �ȶ�����  ԭ�����ȼ�¼���ѭ���±�  ��������ı� ��ȡ��������Сֵ   �������idx�����仯����н���  ��֮����
void xzSortS(int * arr, int len)  
{
	for (int i = 0; i < len - 1; i++)
	{
		int idx = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[idx]>arr[j])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			arr[i] ^= arr[idx];
			arr[idx] ^= arr[i];
			arr[i] ^= arr[idx];
		}
	}
}

//2��ð������ ������   
void mpSort(int * arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
			}
		}
	}
}

//2��ð������ �Ż���  : 
void mpSortS(int * arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				flag = 1;
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
			}
		}
		if (!flag)//���flagû�б仯 ˵�������Ѿ��������  �����ٱ��� ֱ���˳�  
			break;
	}
}


int main()
{
	//printf("%d\n",sizeof("8822228"));
	int arr[10] = {1,2,3,33,43,1,0,3,44,5};
	//xzSort(arr,10);
	//xzSortS(arr,10);
	//mpSort(arr,10);
	mpSortS(arr,10);
	//quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}