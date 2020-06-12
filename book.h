#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 1
#define F -1
#define _CRT_SECURE_NO_WARNINGS
typedef int Boolean;
typedef struct Node* node;

void id_order(node head);
Boolean init(node* head);
int length(node head);
void print(node head);
Boolean insert_tail(node head); //尾插法创建链表
Boolean delete_id(node head); //通过序号删除
void delete_name(node head);   //通过名字删除
void delete_num(node head);    //通过学号删除
Boolean update_id(node head);
Boolean update_name(node head);
Boolean update_num(node head);
Boolean query_id(node head);
void query_name(node head);
void query_num(node head);

void bubblesort_num(node head);
void quicksort_name(node head, int left, int right);
node unit_index(node head, int index);

/*结点类型*/
struct Node
{
    int id; //学生序号
    char name[20]; //姓名
    char num[12]; //学号
    char addr[20];//家庭住址
    node next; 
};


void book()
{
    int flag;  //通过添加标志决定是否退出内层选择
    node head;
    init(&head);


    while (1)
    {
        printf("******************************\n");
        printf("--MENU--\n");
        printf("1.INSERT\n2.DELETE\n3.UPDATE\n4.QUERY\n5.PRINT\n");
        int key;
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            insert_tail(head);
            break;
        case 2:
            flag = 1;
            while (flag)
            {
                printf("******************************\n");
                printf("--DELETE--\n");
                printf("1.by ID\n2.by_NAME\n3.by_NUMBER\n0.BACK\n");
                scanf("%d", &key);
                switch (key)
                {
                case 0:
                    flag = 0;  //标志为0退出循环
                    break;
                case 1:
                    delete_id(head);
                    break;
                case 2:
                    delete_name(head);
                    break;
                case 3:
                    delete_num(head);
                    break;
                default:
                    printf("(ERROR)\n");
                    break;
                }
            }
            break;
        case 3:
            flag = 1;
            while (flag)
            {
                printf("******************************\n");
                printf("--UPDATE--\n");
                printf("1.by ID\n2.by_NAME\n3.by_NUMBER\n0.BACK\n");
                scanf("%d", &key);
                switch (key)
                {
                case 0:
                    flag = 0;
                    break;
                case 1:
                    update_id(head);
                    break;
                case 2:
                    update_name(head);
                    break;
                case 3:
                    update_num(head);
                    break;
                default:
                    printf("(ERROR)\n");
                    break;
                }
            }
            break;
        case 4:
            flag = 1;
            while (flag)
            {
                printf("******************************\n");
                printf("--QUERY--\n");
                printf("1.by ID\n2.by_NAME\n3.by_NUMBER\n0.BACK\n");
                scanf("%d", &key);
                switch (key)
                {
                case 0:
                    flag = 0;
                    break;
                case 1:
                    query_id(head);
                    break;
                case 2:
                    query_name(head);
                    break;
                case 3:
                    query_num(head);
                    break;
                default:
                    printf("(ERROR)\n");
                    break;
                }
            }
            break;
        case 5:
            flag = 1;
            while (flag)
            {
                printf("******************************\n");
                printf("--PRINT--\n");
                printf("1.by_NAME\n2.by_NUMBER\n0.BACK\n");
                scanf("%d", &key);
                switch (key)
                {
                case 0:
                    flag = 0;
                    break;
                case 1:
                    printf("******************************\n");
                    printf("--PRINT_by_NAME--\n");
                    quicksort_name(head, 1, length(head));
                    print(head);
                    break;
                case 2:
                    bubblesort_num(head);
                    break;
                default:
                    printf("(ERROR)\n");
                    break;
                }
            }
            break;
        default:
            printf("(ERROR)\n");
            break;
        }
    }
}

Boolean insert_tail(node head)
{
    printf("******************************\n");
    printf("--CREAT NEW CONTATOR--\n");
    char name[20];
    char num[12];
    char addr[20];
    printf("NAME: ");
    scanf("%s", &name);
    printf("NUMBER: ");
    scanf("%s", &num);
    printf("ADDRESS: ");
    scanf("%s", &addr);

    node newnode = (node)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        return F;
    }
    strcpy(newnode->name, name);
    strcpy(newnode->num, num);
    strcpy(newnode->addr, addr);

    node temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;

    id_order(head);
    printf("(SAVE SUCCESS!)\n");
    return T;
}

