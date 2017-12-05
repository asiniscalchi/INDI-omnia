#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include "indibase/baseclientqt.h"

class IndiClient : public INDI::BaseClientQt
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);

signals:

public slots:
};

#endif // INDICLIENT_HPP
