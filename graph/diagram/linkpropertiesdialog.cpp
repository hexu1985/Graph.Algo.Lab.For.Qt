#include "linkpropertiesdialog.h"
#include "ui_linkpropertiesdialog.h"
#include "link.h"
#include "node.h"

LinkPropertiesDialog::LinkPropertiesDialog(Link *link, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkPropertiesDialog)
{
    ui->setupUi(this);

    this->link = link;
    auto fromNode = link->fromNode();
    auto toNode = link->toNode();

    QString str;
    str.sprintf("(%d, %d)", (int) fromNode->x(), (int) fromNode->y());
    ui->label_from->setText(str);

    str.sprintf("(%d, %d)", (int) toNode->x(), (int) toNode->y());
    ui->label_to->setText(str);

    double length = link->length();
    ui->label_length->setText(QString::number(length));
}

LinkPropertiesDialog::~LinkPropertiesDialog()
{
    delete ui;
}
