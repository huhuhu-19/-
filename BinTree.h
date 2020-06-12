#pragma once
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char ElType;
typedef struct BiNode* BiTree; 
int flag = 1;
struct BiNode	/* 二叉线索存储结点结构 */
{
	ElType data;	/* 结点数据 */
	struct BiNode* Left, * Right;	/* 左右孩子指针 */		/* 左右标志 */
} ;

void CreateBiTree(BiTree* BT)
{
	ElType ch;
	scanf_s("%c", &ch);
	if (ch == ' ')
		*BT = NULL;                //如果数据域为‘#’则让该指针为NULL
	else
	{
		*BT = (BiTree)malloc(sizeof(struct BiNode)); //动态创建内存结点空间
		if (!*BT)               //如果结点为空，退出
			exit(0);
		(*BT)->data = ch;
		CreateBiTree(&(*BT)->Left);  //创建左子树
		CreateBiTree(&(*BT)->Right);  //创建右子树
	}
}

//前序遍历
void PreOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	printf("%c", BT->data);  //显示节点数据
	PreOrder(BT->Left);  //遍历左子树
	PreOrder(BT->Right); //遍历右子树
}
//中序遍历
void InOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	InOrder(BT->Left);
	printf("%c", BT->data);
	InOrder(BT->Right);
}

//后序遍历
void PostOrder(BiTree BT)
{
	if (BT == NULL)
		return;
	PostOrder(BT->Left);
	PostOrder(BT->Right);
	printf("%c", BT->data);

}
//二叉树的深度
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

/*二叉树叶子结点个数*/
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

//递归实现查找双亲结点 
void  Find_Father(BiTree T, ElType data)
{
	if (T == NULL)
		return;
	if (T->Left != NULL)//当左孩子存在的时候才进行判断，否则程序出错
	{
		if (T->Left->data == data)
		{
			printf("该节点的父结点是:%c", T->data);
			flag = 1;//全局变量设置了一个标志flag=false，如果找到父结点，则flag赋值为true
		}
	}
	if (T->Right != NULL)//如左子树所示
	{
		if (T->Right->data == data)
		{
			printf("该节点的父结点是:%c", T->data);
			flag = 1;
		}

	}
	Find_Father(T->Left, data);
	Find_Father(T->Right, data);
}

void findfather(BiTree T, ElType data)
{
	Find_Father(T, data);//执行递归函数
	if (flag == 0)
	{
		printf("你搜索的结点为根节点或你搜索的结点在该二叉树中不存在");
	}
}
//查找兄弟
void BiTreefindBorther(BiTree T, ElType e)
{
	if (T == NULL)return;
	if (T->Left != NULL)
	{
		if (T->Left->data == e)
			printf("该结点的兄弟结点是:%c", T->Right->data);
	}
	if (T->Right != NULL)
	{
		if (T->Right->data == e)
			printf("该结点的兄弟结点是:%c", T->Left->data);
	}
	BiTreefindBorther(T->Left, e);
	BiTreefindBorther(T->Right, e);
}