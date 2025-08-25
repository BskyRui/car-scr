#include "Interface.h"

// 1) 创建全局唯一的、线程安全的单例对象
Q_GLOBAL_STATIC(Interface, interface)

Interface::Interface(QObject *parent)
    : QObject{parent}
{}

Interface *Interface::instance()
{
    return interface;
}
