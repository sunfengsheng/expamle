#ifndef WATCHER_H
#define WATCHER_H

#include <QWidget>
#include <QLabel>
#include <QFileSystemWatcher>
class watcher : public QWidget
{
    Q_OBJECT

public:
    watcher(QWidget *parent = nullptr);
    ~watcher();

public slots:
    void directoryChanged(QString path);

private:
    QLabel *pathLabel;
    QFileSystemWatcher *fsWatcher;

};
#endif // WATCHER_H
