#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>

// 2) 单例模式的宏定义
#define INTERFACE Interface::instance()

class Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject *parent = nullptr);
    static Interface *instance();

signals:
};

#endif // INTERFACE_H
