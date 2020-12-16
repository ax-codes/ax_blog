#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int data;
	struct node * next;
	struct node * per;
}Node;


//β�巨
Node * createListTail()
{
	//����ͷ���
	Node * head = (Node*)malloc(sizeof(Node));
	Node *  cur = NULL;
	head->next = head;
	head->per = head;
	Node * tail = head;//ȷ��β�ڵ�
	int data;
	scanf("%d",&data);
	while (data)
	{
		cur = (Node*)malloc(sizeof(Node));
		cur->data = data;
		tail->next = cur;
		cur->per = tail;
		tail = cur;//��tail �ƶ������
		scanf("%d",&data);
	}
	//�ػ�
	cur->next = head;
	head->per = cur;

	return head;
}

//ͷ�巨
Node  * createListHead()
{
	Node * head = (Node*)malloc(sizeof(Node));
	head->next = head;
	head->per = head;
	int data;
	scanf("%d",&data);
	while (data)
	{
		Node * cur = (Node*)malloc(sizeof(Node));
		cur->data = data;
                cur->next = head->next;
		cur->per = head;
		head->next = cur;
		cur->next->per = cur;
		scanf("%d", &data);
	}
	return head;
}

//��������
void traveseList(Node *  head)
{
	Node * temp = head->next;//˫��������Ҫ��ͷ�ڵ�Ϊ��ʶ�ڵ�
	while (temp!=head)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

//��ȡ������
int lenList(Node * head)
{
	int len = 0;
	Node * temp = head->next;
	while (temp!=head)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

//��������Ԫ��
Node * searchNode(Node * head,int findData)
{
	Node * temp = head->next;
	while (temp!=head)
	{
		if (temp->data == findData)
			break;
		temp = temp->next;
	}
	return temp;
}

//˫���ѯ����
Node * search2Node(Node * head, int findData)
{
	Node * lowNode = head->next;
	Node * highNode = head->per;
	while (lowNode!=highNode)//��ȵ�ʱ���ʾ����
	{
		if (lowNode->data == findData)
			return lowNode;
		if (highNode->data == findData)
			return highNode;
		lowNode = lowNode->next;
		highNode = highNode->per;
	}
	return NULL;
}

//���ݵ�ַɾ��ָ��Ԫ��
void delNode(Node * head,Node * findNode)
{
	Node * temp = head->next;
	while (temp!=head)
	{
		if (temp == findNode)
		{
			temp->per->next = temp->next;
			temp->next->per = temp->per;
			free(findNode);
			break;
		}
		temp = temp->next;
	}
}

//����ֵ��������  ��������
void sortListD(Node * head)
{
	int len = lenList(head);
	for (int i = 0; i < len-1; i++)
	{
		Node * temp = head->next;//ð������ ���Ǵ�0��㿪ʼ
		for (int j = 0; j < len-1-i; j++)
		{
			if (temp->data>temp->next->data)
			{
				temp->data ^= temp->next->data;
				temp->next->data ^= temp->data;
				temp->data ^= temp->next->data;
			}
			temp = temp->next;
		} 
	}
}

//����ֵ��������  ����ָ��
void sortListP(Node * head)
{
	Node * temp = NULL;
	int len = lenList(head);
	for (int i = 0; i < len - 1; i++)
	{ 
		Node * sh = head;
		Node * p = sh->next;
		Node  * q = p->next;   
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p->data>q->data)//��ͼ����
			{
				sh->next = q;
				q->per = sh;
				p->next = q->next;
				q->next = p;
				p->per = q;
				q->next->per = p; 

				temp = p;
				p = q;
				q = temp;
			}
			sh = sh->next;
			q = q->next;
			p = p->next;
		}
	}
}

//�ͷ�����ռ�
void freeList(Node * head)
{
	Node  * temp = head->next;
	Node * pro = NULL;
	while (temp->next!=head)//�ж���һ���ڵ��Ƿ���ͷ���
	{
		pro = temp->next;
		free(temp);
		temp = pro;
	}
	free(head);
}

int main()
{
	//����ѭ�������ʱ��   ֱ�ӽ�ͷ����next��per��Ϊhead���� ��Ҫ��ΪNULL
	//Node * head = createListTail();
	Node * head = createListHead();
	//sortListD(head);
	//sortListP(head);
	//traveseList(head);
	//freeList(head);
	printf("����Ԫ��\n");
	//Node  * s_node = searchNode(head, 3);
	//if (s_node == head)
	//	printf("Ԫ�ز�����!\n"); 
	//printf("Ԫ�ش���!\n");
	Node  * s_node = search2Node(head, 3);
	if (s_node == NULL)
		printf("Ԫ�ز�����!\n"); 
	else
		printf("Ԫ�ش���!\n");
	
	delNode(head,s_node); 
	traveseList(head);
	return 0;
}