/*通过ID删除*/
Boolean delete_id(node head)
{
    printf("******************************\n");
    printf("--DELETE_ID--\n");
    int id;
    printf("ID: ");
    scanf("%d", &id);

    if (id <= 0 || id > length(head))
    {
        printf("(NOT FOUND ID: %d)\n", id);
        return F;
    }

    int i;
    node temp = head;
    for (i = 1; i < id; i++)  //找到要删除结点的前一个
    {
        temp = temp->next;
    }
    node temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

    id_order(head);
    printf("(DELETE SUCCESS!)\n");
    return T;
}
/*通过姓名删除*/
void delete_name(node head)
{
    printf("******************************\n");
    printf("--DELETE_NAME--\n");
    char name[20];
    printf("NAME: ");
    scanf("%s", &name);

    int count = 0;
    node temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->name, name))) //找到删除结点的前一个
        {
            count++;
            node temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
        else
        {
            temp = temp->next;
        }
    }

    if (count)  //找到了
    {
        id_order(head);
        printf("(DELETE SUCCESS!)\n");
    }
    else   //没找到
    {
        printf("(NOT FOUND NAME: %s)\n", name);
    }
}

/*通过学号删除*/
void delete_num(node head)
{
    printf("******************************\n");
    printf("--DELETE_NUMBER--\n");
    char num[12];
    printf("NUMBER: ");
    scanf("%s", &num);

    int count = 0;
    node temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->num, num)))
        {
            count++;
            node temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
        else
        {
            temp = temp->next;
        }
    }

    if (count)
    {
        id_order(head);
        printf("(DELETE SUCCESS!)\n");
    }
    else
    {
        printf("(NOT FOUND NUMBER: %s)\n", num);
    }

}

/*通过学号更新*/
Boolean update_id(node head)
{
    printf("******************************\n");
    printf("--UPDATE_ID--\n");
    int id;
    printf("ID: ");
    scanf("%d", &id);

    if (id <= 0 || id > length(head))
    {
        printf("(NOT FOUND ID: %d)\n", id);
        return F;
    }

    printf("PLEASE INPUT NEW INFOMATION:\n");
    char name[20];
    char num[12];
    char addr[20];
    printf("NAME: ");
    scanf("%s", &name);
    printf("NUMBER: ");
    scanf("%s", &num);
    printf("ADDRESS: ");
    scanf("%s", &addr);

    int i;
    for (i = 1; i <= id; i++)
    {
        head = head->next;
    }
    strcpy(head->name, name);
    strcpy(head->num, num);
    strcpy(head->addr, addr);

    printf("(UPDATE SUCCESS!)\n");
    return T;
}

/*通过姓名更新*/
Boolean update_name(node head)
{
    printf("******************************\n");
    printf("--UPDATE_NAME--\n");
    char old_name[20];
    printf("OLD_NAME: ");
    scanf("%s", &old_name);

    node temp = head;
    int count = 0;
    while (temp->next != head) //只要表不空
    {
        if (!(strcmp(temp->next->name, old_name))) //找到了
        {
            count++;
        }
        temp = temp->next;
    }
    if (0 == count)
    {
        printf("(NOT FOUND THIS NAME.)\n");
        return F;
    }

    printf("PLEASE INPUT NEW INFOMATION:\n");
    char name[20];
    char num[12];
    char addr[20];
    printf("NAME: ");
    scanf("%s", &name);
    printf("NUMBER: ");
    scanf("%s", &num);
    printf("ADDRESS: ");
    scanf("%s", &addr);

    temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->name, old_name)))
        {
            strcpy(temp->next->name, name);
            strcpy(temp->next->num, num);
            strcpy(temp->next->addr, addr);
        }
        temp = temp->next;
    }

    printf("(UPDATE SUCCESS!)\n");
    return T;
}

/*通过学号更新*/
Boolean update_num(node head)
{
    printf("******************************\n");
    printf("--UPDATE_NUMBER--\n");
    char old_num[20];
    printf("OLD_NUMBER: ");
    scanf("%s", &old_num);

    node temp = head;
    int count = 0;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->num, old_num)))
        {
            count++;
        }
        temp = temp->next;
    }
    if (0 == count)
    {
        printf("(NOT FOUND THIS NUMBER.)\n");
        return F;
    }

    printf("PLEASE INPUT NEW INFOMATION:\n");
    char name[20];
    char num[12];
    char addr[20];
    printf("NAME: ");
    scanf("%s", &name);
    printf("NUMBER: ");
    scanf("%s", &num);
    printf("ADDRESS: ");
    scanf("%s", &addr);

    temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->num, old_num)))
        {
            strcpy(temp->next->name, name);
            strcpy(temp->next->num, num);
            strcpy(temp->next->addr, addr);
        }
        temp = temp->next;
    }

    printf("(UPDATE SUCCESS!)\n");
    return T;
}

