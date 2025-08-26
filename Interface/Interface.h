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

    const static int PAGE_MAIN = 0;// 功能界面
    const static int PAGE_HOME = 1; // 主页
    const static int PAGE_AC = 2; // 空调
    const static int PAGE_APP = 3;// 应用
    const static int PAGE_SETTINGS = 4; // 设置
    const static int PAGE_CONTROL = 5; // 控制中心

    // 主页
    int pageIndex; // 右键，重构，Generate Q_PROPERTY and Missing Members
    int previousPageIndex;

    int getPageIndex() const;
    void setPageIndex(int newPageIndex);

    int getPreviousPageIndex() const;
    void setPreviousPageIndex(int newPreviousPageIndex);

    static int getPAGE_CONTROL();

    static int getPAGE_SETTINGS();

    static int getPAGE_APP();

    static int getPAGE_AC();

    static int getPAGE_HOME();

    static int getPAGE_MAIN();

signals:
    void pageIndexChanged();
    void previousPageIndexChanged();

private:
    Q_PROPERTY(int pageIndex READ getPageIndex WRITE setPageIndex NOTIFY pageIndexChanged FINAL)
    Q_PROPERTY(int previousPageIndex READ getPreviousPageIndex WRITE setPreviousPageIndex NOTIFY previousPageIndexChanged FINAL)
    Q_PROPERTY(int PAGE_CONTROL READ getPAGE_CONTROL CONSTANT FINAL)
    Q_PROPERTY(int PAGE_SETTINGS READ getPAGE_SETTINGS CONSTANT FINAL)
    Q_PROPERTY(int PAGE_APP READ getPAGE_APP CONSTANT FINAL)
    Q_PROPERTY(int PAGE_AC READ getPAGE_AC CONSTANT FINAL)
    Q_PROPERTY(int PAGE_HOME READ getPAGE_HOME CONSTANT FINAL)
    Q_PROPERTY(int PAGE_MAIN READ getPAGE_MAIN CONSTANT FINAL)
};

#endif // INTERFACE_H
