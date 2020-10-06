/*
 * @Description: 猫狗队列
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-09-26 16:24:12
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-09-26 16:37:30
 */
#include <queue>
#include <string>
using std::string;
class Pet
{
    private:
        string type;
    public:
        Pet(string type)
        {
            this->type = type;
        }
        string get_pet_type() 
        {
            return this->type;
        }
};

class Dog : public Pet
{
    public:
        Dog()
        {
            Pet("dog");
        }
};

class Cat : public Pet
{
    public:
        Cat()
        {
            Pet("cat");
        }
};