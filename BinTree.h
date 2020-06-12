#pragma once
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef char ElType;
typedef struct BiNode* BiTree; 
int flag = 1;
struct BiNode	/* ���������洢���ṹ */
{
	ElType data;	/* ������� */
	struct BiNode* Left, * Right;	/* ���Һ���ָ�� */		/* ���ұ�־ */
} ;

void CreateBiTree(BiTree* BT)
{
	ElType ch;
	scanf_s("%c", &ch);
	if (ch == ' ')
		*BT = NULL;                //���������Ϊ��#�����ø�ָ��ΪNULL
	else
	{
		*BT = (BiTree)malloc(sizeof(struct BiNode)); //��̬�����ڴ���ռ�
		if (!*BT)               //������Ϊ�գ��˳�
			exit(0);
		(*BT)->data = ch;
		CreateBiTree(&(*BT)->Left);  //����������
		CreateBiTree(&(*BT)->Right);  //����������
	}
}

//ǰ�����
void PreOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	printf("%c", BT->data);  //��ʾ�ڵ�����
	PreOrder(BT->Left);  //����������
	PreOrder(BT->Right); //����������
}
//�������
void InOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	InOrder(BT->Left);
	printf("%c", BT->data);
	InOrder(BT->Right);
}

//�������
void PostOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	PostOrder(BT->Left);
	PostOrder(BT->Right);
	printf("%c", BT->data);

}
//�����������
int Depth(BiTree BT)
{
	int i, j;
	if (!BT)
		return 0;
	if (BT->Left)
		i = Depth(BT->Left);
	else
		i = 0;
	if (BT->Right)
		j = Depth(BT->Right);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}

/*������Ҷ�ӽ�����*/
int CountLeaf(BiTree* BT, int count)
{
	if ((*BT) != NULL)
	{
		if ((*BT)->Left == NULL && (*BT)->Right == NULL)
			count++;
		count = CountLeaf(&(*BT)->Left, count);
		count = CountLeaf(&(*BT)->Right, count);
	}
	return count;
}

//�ݹ�ʵ�ֲ���˫�׽�� 
void  Find_Father(BiTree T, ElType data)
{
	if (T == NULL)
		return;
	if (T->Left != NULL)//�����Ӵ��ڵ�ʱ��Ž����жϣ�����������
	{
		if (T->Left->data == data)
		{
			printf("�ýڵ�ĸ������:%c", T->data);
			flag = 1;//ȫ�ֱ���������һ����־flag=false������ҵ�����㣬��flag��ֵΪtrue
		}
	}
	if (T->Right != NULL)//����������ʾ
	{
		if (T->Right->data == data)
		{
			printf("�ýڵ�ĸ������:%c", T->data);
			flag = 1;
		}

	}
	Find_Father(T->Left, data);
	Find_Father(T->Right, data);
}

void findfather(BiTree T, ElType data)
{
	Find_Father(T, data);//ִ�еݹ麯��
	if (flag == 0)
	{
		printf("�������Ľ��Ϊ���ڵ���������Ľ���ڸö������в�����");
	}
}
//�����ֵ�
void BiTreefindBorther(BiTree T, ElType e)
{
	if (T == NULL)return;
	if (T->Left != NULL)
	{
		if (T->Left->data == e)
			printf("�ý����ֵܽ����:%c", T->Right->data);
	}
	if (T->Right != NULL)
	{
		if (T->Right->data == e)
			printf("�ý����ֵܽ����:%c", T->Left->data);
	}
	BiTreefindBorther(T->Left, e);
	BiTreefindBorther(T->Right, e);
}