#ifndef SRC_CONSOLE_H
#define SRC_CONSOLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class src_console;
}
QT_END_NAMESPACE

class src_console : public QMainWindow
{
    Q_OBJECT

public:
    src_console(QWidget *parent = nullptr);
    ~src_console();

private slots:
    void on_consoleInput_returnPressed();

    void on_pushButton_3_clicked();

private:
    Ui::src_console *ui;
};
#endif // SRC_CONSOLE_H
