/*
 * letcure 2 demo
 * 线性结构之线性表（数组，链表）
 * Created by zipei on 2021/8/12.
 */

#include<stdio.h>
/* 定义 node 结构体 */

typedef  struct lnode *List;
struct lnode{
    ElemType Data;
    List Next;
};
struct lnode L;
List PtrL;


/* 求表长 */
int length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    while (p) {
        p = p -> Next;
        j ++;
    }
    return j;
}
int main()
{

    return 0;
}

