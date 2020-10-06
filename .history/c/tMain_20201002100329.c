/*
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-10-02 10:01:40
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-10-02 10:03:29
 */
#include <stdio.h>
#include <stdlib.h>


static void before(void) __attribute__ ((constructor));
static void after(void) __attribute__ ((destructor));