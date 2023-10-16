#include<iostream>
using namespace std;
class Fraction
{
    private:
        int numerator,denominator;
        static int count;
    public:
        Fraction(int a, int b):numerator(a),denominator(b){};//
        Fraction():numerator(1),denominator(1){};//
        Fraction(int a):numerator(a),denominator(1){};//
        void add(const Fraction &obj1,const Fraction &obj2);//
        friend void mul(const Fraction &obj1,const Fraction &obj2);//
        static void show_count();//
        void print_fraction()const;//
};
int main()
{
    Fraction r1;
    Fraction r2(5,4);
    Fraction r3(r2);
    return 0;
}