#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<stdlib.h>
#include<iostream>
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include<QtWebKit>
#include <QWebFrame>
#include <QVideoEncoderSettings>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_webView_linkClicked(const QUrl &arg1);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void on_commandLinkButton_clicked();

    void on_webView_loadStarted();

    void on_textEdit_textChanged();

    void on_back_clicked();

    void on_forward_clicked();

    void on_source_triggered();

    void on_pushButton_2_clicked();

    void on_forward_2_clicked();

    void on_widget_windowTitleChanged(const QString &title);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
