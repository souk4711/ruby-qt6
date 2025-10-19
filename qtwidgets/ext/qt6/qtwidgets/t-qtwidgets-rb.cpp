#include "t-qtwidgets-rb.hpp"
#include <rice/qlist.hpp>

#include <QAbstractButton>
#include <QAction>
#include <QKeyCombination>
#include <QMdiSubWindow>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <QTableWidgetSelectionRange>
#include <QTreeWidgetItem>

using namespace Rice;

void Init_t_qtwidgets(Rice::Module rb_mQt6T)
{
    // QList<QAbstractButton *>
    define_qlist_under<QAbstractButton *>(rb_mQt6T);

    // QList<QAction *>
    define_qlist_under<QAction *>(rb_mQt6T);

    // QList<QKeyCombination>
    define_qlist_under<QKeyCombination>(rb_mQt6T);

    // QList<QMdiSubWindow *>
    define_qlist_under<QMdiSubWindow *>(rb_mQt6T);

    // QList<QListWidgetItem *>
    define_qlist_under<QListWidgetItem *>(rb_mQt6T);

    // QList<QTableWidgetItem *>
    define_qlist_under<QTableWidgetItem *>(rb_mQt6T);

    // QList<QTableWidgetSelectionRange>
    define_qlist_under<QTableWidgetSelectionRange>(rb_mQt6T);

    // QList<QTreeWidgetItem *>
    define_qlist_under<QTreeWidgetItem *>(rb_mQt6T);

    // QList<QWidget *> -> QWidgetList
    define_qlist_under<QWidget *>(rb_mQt6T);
}
