/*
 @Date    : 2018-05-06 15:50:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
RemoteControl为遥控器，LightOnCommand为开灯请求对象，
LightOffCommand为关灯请求对象，他们继承自基类Command，这样设计可以使插槽在以后防止其他的装置。
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// 点灯类，即receiver
class Light
{
public:
    void on()
    {
        cout << "灯开了" << endl;
        return;
    }
    void off()
    {
        cout << "灯关了" << endl;
        return;
    }
};

// 命令抽象类
class Command
{
public:
    virtual void execute() = 0;
};

// 命令具体类
class LightOnCommand: public Command
{
public:
    LightOnCommand(const shared_ptr<Light> &pLight): m_light(pLight) {}
    void execute() override
    {
        m_light->on();
        return;
    }
private:
    shared_ptr<Light> m_light;
};

class LightOffCommand: public Command
{
public:
    LightOffCommand(const shared_ptr<Light> &pLight): m_light(pLight) {}
    void execute() override
    {
        m_light->off();
        return;
    }
private:
    shared_ptr<Light> m_light;
};

// 遥控器类，即invoker
class RemoteControl
{
public:
    void set_command(const shared_ptr<Command> &command)
    {
        button = command;
        return;
    }
    void press_button()
    {
        button->execute();
        return;
    }
private:
    shared_ptr<Command> button;
};

int main(int argc, char const *argv[])
{
    shared_ptr<RemoteControl> lightOnControl(new RemoteControl), lightOffControl(new RemoteControl);
    shared_ptr<Light> light;

    shared_ptr<LightOnCommand> onCommand(new LightOnCommand(light));
    shared_ptr<LightOffCommand> offCommand(new LightOffCommand(light));

    lightOnControl->set_command(onCommand);
    lightOffControl->set_command(offCommand);

    lightOnControl->press_button();
    cout << "开灯玩耍" << endl;
    lightOffControl->press_button();

    return 0;
}

