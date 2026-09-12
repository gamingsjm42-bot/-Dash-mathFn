#define RationNum RationalNumber(4545)
#define RealNum RealNumber(420)
// #includes
#include <math.h>
#include <functional>
#include <vector>
#include <map>
#include "Errores/Error.h"
//! messages
namespace message
{
    //*inf*0
    const char *multiplyInfByZero = "can't multyply inf with inf";
    //*inf/inf
    const char *devideInfByInf = "can't devided inf by inf";
    //*inf-inf
    const char *subInfByInf = "can't sub inf by inf";
    //*inf^-inf
    const char *powInfByMinusInf = "can't power inf by -inf";
}
#define numAll RealNumber
//! types
struct numAll;
using number = float;
using shortDecimalNumber = float;
using DecimalNumber =  double;
using IntegerNumber = long;
using Nnumber = size_t;
//using numArray = std::vector<numAll>;
//using strFn = std::function<std::string(RealNumber)>;
//*base sturct
////struct Inf;
//*types2
//using boolFunction = std::function<bool(numAll)>;
//using numFunction = std::function<numAll(numAll)>;
//#define infFunction(returning) = std::function<returning(Inf)>;
//*Errors
creatErrorClass(DifinitionSetError, "DifinitionSetError");
creatErrorClass(UssingnedStatus, "UssingnedStatus");
creatErrorClass(ZeroDevisionError, "ZeroDevisionError");
creatErrorClass(ValueError, "ValueError");
creatErrorClass(ConstanstsetError, "ConstanstsetError");
//*isOdd
#define isEven(num) (num % 2 == 0)
#define isOdd(num) !isEven(num)
//*sign
int Sign(number num) { return (num >= 0) ? 1 : -1; }
//*Abs
template <typename T>
T Abs(T num) { return (num >= 0) ? num : num * -1; }
//*MathFunction
/*
Retuning_and_args :  "returning(arg1,arg2,arg3,...)"
example: Retuning_ang_Args : int(string,double,int,MathFn,Fraction,float,Uint8)
function : any function
example
function :cout<<5 ;return 8;
*/
#define Mfn(functionBody) numFunction([=](DecimalNumber x) { functionBody; })
#define __mfn(functionBody) numFunction([](numAll x) { functionBody; })
#define boolFn (functionBody) boolFunction([=](numAll x) { functionBody;})
#define __boolFn(functionBody) boolFunction([](numAll x) { functionBody; })
#define Sfn(functionBody) strFn([](RealNumber r) { functionBody; })
//$infnit number
/*
infinity
*/
//! inf operator
using Lim = const DecimalNumber;
//$bool num
#define isNatural(num) (num >= 0 and R(num) == R(int(num));)
//*len
//*numberOfCommas
//*Floor
IntegerNumber Floor(DecimalNumber x) { return (x - floor(x) < 0.5) ? x : x + 1; }
//*POW10
#define pow10(num) pow(10, num)
//*root
#define root(num, Root) pow(num, (1 / Root))
//*sqrt
#define sqrt(num) pow(num, 0.5)
//$fraction
/**/
struct Fraction
{
    //*pgcd
    static Nnumber pgcd(Nnumber __first, Nnumber __socond)
    {
        //*vars
        IntegerNumber First = std::max(__first, __socond), Socond = std::min(__first, __socond), mod = First % Socond;
        //*returning
        return (mod == 0) ? Socond : pgcd(Socond, mod);
    }
    //
    size_t numOfCommas(DecimalNumber num)
    {
        //for loop
        size_t returning =1;
        //set num *=10
        while (num==floor(num)){ num*=10;returning++; }
        //
        return returning;
    }
    //*vars
    IntegerNumber numerator = 1, denominator = 1;

private:
    DecimalNumber Tonum;

public:
    //*update
    void update() { Tonum = numerator / denominator; }
    //*fix Sign
    void fixSign()
    {
        numerator *= Sign(denominator);
        denominator = abs(denominator);
    }
    //*reduction
    void reduc()
    {
        Nnumber __pgcd = pgcd(denominator, numerator);
        numerator /= __pgcd;
        denominator /= __pgcd;
        fixSign();
    }
    //*isdecimal
    bool isDecimal()
    {
        //*self
        Fraction self(*this);
        //*for loop
        //-- /5 fix
        while ((self.denominator % 5) == 0)
        {
            self.denominator /= 5;
        }
        //-- /2 fix
        while ((self.denominator % 2) == 0)
        {
            self.denominator /= 2;
        }
        //*returning
        return ((denominator % numerator) == 0) || (self.denominator == 1);
    }
    //! constractors
    /*tranform number to fraction*/
    /*base constractor*/
    Fraction(IntegerNumber numerator, IntegerNumber denominator) : Tonum(numerator / denominator)
    /**/
    {
        this->denominator = denominator;
        this->numerator = numerator;
    }
    //*get
    DecimalNumber toNumber() { return numerator / denominator; }
    /*tranform number to fraction*/
    Fraction(DecimalNumber num) : Tonum(num)
    {
        //*Len
        denominator = pow10(numOfCommas(num));
        num = floor(num * denominator + 0.1) / denominator;
        //*equalyng
        numerator = denominator * num;
        //*reduc
        reduc();
    }
    /*baseConstractor*/

