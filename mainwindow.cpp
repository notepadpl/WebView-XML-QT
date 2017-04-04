#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchbox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SearchBox searchEdit ;
ui->textEdit->setTextBackgroundColor(Qt::transparent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
/*tutaj bobieram url z line edit i  podaje komponentowi webView*/
  /* ui->webView->load(("http://"+ui->lineEdit->text()));

      ui->webView->show();*/
      QString url_str = ui->lineEdit->text();
      if (!url_str.startsWith("http://"))
      {
      url_str = "http://"+url_str;
      }
      QUrl url(url_str);
      ui->webView->load(url);
    /*  QVideoEncoderSettings videoSettings;
      videoSettings.setCodec("/home/eho/C/lesson35_linux/data/Face2.avi");
      videoSettings.setResolution(640, 480);
*/


}

void MainWindow::on_webView_linkClicked(const QUrl &arg1)
{

}

void MainWindow::on_actionOpen_triggered()
{
    /*tutaj mam zdefinowane otwieranie pliku na pasku zadań ale nie działa*/
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;Page Files (*.html *.xml *.cs *.js *.java *.py *.cpp *.c)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }


        QTextStream in(&file);
        ui->webView->setWindowFilePath(("html/index.html"));
         ui->webView->show();
        file.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    /*tu jest save robir to tak ze wysylam zrodlo strony do text rdit i wtedy zapisuje zrodlo*/
     ui->textEdit->setPlainText(ui->webView->page()->currentFrame()->toHtml());
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),

            tr("Text Files (*.txt);;HTML Files (*.html *.xml)"));

    if (!fileName.isEmpty()) {

        QFile file(fileName);

        if (!file.open(QIODevice::WriteOnly)) {

            // error message

        } else {

            QTextStream stream(&file);

            stream << ui->textEdit->toPlainText();

            stream.flush();

            file.close();

        }

    }
}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_commandLinkButton_clicked()
{
/*tu  sa podpiete komendy systemu linux lub windows czyli "curl"*/
   QString Qstr1 = ui->lineEdit->text();
   char *acsUserName = new char[ Qstr1.length() + 1 ]; // + 1 for zero in the end of string
   strcpy( acsUserName, Qstr1.toUtf8().constData() );
   system(acsUserName);/*
    QString aaa;
  QString  aaats( stdout );
        strcpy( aaa, aaats.toUtf8().constData() );
   ui->lineEdit->setPlaceholderText(aaa);*/
/*
connect(this,SIGNAL(readyReadStandardOutput()),this,SLOT(readStdOutput()));
   ui->textEdit->setText("");*/
}

void MainWindow::on_webView_loadStarted()
{

}

void MainWindow::on_textEdit_textChanged()
{


}

void MainWindow::on_back_clicked()
{

        ui->webView->back();

}

void MainWindow::on_forward_clicked()
{
    ui->webView->forward();
}

void MainWindow::on_source_triggered()
{
   ui->textEdit->setPlainText(ui->webView->page()->currentFrame()->toHtml());
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->webView->hide();
}

void MainWindow::on_forward_2_clicked()
{
     ui->webView->showFullScreen();
}

void MainWindow::on_widget_windowTitleChanged(const QString &title)
{
    setWindowTitle("Search with Google");
}
