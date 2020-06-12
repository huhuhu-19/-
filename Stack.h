#pragma once
/*ջ*/
typedef int ElementType;
typedef struct SNode* Stack;

struct SNode {
	ElementType Data;
	Stack Next;
};


Stack CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack S);  // �ж���ջ�Ƿ�Ϊ�� 
void PushStack(Stack S, ElementType item);  // ��ջ 
ElementType PopStack(Stack S);  // ��ջ
ElementType GetTop(Stack S);//ȡջ��Ԫ��

// ��ʼ�� 
Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack S) {
	return (S->Next == NULL);
}

// ��ջ
void PushStack(Stack S, ElementType item) {
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = S->Next;
	S->Next = tmp;
}

// ��ջ
ElementType PopStack(Stack S) {
	Stack First;
	ElementType TopVal;
	if (IsEmpty(S)) {
		printf("��ջ��");
		return 0;
	}
	else {
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		free(First);  // �ͷſռ� 
		return TopVal;
	}
}

ElementType GetTop(Stack S)
{
	return S->Next->Data;
}
