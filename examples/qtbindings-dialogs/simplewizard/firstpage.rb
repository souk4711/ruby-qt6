# frozen_string_literal: true

class FirstPage < RubyQt6::Bando::QWidget
  q_object do
    slot 'class_name_changed()'
  end

  attr_accessor :class_name_line_edit,
                :base_class_line_edit,
                :headerLineEdit,
                :qobject_macro_checkbox,
                :qobject_ctor_radio_button,
                :qwidget_ctor_radio_button,
                :default_ctor_radio_button,
                :copy_ctor_checkbox

  def initialize(wizard)
    super(wizard)

    @top_label = QLabel.new(tr('<center><b>Class information</b></center><p>This wizard will generate a skeleton class definition and member function definitions.'))
    @top_label.set_word_wrap false

    @class_name_label = QLabel.new(tr('Class &name:'))
    @class_name_line_edit = QLineEdit.new
    @class_name_label.set_buddy @class_name_line_edit
    set_focus_proxy(@class_name_line_edit)

    @base_class_label = QLabel.new(tr('&Base class:'))
    @base_class_line_edit = QLineEdit.new
    @base_class_label.set_buddy @base_class_line_edit

    @qobject_macro_checkbox = QCheckBox.new(tr('&Generate Q_OBJECT macro'))
    @groupbox = QGroupBox.new(tr('&Constructor'))

    @qobject_ctor_radio_button = QRadioButton.new(tr('&QObject-style constructor'))
    @qwidget_ctor_radio_button = QRadioButton.new(tr('Q&Widget-style constructor'))
    @default_ctor_radio_button = QRadioButton.new(tr('&Default constructor'))
    @copy_ctor_checkbox = QCheckBox.new(tr('&Also generate copy constructor and assignment operator'))

    @default_ctor_radio_button.set_checked true

    @class_name_line_edit.text_changed.connect(self, :class_name_changed)
    @default_ctor_radio_button.toggled.connect(@copy_ctor_checkbox, :set_enabled)

    wizard.set_button_enabled false

    g = QVBoxLayout.new
    g.add_widget(@qobject_ctor_radio_button)
    g.add_widget(@qwidget_ctor_radio_button)
    g.add_widget(@default_ctor_radio_button)
    g.add_widget(@copy_ctor_checkbox)
    @groupbox.set_layout g

    l = QGridLayout.new
    l.add_widget(@top_label, 0, 0, 1, 2)
    l.set_row_minimum_height(1, 10)
    l.add_widget(@class_name_label, 2, 0)
    l.add_widget(@class_name_line_edit, 2, 1)
    l.add_widget(@base_class_label, 3, 0)
    l.add_widget(@base_class_line_edit, 3, 1)
    l.add_widget(@qobject_macro_checkbox, 4, 0, 1, 2)
    l.add_widget(@groupbox, 5, 0, 1, 2)
    l.set_row_stretch(6, 1)
    set_layout(l)
  end

  def class_name_changed
    wizard = parent
    wizard.set_button_enabled !@class_name_line_edit.text.empty?
  end
end
