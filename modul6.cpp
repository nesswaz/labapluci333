#include "laura6.h"
#include <iostream>
#include <cmath>
using namespace std;

int Nod(int m, int n) {
    m = abs(m);
    n = abs(n);
    int res = 0;
    while (n != 0) {
        res = m % n;
        m = n;
        n = res;
    }
    return m;
}

void Socr(int &chislitel, int &znamenatel) {
    int nod = Nod(chislitel, znamenatel);
    chislitel = chislitel / nod;
    znamenatel = znamenatel / nod;
    
}

void Summ(int c1, int z1, int c2, int z2, int &sum_chislitel, int &sum_znamenatel) {
    sum_chislitel = c1 * z2 + c2 * z1;
    sum_znamenatel = z1 * z2;
    Socr(sum_chislitel, sum_znamenatel);
}

void Mult(int c1, int z1, int c2, int z2, int &c, int &z) {
    c = c1 * c2;
    z = z1 * z2;
    Socr(c, z );
}

int print() {
    int a, b, c, d, k, m, e, f;
    cout << "Введите числа(дроби) a, b, c, d, k, m, e, f" << endl;
    cout << "Вычисляем выражение (a/b + c/d + k/m) * e/f" << endl;
    cout << "a/b: "; 
    cin >> a >> b;
    cout << "c/d: "; 
    cin >> c >> d;
    cout << "k/m: "; 
    cin >> k >> m;
    cout << "e/f: "; 
    cin >> e >> f;
    
    if (b == 0 || d == 0 || m == 0 || f == 0) {
        cout << "Ошибка: знаменатель не может быть нулем!" << endl;
        return 1;
    }

    // Вычисление выражения: (a/b + c/d + k/m) * e/f
    int sum1_c = 0;  
    int sum1_z = 0; 
    // a/b + c/d
    Summ(a, b, c, d, sum1_c, sum1_z);
    
    int sum2_c = 0;  
    int sum2_z = 0;  
    // (a/b + c/d) + k/m
    Summ(sum1_c, sum1_z, k, m, sum2_c, sum2_z);
    
    int result_c = 0;  
    int result_z = 0;  
    // (a/b + c/d + k/m) * e/f
    Mult(sum2_c, sum2_z, e, f, result_c, result_z);

    cout << "Ответ: " << "Числитель = "  << result_c << " "<< "Знаменатель = " << result_z << endl;
    return 0;
}

//написать примеры 4 теста
//1
//a=1, b=2, c=1, d=3, k=1, m=6, e=1, f=1
//(1/2 + 1/3 + 1/6) * 1/1 = 1 * 1 = 1; числитель = 1, знаменатель = 1;

//2
//a=1, b=3, c=1, d=3, k=1, m=3, e=3, f=1
//(1/3 + 1/3 + 1/3) * 3/1 = 1 * 3 = 3; числитель = 3, знаменатель = 1;

//3
//a=-1, b=2, c=1, d=4, k=1, m=4, e=2, f=1
//(-1/2 + 1/4 + 1/4) * 2/1 = 0 * 2 = 0; числитель = 0, знаменатель = 1;

//4
//a=1, b=2, c=1, d=0(знам. не мож = 0), k=1, m=3, e=1, f=1
//Ошибка: знаменатель не может быть нулем!