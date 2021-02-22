/*
 * @Author: Mayc
 * @Date: 2021-02-22 13:22:07
 * @LastEditTime: 2021-02-22 13:34:30
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 64. 求 1 + 2 +...+ n\source_code.cpp
 * @这是一个漂亮的注释头
 */
// 构造函数
class Temp{
public:
    Temp(){ ++N; Sum += N; };
    static void Reset() {
        N = 0;
        Sum = 0;
    }
    static int GetSum() { return Sum; };
private:
    static int N;
    static int Sum;
};
int Temp::N = 0;
int Temp::Sum = 0;

class Solution {
public:
    int sumNums(int n) {
        Temp::Reset();
        vector<Temp> ans(n);
        return Temp::GetSum();
    }
};

// 虚函数
class A{
public:
    virtual int Sum( int n ){
        return 0;
    }
};
vector<A*> Array(2);
class B: public A{
    virtual int Sum( int n ){
        return Array[!!n]->Sum(n - 1) + n;
    }
};

class Solution {
public:
    int sumNums(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        int value = Array[1]->Sum(n);
        return value;
    }
};

// 函数指针 C
typedef int(*fun)(int);
int Solution_Teminator(int n){
    return 0;
}

int sumNums(int n) {
    static fun f[2] = {Solution_Teminator, sumNums};
    return n + f[!!n](n - 1);
}
