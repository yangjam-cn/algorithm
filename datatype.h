/*
 * @Author: youngjam
 * @Date: 2020-04-24 20:06:27
 * @LastEditTime: 2020-04-25 20:29:41
 * @Description:数据类型定义 
 * @logs: 
 * @Environment: Ubuntu 18.04.4 LTS && gcc 7.5.0
 */
#ifndef DATATYPE_H
#define DATATYPE_h

#define MAXLENGTH 16
/******--<数据类型定义>--******/
typedef struct PersonInfo {
    char name[MAXLENGTH];
    short int age;
    float score;
}DataType;

/******--<函数列表>--******/

/* 从键盘获取数据 */
void GetData(DataType *const element);

/* 交换 e1 和 e2 的值 */
void SwapData(DataType *const e1, DataType *const e2);

/* 将 element 的值复制到 object */
void CopyData(DataType const *const element, DataType *const object);

/* 向屏幕输出 element 的值 */
void PrintData(DataType const * const element);

#endif