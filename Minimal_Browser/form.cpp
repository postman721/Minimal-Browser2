#include "form.h"
#include "ui_form.h"
#include <QFileDialog>
#include <QKeyEvent>
#include <QString>
#include <QWebView>
#include <QtWidgets>
#include <QUrl>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPrinter>
#include <QPageLayout>
#include <QWebInspector>
#include <QCoreApplication>
#include <QProcess>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

//Basic page downloading.
        ui->webView->page()->setForwardUnsupportedContent(true);
        ui->webView->load(QUrl("https://duckduckgo.com/"));

//Delegate links to new webview
ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

//Settings
        ui->webView->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::PluginsEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::PrivateBrowsingEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::SpatialNavigationEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::PrivateBrowsingEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::Accelerated2dCanvasEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::AutoLoadImages,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::ScrollAnimatorEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::FullScreenSupportEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::WebGLEnabled,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
        ui->webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
}

Form::~Form()
{
    delete ui;
}

void Form::on_addressbar_returnPressed()
{

        QString x;
        x=ui->addressbar->text();

        QString y;
        y="https://";

        QString z;
        z="www.";

        QString o;
        o="";

        QString search;
        search="search:";
        QString searching;
        searching=ui->addressbar->text();
// Search engine
        QString engine="https://duckduckgo.com/?q=" + searching;


        if(ui->addressbar->text().startsWith(o)){ui->webView->load(QUrl(y+x));
            ui->addressbar->setText(x);}

        if(ui->addressbar->text().startsWith(search)){ui->webView->load(QUrl(engine));}

}

void Form::on_back_clicked()
{
    ui->webView->back();
    ui->addressbar->setText(ui->webView->url().toString());

}

void Form::on_forward_clicked()
{
    ui->webView->forward();
    ui->addressbar->setText(ui->webView->url().toString());

}

void Form::on_reload_clicked()
{
    ui->webView->reload();
    ui->addressbar->setText(ui->webView->url().toString());

}

void Form::on_print_clicked()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() != QDialog::Accepted) return;
    ui->webView->print(&printer);
}

void Form::on_stop_clicked()
{
    ui->webView->stop();
}

void Form::on_download_clicked()
{
    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAttribute(Qt::WA_DeleteOnClose);
    QString urls= ui->webView->url().toString();
    QString filename;
    filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                "",
                                                tr("All files (*"));

    QString getme=ui->webView->url().toString();
    QProcess proc;
    QStringList args;
    args << getme;
    args << "-O";
    args << filename;

   proc.start("wget", args);
        proc.waitForFinished();
        qDebug() << proc.readAllStandardOutput();
}

void Form::on_zoomplus_clicked()
{
     ui->webView->setZoomFactor(ui->webView->zoomFactor()+.2);
}

void Form::on_zoominus_clicked()
{
     ui->webView->setZoomFactor(ui->webView->zoomFactor()-.2);
}


void Form::on_home_clicked()
{
     ui->webView->load(QUrl("https://duckduckgo.com/"));
     ui->addressbar->setText(ui->webView->url().toString());
}

void Form::on_webView_loadFinished(bool arg1)
{
    if (arg1){
        ui->addressbar->setText(ui->webView->url().toString());}

}
