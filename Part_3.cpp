#include <stdio.h>
#include <string.h>


// #    用链表保存密符串
// ##   定义节点结构
struct node
{
    char data;
    node* next = nullptr;
};

using nodeptr = node*;

// ##   定义链表类型
struct list
{
    nodeptr head = nullptr, tail = nullptr;
};

using listptr = list*;

// ##   输入数据
void creat_list(listptr ptr,char a[])
{
    nodeptr p, pre;
    int i = strlen(a);
    pre = ptr->head;
    for (int j = 0; j < i; ++j)
    {
        p = new node;

        p->data = a[j];
        pre->next = p;
        p->next = nullptr;
        pre = p;
        ptr->tail = p;
    }
}

// #    定义栈
// ##   栈中每个节点结构
struct s_node
{
    char data;
    s_node* next;
};

using s_nodeptr = s_node*;


// ##   入栈
void push(s_node** ptop,char c)
{
    s_nodeptr p = new s_node;
    s_node** ptr = &p;
    p->data = c;
    if (*ptop == nullptr)
    {
        p->next = nullptr;
    }
    else
    {
        p->next = *ptop;
    }
    *ptop = p;
}

// ##   出栈并打印data
void pull(s_node** ptop)
{
    if (*ptop != nullptr)//判栈空
    {
        s_nodeptr p = *ptop;
        *ptop = p->next;//移动top指针
        printf("%c", p->data);//打印data
        delete p;
    }
    //else
    //{
    //    printf("Error! The stack is empty!");
    //}
}

// #    主体
int main()
{
    int number[] = { 3,1,1,2,2,1,2,1,1,2,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,1,1,1,1,1,2 };//Part2得到的数字串
    int i = sizeof(number) / sizeof(int);
    int l = 0;

    //用链表保存密符串
    char char_line[26] = "kiglnmrmeiahenrteof4ardar";

    //初始化链表
    list list;
    listptr ptr = &list;
    ptr->head = new node;
    list.head->next = nullptr;

    creat_list(ptr, char_line);//输入密符串
    nodeptr p = list.head;
    list.head = list.head->next;
    delete p;

    //初始化栈
    s_nodeptr top = nullptr;
    s_node** ptop = &top;

    for (int a = 1; a <= i; a++)
    {

        int nb = number[a - 1];

        //判断奇偶
        if (a % 2 == 1)        //奇数情况 ->压入
        {
            for (; nb > 0; nb--)
            {
                push(ptop, char_line[l]);
                l = l + 1;
            }
        }
        else if (a % 2 == 0)   //偶数情况 ->弹出
        {
            for (; nb > 0; nb--)
            {
                pull(ptop);
            }
        }
        else
        {
            printf("error!");
        }
    }

    return 0;
}
