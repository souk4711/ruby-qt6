#include "bando-qtwidgets-widget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QRadioButton>
#include <QToolButton>
#include <QDial>
#include <QScrollBar>
#include <QSlider>
#include <QDateTimeEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCalendarWidget>
#include <QComboBox>
#include <QFontComboBox>
#include <QDialog>
#include <QColorDialog>
#include <QErrorMessage>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QWizard>
#include <QWizardPage>
#include <QFrame>
#include <QAbstractScrollArea>
#include <QColumnView>
#include <QHeaderView>
#include <QListView>
#include <QListWidget>
#include <QUndoView>
#include <QTableView>
#include <QTableWidget>
#include <QTreeView>
#include <QTreeWidget>
#include <QGraphicsView>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QScrollArea>
#include <QTextEdit>
#include <QTextBrowser>
#include <QLabel>
#include <QLCDNumber>
#include <QSplitter>
#include <QSplitterHandle>
#include <QStackedWidget>
#include <QToolBox>
#include <QDialogButtonBox>
#include <QDockWidget>
#include <QFocusFrame>
#include <QGroupBox>
#include <QKeySequenceEdit>
#include <QLineEdit>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QRubberBand>
#include <QSizeGrip>
#include <QSplashScreen>
#include <QStatusBar>
#include <QTabBar>
#include <QTabWidget>
#include <QToolBar>

using namespace Rice;

