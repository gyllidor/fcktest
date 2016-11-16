#include <iostream>

class A
{
public:
    A() { std::cout << "A()" << std::endl; }
    virtual ~A() { std::cout << "~A()" << std::endl; }

    void f1() { std::cout << "A::f1()" << std::endl; }
    void f2() const { std::cout << "A::f2() const" << std::endl; }
    virtual void f3() { std::cout << "virtual A::f3()" << std::endl; }
    static void f4() { std::cout << "static A::f4()" << std::endl; }
    void f5(int i) { std::cout << "A::f5 int (" << i << ")" << std::endl; }
    void f5(long i) { std::cout << "A::f5 long(" << i << ")" << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }

    struct C
    {
        C() {std::cout << "C()" << std::endl;}
        ~C() {std::cout << "~C()" << std::endl;}
    } c;

    void f1() { std::cout << "B::f1()" << std::endl; }
    void f2() const { std::cout << "B::f2() const" << std::endl; }
    virtual void f3() { std::cout << "virtual B::f3()" << std::endl; }
    static void f4() { std::cout << "static B::f4()" << std::endl; }
    void f5(int i) { std::cout << "B::f5 int (" << i << ")" << std::endl; }
    void f5(long i) { std::cout << "B::f5 long(" << i << ")" << std::endl; }
};

int main(int argc, char *argv[])
{
    int a[100];
    for (int* i = a; i != &a[100]; ++i)
    {
        std::cout << i << " " << a << std::endl;
        std::cout << i - a << std::endl;
        *i = i - a;
    }

    std::cout << *(a + 25) << std::endl;

    B b;
    A& a1 = b;
    a1.f1();
    a1.f2();
    a1.f3();
    a1.f4();
    a1.f5(INT32_MAX + 1);
    std::cout << INT32_MAX << std::endl;

    return 0;
}
