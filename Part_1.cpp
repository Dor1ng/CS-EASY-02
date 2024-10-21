#include <stdio.h>
#include <stdlib.h>

//定义节点结构
struct list_node
{
    unsigned int data;
    list_node* next = nullptr;
};

using nodeptr = list_node*;

//定义链表类型
struct list
{
    nodeptr head = nullptr, tail = nullptr;
};

using listptr = list*;


//删掉从链表第b位的节点
void del(listptr ptr,int b)
{
    nodeptr pre,p,nxt;
    pre = ptr->head;
    if (b == 1)
    {
        ptr->head = ptr->head->next;
        //printf("%p\n",a.head);
        delete pre;
    }
    else if(b <= 0)
    {
        printf("error!note number <= 0!\n");
    }
    else 
    {
        for (int i = 1; i <= b - 2; i++)
        {
            if (pre->next == nullptr)
            {
                printf("you can't delete note %d\n", b);
                break;
            }
            pre = pre->next;
        }
        p = pre->next;
        if (p == nullptr)
        {
            printf("you can't delete note %d\n", b);
        }
        else
        {
            if (p->next == nullptr)
            {
                ptr->tail = pre;
                pre->next = nullptr;
            }
            else
            {
                nxt = p->next;
                pre->next = nxt;
            }
            delete p;
        }
    }
}

//尾插（这里只写了插入3个数据的情况）
void t_insert(listptr ptr,int a[])
{
    nodeptr pre, p;
    pre = ptr->tail;
    for (int i = 0; i < 3; i++)
        {
            p = new list_node;
            p->data = a[i];
            p->next = nullptr;

            pre->next = p;
            pre = p;
        }

    ptr->tail = pre;
};

//头插（同样只写了插入3个数据的情况）
void h_insert(listptr ptr,int a[]) 
{
    nodeptr pre, p;
    pre = ptr->head;
    for (int i = 2; i >= 0; i--)
    {
        p = new list_node;
        p->data = a[i];
        p->next = pre;

        pre = p;

    }
    ptr->head = pre;
}

//打印链表
void printlist(list a)
{
    nodeptr p;
    p = a.head;
    while (p != a.tail)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("%d",p->data);
    printf("\n");
}

//主体
int main()
{
    //需要插入的数据
    int data_t_1[3] = { 1,1,1 },data_t_2[3] = { 1,3,1 },data_t_3[3] = { 2,2,2 },data_t_4[3] = { 1,2,2 },data_t_5[3] = { 2,1,1 },data_t_6[3] = { 2,2,2 };
    int data_h_1[3] = { 3,2,1 }, data_h_2[3] = { 1,2,1 }, data_h_3[3] = { 2,1,2 }, data_h_4[3] = { 2,2,1 }, data_h_5[3] = { 1,2,1 }, data_h_6[3] = { 1,1,1 };

    list a;//创建链表a
    a.head = new list_node;//生成头节点
    a.head->data = 1; //对头节点赋值1
    a.head->next = nullptr;//初始化头节点
    a.tail = a.head;//指向尾节点指针初始化

    listptr ptr = &a;

    t_insert(ptr, data_t_1);

    h_insert(ptr, data_h_1);

    t_insert(ptr, data_t_2);

    del(ptr, 9);

    h_insert(ptr, data_h_2);

    t_insert(ptr, data_t_3);

    h_insert(ptr, data_h_3);

    del(ptr,1);

    h_insert(ptr, data_h_4);

    t_insert(ptr, data_t_4);

    del(ptr, 23);

    t_insert(ptr, data_t_5);

    t_insert(ptr, data_t_6);

    h_insert(ptr, data_h_5);

    h_insert(ptr, data_h_6);
    
    a.tail->next = a.head;//尾节点指向头节点

    printlist(a);//打印链表
    
    return 0;
}