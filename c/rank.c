/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: rank.c
 * @Description: 
    * 有n个考场，每个考场有若干数量的考生。现在给出各个考场中的准考证号与分数，要求将所有考生按分数从高到低进行排序，并按顺序输出所有考生的准考证号、排名、考场号以及考场内的排名 
 * @Author: yangjam
 * @Version: demo
 * @Date: 2020-07-16 19:33:10
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-07-16 20:44:55
 */ 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct student
{
    char m_id[15];        /* 准考证号 */
    int  m_grade;         /* 考试成绩 */
    int  m_rank_room;     /* 考场内排名 */
    int  m_room;          /* 考场号 */
}stu[300];

bool cmp_stu(struct student s1, struct student s2)
{
    if (s1.m_grade != s2.m_grade)
    {
        return s1.m_grade > s2.m_grade;
    }
    else
    {
        return (strcmp(s1.m_id, s2.m_id) < 0);
    }
}

void swap_stu(struct student *s1, struct student *s2)
{
    struct student tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void sort_stu(int start, int end)
{
    int max = 0;
    for (int i = start; i < end - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < end; j++)
        {
            if (cmp_stu(stu[j], stu[max]))
            {
                max = j;
            }
        }
        swap_stu(&(stu[i]), &(stu[max]));
    }
}

int main(void)
{
    int rooms, students;
    int totals = 0;
    int rank;
    scanf("%d", &rooms);
    for (int i = 1; i <= rooms; i++)
    {
        scanf("%d", &students);
        for (int j = 0; j < students; j++)
        {
            scanf("%s %d", &stu[totals].m_id, &stu[totals].m_grade);
            stu[totals].m_room = i;
            totals++;
        }
        sort_stu(totals - students, totals);
        stu[totals -students].m_rank_room = 1;
        for (int j = totals - students; j < totals; j++)
        {
            if (stu[j].m_grade == stu[j - 1].m_grade)
            {
                stu[j].m_rank_room = stu[j - 1].m_rank_room;
            }
            else
            {
                stu[j].m_rank_room = j - (totals - students) + 1;
            }
        }
    }
    sort_stu(0, totals);
    rank = 1;
    for (int i = 0; i < totals; i++)
    {
        if (i > 0 && stu[i].m_grade != stu[i - 1].m_grade)
        {
            rank = i + 1;
        }
        printf("%s %d %d %d\n", stu[i].m_id, rank, stu[i].m_room, stu[i].m_rank_room);
    }
    return 0;
}