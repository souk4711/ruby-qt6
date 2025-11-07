# frozen_string_literal: true

class GeneralTab < RubyQt6::Bando::QWidget
  def initialize(fileinfo, parent = nil)
    super(parent)

    frame_style = QFrame::Panel.to_i | QFrame::Sunken.to_i

    filename_label = QLabel.new(tr('File Name:'))
    filename_edit = QLineEdit.new(fileinfo.file_name)

    path_label = QLabel.new(tr('Path:'))
    path_value_label = QLabel.new(fileinfo.absolute_file_path)
    path_value_label.set_frame_style frame_style

    size_label = QLabel.new(tr('Size:'))
    size = fileinfo.size / 1024
    size_value_label = QLabel.new('%d K' % size)
    size_value_label.set_frame_style frame_style

    last_read_label = QLabel.new(tr('Last Read:'))
    last_read_value_label = QLabel.new(fileinfo.last_read.to_string)
    last_read_value_label.set_frame_style frame_style

    last_mod_label = QLabel.new(tr('Last Modified:'))
    last_mod_value_label = QLabel.new(fileinfo.last_modified.to_string)
    last_mod_value_label.set_frame_style frame_style

    m = QVBoxLayout.new
    m.add_widget(filename_label)
    m.add_widget(filename_edit)
    m.add_widget(path_label)
    m.add_widget(path_value_label)
    m.add_widget(size_label)
    m.add_widget(size_value_label)
    m.add_widget(last_read_label)
    m.add_widget(last_read_value_label)
    m.add_widget(last_mod_label)
    m.add_widget(last_mod_value_label)
    m.add_stretch(1)
    set_layout(m)
  end
end
