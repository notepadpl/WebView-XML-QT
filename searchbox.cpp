#include <QDesktopServices>
#include <QUrl>
#include "mainwindow.h"
#include "searchbox.h"

#define GSEARCH_URL "http://www.google.com/search?q=%1"

//! [1]
SearchBox::SearchBox(QWidget *parent): QLineEdit(parent)
{

    connect(this, SIGNAL(returnPressed()),this, SLOT(doSearch()));

    setWindowTitle("Search with Google");

    adjustSize();
    resize(400, height());
    setFocus();
}

//! [1]

//! [2]
void SearchBox::doSearch()
{

    QString url = QString(GSEARCH_URL).arg(text());

}
//! [2]
