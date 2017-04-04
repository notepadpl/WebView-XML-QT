#ifndef SEARCHBOX_H
#define SEARCHBOX_H

//! [1]
#include <QLineEdit>
#include <QWidget>
namespace Ui {
class SearchBox;
}
class SearchBox: public QLineEdit
{
    Q_OBJECT

public:
    SearchBox(QWidget *parent = 0);

protected slots:
    void doSearch();

private:
Ui::SearchBox *ui;
//! [1]
};


#endif // SEARCHBOX_H
