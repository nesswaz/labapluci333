
#include "laura.h"
#include <iostream>
#include <cmath>
using namespace std;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool IsPowerN(int K, int N) {
    if (K < 1 || N < 2) return 0;
    if (K == 1) return 1;
    int power = 1;
    while (power < K) {
        power = power * N;
        if (power == K) return 1;
        if (power > K || power < 0) break;
    }
    return 0;
}

void taskProc27() {
    cout << "1) Задача - Proc27 " << endl;
    int N;
    cout << "Введите N (>1): ";
    cin >> N;
    int cnt = 0;
    int K;
    cout << "Введите 10 целых положительных чисел: ";
    for (int i = 0; i < 10; i++) {
        cin >> K;
        if (IsPowerN(K,  N)) {
            cout << K << " - True" << endl;
            cnt++;
        }
        else {
            cout << K << " - False" << endl;
        }
    }
    cout << "Количество степеней числа " << N << " в наборе = " << cnt << endl;
    cout << "Конец задачи." << endl;
}

//------------------------------------------------------------------------------------


void sortdec3(float &a, float &b, float &c){
    float t = 0.0;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    if (a < c) {
        t = a;
        a = c;
        c = t;
    }
    if (b < c) {
        t = b;
        b = c;
        c = t;
    }
}

void Proc13() {
    cout << "2) Задача - Proc13" << endl;
    for (int i = 1; i <= 2; i++) {
        float a, b, c;
        cout << "Введите числа a" << i << " b" << i << " c" << i <<": ";
        cin >> a >> b >> c;
        sortdec3(a, b, c);
        cout << a << " " << b << " " << c << endl;
    }
    cout << "Конец задачи." << endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double Ln(double x, double e) {
    if (fabs(x) >= 1 || e <= 0) {
        cout << "Ошибка: введены неверные значения" << endl;
        return 0;
    }
    double result = x;
    double a = x;
    double i = 1;
    while (fabs(a) > e) {
        i = i + 1;
        a = -a * x * (i-1) / i;
        result += a;
    }
    return result;
}

void Proc43() {
    cout << "3) Задача - Proc43 " << endl;
    double x;
    cout << "Введите число x, |x| < 1" << endl;
    cin >> x;
    double e1;
    double log1 = log(1 + x);
    cout << "Точное значение = " << log1 << endl;
    cout << "Введите 6 значений эпсилон (эпсилон > 0):" << endl;
    for (int i = 1; i < 7; i++) {
        cin >> e1;
        cout << "Результат " << i << " функции: " <<  Ln(x, e1) << endl;
    }
    cout << "Конец задачи." << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int desyat(int num, int p) {
    if (p < 2 || p > 9) {
        cout << "Вы ввели неправильно СС." << endl;
        return 0;
    }

    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num; //rabotaet s modulem chisla
    }

    int res = 0;
    int i = 0; //текущая степень 
    int copy = num;
    
    while (copy > 0) { //проверка правильных цифр в числе
        int v = copy % 10;
        if (v >= p) {
            cout << "Число содержит цифры больше самой системы счисления " << endl;
            return 0;
        }
        copy = copy / 10;
    }

    copy = num;
    while (copy > 0) { 
        int v = copy % 10;
        res +=  v * pow(p,i);
        i++;
        copy = copy / 10;
    }
    return sign * res; //vozvrazhyaem znachenie so znakom
}

int TheTri13() {
    cout << "4) Задача - TheTri13" << endl;
    int x, p;
    cout << "Введите систему счисления числа x - Р [2-9] " << endl;
    cin >> p;
    cout << "Введите число x, чтобы перевести в 10 систему счисления " << endl;
    cin >> x;

    if (p < 2 || p > 9) {
        cout << "Вы ввели неправильно СС. Запустите задачу заново." << endl;
        return 1;
    }

    int tempX = abs(x);
    while (tempX > 0) { 
        int v = tempX % 10;
        if (v >= p) {
            cout << "Число X записано неправильно" << endl;
            break;
        }
        tempX = tempX / 10;
    }
    int ct = desyat(x, p);
    cout << "Число "<< x << " в 10СС: " << ct << endl;
    return 0;
}


//--------------------------------------------------------------------

int Reccur12(int number) {
    if (number == 1){
        return 2;
    }
    else {
        return number * (number + 1) + Reccur12(number - 1);
    }
}

int Reccur12z() {
    cout << "5) Задача - Reccur12 " << endl;
    int n, s = 0;
    cout << "Введите N - кол-во первых членов последовательности:" << endl;
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "Ошибка, введите другое значение N." << endl;
        //n = 1;
        return 1;
    }
    else {
        cout << "Сумма = " << Reccur12(n) << endl;
        return 0;
    }

}

//endendendendendendendendendendendendendendendendendendendendendendendendendendendendendendendendendendend