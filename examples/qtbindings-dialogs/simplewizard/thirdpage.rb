# frozen_string_literal: true

class ThirdPage < RubyQt6::Bando::QWidget
  attr_accessor :output_dir_line_edit,
                :header_line_edit,
                :implementation_line_edit

  def initialize(wizard)
    super(wizard)

    @top_label = QLabel.new(tr('<center><b>Output files</b></center>'))

    @output_dir_label = QLabel.new(tr('&Output directory:'))
    @output_dir_line_edit = QLineEdit.new
    @output_dir_label.set_buddy @output_dir_line_edit
    set_focus_proxy @output_dir_line_edit

    @header_label = QLabel.new(tr('&Header file name:'))
    @header_line_edit = QLineEdit.new
    @header_label.set_buddy @header_line_edit

    @implementation_label = QLabel.new(tr('&Implementation file name:'))
    @implementation_line_edit = QLineEdit.new
    @implementation_label.set_buddy @implementation_line_edit

    class_name = wizard.first_page.class_name_line_edit.text
    @header_line_edit.set_text "#{class_name.downcase}.h"
    @implementation_line_edit.set_text "#{class_name.downcase}.cpp"
    @output_dir_line_edit.set_text QDir.home_path

    l = QGridLayout.new
    l.add_widget(@top_label, 0, 0, 1, 2)
    l.set_row_minimum_height(1, 10)
    l.add_widget(@output_dir_label, 2, 0)
    l.add_widget(@output_dir_line_edit, 2, 1)
    l.add_widget(@header_label, 3, 0)
    l.add_widget(@header_line_edit, 3, 1)
    l.add_widget(@implementation_label, 4, 0)
    l.add_widget(@implementation_line_edit, 4, 1)
    l.set_row_stretch(5, 1)
    set_layout(l)
  end
end
