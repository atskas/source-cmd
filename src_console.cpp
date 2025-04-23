#include <iostream>
#include <QProcess> // Need this for the console function
#include <QTimer>
#include "src_console.h"
#include "ui_src_console.h"

src_console::src_console(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::src_console)
{
    ui->setupUi(this);
}

src_console::~src_console()
{
    delete ui;
}

void src_console::on_consoleInput_returnPressed()
{
    QString input = ui->consoleInput->text();
    if (input.isEmpty()) return;

    if (input == "clear" || input == "clr") {
        ui->console->clear();
        ui->consoleInput->clear();
        return;
    }

    std::cout << "Input received" << std::endl;
    ui->consoleInput->clear();
    ui->console->append(input);
    ui->consoleInput->clear();

    QTimer::singleShot(150, this, [=] {
        QProcess process;

    #ifdef Q_OS_WIN
        process.start("cmd.exe", QStringList() << "/c" << input);
    #else
        process.start("bash", QStringList() << "-c" << input);
    #endif

        process.waitForFinished(); // Wait until command finishes

        QString output = QString::fromLocal8Bit(process.readAllStandardOutput());
        QString error = QString::fromLocal8Bit(process.readAllStandardError());

        if (!output.isEmpty())
            ui->console->append(output);
        if (!error.isEmpty())
            ui->console->append(error);
    });
}


void src_console::on_pushButton_3_clicked()
{
    if (!ui->consoleInput->text().isEmpty()) {
        on_consoleInput_returnPressed();
    }
}


