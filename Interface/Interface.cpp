#include "Interface.h"

// 1) 创建全局唯一的、线程安全的单例对象
Q_GLOBAL_STATIC(Interface, interface)

Interface::Interface(QObject *parent)
    : QObject{parent}
{
    pageIndex = PAGE_HOME;
}

Interface *Interface::instance()
{
    return interface;
}

int Interface::getPAGE_MAIN()
{
    return PAGE_MAIN;
}

int Interface::getPAGE_HOME()
{
    return PAGE_HOME;
}

int Interface::getPAGE_AC()
{
    return PAGE_AC;
}

int Interface::getPAGE_APP()
{
    return PAGE_APP;
}

int Interface::getPAGE_SETTINGS()
{
    return PAGE_SETTINGS;
}

int Interface::getPAGE_CONTROL()
{
    return PAGE_CONTROL;
}

int Interface::getPreviousPageIndex() const
{
    return previousPageIndex;
}

void Interface::setPreviousPageIndex(int newPreviousPageIndex)
{
    if (previousPageIndex == newPreviousPageIndex)
        return;
    previousPageIndex = newPreviousPageIndex;
    emit previousPageIndexChanged();
}

int Interface::getPageIndex() const
{
    return pageIndex;
}

void Interface::setPageIndex(int newPageIndex)
{
    if (pageIndex == newPageIndex)
        return;
    pageIndex = newPageIndex;
    emit pageIndexChanged();
}
