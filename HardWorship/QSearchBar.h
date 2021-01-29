#ifndef QSEARCHBAR_H
#define QSEARCHBAR_H

#include <QLineEdit>

class QSearchBar : public QLineEdit
{
    Q_OBJECT

public:
    QSearchBar(QWidget *parent = 0);
    virtual ~QSearchBar();

signals:
    void focussed();
    void unfocussed();

protected:
    virtual void focusInEvent(QFocusEvent *) override;
    virtual void focusOutEvent(QFocusEvent *) override;
};

#endif // QSEARCHBAR_H
