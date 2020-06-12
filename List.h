#pragma once
/*���Ա�*/
typedef int ElementType; // ElementType �ɶ���Ϊ��������
typedef struct LNode* List;

struct LNode {
	ElementType Data;   //������ 
	List Next;   // ��һ������ĵ�ַ 
};

List L;
void CreateList(List* L, int n); //��������  
void SearchList(ElementType X, List L);  // ��ֵ���� 
List InsertList(ElementType X, int i, List* L);  //�� X ���뵽�� i-1(i>0) �����֮�� 
List DeleteList(int i, List* L); // ɾ���� i(i>0) ����� 
void ShowList(List L); // �������Ԫ�� 


// �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� 
void CreateList(List* L, int n)
{
	List p;
	int i;
	srand(time(0));                         //��ʼ�����������
	*L = (List)malloc(sizeof(LNode));
	(*L)->Next = NULL;                      //�Ƚ���һ����ͷ���ĵ�����
	for (i = 0; i < n; i++)
	{
		p = (List)malloc(sizeof(LNode));    //�����½�� 
		p->Data = rand() % 100 + 1;             //�������100���ڵ�����
		p->Next = (*L)->Next;
		(*L)->Next = p;						//���뵽��ͷ
	}
}


// ��ֵ����  
void SearchList(ElementType X, List L) {
	List p = L->Next;
	int i = 1;
	while (p && p->Data != X)
	{
		p = p->Next;
		i++;
	}
	if (p->Data == X)
		printf("Ԫ��%d��λ��Ϊ%d",X, i);// �ҵ��ˣ����� i
	else
		printf("û�����Ԫ��");

}

/* ����
1. �� s ָ��һ���µĽ��
2. �� p ָ������ĵ� i-1 �����
3. s->Next = p->Next���� s ����һ�����ָ�� p ����һ�����
4. p->Next = s���� p ����һ����Ϊ s   */
List InsertList(ElementType X, int i, List* L)
{
	int j;
	List p, s;
	p = *L;
	j = 1;
	while (p && j < i)     //Ѱ�ҵ�i����� 
	{
		p = p->Next;
		++j;
	}
	if (!p || j > i)
		printf("ERROR");   // ��i��Ԫ�ز����� 
	s = (List)malloc(sizeof(LNode));  //  �����½��(C���Ա�׼����) 
	s->Data = X;
	s->Next = p->Next;      // ��p�ĺ�̽�㸳ֵ��s�ĺ��  
	p->Next = s;          // ��s��ֵ��p�ĺ�� 
	return *L;
}

/* ɾ��
1. �� p ָ������ĵ� i-1 �����
2. �� s ָ��Ҫ��ɾ���ĵĵ� i �����
3. p->Next = s->Next��p ָ��ָ�� s ����
4. free(s)���ͷſռ�
*/
List DeleteList(int i, List* L) {
	int j;
	List p, q;
	p = *L;
	j = 1;
	while (p->Next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->Next;
		++j;
	}
	if (!(p->Next) || j > i)
		printf("ERROR");           /* ��i��Ԫ�ز����� */
	q = p->Next;
	p->Next = q->Next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return *L;

}
	// �������Ԫ�� 
	void ShowList(List L)
	{
		List p = L->Next;
		printf("��ǰ����Ϊ��");
		while (p)
		{
			printf("%d  ", p->Data);
			p = p->Next;
		}
		printf("\n");
	}
