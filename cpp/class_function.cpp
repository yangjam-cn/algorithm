/*
 * @Copyright: 《c++ Primer Plus》第10章
 * @File name: class_function.cpp
 * @Description: 构造函数与析构函数
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-02 14:00:50
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-02 15:24:19
 */
#include<iostream>
#include<string>

class Stock
{
    private:
        std::string ms_company;
        long ml_shares;
        double md_share_val;
        double md_total_val;
        void set_tot()
        {
            md_total_val = md_share_val * ml_shares;
        }
    public:
        Stock();
        Stock(const std::string &co, long num = 0, double price = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

Stock::Stock()
{
    std::cout << "Default construction called.\n";

    ms_company = "no name";
    ml_shares = 0;
    md_share_val = 0.0;
    md_total_val = 0.0;
}

Stock::Stock(const std::string &co, long num, double price)
{
    std::cout << "Construction using " << co << " Called.\n";
    ms_company = co;

    if (num < 0)
    {
        std::cout << "Number of shares can't be negative; " 
                  << ms_company << " Shares set to 0.\n";
        ml_shares = 0;
    }    /* end if(num < 0) */
    else 
    {
        ml_shares = num;
        md_share_val = price;
        set_tot();
    }    /* end else */
}

Stock::~Stock()
{
    std::cout << "Bye, " << ms_company << "!\n";
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares of purchased can't be negative." 
                  << "Transaction is aborted.\n";
    }
    else
    {
        ml_shares += num;
        md_share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares of sold can't be negative." 
             << "Transaction is aborted.\n";
    }
    else if (num > ml_shares)
    {
        cout << "You can't sell more than you have!" 
             << "Transaction is aborted.\n";
    }
    else
    {
        ml_shares -= num;
        md_share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    md_share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
 
    cout << "Company: " << ms_company
         << " Shares: " << ml_shares << '\n';
    cout << "Share price: $" << md_share_val;

    cout.precision(2);
    cout << " Total Worth: $" << md_total_val << std::endl;

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new object\n";

        /* 创建stock1对象，并调用构造函数将数据成员初始化 */
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();
        /*
         * c++编译器使用两种方式执行如下语句
         * 第一种同stock1初始化
         * 第二种先调用构造函数创建临时对象，然后复制给到stock2，然后销毁临时对象并调用析构函数
         */
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";

        /* 默认下，对象赋值时，将对象的成员复制给另一个 */
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";

        /* 通过构造函数创建一个新的，临时的对象，然后复制给stock1，随后调用析构函数，删除该临时对象 */
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}
/*
 * a.构造函数是一种特殊的类成员函数，在创建类类对象时被调用
 * b.构造函数的名称与类名相同，但可以通过函数参数列表不同实现函数重载，创建多个同名构造函数
 * c.构造函数没有声明类型
 * d.构造函数用于初始化类对象成员，初始化应与构造函数参数列表匹配
 * e.默认构造函数没有参数，当对象没有显示初始化时，调用默认构造函数
 * f.若程序没有提供默认构造函数，编译器将自定义一个默认构造函数
 * g.默认构造函数没有参数，若有必须提供默认值
 */
/*
 * 当对象被删除时，程序将调用析构函数
 * 每个类都只能有一个析构函数
 * 析构函数没有返回类型，没有参数，其名称为类名称前加上“~”
 */