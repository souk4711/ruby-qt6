# frozen_string_literal: true

require 'qt6/all'
require_relative 'window'
require_relative 'rc_systray'

app = QApplication.new(ARGV)

unless QSystemTrayIcon.system_tray_available?
  QMessageBox.critical(nil, QObject.tr('Systray'), QObject.tr("I couldn't detect any system tray on this system."))
  exit 1
end

window = Window.new
window.show
app.exec
