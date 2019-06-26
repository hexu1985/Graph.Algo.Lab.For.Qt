#ifndef LINKPROPERTIESDIALOG_H
#define LINKPROPERTIESDIALOG_H

#include <QDialog>

namespace Ui {
class LinkPropertiesDialog;
}

class Link;

class LinkPropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinkPropertiesDialog(Link *link, QWidget *parent = nullptr);
    ~LinkPropertiesDialog();

private:
    Ui::LinkPropertiesDialog *ui;
    Link *link;
};

#endif // LINKPROPERTIESDIALOG_H
