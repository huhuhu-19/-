#pragma once
/* �õ��Ķ��нṹ�뺯��********************************** */
/* ѭ�����е�˳��洢�ṹ */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 9

typedef int Status;
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* ͷָ�� */
	int rear;		/* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
}Queue;

/* ��ʼ��һ���ն���Q */
Status InitQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}

/* ������δ��,�����Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(Queue* Q, int e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear] = e;			/* ��Ԫ��e��ֵ����β */
	Q->rear = (Q->rear + 1) % MAXSIZE;/* rearָ�������һλ��, */
								/* ���������ת������ͷ�� */
	return  OK;
}

/* �����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ */
Status DeQueue(Queue* Q, int* e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e = Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front = (Q->front + 1) % MAXSIZE;	/* frontָ�������һλ��, */
									/* ���������ת������ͷ�� */
	return  OK;
}