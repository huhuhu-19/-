#pragma once
#include "Queue.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef int Patharc[MAXVEX];    /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAXVEX];/* 用于存储到各点最短路径的权值和 */

/* 邻接矩阵结构 */
typedef struct
{
	VertexType vexs[MAXVEX]; /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵,可看作边表 */
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点 */
{
	int adjvex;    /* 邻接点域,存储该顶点对应的下标 */
	int weight;		/* 用于存储权值,对于非网图可以不需要 */
	struct EdgeNode* next; /* 链域,指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	char data; /* 顶点域,存储顶点信息 */
	EdgeNode* firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}graphAdjList, * GraphAdjList;

/*构造有向图*/
void CreateMGraph_01(MGraph* G)
{
	int i, j;

	G->numEdges = 15;
	G->numVertexes = 9;

	/* 读入顶点信息,建立顶点表 */
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';


	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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

/*构造无向图*/
void CreateMGraph_02(MGraph* G)
{
	int i, j;

	G->numEdges = 15;   //确定顶点数量，边的数量
	G->numVertexes = 9;

	/* 读入顶点信息,建立顶点表 */
	G->vexs[0] = 'A';    
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
	G->vexs[7] = 'H';
	G->vexs[8] = 'I';


	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
    /*读入边的信息*/
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

/*构造有向网*/
void CreateMGraph_03(MGraph* G)/* 构造图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 15;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = 16;
	G->numVertexes = 9;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
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

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* 读入顶点信息,建立顶点表 */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* 将边表置为空表 */
	}

	for (i = 0; i < G.numVertexes; i++) /* 建立边表 */
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;					/* 邻接序号为j */
				e->next = (*GL)->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				(*GL)->adjList[i].firstedge = e;		/* 将当前顶点的指针指向e */
				(*GL)->adjList[j].in++;

			}
		}
	}

}

Boolean visited[MAXSIZE]; /* 访问标志的数组 */

/* 邻接表的深度优先递归算法 */
void DFS(GraphAdjList GL, int i)
{
	EdgeNode* p;
	visited[i] = TRUE;
	printf("%c ", GL->adjList[i].data);/* 打印顶点,也可以其它操作 */
	p = GL->adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(GL, p->adjvex);/* 对为访问的邻接顶点递归调用 */
		p = p->next;
	}
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for (i = 0; i < GL->numVertexes; i++)
		visited[i] = FALSE; /* 初始所有顶点状态都是未访问过状态 */
	for (i = 0; i < GL->numVertexes; i++)
		if (!visited[i]) /* 对未访问过的顶点调用DFS,若是连通图,只会执行一次 */
			DFS(GL, i);
}

/* 邻接表的广度遍历算法 */
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
			printf("%c ", GL->adjList[i].data);/* 打印顶点,也可以其它操作 */
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;	/* 找到当前顶点的边表链表头指针 */
				while (p)
				{
					if (!visited[p->adjvex])	/* 若此顶点未被访问 */
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);	/* 将此顶点入队列 */
					}
					p = p->next;	/* 指针指向下一个邻接点 */
				}
			}
		}
	}
}

/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。 */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;  /* 用于栈指针下标  */
	int count = 0;/* 用于统计输出顶点的个数  */
	int* stack;	/* 建栈将入度为0的顶点入栈  */
	stack = (int*)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
		if (0 == GL->adjList[i].in) /* 将入度为0的顶点入栈 */
			stack[++top] = i;
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%c -> ", GL->adjList[gettop].data);
		count++;        /* 输出i号顶点，并计数 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))  /* 将i号顶点的邻接点的入度减1，如果减1后为0，则入栈 */
				stack[++top] = k;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}

/* Prim算法生成最小生成树  */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		/* 保存相关顶点下标 */
	int lowcost[MAXVEX];	/* 保存相关顶点间边的权值 */
	lowcost[0] = 0;/* 初始化第一个权值为0，即v0加入生成树 */
			/* lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */
	adjvex[0] = 0;			/* 初始化第一个顶点下标为0 */
	for (i = 1; i < G.numVertexes; i++)	/* 循环除下标为0外的全部顶点 */
	{
		lowcost[i] = G.arc[0][i];	/* 将v0顶点与之有边的权值存入数组 */
		adjvex[i] = 0;					/* 初始化都为v0的下标 */
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;	/* 初始化最小权值为∞， */
						/* 通常设置为不可能的大数字如32767、65535等 */
		j = 1; k = 0;
		while (j < G.numVertexes)	/* 循环全部顶点 */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)/* 如果权值不为0且权值小于min */
			{
				min = lowcost[j];	/* 则让当前权值成为最小值 */
				k = j;			/* 将当前最小值的下标存入k */
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);/* 打印当前顶点边中权值最小的边 */
		lowcost[k] = 0;/* 将当前顶点的权值设置为0,表示此顶点已经完成任务 */
		for (j = 1; j < G.numVertexes; j++)	/* 循环所有顶点 */
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{/* 如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */
				lowcost[j] = G.arc[k][j];/* 将较小的权值存入lowcost相应位置 */
				adjvex[j] = k;				/* 将下标为k的顶点存入adjvex */
			}
		}
	}
}

/*  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */
/*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAXVEX];/* final[w]=1表示求得顶点v0至vw的最短路径 */
	for (v = 0; v < G.numVertexes; v++)    /* 初始化数据 */
	{
		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
		(*D)[v] = G.arc[v0][v];/* 将与v0点有连线的顶点加上权值 */
		(*P)[v] = -1;				/* 初始化路径数组P为-1  */
	}

	(*D)[v0] = 0;  /* v0至v0路径为0 */
	final[v0] = 1;    /* v0至v0不需要求路径 */
	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;    /* 当前所知离v0顶点的最近距离 */
		for (w = 0; w < G.numVertexes; w++) /* 寻找离v0最近的顶点 */
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];    /* w顶点离v0顶点更近 */
			}
		}
		final[k] = 1;    /* 将目前找到的最近的顶点置为1 */
		for (w = 0; w < G.numVertexes; w++) /* 修正当前最短路径及距离 */
		{
			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w];  /* 修改当前路径长度 */
				(*P)[w] = k;
			}
		}
	}
}

