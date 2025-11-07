# frozen_string_literal: true

class QueryPage < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    update_group = QGroupBox.new(tr('Package selection'))
    system_checkbox = QCheckBox.new(tr('Update system'))
    apps_checkbox = QCheckBox.new(tr('Update applications'))
    docs_checkbox = QCheckBox.new(tr('Update documentation'))

    package_group = QGroupBox.new(tr('Existing packages'))
    package_list = QListWidget.new
    package_list.add_item('Qt')
    package_list.add_item('QSA')
    package_list.add_item('Teambuilder')

    u = QVBoxLayout.new
    u.add_widget(system_checkbox)
    u.add_widget(apps_checkbox)
    u.add_widget(docs_checkbox)
    update_group.set_layout(u)

    p = QVBoxLayout.new
    p.add_widget(package_list)
    package_group.set_layout(p)

    start_update_button = QPushButton.new(tr('Start update'))
    m = QVBoxLayout.new
    m.add_widget(update_group)
    m.add_widget(package_group)
    m.add_spacing(12)
    m.add_widget(start_update_button)
    m.add_stretch(1)
    set_layout(m)
  end
end
