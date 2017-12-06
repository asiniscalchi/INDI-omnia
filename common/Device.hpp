#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <QString>

class Device
{
public:
    Device(const QString &type);

    QString name() const;

private:
    QString mName;
};


#endif // DEVICE_HPP
