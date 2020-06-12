#pragma once
/*线性表*/
typedef int ElementType; // ElementType 可定义为任意类型
typedef struct LNode* List;

struct LNode {
	ElementType Data;   //数据域 
	List Next;   // 下一个链表的地址 
};

List L;
void CreateList(List* L, int n); //创建链表  
void SearchList(ElementType X, List L);  // 按值查找 
List InsertList(ElementType X, int i, List* L);  //将 X 插入到第 i-1(i>0) 个结点之后 
List DeleteList(int i, List* L); // 删除第 i(i>0) 个结点 
void ShowList(List L); // 输出链表元素 


// 随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） 
void CreateList(List* L, int n)
{
	List p;
	int i;
	srand(time(0));                         //初始化随机数种子
	*L = (List)malloc(sizeof(LNode));
	(*L)->Next = NULL;                      //先建立一个带头结点的单链表
	for (i = 0; i < n; i++)
	{
		p = (List)malloc(sizeof(LNode));    //生成新结点 
		p->Data = rand() % 100 + 1;             //随机生成100以内的数字
		p->Next = (*L)->Next;
		(*L)->Next = p;						//插入到表头
	}
}


// 按值查找  
void SearchList(ElementType X, List L) {
	List p = L->Next;
	int i = 1;
	while (p && p->Data != X)
	{
		p = p->Next;
		i++;
	}
	if (p->Data == X)
		printf("元素%d的位置为%d",X, i);// 找到了，返回 i
	else
		printf("没有这个元素");

}

/* 插入
1. 用 s 指向一个新的结点
2. 用 p 指向链表的第 i-1 个结点
3. s->Next = p->Next，将 s 的下一个结点指向 p 的下一个结点
4. p->Next = s，将 p 的下一结点改为 s   */
List InsertList(ElementType X, int i, List* L)
{
	int j;
	List p, s;
	p = *L;
	j = 1;
	while (p && j < i)     //寻找第i个结点 
	{
		p = p->Next;
		++j;
	}
	if (!p || j > i)
		printf("ERROR");   // 第i个元素不存在 
	s = (List)malloc(sizeof(LNode));  //  生成新结点(C语言标准函数) 
	s->Data = X;
	s->Next = p->Next;      // 将p的后继结点赋值给s的后继  
	p->Next = s;          // 将s赋值给p的后继 
	return *L;
}

/* 删除
1. 用 p 指向链表的第 i-1 个结点
2. 用 s 指向要被删除的的第 i 个结点
3. p->Next = s->Next，p 指针指向 s 后面
4. free(s)，释放空间
*/
List DeleteList(int i, List* L) {
	int j;
	List p, q;
	p = *L;
	j = 1;
	while (p->Next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->Next;
		++j;
	}
	if (!(p->Next) || j > i)
		printf("ERROR");           /* 第i个元素不存在 */
	q = p->Next;
	p->Next = q->Next;			/* 将q的后继赋值给p的后继 */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return *L;

}
	// 输出链表元素 
	void ShowList(List L)
	{
		List p = L->Next;
		printf("当前链表为：");
		while (p)
		{
			printf("%d  ", p->Data);
			p = p->Next;
		}
		printf("\n");
	}
