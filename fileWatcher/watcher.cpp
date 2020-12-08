#include "watcher.h"
#include <QVBoxLayout>
#include <QDir>
#include <QMessageBox>
#include <QApplication>
watcher::watcher(QWidget *parent)
    : QWidget(parent)
{
    fsWatcher=new QFileSystemWatcher;
    QStringList args=qApp->arguments();
    QString path;
    if(args.count()>1){
        path=args[1];
    }else{
        path=QDir::currentPath();
    }
    pathLabel =new QLabel;
    pathLabel->setText("监视的目录："+path);
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(pathLabel);
    fsWatcher->addPath(path);
    connect(fsWatcher,&QFileSystemWatcher::directoryChanged,this,[=](const QString &key){
        directoryChanged(key);
    });
}

void watcher::directoryChanged(QString path){
    QMessageBox::information(NULL,"目录发生变化",path);
}

watcher::~watcher()
{
}

