/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: data_type.c
 * @Description: 自定义数据类型及其运算
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-20 20:44:21
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-21 15:31:11
 */ 
#include<stdio.h>

/*++++++++++++学生信息数据类型++++++++++++*/
/*学生信息结构体 */
typedef struct student_info
{
    char m_name[11];
    char m_sex;
    int  m_grade;
}Info;

/* 函数列表 */

/* 从键盘获取数据初始化对象 */
void InitializeInfo(Info *const stu);
/* 向屏幕输出对象的值 */
void PrintInfo(const Info *const stu);

/* 函数实现 */

void InitializeInfo(Info *const stu)
{
    printf("input the name: ");
    scanf("%s", stu->m_name);
    printf("input the sex: ");
    getchar();
    scanf("%c", &(stu->m_sex));
    printf("input the grade: ");
    scanf("%d", &(stu->m_grade));
}

void PrintInfo(const Info *const stu)
{
    printf("name: %s\tsex: %c\tgrade: %d\n", stu->m_name, stu->m_sex, stu->m_grade);
}
