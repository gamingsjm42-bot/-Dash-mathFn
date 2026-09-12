#include <iostream>
//!Exception
class Exception
{
    //*premeters
    protected:
    std::string Err , Message;
    public:
    /*print*/
    void print()
    {
        std::cerr<< Err<<"("<<Message<<")";
    }
    /*raise*/
    void raise()
    {
        print(); exit(1);
    }
};
#define creatErrorClass(clsName,clsStrName) \
class clsName :Exception \
{public:  clsName(std::string message){Err=message; Message = message;}}
creatErrorClass(ium,"");