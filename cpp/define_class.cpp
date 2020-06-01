/*
 * @Copyright: <<c++ Primer Plus>>第10章
 * @File name: define_class.cpp
 * @Description: c++类声明
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-01 14:30:26
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-01 16:12:21
 */ 
#include<iostream>
#include<string>

/*
 * 类规范一般由两个部分组成
 * 类声明：以数据成员的方式描述数据部分，以成员函数（方法）的方式描述共有接口
 * 类方法定义：描述如何实现类成员变量
 */

/* 类声明，将股票信息抽象为一个类 */
class Stock
{
    /* 
     * 访问控制：使用类对象的程序都可以直接访问公有部分(public)，但只能通过公有成员函数来\访问对象的私有成员
     */
    private:
        std::string company;    /* 类成员，公司名称 */
        long shares;            /* 股票数量 */
        double share_val;       /* 每股股票价格 */
        double total_val;       /* 股票总价格 */

        /* 
         * 定义位与类声明中的函数自动成为内联函数 
         */
        void set_tot()
        {
            total_val = share_val * shares;
        }
    public:
        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};    /* end of class declaration */

/* 
 * 实现类成员函数
 * 定义类成员时，使用作用域解析运算符(::)来标识函数所属类；
 * 类方法可以访问类的private组件
 */
/**
 * @Function: Stock::acquire()
 * @Description: 首次购买股票，初始化对象的成员变量值
 * @Calls: 
 *     set_tot()
 * @Called By: 
 *     main()
 * @Input: 
 *     co:公司名称
 *     n:股票数量
 *     pr:单股股票价格
 * @Output: 
 *     company：设定对象的股票名称
 *     shares：设定对象的股票数量
 *     share_val:设定股票价格
 *     total_val：计算对象的股票总价值
 * @Return: 无返回值
 * @Others: 其它说明
 */
void Stock::acquire(const std::string &co, long n, double pr)
{
    company = co;

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative;"
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    
    share_val = pr;
    set_tot();
}

/**
 * @Function: Stock::buy()
 * @Description: 购买股票
 * @Calls: 
 *     set_tot()
 * @Called By: 
 *     main()
 * @Input: 
 *     num:股票数量
 *     price:股票价格
 * @Output: 
 *     shares：增加股票持有量
 *     share_val:更新股票价格
 *     total_val：更新股票总价值
 * @Return: 无返回值
 * @Others: 其它说明
 */
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative."
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

/**
 * @Function: Stock::sell()
 * @Description: 卖出股票
 * @Calls: 
 *     set_tot()
 * @Called By: 
 *     main()
 * @Input: 
 *     num:股票数量
 *     price:股票价格
 * @Output: 
 *     shares：减少股票持有量
 *     share_val:更新股票价格
 *     total_val：更新股票总价值
 * @Return: 无返回值
 * @Others: 其它说明
 */
void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative."
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have!"
             << "Transactio  is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

/**
 * @Function: Stock::update()
 * @Description: 更新股票价格
 * @Calls: 
 *     set_tot()
 * @Called By: 
 *     main()
 * @Input: 
 *     price:股票价格
 * @Output: 
 *     share_val:更新股票价格
 *     total_val：更新股票总价值
 * @Return: 无返回值
 * @Others: 其它说明
 */
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

/**
 * @Function: Stock::show()
 * @Description: 输出股票信息
 * @Calls: 
 * @Called By: 
 *     main()
 * @Input: 输入参数说明，包括每个参数的作用、取值及参数间的关系
 * @Output: 输出参数说明
 * @Return: 无返回值
 * @Others: 其它说明
 */
void Stock::show()
{
    using std::cout;
    cout << "Company: " << company << '\n'
         << "Shares: " << shares << '\n'
         << "Share Price: " << share_val << '\n'
         << "Total Worth:" << total_val << '\n';
}

int main()
{
    Stock young;
    young.acquire("china", 20, 12.50);
    young.show();
    young.buy(15, 18.125);
    young.show();
    young.sell(400, 20.00);
    young.show();
    young.buy(10000, 12.5);
    young.show();
    young.sell(10000, 40.00);
    young.show();
    return 0;
}