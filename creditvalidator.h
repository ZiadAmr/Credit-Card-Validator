#ifndef CREDITVALIDATOR_H
#define CREDITVALIDATOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CreditValidator; }
QT_END_NAMESPACE

class CreditValidator : public QWidget
{
    Q_OBJECT

public:
    CreditValidator(QWidget *parent = nullptr);
    ~CreditValidator();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreditValidator *ui;
};
#endif // CREDITVALIDATOR_H
