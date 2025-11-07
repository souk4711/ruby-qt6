# frozen_string_literal: true

class ConfigurationPage < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    config_group = QGroupBox.new(tr('Server configuration'))

    server_label = QLabel.new(tr('Server:'))
    server_combo = QComboBox.new
    server_combo.add_item(tr('Trolltech (Australia)'))
    server_combo.add_item(tr('Trolltech (Norway)'))
    server_combo.add_item(tr("Trolltech (People's Republic of China)"))
    server_combo.add_item(tr('Trolltech (USA)'))

    s = QHBoxLayout.new
    s.add_widget(server_label)
    s.add_widget(server_combo)

    c = QVBoxLayout.new
    c.add_layout(s)
    config_group.set_layout(c)

    m = QVBoxLayout.new
    m.add_widget(config_group)
    m.add_stretch(1)
    set_layout(m)
  end
end
