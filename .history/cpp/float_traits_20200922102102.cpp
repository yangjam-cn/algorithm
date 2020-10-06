/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-22 10:12:28
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-22 10:21:02
 */
#include <iostream>
#include <float.h>

using namespace std;

template <typename numT>
struct fp_traits
{
};

template<>
struct fp_traits<float>
{
    typedef float fp_type;
    enum {max_exponent = FLT_MAX_EXP};
    static inline fp_type epsilon() 
    {
        return FLT_EPSILON;
    }
};

template<>
struct fp_traits<double>
{
    typedef double fp_type;
    enum {max_exponent = DBL_MAX_EXP};
    static inline fp_type epsilon()
    {
        return DBL_EPSILON;
    }
};

template<typename numT>
class matrix
{
    public:
        typedef numT num_type;
        typedef fp_traits<num> num_type_info;
        inline num_type epsilon()
        {
            return num_type_info::epsilon();
        }
};

int main()
{
    matrix<float> fm;
    matrix<double> dm;
    cout <<
}

