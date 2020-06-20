/*
 * @Copyright: <剑指offer第二版>
 * @File name: AssignmentOperator.cpp
 * @Description: 赋值运算符函数
 * 考察内容：
 * 1.是否将返回值的类型声明为该类型的引用，并在函数结束前返回示例自身的引用(*this)。只有返回一个引用才允许连续赋值
 * 2.是否将传入的参数声明为常量引用。如果传入参数是实例，从形参到实参会调用一次复制构造函数，使用引用可以避免无谓的消耗，提高代码效率；赋值运算符函数内不改变传入实例的状态，因此使用const关键字
 * 3.是否释放实例自身已有的内存
 * 4.判断传入的参数和当前的实例(*this)是不是同一个实例
 * @Author: yangjam
 * @Version: 
 * @Date: 2020-06-19 20:07:43
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-06-20 14:32:56
 */ 
#include<cstring>
#include<cstdio>

class CMyString
{
    public:
        /*
         * 构造函数
         * 用于类成员初始化
         * 默认构造函数是在未提供显示初始值时，用来创建对象的构造函数，如CMyString str1；如果没有提供任何构造函数，c++将自动提供默认构造函数；如果提供了非默认构造函数，则编译器不会提供默认构造函数；如果提供了构造函数，但是没有提供默认构造函数，则声明CMyString str会报错；定义默认函数有两种方式：一种是给已有构造函数的所有参数提供默认值；另一种是通过函数重载定义另一个没有参数的构造函数
         * 默认参数
         * 当实参缺省时自动使用一个值
         */
        CMyString(char *pData = nullptr);    /* 默认构造函数 */
        /*
         * 函数重载
         * C++允许定义名称相同的函数，条件是他们的特征标(参数列表)不同
         */
        CMyString(const CMyString &str);
        /*
         * 析构函数
         * 当对象过期时，程序自动调用析构函数完成对象清理
         */
        ~CMyString(void);
        /*
         * 运算符重载
         */
        CMyString& operator= (const CMyString &str);

        void Print();
    
    private:
        char *m_pData;
};

CMyString::CMyString(char *pData)
{
    if (pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}


CMyString &CMyString::operator = (const CMyString &str)
{
    /*
     * this指针指向用来调用成员函数的对象(作为隐藏参数传递给方法)
     */
    if (this == &str)
    {
        return *this;
    }

    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

/* ------test---- */

void CMyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char *text = (char *)"Hello World";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is:%s.\n", text);

    printf("The actual result is:");
    str2.Print();
    printf(".\n");
}

/* 赋值给自己 */
void Test2()
{
    printf("Test2 begins:\n");

    char *text = (char *)"Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is:%s.\n", text);

    printf("The actual result is:");
    str1.Print();
    printf(".\n");
}

/* 连续赋值 */
void Test3()
{
    printf("Test3 begins:\n");

    char *text = (char *)"Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is:%s.\n", text);

    printf("The actual result is:");
    str2.Print();
    printf(".\n");

    printf("The actual result is:");
    str3.Print();
    printf(".\n");
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}