using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;
using Bando_QCheckBox = BandoQWidget<QCheckBox, const QString &, QWidget *>;
using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;
using Bando_QCommandLinkButton = BandoQWidget<QCommandLinkButton, const QString &, const QString &, QWidget *>;
using Bando_QRadioButton = BandoQWidget<QRadioButton, const QString &, QWidget *>;
using Bando_QToolButton = BandoQWidget<QToolButton, QWidget *>;
using Bando_QDial = BandoQWidget<QDial, QWidget *>;
using Bando_QScrollBar = BandoQWidget<QScrollBar, Qt::Orientation, QWidget *>;
using Bando_QSlider = BandoQWidget<QSlider, Qt::Orientation, QWidget *>;
using Bando_QDateTimeEdit = BandoQWidget<QDateTimeEdit, const QDateTime &, QWidget *>;
using Bando_QDateEdit = BandoQWidget<QDateEdit, QDate, QWidget *>;
using Bando_QTimeEdit = BandoQWidget<QTimeEdit, QTime, QWidget *>;
using Bando_QDoubleSpinBox = BandoQWidget<QDoubleSpinBox, QWidget *>;
using Bando_QSpinBox = BandoQWidget<QSpinBox, QWidget *>;
using Bando_QCalendarWidget = BandoQWidget<QCalendarWidget, QWidget *>;
using Bando_QComboBox = BandoQWidget<QComboBox, QWidget *>;
using Bando_QFontComboBox = BandoQWidget<QFontComboBox, QWidget *>;
using Bando_QDialog = BandoQWidget<QDialog, QWidget *>;
using Bando_QColorDialog = BandoQWidget<QColorDialog, const QColor &, QWidget *>;
using Bando_QErrorMessage = BandoQWidget<QErrorMessage, QWidget *>;
using Bando_QFileDialog = BandoQWidget<QFileDialog, QWidget *>;
using Bando_QFontDialog = BandoQWidget<QFontDialog, const QFont &, QWidget *>;
using Bando_QInputDialog = BandoQWidget<QInputDialog, QWidget *>;
using Bando_QMessageBox = BandoQWidget<QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>;
using Bando_QProgressDialog = BandoQWidget<QProgressDialog, const QString &, const QString &, int, int, QWidget *>;
using Bando_QWizard = BandoQWidget<QWizard, QWidget *>;
using Bando_QWizardPage = BandoQWidget<QWizardPage, QWidget *>;
using Bando_QFrame = BandoQWidget<QFrame, QWidget *>;
using Bando_QAbstractScrollArea = BandoQWidget<QAbstractScrollArea, QWidget *>;
using Bando_QColumnView = BandoQWidget<QColumnView, QWidget *>;
using Bando_QHeaderView = BandoQWidget<QHeaderView, Qt::Orientation, QWidget *>;
using Bando_QListView = BandoQWidget<QListView, QWidget *>;
using Bando_QListWidget = BandoQWidget<QListWidget, QWidget *>;
using Bando_QUndoView = BandoQWidget<QUndoView, QWidget *>;
using Bando_QTableView = BandoQWidget<QTableView, QWidget *>;
using Bando_QTableWidget = BandoQWidget<QTableWidget, int, int, QWidget *>;
using Bando_QTreeView = BandoQWidget<QTreeView, QWidget *>;
using Bando_QTreeWidget = BandoQWidget<QTreeWidget, QWidget *>;
using Bando_QGraphicsView = BandoQWidget<QGraphicsView, QWidget *>;
using Bando_QMdiArea = BandoQWidget<QMdiArea, QWidget *>;
using Bando_QPlainTextEdit = BandoQWidget<QPlainTextEdit, const QString &, QWidget *>;
using Bando_QScrollArea = BandoQWidget<QScrollArea, QWidget *>;
using Bando_QTextEdit = BandoQWidget<QTextEdit, const QString &, QWidget *>;
using Bando_QTextBrowser = BandoQWidget<QTextBrowser, QWidget *>;
using Bando_QLabel = BandoQWidget<QLabel, const QString &, QWidget *>;
using Bando_QLCDNumber = BandoQWidget<QLCDNumber, uint, QWidget *>;
using Bando_QSplitter = BandoQWidget<QSplitter, Qt::Orientation, QWidget *>;
using Bando_QSplitterHandle = BandoQWidget<QSplitterHandle, Qt::Orientation, QSplitter *>;
using Bando_QStackedWidget = BandoQWidget<QStackedWidget, QWidget *>;
using Bando_QToolBox = BandoQWidget<QToolBox, QWidget *>;
using Bando_QDialogButtonBox = BandoQWidget<QDialogButtonBox, QDialogButtonBox::StandardButtons, Qt::Orientation, QWidget *>;
using Bando_QDockWidget = BandoQWidget<QDockWidget, const QString &, QWidget *>;
using Bando_QFocusFrame = BandoQWidget<QFocusFrame, QWidget *>;
using Bando_QGroupBox = BandoQWidget<QGroupBox, const QString &, QWidget *>;
using Bando_QKeySequenceEdit = BandoQWidget<QKeySequenceEdit, const QKeySequence &, QWidget *>;
using Bando_QLineEdit = BandoQWidget<QLineEdit, const QString &, QWidget *>;
using Bando_QMainWindow = BandoQWidget<QMainWindow, QWidget *>;
using Bando_QMdiSubWindow = BandoQWidget<QMdiSubWindow, QWidget *>;
using Bando_QMenu = BandoQWidget<QMenu, const QString &, QWidget *>;
using Bando_QMenuBar = BandoQWidget<QMenuBar, QWidget *>;
using Bando_QProgressBar = BandoQWidget<QProgressBar, QWidget *>;
using Bando_QRubberBand = BandoQWidget<QRubberBand, QRubberBand::Shape, QWidget *>;
using Bando_QSizeGrip = BandoQWidget<QSizeGrip, QWidget *>;
using Bando_QSplashScreen = BandoQWidget<QSplashScreen, const QPixmap &>;
using Bando_QStatusBar = BandoQWidget<QStatusBar, QWidget *>;
using Bando_QTabBar = BandoQWidget<QTabBar, QWidget *>;
using Bando_QTabWidget = BandoQWidget<QTabWidget, QWidget *>;
using Bando_QToolBar = BandoQWidget<QToolBar, const QString &, QWidget *>;

