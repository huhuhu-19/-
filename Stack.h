#pragma once
/*栈*/
typedef int ElementType;
typedef struct SNode* Stack;

struct SNode {
	ElementType Data;
	Stack Next;
};


Stack CreateStack();  // 初始化链栈 
int IsEmpty(Stack S);  // 判断链栈是否为空 
void PushStack(Stack S, ElementType item);  // 入栈 
ElementType PopStack(Stack S);  // 出栈
ElementType GetTop(Stack S);//取栈顶元素

// 初始化 
Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// 判断是否为空 
int IsEmpty(Stack S) {
	return (S->Next == NULL);
}

// 入栈
void PushStack(Stack S, ElementType item) {
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面 
	tmp->Next = S->Next;
	S->Next = tmp;
}

// 出栈
ElementType PopStack(Stack S) {
	Stack First;
	ElementType TopVal;
	if (IsEmpty(S)) {
		printf("堆栈空");
		return 0;
	}
	else {
		First = S->Next;   // 出栈第一个元素在栈顶元素后面 
		S->Next = First->Next;  //把第一个元素从链栈删除 
		TopVal = First->Data;   // 取出被删除结点的值 
		free(First);  // 释放空间 
		return TopVal;
	}
}

ElementType GetTop(Stack S)
{
	return S->Next->Data;
}
