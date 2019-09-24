/*
 @Date    : 2018-01-04 16:15:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p544
 */

#ifndef FOLDER_MESSAGE_H
#define FOLDER_MESSAGE_H

#include <string>
#include <set>

using namespace std;

class Message;

class Folder
{
public:
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void add_to_Messages(const Folder &f);
    void remove_from_Messages();
    Folder(const Folder &f);
    ~Folder() { remove_from_Messages(); }
    Folder& operator=(const Folder &f);
private:
    set<Message*> msgs;
};


class Message
{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""): contents(str) {}
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message &&m);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFldr(Folder *pf) { folders.insert(pf); }
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_folders(Message *m);
};

void Message::move_folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
    return;
}

Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_folders(&m);
}

Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
    return;
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
    return;
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
    return;
}

Message::Message(const Message &m)
{
    add_to_Folders(m);
    return;
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
    return;
}

Message::~Message()
{
    remove_from_Folders();
    return;
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
    {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->remMsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders)
    {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->addMsg(&rhs);
    }
    return;
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : f.msgs)
    {
        msg->addFldr(this);
    }
}

void Folder::remove_from_Messages()
{
    for (auto msg : msgs)
    {
        msg->remove(*this);
    }
    return;
}

Folder::Folder(const Folder &f): msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_Messages();
    msgs= f.msgs;
    add_to_Messages(f);
    return *this;
}

#endif