Rice::Class rb_mBando_cQWidget;
Rice::Class rb_mBando_cQCheckBox;
Rice::Class rb_mBando_cQPushButton;
Rice::Class rb_mBando_cQCommandLinkButton;
Rice::Class rb_mBando_cQRadioButton;
Rice::Class rb_mBando_cQToolButton;
Rice::Class rb_mBando_cQDial;
Rice::Class rb_mBando_cQScrollBar;
Rice::Class rb_mBando_cQSlider;
Rice::Class rb_mBando_cQDateTimeEdit;
Rice::Class rb_mBando_cQDateEdit;
Rice::Class rb_mBando_cQTimeEdit;
Rice::Class rb_mBando_cQDoubleSpinBox;
Rice::Class rb_mBando_cQSpinBox;
Rice::Class rb_mBando_cQCalendarWidget;
Rice::Class rb_mBando_cQComboBox;
Rice::Class rb_mBando_cQFontComboBox;
Rice::Class rb_mBando_cQDialog;
Rice::Class rb_mBando_cQColorDialog;
Rice::Class rb_mBando_cQErrorMessage;
Rice::Class rb_mBando_cQFileDialog;
Rice::Class rb_mBando_cQFontDialog;
Rice::Class rb_mBando_cQInputDialog;
Rice::Class rb_mBando_cQMessageBox;
Rice::Class rb_mBando_cQProgressDialog;
Rice::Class rb_mBando_cQWizard;
Rice::Class rb_mBando_cQWizardPage;
Rice::Class rb_mBando_cQFrame;
Rice::Class rb_mBando_cQAbstractScrollArea;
Rice::Class rb_mBando_cQColumnView;
Rice::Class rb_mBando_cQHeaderView;
Rice::Class rb_mBando_cQListView;
Rice::Class rb_mBando_cQListWidget;
Rice::Class rb_mBando_cQUndoView;
Rice::Class rb_mBando_cQTableView;
Rice::Class rb_mBando_cQTableWidget;
Rice::Class rb_mBando_cQTreeView;
Rice::Class rb_mBando_cQTreeWidget;
Rice::Class rb_mBando_cQGraphicsView;
Rice::Class rb_mBando_cQMdiArea;
Rice::Class rb_mBando_cQPlainTextEdit;
Rice::Class rb_mBando_cQScrollArea;
Rice::Class rb_mBando_cQTextEdit;
Rice::Class rb_mBando_cQTextBrowser;
Rice::Class rb_mBando_cQLabel;
Rice::Class rb_mBando_cQLCDNumber;
Rice::Class rb_mBando_cQSplitter;
Rice::Class rb_mBando_cQSplitterHandle;
Rice::Class rb_mBando_cQStackedWidget;
Rice::Class rb_mBando_cQToolBox;
Rice::Class rb_mBando_cQDialogButtonBox;
Rice::Class rb_mBando_cQDockWidget;
Rice::Class rb_mBando_cQFocusFrame;
Rice::Class rb_mBando_cQGroupBox;
Rice::Class rb_mBando_cQKeySequenceEdit;
Rice::Class rb_mBando_cQLineEdit;
Rice::Class rb_mBando_cQMainWindow;
Rice::Class rb_mBando_cQMdiSubWindow;
Rice::Class rb_mBando_cQMenu;
Rice::Class rb_mBando_cQMenuBar;
Rice::Class rb_mBando_cQProgressBar;
Rice::Class rb_mBando_cQRubberBand;
Rice::Class rb_mBando_cQSizeGrip;
Rice::Class rb_mBando_cQSplashScreen;
Rice::Class rb_mBando_cQStatusBar;
Rice::Class rb_mBando_cQTabBar;
Rice::Class rb_mBando_cQTabWidget;
Rice::Class rb_mBando_cQToolBar;

void Init_bando_qtwidgets_widget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWidget =
        define_bando_qwidget_under<Bando_QWidget, QWidget>(rb_mQt6Bando, "QWidget")
            .define_constructor(Constructor<Bando_QWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQCheckBox =
        define_bando_qwidget_under<Bando_QCheckBox, QCheckBox>(rb_mQt6Bando, "QCheckBox")
            .define_constructor(Constructor<Bando_QCheckBox, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQPushButton =
        define_bando_qwidget_under<Bando_QPushButton, QPushButton>(rb_mQt6Bando, "QPushButton")
            .define_constructor(Constructor<Bando_QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQCommandLinkButton =
        define_bando_qwidget_under<Bando_QCommandLinkButton, QCommandLinkButton>(rb_mQt6Bando, "QCommandLinkButton")
            .define_constructor(Constructor<Bando_QCommandLinkButton, const QString &, const QString &, QWidget *>(), Arg("text"), Arg("description"), Arg("parent"));

    rb_mBando_cQRadioButton =
        define_bando_qwidget_under<Bando_QRadioButton, QRadioButton>(rb_mQt6Bando, "QRadioButton")
            .define_constructor(Constructor<Bando_QRadioButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQToolButton =
        define_bando_qwidget_under<Bando_QToolButton, QToolButton>(rb_mQt6Bando, "QToolButton")
            .define_constructor(Constructor<Bando_QToolButton, QWidget *>(), Arg("parent"));

    rb_mBando_cQDial =
        define_bando_qwidget_under<Bando_QDial, QDial>(rb_mQt6Bando, "QDial")
            .define_constructor(Constructor<Bando_QDial, QWidget *>(), Arg("parent"));

    rb_mBando_cQScrollBar =
        define_bando_qwidget_under<Bando_QScrollBar, QScrollBar>(rb_mQt6Bando, "QScrollBar")
            .define_constructor(Constructor<Bando_QScrollBar, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));

    rb_mBando_cQSlider =
        define_bando_qwidget_under<Bando_QSlider, QSlider>(rb_mQt6Bando, "QSlider")
            .define_constructor(Constructor<Bando_QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));

    rb_mBando_cQDateTimeEdit =
        define_bando_qwidget_under<Bando_QDateTimeEdit, QDateTimeEdit>(rb_mQt6Bando, "QDateTimeEdit")
            .define_constructor(Constructor<Bando_QDateTimeEdit, const QDateTime &, QWidget *>(), Arg("datetime"), Arg("parent"));

    rb_mBando_cQDateEdit =
        define_bando_qwidget_under<Bando_QDateEdit, QDateEdit>(rb_mQt6Bando, "QDateEdit")
            .define_constructor(Constructor<Bando_QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"));

    rb_mBando_cQTimeEdit =
        define_bando_qwidget_under<Bando_QTimeEdit, QTimeEdit>(rb_mQt6Bando, "QTimeEdit")
            .define_constructor(Constructor<Bando_QTimeEdit, QTime, QWidget *>(), Arg("time"), Arg("parent"));

    rb_mBando_cQDoubleSpinBox =
        define_bando_qwidget_under<Bando_QDoubleSpinBox, QDoubleSpinBox>(rb_mQt6Bando, "QDoubleSpinBox")
            .define_constructor(Constructor<Bando_QDoubleSpinBox, QWidget *>(), Arg("parent"));

    rb_mBando_cQSpinBox =
        define_bando_qwidget_under<Bando_QSpinBox, QSpinBox>(rb_mQt6Bando, "QSpinBox")
            .define_constructor(Constructor<Bando_QSpinBox, QWidget *>(), Arg("parent"));

    rb_mBando_cQCalendarWidget =
        define_bando_qwidget_under<Bando_QCalendarWidget, QCalendarWidget>(rb_mQt6Bando, "QCalendarWidget")
            .define_constructor(Constructor<Bando_QCalendarWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQComboBox =
        define_bando_qwidget_under<Bando_QComboBox, QComboBox>(rb_mQt6Bando, "QComboBox")
            .define_constructor(Constructor<Bando_QComboBox, QWidget *>(), Arg("parent"));

    rb_mBando_cQFontComboBox =
        define_bando_qwidget_under<Bando_QFontComboBox, QFontComboBox>(rb_mQt6Bando, "QFontComboBox")
            .define_constructor(Constructor<Bando_QFontComboBox, QWidget *>(), Arg("parent"));

    rb_mBando_cQDialog =
        define_bando_qwidget_under<Bando_QDialog, QDialog>(rb_mQt6Bando, "QDialog")
            .define_constructor(Constructor<Bando_QDialog, QWidget *>(), Arg("parent"));

    rb_mBando_cQColorDialog =
        define_bando_qwidget_under<Bando_QColorDialog, QColorDialog>(rb_mQt6Bando, "QColorDialog")
            .define_constructor(Constructor<Bando_QColorDialog, const QColor &, QWidget *>(), Arg("initial"), Arg("parent"));

    rb_mBando_cQErrorMessage =
        define_bando_qwidget_under<Bando_QErrorMessage, QErrorMessage>(rb_mQt6Bando, "QErrorMessage")
            .define_constructor(Constructor<Bando_QErrorMessage, QWidget *>(), Arg("parent"));

    rb_mBando_cQFileDialog =
        define_bando_qwidget_under<Bando_QFileDialog, QFileDialog>(rb_mQt6Bando, "QFileDialog")
            .define_constructor(Constructor<Bando_QFileDialog, QWidget *>(), Arg("parent"));

    rb_mBando_cQFontDialog =
        define_bando_qwidget_under<Bando_QFontDialog, QFontDialog>(rb_mQt6Bando, "QFontDialog")
            .define_constructor(Constructor<Bando_QFontDialog, const QFont &, QWidget *>(), Arg("initial"), Arg("parent"));

    rb_mBando_cQInputDialog =
        define_bando_qwidget_under<Bando_QInputDialog, QInputDialog>(rb_mQt6Bando, "QInputDialog")
            .define_constructor(Constructor<Bando_QInputDialog, QWidget *>(), Arg("parent"));

    rb_mBando_cQMessageBox =
        define_bando_qwidget_under<Bando_QMessageBox, QMessageBox>(rb_mQt6Bando, "QMessageBox")
            .define_constructor(Constructor<Bando_QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>(), Arg("icon"), Arg("title"), Arg("text"), Arg("buttons"), Arg("parent"));

    rb_mBando_cQProgressDialog =
        define_bando_qwidget_under<Bando_QProgressDialog, QProgressDialog>(rb_mQt6Bando, "QProgressDialog")
            .define_constructor(Constructor<Bando_QProgressDialog, const QString &, const QString &, int, int, QWidget *>(), Arg("label_text"), Arg("cancel_button_text"), Arg("minimum"), Arg("maximum"), Arg("parent"));

    rb_mBando_cQWizard =
        define_bando_qwidget_under<Bando_QWizard, QWizard>(rb_mQt6Bando, "QWizard")
            .define_constructor(Constructor<Bando_QWizard, QWidget *>(), Arg("parent"));

    rb_mBando_cQWizardPage =
        define_bando_qwidget_under<Bando_QWizardPage, QWizardPage>(rb_mQt6Bando, "QWizardPage")
            .define_constructor(Constructor<Bando_QWizardPage, QWidget *>(), Arg("parent"));

    rb_mBando_cQFrame =
        define_bando_qwidget_under<Bando_QFrame, QFrame>(rb_mQt6Bando, "QFrame")
            .define_constructor(Constructor<Bando_QFrame, QWidget *>(), Arg("parent"));

    rb_mBando_cQAbstractScrollArea =
        define_bando_qwidget_under<Bando_QAbstractScrollArea, QAbstractScrollArea>(rb_mQt6Bando, "QAbstractScrollArea")
            .define_constructor(Constructor<Bando_QAbstractScrollArea, QWidget *>(), Arg("parent"));

    rb_mBando_cQColumnView =
        define_bando_qwidget_under<Bando_QColumnView, QColumnView>(rb_mQt6Bando, "QColumnView")
            .define_constructor(Constructor<Bando_QColumnView, QWidget *>(), Arg("parent"));

    rb_mBando_cQHeaderView =
        define_bando_qwidget_under<Bando_QHeaderView, QHeaderView>(rb_mQt6Bando, "QHeaderView")
            .define_constructor(Constructor<Bando_QHeaderView, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));

    rb_mBando_cQListView =
        define_bando_qwidget_under<Bando_QListView, QListView>(rb_mQt6Bando, "QListView")
            .define_constructor(Constructor<Bando_QListView, QWidget *>(), Arg("parent"));

    rb_mBando_cQListWidget =
        define_bando_qwidget_under<Bando_QListWidget, QListWidget>(rb_mQt6Bando, "QListWidget")
            .define_constructor(Constructor<Bando_QListWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQUndoView =
        define_bando_qwidget_under<Bando_QUndoView, QUndoView>(rb_mQt6Bando, "QUndoView")
            .define_constructor(Constructor<Bando_QUndoView, QWidget *>(), Arg("parent"));

    rb_mBando_cQTableView =
        define_bando_qwidget_under<Bando_QTableView, QTableView>(rb_mQt6Bando, "QTableView")
            .define_constructor(Constructor<Bando_QTableView, QWidget *>(), Arg("parent"));

    rb_mBando_cQTableWidget =
        define_bando_qwidget_under<Bando_QTableWidget, QTableWidget>(rb_mQt6Bando, "QTableWidget")
            .define_constructor(Constructor<Bando_QTableWidget, int, int, QWidget *>(), Arg("rows"), Arg("columns"), Arg("parent"));

    rb_mBando_cQTreeView =
        define_bando_qwidget_under<Bando_QTreeView, QTreeView>(rb_mQt6Bando, "QTreeView")
            .define_constructor(Constructor<Bando_QTreeView, QWidget *>(), Arg("parent"));

    rb_mBando_cQTreeWidget =
        define_bando_qwidget_under<Bando_QTreeWidget, QTreeWidget>(rb_mQt6Bando, "QTreeWidget")
            .define_constructor(Constructor<Bando_QTreeWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQGraphicsView =
        define_bando_qwidget_under<Bando_QGraphicsView, QGraphicsView>(rb_mQt6Bando, "QGraphicsView")
            .define_constructor(Constructor<Bando_QGraphicsView, QWidget *>(), Arg("parent"));

    rb_mBando_cQMdiArea =
        define_bando_qwidget_under<Bando_QMdiArea, QMdiArea>(rb_mQt6Bando, "QMdiArea")
            .define_constructor(Constructor<Bando_QMdiArea, QWidget *>(), Arg("parent"));

    rb_mBando_cQPlainTextEdit =
        define_bando_qwidget_under<Bando_QPlainTextEdit, QPlainTextEdit>(rb_mQt6Bando, "QPlainTextEdit")
            .define_constructor(Constructor<Bando_QPlainTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQScrollArea =
        define_bando_qwidget_under<Bando_QScrollArea, QScrollArea>(rb_mQt6Bando, "QScrollArea")
            .define_constructor(Constructor<Bando_QScrollArea, QWidget *>(), Arg("parent"));

    rb_mBando_cQTextEdit =
        define_bando_qwidget_under<Bando_QTextEdit, QTextEdit>(rb_mQt6Bando, "QTextEdit")
            .define_constructor(Constructor<Bando_QTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQTextBrowser =
        define_bando_qwidget_under<Bando_QTextBrowser, QTextBrowser>(rb_mQt6Bando, "QTextBrowser")
            .define_constructor(Constructor<Bando_QTextBrowser, QWidget *>(), Arg("parent"));

    rb_mBando_cQLabel =
        define_bando_qwidget_under<Bando_QLabel, QLabel>(rb_mQt6Bando, "QLabel")
            .define_constructor(Constructor<Bando_QLabel, const QString &, QWidget *>(), Arg("text"), Arg("parent"));

    rb_mBando_cQLCDNumber =
        define_bando_qwidget_under<Bando_QLCDNumber, QLCDNumber>(rb_mQt6Bando, "QLCDNumber")
            .define_constructor(Constructor<Bando_QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"));

    rb_mBando_cQSplitter =
        define_bando_qwidget_under<Bando_QSplitter, QSplitter>(rb_mQt6Bando, "QSplitter")
            .define_constructor(Constructor<Bando_QSplitter, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));

    rb_mBando_cQSplitterHandle =
        define_bando_qwidget_under<Bando_QSplitterHandle, QSplitterHandle>(rb_mQt6Bando, "QSplitterHandle")
            .define_constructor(Constructor<Bando_QSplitterHandle, Qt::Orientation, QSplitter *>(), Arg("orientation"), Arg("parent"));

    rb_mBando_cQStackedWidget =
        define_bando_qwidget_under<Bando_QStackedWidget, QStackedWidget>(rb_mQt6Bando, "QStackedWidget")
            .define_constructor(Constructor<Bando_QStackedWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQToolBox =
        define_bando_qwidget_under<Bando_QToolBox, QToolBox>(rb_mQt6Bando, "QToolBox")
            .define_constructor(Constructor<Bando_QToolBox, QWidget *>(), Arg("parent"));

    rb_mBando_cQDialogButtonBox =
        define_bando_qwidget_under<Bando_QDialogButtonBox, QDialogButtonBox>(rb_mQt6Bando, "QDialogButtonBox")
            .define_constructor(Constructor<Bando_QDialogButtonBox, QDialogButtonBox::StandardButtons, Qt::Orientation, QWidget *>(), Arg("buttons"), Arg("orientation"), Arg("parent"));

    rb_mBando_cQDockWidget =
        define_bando_qwidget_under<Bando_QDockWidget, QDockWidget>(rb_mQt6Bando, "QDockWidget")
            .define_constructor(Constructor<Bando_QDockWidget, const QString &, QWidget *>(), Arg("title"), Arg("parent"));

    rb_mBando_cQFocusFrame =
        define_bando_qwidget_under<Bando_QFocusFrame, QFocusFrame>(rb_mQt6Bando, "QFocusFrame")
            .define_constructor(Constructor<Bando_QFocusFrame, QWidget *>(), Arg("parent"));

    rb_mBando_cQGroupBox =
        define_bando_qwidget_under<Bando_QGroupBox, QGroupBox>(rb_mQt6Bando, "QGroupBox")
            .define_constructor(Constructor<Bando_QGroupBox, const QString &, QWidget *>(), Arg("title"), Arg("parent"));

    rb_mBando_cQKeySequenceEdit =
        define_bando_qwidget_under<Bando_QKeySequenceEdit, QKeySequenceEdit>(rb_mQt6Bando, "QKeySequenceEdit")
            .define_constructor(Constructor<Bando_QKeySequenceEdit, const QKeySequence &, QWidget *>(), Arg("key_sequence"), Arg("parent"));

    rb_mBando_cQLineEdit =
        define_bando_qwidget_under<Bando_QLineEdit, QLineEdit>(rb_mQt6Bando, "QLineEdit")
            .define_constructor(Constructor<Bando_QLineEdit, const QString &, QWidget *>(), Arg("contents"), Arg("parent"));

    rb_mBando_cQMainWindow =
        define_bando_qwidget_under<Bando_QMainWindow, QMainWindow>(rb_mQt6Bando, "QMainWindow")
            .define_constructor(Constructor<Bando_QMainWindow, QWidget *>(), Arg("parent"));

    rb_mBando_cQMdiSubWindow =
        define_bando_qwidget_under<Bando_QMdiSubWindow, QMdiSubWindow>(rb_mQt6Bando, "QMdiSubWindow")
            .define_constructor(Constructor<Bando_QMdiSubWindow, QWidget *>(), Arg("parent"));

    rb_mBando_cQMenu =
        define_bando_qwidget_under<Bando_QMenu, QMenu>(rb_mQt6Bando, "QMenu")
            .define_constructor(Constructor<Bando_QMenu, const QString &, QWidget *>(), Arg("title"), Arg("parent"));

    rb_mBando_cQMenuBar =
        define_bando_qwidget_under<Bando_QMenuBar, QMenuBar>(rb_mQt6Bando, "QMenuBar")
            .define_constructor(Constructor<Bando_QMenuBar, QWidget *>(), Arg("parent"));

    rb_mBando_cQProgressBar =
        define_bando_qwidget_under<Bando_QProgressBar, QProgressBar>(rb_mQt6Bando, "QProgressBar")
            .define_constructor(Constructor<Bando_QProgressBar, QWidget *>(), Arg("parent"));

    rb_mBando_cQRubberBand =
        define_bando_qwidget_under<Bando_QRubberBand, QRubberBand>(rb_mQt6Bando, "QRubberBand")
            .define_constructor(Constructor<Bando_QRubberBand, QRubberBand::Shape, QWidget *>(), Arg("shape"), Arg("parent"));

    rb_mBando_cQSizeGrip =
        define_bando_qwidget_under<Bando_QSizeGrip, QSizeGrip>(rb_mQt6Bando, "QSizeGrip")
            .define_constructor(Constructor<Bando_QSizeGrip, QWidget *>(), Arg("parent"));

    rb_mBando_cQSplashScreen =
        define_bando_qwidget_under<Bando_QSplashScreen, QSplashScreen>(rb_mQt6Bando, "QSplashScreen")
            .define_constructor(Constructor<Bando_QSplashScreen, const QPixmap &>(), Arg("pixmap"));

    rb_mBando_cQStatusBar =
        define_bando_qwidget_under<Bando_QStatusBar, QStatusBar>(rb_mQt6Bando, "QStatusBar")
            .define_constructor(Constructor<Bando_QStatusBar, QWidget *>(), Arg("parent"));

    rb_mBando_cQTabBar =
        define_bando_qwidget_under<Bando_QTabBar, QTabBar>(rb_mQt6Bando, "QTabBar")
            .define_constructor(Constructor<Bando_QTabBar, QWidget *>(), Arg("parent"));

    rb_mBando_cQTabWidget =
        define_bando_qwidget_under<Bando_QTabWidget, QTabWidget>(rb_mQt6Bando, "QTabWidget")
            .define_constructor(Constructor<Bando_QTabWidget, QWidget *>(), Arg("parent"));

    rb_mBando_cQToolBar =
        define_bando_qwidget_under<Bando_QToolBar, QToolBar>(rb_mQt6Bando, "QToolBar")
            .define_constructor(Constructor<Bando_QToolBar, const QString &, QWidget *>(), Arg("title"), Arg("parent"));
}
