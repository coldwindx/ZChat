#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <memory>
#include <QNetworkAccessManager>
#include "singleton.h"

class HttpManager : public QObject, public Singleton<HttpManager>, public std::enable_shared_from_this<HttpManager>
{
    Q_OBJECT
public:
    ~HttpManager();
private:
    friend class Singleton<HttpManager>;
    HttpManager();
    QNetworkAccessManager _manager;
signals:
    void finished();
};

#endif // HTTPMANAGER_H