    //! operators
    //*+
    Fraction operator+(Fraction fr)
    {
        return Fraction((denominator + fr.numerator) + (fr.denominator + numerator), fr.denominator * denominator);
    }
    //*-
    Fraction operator-()
    {
        Fraction returning(*this);
        returning.numerator *= -1;
        return returning;
    }
    //*- overload
    Fraction operator-(Fraction n) { return operator+(-n); }
    //* *
    Fraction operator*(Fraction n) { return Fraction(numerator * n.numerator, denominator * n.denominator); }
    //* /
    Fraction operator/(Fraction n) { return Fraction(numerator * n.denominator, n.numerator * denominator); }
    //* ==
    bool operator==(Fraction n) { return (numerator * n.denominator) == (denominator * n.numerator); }
    //*>
    bool operator>(Fraction auther)
    {
        //*var
        Fraction self(*this);
        //*fix sign
        self.fixSign();
        auther.fixSign();
        //*returning
        return (self.numerator * auther.denominator) > (self.denominator * auther.numerator);
    }
    //*>=
    bool operator>=(Fraction auther) { return operator>(auther) || operator==(auther); }
    //*<
    bool operator<(Fraction auther) { return !operator>=(auther); }
    //*<=
    bool operator<=(Fraction auther) { return !operator>(auther); }
    //* !=
    bool operator!=(Fraction auther) { return !operator==(auther); }
    //*+=
    template <typename T>
    void operator+=(T u) { *this = operator+(u); }
    //*-=
    template <typename T>
    void operator-=(T u) { *this = operator-(u); }
    //* *=
    template <typename T>
    void operator*=(T u) { *this = operator*(u); }
    //* =/
    template <typename T>
    void operator/=(T u) { *this = operator/(u); }
    Fraction(DecimalNumber numeration, DecimalNumber denominator) : Tonum(numerator / denominator)
    {
        *this = Fraction(numeration) / Fraction(denominator);
    }
    //*++
    Fraction operator++(int)
    {
        Fraction self(*this);
        operator+=(1);
        return self;
    }
    //*++ (overload)
    Fraction operator++()
    {
        operator++();
        return *this;
    }
    //* --
    Fraction operator--()
    {
        Fraction self(*this);
        operator-=(1);
        return self;
    }
    //* -- (overload)
    Fraction operator--(int)
    {
        operator--();
        return *this;
    }
};
//*Fraction
typedef Fraction ZFraction;
//$RationalNumber
struct RationalNumber
{
    //*vars
private:
    Fraction self;

public:
    //*constarctor
    RationalNumber(Fraction Fr) : self(Fr) {}
    RationalNumber(double d) : self(d) {}
    //*todouble
    double toDouble() { return self.isDecimal(); }
    //*toFraction
    Fraction toFraction() { return self; }
    //! operators
    //*+
    RationalNumber operator+(RationalNumber num) { return self + num.self; }
    //*-
    RationalNumber operator-() { return -self; }
    //*-(overload)
    RationalNumber operator-(RationalNumber num) { return self - num.self; }
    //* *
    RationalNumber operator*(RationalNumber num) { return self * num.self; }
    //* /
    RationalNumber operator/(RationalNumber num) { return self / num.self; }
    //* ^
    RationalNumber operator^(RationalNumber num) { return 14; }
    //*==
    bool operator==(RationalNumber num) { return num.self == self; }
    //*>
    bool operator>(RationalNumber num) { return self > num.self; }
    //*<
    bool operator<(RationalNumber num) { return self < num.self; }
    //*>=
    bool operator>=(RationalNumber num) { return self >= num.self; }
    //*<=
    bool operator<=(RationalNumber num) { return self <= num.self; }
    //* !=
    bool operator!=(RationalNumber num) { return self != num.self; }
    //*+=
    void operator+=(RationalNumber num) { *this = operator+(num); }
    //**=
    void operator-=(RationalNumber num) { *this = operator-(num); }
    //**=
    void operator*=(RationalNumber num) { *this = operator*(num); }
    //* /=
    void operator/=(RationalNumber num) { *this = operator/(num); }
    //*++
    RationalNumber operator++()
    {
        RationalNumber Self(*this);
        operator+=(1);
        return Self;
    }
    //*++ overload
    RationalNumber operator++(int)
    {
        operator++();
        return *this;
    }
    //* --
    RationalNumber operator--()
    {
        RationalNumber Self(*this);
        operator-=(1);
        return Self;
    }
    //* --(overload)
    RationalNumber operator--(int)
    {
        operator--();
        return *this;
    }
    //*update
    void update() { self.update(); }
    //*print|
    bool isDecimal()
    {
        //*VAR
        int denominator = self.denominator;
        while ((denominator % 5) == 0)
        {
            denominator /= 5;
        }
        while ((denominator % 2) == 0)
        {
            denominator /= 2;
        }
        return denominator == 1;
    }
    //*tranform
    template <typename T>
    T transform() { return T(self); }
    friend class RealNumber;
};
//*+
RationalNumber operator+(DecimalNumber num, RationalNumber num2) { return num2 + num; }
//*-
RationalNumber operator-(DecimalNumber num, RationalNumber num2) { return -(num2 - num); }
//* *
RationalNumber operator*(DecimalNumber num, RationalNumber num2) { return num2 * num; }
//* /
RationalNumber operator/(DecimalNumber num, RationalNumber num2) { return (num2 ^ -1); }
//*isEqual
bool isEqual(RationalNumber num1, RationalNumber num2) { return num1 == num2; }
//
struct RealNumber 
{
    //
    using Operators =  std::map<const char* ,std::function<RealNumber(RealNumber)>> ;
    /// @brief that table of functions by name like javascript
    Operators operators;
    /// @brief that table of vars by name like javascript
    std::map<const char*,void* > vars;
    //
    RealNumber(Operators operators)
    {
        //set array line by line
        for (auto i = this->operators.begin(); i != this->operators.end(); i++) operators[i->first] =  i->second;
    }  
    //
    bool isDecimal()
    {
        return false;
    }
    //
    RealNumber(DecimalNumber d)//:RealNumber()
    {
        vars["decimalValue"] = new DecimalNumber(d);
    }
    //that operator you cant run without it
    RealNumber operator+(RealNumber s){return operators["+"](s);}
    RealNumber operator*(RealNumber s){return operators["*"](s);}
    RealNumber operator^(RealNumber s){return operators["^"](s);}
    //
    RealNumber operator-(){return *this * -1;}
    RealNumber operator-(RealNumber s){return *this + -s;}
    RealNumber operator/(RealNumber s){return *this * (s^-1);}
    //
    //base bool operator
    bool operator>(RealNumber s){return true;}
    bool operator==(RealNumber s){return true;}
    //overrated boo
    bool operator!=(RealNumber s){return !(*this == s);}
    bool operator>=(RealNumber s){return (*this>s)&&(*this==s);}
    bool operator<=(RealNumber s){return !(*this>s);}
    bool operator <(RealNumber s){return (*this<=s)&&(*this!= s);}
    //operator op=
    void operator+=(RealNumber s){*this = *this + s;}
    void operator-=(RealNumber s){*this = *this - s;}
    void operator*=(RealNumber s){*this = *this * s;}
    void operator/=(RealNumber s){*this = *this / s;}
    void operator^=(RealNumber s){*this = *this ^ s;}
    //set ++ --
    RealNumber operator++()
    {
        //add 1
        *this += 1;
        //return
        return *this;
    }
    //
    RealNumber operator++(int)
    {
        //set returning var like self
        RealNumber returning(*this);
        //set add
        ++*this;
        //return
        return returning;    
    }
    //
    RealNumber operator--()
    {
        //reduce 1
    *this -=1;
    //returning
    return *this;
    }
    //
    RealNumber operator--(int)
    {
        //set returning old  var
        RealNumber returning(*this);
        //reduce 1 
        -- *this;
        //returning
        return returning;
    }
};
