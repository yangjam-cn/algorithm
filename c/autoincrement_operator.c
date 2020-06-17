/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: autoincrement_operator.c
 * @Description: 测试i++与++i的异同
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-17 13:41:32
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-17 14:31:17
 */ 
#include<stdio.h>

void main()
{
    int i = 0;
    /*
     * output: 2    2
     * ++ 优先级高于 + ，先计算 + 两侧计算式，+从左到右结合
     * 先计算左侧，先用后加，故使用临时变量tmp保存i值，tmp = 0 ，i=1
     * 再计算右侧，先加后用，i = 2
     * 计算+, tmp+i=2
     */
    printf("%d\t", i++ + ++i);
    printf("%d\n", i);
    /*
     * output:3    2
     * 先计算左侧，先加后用，此时i=1，不产生临时变量
     * 再计算右侧，先用后加，此时产生临时变量tmp保存i值，tmp = 1， i=2
     * 计算+，i+tmp=3
     */
    i = 0;
    printf("%d\t", ++i + i++);
    printf("%d\n", i);
    /*
     * output: 4
     * 经过两次++，i=2, 式子等价于i+i = 4
     */
    i = 0;
    printf("%d\n", ++i + ++i);
    /*
     * output: 0
     * 式子等价于i-i=0
     */
    i = 6;
    printf("%d\n", --i - --i);
    /*
     * output: 1
     * 式子等价于tmp1+tmp2 = 1
     */
    i = 0;
    printf("%d\n", i++ + i++);
    /*
     * output: 2    0
     * i++优先级高于++i
     * 先计算后者产生临时变量tmp=0
     * 再计算后者，i自增两次，i=2
     */
    i = 0;
    printf("%d\t%d\n", ++i, i++);
}