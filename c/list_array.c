/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 顺序表的实现
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-06-20 21:23:22
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-21 15:40:14
 */ 
#include<stdlib.h>
#include"data_type.c"

#define TRUE  1
#define FALSE 0

typedef int Bool;
typedef struct list_base_array
{
    Info *m_ele;       /* 数据域 */
    int m_length;      /* 表的当前长度 */
    int m_max_size;    /* 表的最大规模 */
}SeqList;
typedef SeqList *PtrList;

/* 运算列表 */

/* 初始化顺序表 */
PtrList InitialzeSeqList(int size);

/* 检查表是否为空 */
Bool IsEmpty(PtrList const sl);

/* 检查表是否已满 */
Bool IsFull(PtrList const sl);

/* 返回表的当前长度 */
int LengthSeqList(PtrList const sl);

/* 向表中插入元素 */
Bool InsertElement(PtrList const sl, int pos, Info stu);

/* 向表尾添加元素 */
Bool AddToTail(PtrList const sl, Info stu);

/* 删除表中某一位置的元素 */
Bool DeleteElement(PtrList const sl, int pos);

/* 获取表中某一位元素的值 */
Bool GetElement(PtrList const sl, int pos, Info *stu);

/* 删除整张表 */
PtrList ClearSeqList(PtrList sl);

/* 函数实现 */
static inline Bool IsNullptr(void *ptr)
{
    if (ptr == NULL)
    {
        puts("this is a nullptr!");
        return TRUE;
    }
    return FALSE;
}

static Bool IsVaild(int pos, const PtrList const sl)
{
    if (pos >= 0 && pos <= sl->m_length - 1)
    {
        return TRUE;
    }
    else
    {
        puts("pos is invalid!");
        return FALSE;
    }
}

PtrList InitialzeSeqList(int size)
{
    PtrList sl = (PtrList)malloc(sizeof(SeqList));
    if (!IsNullptr(sl))
    {
        sl->m_ele = (Info *)malloc(sizeof(Info) * size);
        if (!IsNullptr(sl->m_ele))
        {
            sl->m_max_size = size;
            sl->m_length = 0;
        }
        else
        {
            sl = NULL;
        }
    }
    return sl;
}

Bool IsEmpty(PtrList const sl)
{
    if (!IsNullptr(sl))
    {
        if (sl->m_length <= 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

Bool IsFull(PtrList const sl)
{
    if (!IsNullptr(sl))
    {
        if (sl->m_length >= sl->m_max_size)
        {
            return TRUE;
        }
    }
    return FALSE;
}

Bool InsertElement(PtrList const sl, int pos, Info stu)
{
    if (!IsNullptr(sl))
    {
        if (!IsFull(sl))
        {
            if (IsVaild(pos, sl))
            {
                int cur = sl->m_length - 1;
                while (cur >= pos)
                {
                    sl->m_ele[cur + 1] = sl->m_ele[cur];
                    cur--;
                }
                sl->m_ele[cur + 1] = stu;
                sl->m_length++;
                return TRUE;
            }
        }
    }
    return FALSE;
}

Bool AddToTail(PtrList const sl, Info stu)
{
    if (!IsNullptr(sl))
    {
        if (!IsFull(sl))
        {
            sl->m_ele[sl->m_length++] = stu;
            return TRUE;
        }
    }
    return FALSE;
}

Bool DeleteElement(PtrList const sl, int pos)
{
    if (!IsNullptr(sl))
    {
        if (!IsEmpty(sl))
        {
            if (IsVaild(pos, sl))
            {
                int cur = pos;
                while (cur < sl->m_length - 1)
                {
                    sl->m_ele[cur] = sl->m_ele[cur + 1];
                    cur++;
                }
                sl->m_length--;
            }
        }
    }
}

Bool GetElement(PtrList const sl, int pos, Info *stu)
{
    if (!IsNullptr(sl))
    {
        if (!IsEmpty(sl))
        {
            if (IsVaild(pos, sl))
            {
                *stu = sl->m_ele[pos];
                return TRUE;
            }
        }
    }
    return FALSE;
}

PtrList ClearSeqList(PtrList sl)
{
    if (!IsNullptr(sl))
    {
        free(sl->m_ele);
        free(sl);
        sl = NULL;
    }
    return sl;
}

/* test */
int main()
{
    PtrList sl = InitialzeSeqList(10);
    Info stu;
    int pos;
    char flag = '0';
    while (flag != 'q')
    {
        scanf("%c", &flag);
        switch (flag)
        {
            case '1':
                InitializeInfo(&stu);
                AddToTail(sl, stu);
                break;
            case '2':
                printf("input the pos: ");
                scanf("%d", &pos);
                InitializeInfo(&stu);
                InsertElement(sl, pos, stu);
                break;
            case '3':
                printf("input the pos: ");
                scanf("%d", &pos);
                DeleteElement(sl, pos);
                break;
            case '4':
                printf("input the pos: ");
                scanf("%d", &pos);
                GetElement(sl, pos, &stu);
                PrintInfo(&stu);
                break;
            case '5':
                for (pos = 0; pos <= sl->m_length - 1; pos++)
                {
                    PrintInfo(&sl->m_ele[pos]);
                }
                break;
            case '6':
                sl = ClearSeqList(sl);
                printf("%p\n", sl);
                break;
            default:
                break;
        }
    }
    return 0;
}