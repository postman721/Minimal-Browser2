#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
     void on_addressbar_returnPressed();

     void on_back_clicked();

     void on_forward_clicked();

     void on_reload_clicked();

     void on_print_clicked();

     void on_stop_clicked();

     void on_download_clicked();

     void on_zoomplus_clicked();

     void on_zoominus_clicked();
     void on_home_clicked();

     void on_webView_loadFinished(bool arg1);

private:
    Ui::Form *ui;
};

#endif // FORM_H
