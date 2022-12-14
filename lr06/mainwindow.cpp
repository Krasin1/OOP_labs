#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString parser(const QString & str){
    std::string temp = str.toStdString();
    char * stri = new char[temp.size() + 1];
    strcpy(stri, temp.c_str());


    int count = 0;
    for(int i = 0; i < temp.size() && stri[i] != '+' && stri[i] != '-' && stri[i] != '*' && stri[i] != '/'; ++i) {
        count++;
    }
    if (count == temp.size()){
        delete [] stri;
        return "Знак операции не считан";
    }


    QString left = str.left(count);
    QString operation = str.mid(count, 1);


    count = 0;
    for(int i = temp.size(); i > 0 && stri[i] != '+' && stri[i] != '-' && stri[i] != '*' && stri[i] != '/'; --i) {
        count++;
    }
    QString right = str.right(count - 1);


    delete []  stri;
    char op = operation.at(0).toLatin1();


    bool check = false;
    double x = left.toDouble(&check);
    if (!check) {
        return "Первое число не считано";
    }
    double y = right.toDouble(&check);
    if (!check) {
        return "Второе число не считано";
    }


    QString result;
    switch(op) {
        case '+':{
            x += y;
            result = QString::number(x);
            return result;
            break;
        }
        case '-':{
            x -= y;
            result = QString::number(x);
            return result;
            break;
        }
        case '*':{
            x *= y;
            result = QString::number(x);
            return result;
            break;
        }
        case '/': {
            if (y == 0)
                return "Division by zero!!!";
            x /= y;
            result = QString::number(x);
            return result;
            break;
        }
    }

    return "Error!!!";
}

void MainWindow::on_pushButton_clicked()
{
    QString str{ui->lineEdit->text()};
    str = str.simplified().replace(" ", "");

    ui->lineEdit->setText(parser(str));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
}


void MainWindow::on_actionCalculate_triggered()
{
    MainWindow::on_pushButton_clicked();
}


void MainWindow::on_actionClean_triggered()
{
    MainWindow::on_pushButton_2_clicked();
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_action_triggered()
{
    ui->lineEdit->setText("Дунаев Влад ИКПИ-14");
}

