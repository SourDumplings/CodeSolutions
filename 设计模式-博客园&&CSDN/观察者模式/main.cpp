/*
 @Date    : 2018-05-05 19:37:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
案例：在教室里老师还没有来，同学都在干着各的事情，小张正在打游戏，小李正在抄作业.....,  现在同学们要求班长当卧底，监视老师，当老师来了通知大家一声。然后打游戏的马上停止，抄作业的也停止。
这里班长相当于是一个通知者， 小张、小李，以及其他同学显然是监听者，他们监听了班长那的消息，一旦老师来了马上采取相关的行动。
首先，先把通知真的行为抽象为一个接口（因为，子类可能监听的东西不同，可能学习委员监听班主任老师，班长监听数学老师等等，但是我们这里这个例子监听没有那么仔细。）
注意同学是监听者，班长是通知者，感觉有点小别扭，但这个例子就是这样。。。
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <algorithm>
#include <memory>

using namespace std;

// 监听者抽象类，其中要实现被通知的接口
class TeacherListener
{
public:
    virtual void teacher_coming() = 0;
    virtual void do_bad_thing() = 0;
};

// 监听者具体类
class XiaoZhang: public TeacherListener
{
public:
    void teacher_coming() override
    {
        stop_copy();
        return;
    }
    void do_bad_thing() override
    {
        copy_homework();
        return;
    }
private:
    void stop_copy()
    {
        cout << "老师来了，停止抄作业！" << endl;
        return;
    }
    void copy_homework()
    {
        cout << "小张抄作业啦！！" << endl;
        return;
    }
};

class XiaoLi: public TeacherListener
{
public:
    void teacher_coming() override
    {
        stop_play_game();
        return;
    }
    void do_bad_thing() override
    {
        play_game();
        return;
    }
private:
    void stop_play_game()
    {
        cout << "老师来了，停止打游戏！" << endl;
        return;
    }
    void play_game()
    {
        cout << "小李打游戏啦！！" << endl;
        return;
    }
};


// 通知者抽象类,即抽象主题类，要实现增删监听者和通知监听者接口
class Notifier
{
public:
    virtual void add_listener(const shared_ptr<TeacherListener> &pTeacherListener) = 0;
    virtual void remove_listener(const shared_ptr<TeacherListener> &pTeacherListener) = 0;
    virtual void notify() = 0;
};

// 班长，即通知者具体类
class Moniter: public Notifier
{
public:
    void add_listener(const shared_ptr<TeacherListener> &pTeacherListener) override
    {
        m_listeners.push_back(pTeacherListener);
        cout << "班长帮忙罩着" << endl;
        return;
    }
    void remove_listener(const shared_ptr<TeacherListener> &pTeacherListener) override
    {
        auto it = find(m_listeners.begin(), m_listeners.end(), pTeacherListener);
        m_listeners.erase(it);
        return;
    }
    void notify() override
    {
        cout << "班长：老师来啦！" << endl;
        for (auto &pTeacherListener : m_listeners)
        {
            pTeacherListener->teacher_coming();
        }
        return;
    }
private:
    list<shared_ptr<TeacherListener>> m_listeners;
};

int main(int argc, char const *argv[])
{
    shared_ptr<Notifier> m(new Moniter);
    shared_ptr<TeacherListener> xz(new XiaoZhang), xl(new XiaoLi);
    m->add_listener(xz);
    xz->do_bad_thing();
    m->add_listener(xl);
    xl->do_bad_thing();

    m->notify();

    return 0;
}