/*通过ID查询*/
Boolean query_id(node head)
{
    printf("******************************\n");
    printf("--QUERY_ID--\n");
    int id;
    printf("ID: ");
    scanf("%d", &id);

    if (id <= 0 || id > length(head))
    {
        printf("(NOT FOUND ID: %d)\n", id);
        return F;
    }

    int i;
    for (i = 1; i <= id; i++)
    {
        head = head->next;
    }
    printf("No.%-5dNAME: %-15sNUMBER: %-15sADDRESS: %-15s\n", head->id, head->name, head->num, head->addr);

    return T;
}

/*通过姓名查询*/
void query_name(node head)
{
    printf("******************************\n");
    printf("--QUERY_NAME--\n");
    char name[20];
    printf("NAME: ");
    scanf("%s", &name);

    int count = 0;
    node temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->name, name)))
        {
            count++;
            printf("No.%-5dNAME: %-15sNUMBER: %-15sADDRESS: %-15s\n", temp->next->id, temp->next->name, temp->next->num, temp->next->addr);
        }
        temp = temp->next;
    }

    if (0 == count)
    {
        printf("(NOT FOUND NAME: %s)\n", name);
    }

}

/*通过学号查询*/
void query_num(node head)
{
    printf("******************************\n");
    printf("--QUERY_NUMBER--\n");
    char num[12];
    printf("NUMBER: ");
    scanf("%s", &num);

    int count = 0;
    node temp = head;
    while (temp->next != head)
    {
        if (!(strcmp(temp->next->num, num)))
        {
            count++;
            printf("No.%-5dNAME: %-15sNUMBER: %-15sADDRESS: %-15s\n", temp->next->id, temp->next->name, temp->next->num, temp->next->addr);
        }
        temp = temp->next;
    }

    if (0 == count)
    {
        printf("(NOT FOUND NUMBER: %s)\n", num);
    }

}

/*初始化链表*/
Boolean init(node* head)
{
    node newnode = (node)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        return F;
    }
    /*初始化信息全为0*/
    newnode->id = 0;
    strcpy(newnode->name, "0");
    strcpy(newnode->num, "0");
    strcpy(newnode->addr, "0");

    /*单向循环链表*/
    newnode->next = newnode;

    *head = newnode;

    return T;
}

/*打印链表*/
void print(node head)
{
    node temp = head;
    while (temp->next != head)
    {
        printf("No.%-5dNAME: %-15sNUMBER: %-15sADDRESS: %-15s\n", temp->next->id, temp->next->name, temp->next->num, temp->next->addr);
        temp = temp->next;
    }

}

/*求表长*/
int length(node head)
{
    int count = 0;
    node temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

/*ID号*/
void id_order(node head)
{
    int count = 0;

    node temp = head;
    while (temp->next != head)
    {
        temp->next->id = ++count;
        temp = temp->next;
    }
}

/*冒泡排序*/
void bubblesort_num(node head)
{
    printf("******************************\n");
    printf("--PRINT_by_NUM--\n");

    int i, j, m;
    for (i = 1; i < length(head); i++)
    {
        for (j = length(head); j > i; j--)
        {
            node temp1 = head;
            for (m = 0; m < j - 2; m++)
            {
                temp1 = temp1->next;
            }

            node temp2 = temp1->next;
            if (strcmp(temp2->next->num, temp2->num) < 0)
            {
                temp1->next = temp2->next;
                temp2->next = temp1->next->next;
                temp1->next->next = temp2;
            }
        }
    }

    id_order(head);
    print(head);
}

/*快速排序*/
void quicksort_name(node head, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int i = left;
    int j = right;
    char key_name[20];
    char key_num[12];
    char key_addr[20];
    strcpy(key_name, unit_index(head, left)->name);
    strcpy(key_num, unit_index(head, left)->num);
    strcpy(key_addr, unit_index(head, left)->addr);

    while (i < j)
    {
        while (i < j && (strcmp(unit_index(head, j)->name, key_name) >= 0))
        {
            j--;
        }
        strcpy(unit_index(head, i)->name, unit_index(head, j)->name);
        strcpy(unit_index(head, i)->num, unit_index(head, j)->num);
        strcpy(unit_index(head, i)->addr, unit_index(head, j)->addr);

        while (i < j && (strcmp(unit_index(head, i)->name, key_name) <= 0))
        {
            i++;
        }
        strcpy(unit_index(head, j)->name, unit_index(head, i)->name);
        strcpy(unit_index(head, j)->num, unit_index(head, i)->num);
        strcpy(unit_index(head, j)->addr, unit_index(head, i)->addr);
    }

    strcpy(unit_index(head, i)->name, key_name);
    strcpy(unit_index(head, i)->num, key_num);
    strcpy(unit_index(head, i)->addr, key_addr);
    quicksort_name(head, left, i - 1);
    quicksort_name(head, i + 1, right);
}

node unit_index(node head, int index)
{
    int i;
    node temp = head;
    for (i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return (temp);
}
