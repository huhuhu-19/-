#pragma once
#include "Queue.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

typedef int Patharc[MAXVEX];    /* ���ڴ洢���·���±������ */
typedef int ShortPathTable[MAXVEX];/* ���ڴ洢���������·����Ȩֵ�� */

/* �ڽӾ���ṹ */
typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ���,�ɿ����߱� */
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */
}MGraph;

/* �ڽӱ�ṹ****************** */
typedef struct EdgeNode /* �߱��� */
{
	int adjvex;    /* �ڽӵ���,�洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode* next; /* ����,ָ����һ���ڽӵ� */
}EdgeNode;

typedef struct VertexNode /* ������� */
{
	int in;	/* ������� */
	char data; /* ������,�洢������Ϣ */
	EdgeNode* firstedge;/* �߱�ͷָ�� */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
}graphAdjList, * GraphAdjList;

/*��������ͼ*/
void CreateMGraph_01(MGraph* G)
{
	int i, j;

	G->numEdges = 15;
	G->numVertexes = 9;

	/* ���붥����Ϣ,��������� */
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';


	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;

	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	G->arc[3][4] = 1;
	G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;

	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;

}

/*��������ͼ*/
void CreateMGraph_02(MGraph* G)
{
	int i, j;

	G->numEdges = 15;   //ȷ�������������ߵ�����
	G->numVertexes = 9;

	/* ���붥����Ϣ,��������� */
	G->vexs[0] = 'A';    
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';


	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
    /*����ߵ���Ϣ*/
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	G->arc[1][2] = 1;
	G->arc[1][8] = 1;
	G->arc[1][6] = 1;

	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	G->arc[3][4] = 1;
	G->arc[3][7] = 1;
	G->arc[3][6] = 1;
	G->arc[3][8] = 1;

	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;

for (i = 0; i < G->numVertexes; i++)
{
	for (j = i; j < G->numVertexes; j++)
	{
		G->arc[j][i] = G->arc[i][j];
	}
}
}

/*����������*/
void CreateMGraph_03(MGraph* G)/* ����ͼ */
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges = 15;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;
}

void CreateMGraph_04(MGraph* G)
{
	int i, j;

	/* printf("����������Ͷ�����:"); */
	G->numEdges = 16;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 1;
	G->arc[0][2] = 5;
	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;
	G->arc[3][4] = 2;
	G->arc[3][6] = 3;
	G->arc[4][5] = 3;

	G->arc[4][6] = 6;
	G->arc[4][7] = 9;
	G->arc[5][7] = 5;
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;


	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

/* �����ڽӾ��󹹽��ڽӱ� */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* ���붥����Ϣ,��������� */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* ���߱���Ϊ�ձ� */
	}

	for (i = 0; i < G.numVertexes; i++) /* �����߱� */
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;					/* �ڽ����Ϊj */
				e->next = (*GL)->adjList[i].firstedge;	/* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
				(*GL)->adjList[i].firstedge = e;		/* ����ǰ�����ָ��ָ��e */
				(*GL)->adjList[j].in++;

			}
		}
	}

}

Boolean visited[MAXSIZE]; /* ���ʱ�־������ */

/* �ڽӱ��������ȵݹ��㷨 */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode* p;
	visited[i] = TRUE;
	printf("%c ", GL->adjList[i].data);/* ��ӡ����,Ҳ������������ */
	p = GL->adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(GL, p->adjvex);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
		p = p->next;
	}
}

/* �ڽӱ����ȱ������� */
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = FALSE; /* ��ʼ���ж���״̬����δ���ʹ�״̬ */
	for (i = 0; i < GL->numVertexes; i++)
		if (!visited[i]) /* ��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ�� */
			DFS(GL, i);
}

/* �ڽӱ�Ĺ�ȱ����㷨 */
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode* p;
	Queue Q;
	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for (i = 0; i < GL->numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", GL->adjList[i].data);/* ��ӡ����,Ҳ������������ */
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;	/* �ҵ���ǰ����ı߱�����ͷָ�� */
				while (p)
				{
					if (!visited[p->adjvex])	/* ���˶���δ������ */
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);	/* ���˶�������� */
					}
					p = p->next;	/* ָ��ָ����һ���ڽӵ� */
				}
			}
		}
	}
}

/* ����������GL�޻�·������������������в�����1�����л�·����0�� */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;  /* ����ջָ���±�  */
	int count = 0;/* ����ͳ���������ĸ���  */
	int* stack;	/* ��ջ�����Ϊ0�Ķ�����ջ  */
	stack = (int*)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
		if (0 == GL->adjList[i].in) /* �����Ϊ0�Ķ�����ջ */
			stack[++top] = i;
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%c -> ", GL->adjList[gettop].data);
		count++;        /* ���i�Ŷ��㣬������ */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))  /* ��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ */
				stack[++top] = k;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}

/* Prim�㷨������С������  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* ������ض����±� */
	int lowcost[MAXVEX];	/* ������ض����ߵ�Ȩֵ */
	lowcost[0] = 0;/* ��ʼ����һ��ȨֵΪ0����v0���������� */
			/* lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ����������� */
	adjvex[0] = 0;			/* ��ʼ����һ�������±�Ϊ0 */
	for (i = 1; i < G.numVertexes; i++)	/* ѭ�����±�Ϊ0���ȫ������ */
	{
		lowcost[i] = G.arc[0][i];	/* ��v0������֮�бߵ�Ȩֵ�������� */
		adjvex[i] = 0;					/* ��ʼ����Ϊv0���±� */
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;	/* ��ʼ����СȨֵΪ�ޣ� */
						/* ͨ������Ϊ�����ܵĴ�������32767��65535�� */
		j = 1; k = 0;
		while (j < G.numVertexes)	/* ѭ��ȫ������ */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)/* ���Ȩֵ��Ϊ0��ȨֵС��min */
			{
				min = lowcost[j];	/* ���õ�ǰȨֵ��Ϊ��Сֵ */
				k = j;			/* ����ǰ��Сֵ���±����k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* ��ӡ��ǰ�������Ȩֵ��С�ı� */
		lowcost[k] = 0;/* ����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ�������� */
		for (j = 1; j < G.numVertexes; j++)	/* ѭ�����ж��� */
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{/* ����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ */
				lowcost[j] = G.arc[k][j];/* ����С��Ȩֵ����lowcost��Ӧλ�� */
				adjvex[j] = k;				/* ���±�Ϊk�Ķ������adjvex */
			}
		}
	}
}

/*  Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */
/*  P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAXVEX];/* final[w]=1��ʾ��ö���v0��vw�����·�� */
	for (v = 0; v < G.numVertexes; v++)    /* ��ʼ������ */
	{
		final[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
		(*D)[v] = G.arc[v0][v];/* ����v0�������ߵĶ������Ȩֵ */
		(*P)[v] = -1;				/* ��ʼ��·������PΪ-1  */
	}

	(*D)[v0] = 0;  /* v0��v0·��Ϊ0 */
	final[v0] = 1;    /* v0��v0����Ҫ��·�� */
	/* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;    /* ��ǰ��֪��v0������������ */
		for (w = 0; w < G.numVertexes; w++) /* Ѱ����v0����Ķ��� */
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];    /* w������v0������� */
			}
		}
		final[k] = 1;    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
		for (w = 0; w < G.numVertexes; w++) /* ������ǰ���·�������� */
		{
			/* �������v�����·������������·���ĳ��ȶ̵Ļ� */
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{ /*  ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
				(*D)[w] = min + G.arc[k][w];  /* �޸ĵ�ǰ·������ */
				(*P)[w] = k;
			}
		}
	}
}

