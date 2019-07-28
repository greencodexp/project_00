#ifndef DLG_SHIP17_H
#define DLG_SHIP17_H

#include <QDialog>

namespace Ui {
class Dlg_Ship17;
}

class Dlg_Ship17 : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Ship17(QWidget *parent = 0);
    ~Dlg_Ship17();

private:
    Ui::Dlg_Ship17 *ui;
};

#endif // DLG_SHIP17_H
