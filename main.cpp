#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <io.h> 
#include <math.h> 
#include"List.h"
#include"Stack.h"
#include"BinTree.h"
#include"Graph.h"
#include "Array.h"
#include "stack_application.h"
#include"book.h"
void ShowMainMenu()
{
	printf("\n");
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  数组的基本操作及应用                         *\n");
	printf("* 4  树的基本操作及应用                           *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}

void LinkListModule() {

	int choice, n, i;
	ElementType X;
	do {
		printf("\n");
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  显示                                         *\n");
		printf("* 6  通讯录(应用)                                 *\n");
		printf("* 7  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择:");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("--------创建链表-------\n");
			printf("请输入要创建的元素个数:");
			scanf_s("%d", &n);
			CreateList(&L, n);
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("请输入要插入的元素和位置:");
			scanf_s("%d %d", &X, &i);
			L = InsertList(X, i, &L); break;
		case 3:
			printf("--------删除元素-------\n");
			printf("请输入要删除元素的位置:");
			scanf_s("%d", &i);
			L = DeleteList(i, &L); break;
		case 4:
			printf("--------查找元素-------\n");
			printf("请输入要查找的元素:");
			scanf_s("%d", &X);
			SearchList(X, L); break;
		case 5:
			printf("--------显示链表-------\n");
			ShowList(L); break;
		case 6:
			printf("--------通讯录---------\n");
			book();
			break;
		case 7: break;
		default:
			printf("ERROR!"); break;
		}
	} while (choice != 7);
}

void StackModule() {
	int choice;
	ElementType X;
	Stack S = CreateStack();
	do {
		printf("\n");
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  表达式求解（应用）                           *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("--------进栈-------\n");
			printf("请输入要进栈的元素：");
			scanf_s("%d", &X);
			PushStack(S, X); break;
		case 2:
			printf("--------出栈-------\n");
			PopStack(S);
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			printf("栈顶元素为:%d", GetTop(S)); break;
		case 4:
			printf("--------表达式求值-------\n"); 
			run();
			break;
		case 5:
			break;
		default:
			printf("ERROR!"); break;
		}



	} while (choice != 5);
}


void ArrayModule() {
	int choice;
	do {
		printf("\n");
		printf("*************稀疏矩阵的压缩存储及应用**************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  显示                                         *\n");
		printf("* 3  矩阵乘法(应用)                               *\n");
		printf("* 4  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("---------创建-------\n"); 
			Creat_Array();
			break;
		case 2:
			printf("---------显示-------\n"); 
			display_Array(M);
			break;
		case 3:
			printf("---------矩阵乘法-------\n");
			MultTSMatrix();
			break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (choice != 4);
}

void BiTreeModule() {
	int choice;
	int count = 0;
	BiTree BT=NULL ;
	ElType data ;
	do {
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建二叉树                                   *\n");
		printf("* 2  遍历二叉树（先/中/后）                       *\n");
		printf("* 3  计算树的深度                                 *\n");
		printf("* 4  计算叶子结点个数                             *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟                                     *\n");
		printf("* 7  Huffman编码（应用）                          *\n");
		printf("* 8  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择:");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("---------创建二叉树--------\n");
			printf("请按前序输入二叉树(如:'ABDH  I  EJ   CF  G  ')\n");
			CreateBiTree(&BT); /* 按前序产生二叉树 */
			break;
		case 2:
			printf("---------遍历二叉树-------\n");
			printf("先序遍历");
			PreOrder(BT);
			printf("\n");
			printf("中序遍历");
			InOrder(BT);
			printf("\n");
			printf("后序遍历");
			PostOrder(BT);
			printf("\n");
			break;
		case 3:
			printf("---------计算树的深度------\n");
			printf("二叉树的深度为%d", Depth(BT)-1);
			break;
		case 4:
			printf("---------计算叶子节点个数-------\n");
			printf("叶子结点个数为:%d",CountLeaf(&BT,count));
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("请输入要查找的元素:");
			fflush(stdin);  //清空缓冲区 
			getchar();
			scanf_s("%c", &data);
			findfather(BT, data);
			break;
		case 6:
			printf("---------查找兄弟-------\n");
			printf("请输入要查找的元素:");
			fflush(stdin);  //清空缓冲区 
			getchar();
			scanf_s("%c", &data);
			BiTreefindBorther(BT, data);
			break;
		case 7:
			printf("---------Huffman编码-------\n"); break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (choice != 8);
}

void GraphModule() {
	int choice;
	MGraph G;
	GraphAdjList GL = NULL;
	int result, i, j;
	int v0 = 0;
	do {
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建无向图                                   *\n");
		printf("* 2  创建无向网                                   *\n");
		printf("* 3  创建有向图                                   *\n");
		printf("* 4  创建有向网                                   *\n");
		printf("* 5  遍历                                         *\n");
		printf("* 6  拓扑排序                                     *\n");
		printf("* 7  最小生成树(应用)                             *\n");
		printf("* 8  最短路径(应用)                               *\n");
		printf("* 9  关键路径(应用)                               *\n");
		printf("* 10 退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("---------创建无向图-------\n");
			CreateMGraph_02(&G);
			break;
		case 2:
			printf("---------创建无向网-------\n");
			CreateMGraph_04(&G);
			break;
		case 3:
			printf("---------创建有向图-------\n");
			CreateMGraph_01(&G);
			break;
		case 4:
			CreateMGraph_01(&G);
			printf("---------创建有向网-------\n");
			break;
		case 5:
			printf("---------遍历-------\n");
			CreateALGraph(G, &GL);
			printf("深度优先遍历:");
			DFSTraverse(GL);
			printf("\n广度优先遍历:");
			BFSTraverse(GL);
			break;
		case 6:
			printf("---------拓扑排序-------\n");
			printf("拓扑排序序列为");
			CreateALGraph(G, &GL);
			result = TopologicalSort(GL);
			printf("result:%d", result);
			break;
		case 7:
			printf("---------最小生成树-------\n");
			MiniSpanTree_Prim(G);
			break;
		case 8:
			printf("---------最短路径--------\n");
			Patharc P;
			ShortPathTable D;
			ShortestPath_Dijkstra(G, v0, &P, &D);
			printf("最短路径倒序如下:\n");
			for (i = 1; i < G.numVertexes; ++i)
			{
				printf("v%d - v%d : ", v0, i);
				j = i;
				while (P[j] != -1)
				{
					printf("%d ", P[j]);
					j = P[j];
				}
				printf("\n");
			}
			printf("\n源点到各节点路径长度为:\n");
			for (i = 1; i < G.numVertexes; ++i)
				printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
			break;
		case 9:
			printf("---------最短路径-------\n"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (choice != 10);
}

int  main() {
	int choice;
	do {
		ShowMainMenu();
		printf("请选择:");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:LinkListModule(); break;
		case 2:StackModule(); break;
		case 3:ArrayModule(); break;
		case 4:BiTreeModule(); break;
		case 5:GraphModule(); break;
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (choice != 6);
}
