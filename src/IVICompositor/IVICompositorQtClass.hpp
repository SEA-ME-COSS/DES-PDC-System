#ifndef IVICOMPOSITORQTCLASS_HPP
#define IVICOMPOSITORQTCLASS_HPP

#include <QObject>

class IVICompositorQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 gear READ gear WRITE setGear NOTIFY gearChanged)

private:
    quint16 Qgear;

public:
    explicit IVICompositorQtClass(QObject *parent = nullptr);

    quint16 gear() const;

    void setGear(uint16_t _gear);

signals:
    void gearChanged();
};

extern IVICompositorQtClass carinfo;

#endif

