# frozen_string_literal: true

class ApplicationsTab < RubyQt6::Bando::QWidget
  def initialize(fileinfo, parent = nil)
    super(parent)

    top_label = QLabel.new(tr('Open with:'))
    applications_list_box = QListWidget.new
    applications = QStringList.new
    (1..30).each { |i| applications.push tr('Application %d' % i) }
    applications_list_box.insert_items(0, applications)

    if fileinfo.suffix.nil?
      always_checkbox = QCheckBox.new(tr('Always use this application to open this type of file'))
    else
      always_checkbox = QCheckBox.new(tr("Always use this application to #{"open files with the extension '%s'" % fileinfo.suffix}"))
    end

    l = QVBoxLayout.new
    l.add_widget(top_label)
    l.add_widget(applications_list_box)
    l.add_widget(always_checkbox)
    set_layout(l)
  end
end
