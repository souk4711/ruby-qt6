# frozen_string_literal: true

class UpdatePage < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    packages_group = QGroupBox.new(tr('Look for packages'))

    name_label = QLabel.new(tr('Name:'))
    name_edit = QLineEdit.new

    date_label = QLabel.new(tr('Released after:'))
    date_edit = QDateEdit.new(QDate.current_date)

    releases_checkbox = QCheckBox.new(tr('Releases'))
    upgrades_checkbox = QCheckBox.new(tr('Upgrades'))

    h = QSpinBox.new
    h.set_prefix tr('Return up to ')
    h.set_suffix tr(' results')
    h.set_special_value_text tr('Return only the first result')
    h.set_minimum 1
    h.set_maximum 100
    h.set_single_step 10

    p = QGridLayout.new
    p.add_widget(name_label, 0, 0)
    p.add_widget(name_edit, 0, 1)
    p.add_widget(date_label, 1, 0)
    p.add_widget(date_edit, 1, 1)
    p.add_widget(releases_checkbox, 2, 0)
    p.add_widget(upgrades_checkbox, 3, 0)
    p.add_widget(h, 4, 0, 1, 2)
    packages_group.set_layout(p)

    start_query_button = QPushButton.new(tr('Start query'))
    m = QVBoxLayout.new
    m.add_widget(packages_group)
    m.add_spacing(12)
    m.add_widget(start_query_button)
    m.add_stretch(1)
    set_layout(m)
  end
end
