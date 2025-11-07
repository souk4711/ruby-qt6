# frozen_string_literal: true

require_relative 'applicationstab'
require_relative 'generaltab'
require_relative 'permissionstab'

class TabDialog < RubyQt6::Bando::QDialog
  def initialize(filename, parent = nil)
    super(parent)

    fileinfo = QFileInfo.new(filename)

    @tab_widget = QTabWidget.new
    @tab_widget.add_tab(GeneralTab.new(fileinfo), tr('General'))
    @tab_widget.add_tab(PermissionsTab.new(fileinfo), tr('Permissions'))
    @tab_widget.add_tab(ApplicationsTab.new(fileinfo), tr('Applications'))

    ok_button = QPushButton.new(tr('OK'))
    cancel_button = QPushButton.new(tr('Cancel'))

    ok_button.clicked.connect(self, :accept)
    cancel_button.clicked.connect(self, :reject)

    b = QHBoxLayout.new
    b.add_stretch(1)
    b.add_widget(ok_button)
    b.add_widget(cancel_button)

    m = QVBoxLayout.new
    m.add_widget(@tab_widget)
    m.add_layout(b)
    set_layout(m)

    set_window_title(tr('Tab Dialog'))
  end
end
