# frozen_string_literal: true

class SecondPage < RubyQt6::Bando::QWidget
  attr_accessor :comment_checkbox,
                :protect_checkbox,
                :include_base_checkbox,
                :macro_name_line_edit,
                :base_include_line_edit,
                :protect_checkbox,
                :comment_checkbox,
                :include_base_checkbox

  def initialize(wizard)
    super(wizard)

    @top_label = QLabel.new(tr('<center><b>Code style options</b></center>'))

    @comment_checkbox = QCheckBox.new(tr('&Start generated files with a comment'))
    @comment_checkbox.set_checked true
    set_focus_proxy(@comment_checkbox)

    @protect_checkbox = QCheckBox.new(tr('&Protect header file against multiple inclusions'))
    @protect_checkbox.set_checked true

    @macro_name_label = QLabel.new(tr('&Macro name:'))
    @macro_name_line_edit = QLineEdit.new
    @macro_name_label.set_buddy @macro_name_line_edit

    @include_base_checkbox = QCheckBox.new(tr('&Include base class definition'))
    @base_include_label = QLabel.new(tr('Base class include:'))
    @base_include_line_edit = QLineEdit.new
    @base_include_label.set_buddy @base_include_line_edit

    class_name = wizard.first_page.class_name_line_edit.text
    @macro_name_line_edit.set_text "#{class_name.upcase}_H"

    base_class = wizard.first_page.base_class_line_edit.text
    if base_class.empty?
      @include_base_checkbox.set_enabled false
      @base_include_label.set_enabled false
      @base_include_line_edit.set_enabled false
    else
      @include_base_checkbox.set_checked true
      @base_include_line_edit.set_text Regexp.new('Q[A-Z].*').match(base_class) ? "<#{base_class}>" : "\"#{base_class.downcase}.h\""
    end

    @protect_checkbox.toggled.connect(@macro_name_label, :set_enabled)
    @protect_checkbox.toggled.connect(@macro_name_line_edit, :set_enabled)
    @include_base_checkbox.toggled.connect(@base_include_label, :set_enabled)
    @include_base_checkbox.toggled.connect(@base_include_line_edit, :set_enabled)

    l = QGridLayout.new
    l.set_column_minimum_width(0, 20)
    l.add_widget(@top_label, 0, 0, 1, 3)
    l.set_row_minimum_height(1, 10)
    l.add_widget(@comment_checkbox, 2, 0, 1, 3)
    l.add_widget(@protect_checkbox, 3, 0, 1, 3)
    l.add_widget(@macro_name_label, 4, 1)
    l.add_widget(@macro_name_line_edit, 4, 2)
    l.add_widget(@include_base_checkbox, 5, 0, 1, 3)
    l.add_widget(@base_include_label, 6, 1)
    l.add_widget(@base_include_line_edit, 6, 2)
    l.set_row_stretch(7, 1)
    set_layout(l)
  end
end
