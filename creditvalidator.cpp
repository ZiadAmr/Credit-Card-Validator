#include "creditvalidator.h"
#include "./ui_creditvalidator.h"

#include <iostream>
#include <QTextStream>

#include <regex>

CreditValidator::CreditValidator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreditValidator)
{
    ui->setupUi(this);
}

CreditValidator::~CreditValidator()
{
    delete ui;
}

int ctoi(char c){
    return c - 48;
}

void CreditValidator::on_pushButton_clicked()
{
    std::string searchString = ui->lineEdit->text().toStdString();

    std::regex mastercard("^(5[1-5][0-9]{14}|2(22[1-9][0-9]{12}|2[3-9][0-9]{13}|[3-6][0-9]{14}|7[0-1][0-9]{13}|720[0-9]{12}))$");
    std::regex visa("^4[0-9]{12}(?:[0-9]{3})?$");
    std::regex amex("^3[47][0-9]{13}$");

    // Luhn's Algorithm
    int sum = 0;
    bool alternate = false;

    // remove spaces, dashes etc. from string
    searchString = std::regex_replace(searchString, std::regex(R"([\D])"), "");

    for(int i = searchString.length()-1; i >= 0; i--){
        if(alternate){
            int number = 2 * ctoi(searchString[i]);
            std::string n = std::to_string(number);
            for(int j = 0; j < n.length(); j++){
                sum += ctoi(n[j]);
            }
        } else {
            sum += ctoi(searchString[i]);
        }
        alternate = !alternate;
    }

    if(sum % 10 != 0){
        ui->label_3->setText(QString("Invalid Card Number"));
    } else if(std::regex_match(searchString, mastercard)){
        ui->label_3->setText(QString("Mastercard"));
    } else if (std::regex_match(searchString, visa)){
        ui->label_3->setText(QString("Visa"));
    } else if (std::regex_match(searchString, amex)){
        ui->label_3->setText(QString("American Express"));
    } else {
        ui->label_3->setText(QString("Invalid Card Number"));
    }
}

