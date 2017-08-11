#include <QApplication>
#include <QDebug>
#include "gameoflife.h"
#include "cpp/wmanager.h"

WManager                            *WManager::_singleton                   = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WManager::getInstance()->load();
    qDebug() << "avant return a.exec dans le main.";
    return a.exec();
}
