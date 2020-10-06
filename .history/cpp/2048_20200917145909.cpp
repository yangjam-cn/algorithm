/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-17 14:38:47
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 14:59:09
 */
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "C:\PDCurses-3.8\PDCurses-3.8\curses.h"

#define N           4
#define WIDTH  5
#define TARGET 2048

#define S_FAIL       0
#define S_WIN       1
#define S_NORMAL 2
#define S_QUIT      3

class Game2048
{
    private:
        int data[N][N];
        int status;
    public:
        Game2048();
        int get_status();
        void process_input();
        void draw();
        void set_testData();
    private:
        bool is_over();
        bool move_left();
        void rotate();
        void restart();
        bool rand_new();
        void draw_item(int row, int col, char c);
        void draw_num(int row, int col, int num);
};

