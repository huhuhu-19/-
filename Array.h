#pragma once
//
// Created by 胡胡胡先生啦 on 2020/6/10.
//
#define maxsize 100
typedef int ElemType; //定义数据类型
typedef struct
{
	int i, j;  
	ElemType v; 
}Triple;    //三元组结构
typedef struct
{
	Triple data[maxsize];
	int pos[maxsize];
	int m, n, t;   //m->行数  n->列数  t->非零元
}TSMatrix;

TSMatrix M;

/*创建稀疏矩阵*/
void Creat_Array()
{
    int i = 0;
    printf("请输入稀疏矩阵的行数，列数，以及非0元素的个数：");
    scanf_s("%d %d %d", &M.m, &M.n, &M.t);
    for (i = 1; i <= M.t; i++)
    {
        printf("请输入第%d个非0元素的下标i,j以及值data:", i);
        scanf_s("%d" "%d" "%d", &M.data[i - 1].i, &M.data[i - 1].j, &M.data[i - 1].v);
    }
    return;
}
//输出存储的稀疏矩阵
void display_Array(TSMatrix M)
{
    for (int i = 1; i <= M.n; i++) {
        for (int j = 1; j <= M.m; j++) {
            int value = 0;
            for (int k = 0; k < M.t; k++) {
                if (i == M.data[k].i && j == M.data[k].j) {
                    printf("%d ", M.data[k].v);
                    value = 1;
                    break;
                }
            }
            if (value == 0)
                printf("0 ");
        }
        printf("\n");
    }
}
/*稀疏矩阵相乘*/
void MultTSMatrix()
{
	int k;
	int arow, p, q, ccol, t, tp;
	int row = 1;
	int a[100][100] = { 0 };
	int b[100][100] = { 0 };
	int c[100][100] = { 0 };
	TSMatrix A, B, C;
	printf("输入稀疏矩阵A的行数，列数和非零元个数：");
	scanf_s("%d %d %d", &A.m, &A.n, &A.t);
	for (k = 1; k <= A.t; k++)
	{
		printf("输入第%d个非0元素的行数，列数和值:", k);
		scanf_s("%d %d %d", &A.data[k].i, &A.data[k].j, &A.data[k].v);
	}
	for (k = 1; k <= A.t; k++)
	{
		while (row <= A.data[k].i)
		{
			A.pos[row++] = k;
		}
	}
	while (row <= A.m)
		A.pos[row++] = A.t + 1;
	printf("输入稀疏矩阵B的行数，列数和非零元个数：");
	scanf_s("%d %d %d", &B.m, &B.n, &B.t);
	for (k = 1; k <= B.t; k++)
	{
		printf("输入第%d个非0元素的行数，列数和值:", k);
		scanf_s("%d %d %d", &B.data[k].i, &B.data[k].j, &B.data[k].v);
	}
	row = 1;
	for (k = 1; k <= B.t; k++)
	{
		while (row <= B.data[k].i)
		{
			B.pos[row++] = k;
		}
	}
	while (row <= B.m)B.pos[row++] = B.t + 1;
	if (A.n != B.m)
	{
		printf("输入错误：A的列数不等于B的行数，请重新输入\n");
		return;
	}
	C.m = A.m;
	C.n = B.n;
	C.t = 0;
	if (A.t * B.t != 0)
	{
		for (arow = 1; arow <= A.m; ++arow)
		{
			int ctemp[maxsize] = { 0 };
			C.pos[arow] = C.t + 1;
			if (arow < A.m) { tp = A.pos[arow + 1]; }
			else { tp = A.t + 1; }
			for (p = A.pos[arow]; p < tp; ++p)
			{
				int brow = A.data[p].j;
				if (brow < B.m) { t = B.pos[brow + 1]; }
				else { t = B.t + 1; }
				for (q = B.pos[brow]; q < t; ++q)
				{
					ccol = B.data[q].j;
					ctemp[ccol] += A.data[p].v * B.data[q].v;
				}
			}
			for (ccol = 1; ccol <= C.n; ++ccol)
			{
				if (ctemp[ccol])
				{
					if (++C.t > maxsize)
						return;
					C.data[C.t].i = arow;
					C.data[C.t].j = ccol;
					C.data[C.t].v = ctemp[ccol];
				}
			}
		}
	}

	//输出矩阵A
	for (k = 1; k <= A.t; k++)
	{
		a[A.data[k].i][A.data[k].j] = A.data[k].v;
	}
	printf("A输入为：\n");
	for (k = 1; k <= A.m; k++)
	{
		int l;
		for (l = 1; l <= A.n; l++)
			printf("%d ", a[k][l]);
		printf("\n");
	}
	//输出矩阵B
	for (k = 1; k <= B.t; k++)
	{
		b[B.data[k].i][B.data[k].j] = B.data[k].v;
	}
	printf("B输入为：\n");
	for (k = 1; k <= B.m; k++)
	{
		int l;
		for (l = 1; l <= B.n; l++)
			printf("%d ", b[k][l]);
		printf("\n");
	}

	////输出矩阵C
	for (k = 1; k <= C.t; k++)
	{
		c[C.data[k].i][C.data[k].j] = C.data[k].v;
	}
	printf("乘法结果C为：\n");
	for (k = 1; k <= C.m; k++)
	{
		int l;
		for (l = 1; l <= C.n; l++)
			printf("%d ", c[k][l]);
		printf("\n");
	}
}