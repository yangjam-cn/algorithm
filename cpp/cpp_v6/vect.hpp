/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-16 21:56:36
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-17 09:54:47
 */
#ifndef VECT_HPP_
#define VECT_HPP_
#include <iostream>

namespace VECTOR
{
    class Vector
    {
        public:
            enum Mode {RECT, POL};
        private:
            double x;               /* 直角坐标系中x坐标 */
            double y;               /* 直角坐标下y坐标 */
            double mag;           /* 极坐标下距离 */
            double ang;            /* 极坐标下弧度 */
            Mode mode;           /* 模式 */

            void set_mag();
            void set_ang();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const {return mag;}
            double angval() const {return ang;}
            void polar_mode();
            void rect_mode();

            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif