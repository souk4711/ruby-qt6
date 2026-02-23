#include "qcombobox-rb.hpp"
#include <qcombobox.h>
#include <rice/qt6/qenum.hpp>

#include <QAbstractItemView>
#include <QCompleter>
#include <QLineEdit>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQComboBox;

void Init_qcombobox(Module rb_mQt6QtWidgets)
{
    rb_cQComboBox =
        // RubyQt6::QtWidgets::QComboBox
        define_qlass_under<QComboBox, QWidget>(rb_mQt6QtWidgets, "QComboBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QComboBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QComboBox, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method<void (QComboBox::*)(const QString &, const QVariant &)>("_add_item", &QComboBox::addItem, Arg("text"), Arg("user_data") = static_cast<const QVariant &>(QVariant()))
            .define_method<void (QComboBox::*)(const QIcon &, const QString &, const QVariant &)>("_add_item", &QComboBox::addItem, Arg("icon"), Arg("text"), Arg("user_data") = static_cast<const QVariant &>(QVariant()))
            .define_method("add_items", &QComboBox::addItems, Arg("texts"))
            .define_method("completer", &QComboBox::completer)
            .define_method("count", &QComboBox::count)
            .define_method("current_data", &QComboBox::currentData, Arg("role") = static_cast<int>(Qt::UserRole))
            .define_method("current_index", &QComboBox::currentIndex)
            .define_method("current_text", &QComboBox::currentText)
            .define_method("duplicates_enabled", &QComboBox::duplicatesEnabled)
            .define_method("find_data", &QComboBox::findData, Arg("data"), Arg("role") = static_cast<int>(Qt::UserRole), Arg("flags") = static_cast<Qt::MatchFlags>(static_cast<Qt::MatchFlags>(Qt::MatchExactly | Qt::MatchCaseSensitive)))
            .define_method("_find_text", &QComboBox::findText, Arg("text"), Arg("flags") = static_cast<Qt::MatchFlags>(static_cast<Qt::MatchFlags>(Qt::MatchExactly | Qt::MatchCaseSensitive)))
            .define_method("has_frame", &QComboBox::hasFrame)
            .define_method("hide_popup", &QComboBox::hidePopup)
            .define_method("icon_size", &QComboBox::iconSize)
            .define_method<void (QComboBox::*)(int, const QIcon &, const QString &, const QVariant &)>("insert_item", &QComboBox::insertItem, Arg("index"), Arg("icon"), Arg("text"), Arg("user_data") = static_cast<const QVariant &>(QVariant()))
            .define_method<void (QComboBox::*)(int, const QString &, const QVariant &)>("insert_item", &QComboBox::insertItem, Arg("index"), Arg("text"), Arg("user_data") = static_cast<const QVariant &>(QVariant()))
            .define_method("insert_items", &QComboBox::insertItems, Arg("index"), Arg("texts"))
            .define_method("insert_policy", &QComboBox::insertPolicy)
            .define_method("insert_separator", &QComboBox::insertSeparator, Arg("index"))
            .define_method("editable?", &QComboBox::isEditable)
            .define_method("item_data", &QComboBox::itemData, Arg("index"), Arg("role") = static_cast<int>(Qt::UserRole))
            .define_method("item_delegate", &QComboBox::itemDelegate)
            .define_method("item_icon", &QComboBox::itemIcon, Arg("index"))
            .define_method("item_text", &QComboBox::itemText, Arg("index"))
            .define_method("label_drawing_mode", &QComboBox::labelDrawingMode)
            .define_method("line_edit", &QComboBox::lineEdit)
            .define_method("max_count", &QComboBox::maxCount)
            .define_method("max_visible_items", &QComboBox::maxVisibleItems)
            .define_method("minimum_contents_length", &QComboBox::minimumContentsLength)
            .define_method("model", &QComboBox::model)
            .define_method("model_column", &QComboBox::modelColumn)
            .define_method("placeholder_text", &QComboBox::placeholderText)
            .define_method("remove_item", &QComboBox::removeItem, Arg("index"))
            .define_method("root_model_index", &QComboBox::rootModelIndex)
            .define_method("set_completer", &QComboBox::setCompleter, Arg("c"))
            .define_method("set_duplicates_enabled", &QComboBox::setDuplicatesEnabled, Arg("enable"))
            .define_method("set_editable", &QComboBox::setEditable, Arg("editable"))
            .define_method("set_frame", &QComboBox::setFrame, Arg("enable"))
            .define_method("set_icon_size", &QComboBox::setIconSize, Arg("size"))
            .define_method("set_insert_policy", &QComboBox::setInsertPolicy, Arg("policy"))
            .define_method("set_item_data", &QComboBox::setItemData, Arg("index"), Arg("value"), Arg("role") = static_cast<int>(Qt::UserRole))
            .define_method("set_item_delegate", &QComboBox::setItemDelegate, Arg("delegate"))
            .define_method("set_item_icon", &QComboBox::setItemIcon, Arg("index"), Arg("icon"))
            .define_method("set_item_text", &QComboBox::setItemText, Arg("index"), Arg("text"))
            .define_method("set_label_drawing_mode", &QComboBox::setLabelDrawingMode, Arg("label_drawing"))
            .define_method("set_line_edit", &QComboBox::setLineEdit, Arg("edit"))
            .define_method("set_max_count", &QComboBox::setMaxCount, Arg("max"))
            .define_method("set_max_visible_items", &QComboBox::setMaxVisibleItems, Arg("max_items"))
            .define_method("set_minimum_contents_length", &QComboBox::setMinimumContentsLength, Arg("characters"))
            .define_method("set_model", &QComboBox::setModel, Arg("model"))
            .define_method("set_model_column", &QComboBox::setModelColumn, Arg("visible_column"))
            .define_method("set_placeholder_text", &QComboBox::setPlaceholderText, Arg("placeholder_text"))
            .define_method("set_root_model_index", &QComboBox::setRootModelIndex, Arg("index"))
            .define_method("set_size_adjust_policy", &QComboBox::setSizeAdjustPolicy, Arg("policy"))
            .define_method("set_validator", &QComboBox::setValidator, Arg("v"))
            .define_method("set_view", &QComboBox::setView, Arg("item_view"))
            .define_method("show_popup", &QComboBox::showPopup)
            .define_method("size_adjust_policy", &QComboBox::sizeAdjustPolicy)
            .define_method("validator", &QComboBox::validator)
            .define_method("view", &QComboBox::view)
            // Public Slots
            .define_method("clear", &QComboBox::clear)
            .define_method("clear_edit_text", &QComboBox::clearEditText)
            .define_method("set_current_index", &QComboBox::setCurrentIndex, Arg("index"))
            .define_method("set_current_text", &QComboBox::setCurrentText, Arg("text"))
            .define_method("set_edit_text", &QComboBox::setEditText, Arg("text"));
            // Signals
            // .define_method("activated", &QComboBox::activated, Arg("index"))
            // .define_method("current_index_changed", &QComboBox::currentIndexChanged, Arg("index"))
            // .define_method("current_text_changed", &QComboBox::currentTextChanged, Arg("text"))
            // .define_method("edit_text_changed", &QComboBox::editTextChanged, Arg("text"))
            // .define_method("highlighted", &QComboBox::highlighted, Arg("index"))
            // .define_method("text_activated", &QComboBox::textActivated, Arg("text"))
            // .define_method("text_highlighted", &QComboBox::textHighlighted, Arg("text"));

    Data_Type<QComboBox::InsertPolicy> rb_cQComboBoxInsertPolicy =
        // RubyQt6::QtWidgets::QComboBox::InsertPolicy
        define_qenum_under<QComboBox::InsertPolicy>(rb_cQComboBox, "InsertPolicy");
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "NoInsert", QComboBox::InsertPolicy::NoInsert);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertAtTop", QComboBox::InsertPolicy::InsertAtTop);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertAtCurrent", QComboBox::InsertPolicy::InsertAtCurrent);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertAtBottom", QComboBox::InsertPolicy::InsertAtBottom);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertAfterCurrent", QComboBox::InsertPolicy::InsertAfterCurrent);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertBeforeCurrent", QComboBox::InsertPolicy::InsertBeforeCurrent);
        define_qenum_value_under(rb_cQComboBoxInsertPolicy, "InsertAlphabetically", QComboBox::InsertPolicy::InsertAlphabetically);

    Data_Type<QComboBox::LabelDrawingMode> rb_cQComboBoxLabelDrawingMode =
        // RubyQt6::QtWidgets::QComboBox::LabelDrawingMode
        define_qenum_under<QComboBox::LabelDrawingMode>(rb_cQComboBox, "LabelDrawingMode");
        define_qenum_value_under(rb_cQComboBoxLabelDrawingMode, "UseStyle", QComboBox::LabelDrawingMode::UseStyle);
        define_qenum_value_under(rb_cQComboBoxLabelDrawingMode, "UseDelegate", QComboBox::LabelDrawingMode::UseDelegate);

    Data_Type<QComboBox::SizeAdjustPolicy> rb_cQComboBoxSizeAdjustPolicy =
        // RubyQt6::QtWidgets::QComboBox::SizeAdjustPolicy
        define_qenum_under<QComboBox::SizeAdjustPolicy>(rb_cQComboBox, "SizeAdjustPolicy");
        define_qenum_value_under(rb_cQComboBoxSizeAdjustPolicy, "AdjustToContents", QComboBox::SizeAdjustPolicy::AdjustToContents);
        define_qenum_value_under(rb_cQComboBoxSizeAdjustPolicy, "AdjustToContentsOnFirstShow", QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        define_qenum_value_under(rb_cQComboBoxSizeAdjustPolicy, "AdjustToMinimumContentsLengthWithIcon", QComboBox::SizeAdjustPolicy::AdjustToMinimumContentsLengthWithIcon);
}
