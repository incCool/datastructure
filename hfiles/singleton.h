//
// Created by inc on 2018/10/8.
//

#ifndef DATASTRUCTURE_SINGLETON_H
#define DATASTRUCTURE_SINGLETON_H

#include <iostream>

using namespace std;

//懒汉式
class Singelton {
private:
    Singelton() {
        m_singer = NULL;
        m_count = 0;
        cout << "构造函数Singelton ... do" << endl;
    }

public:
    static Singelton *getInstance() {
        if (m_singer == NULL)  //懒汉式：1 每次获取实例都要判断 2 多线程会有问题
        {
            m_singer = new Singelton;
        }
        return m_singer;
    }

    static void printT() {
        cout << "m_count: " << m_count << endl;
    }

private:
    static Singelton *m_singer;
    static int m_count;
};

Singelton *Singelton::m_singer = NULL;  //懒汉式 并没有创建单例对象
int Singelton::m_count = 0;


void main01_1() {
    cout << "演示 懒汉式" << endl;
    Singelton *p1 = Singelton::getInstance(); //只有在使用的时候，才去创建对象。
    Singelton *p2 = Singelton::getInstance();
    if (p1 != p2) {
        cout << "不是同一个对象" << endl;
    } else {
        cout << "是同一个对象" << endl;
    }
    p1->printT();
    p2->printT();


    return;
}

#endif //DATASTRUCTURE_SINGLETON_H
