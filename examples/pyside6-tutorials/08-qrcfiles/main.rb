# frozen_string_literal: true

require 'qt6/all'
require_relative 'rc_icons'

class MainWindow < RubyQt6::Bando::QMainWindow
  def initialize
    super

    open_icon = QIcon.from_theme(QIcon::ThemeIcon::DocumentOpen)
    exit_icon = QIcon.from_theme(QIcon::ThemeIcon::ApplicationExit)
    play_icon = QIcon.new(QPixmap.new(':/icons/play.png'))
    previous_icon = QIcon.new(QPixmap.new(':/icons/previous.png'))
    pause_icon = QIcon.new(QPixmap.new(':/icons/pause.png'))
    next_icon = QIcon.new(QPixmap.new(':/icons/forward.png'))
    stop_icon = QIcon.new(QPixmap.new(':/icons/stop.png'))

    file_menu = menu_bar.add_menu('&File')
    open_action = file_menu.add_action(open_icon, 'Open')
    exit_action = file_menu.add_action(exit_icon, 'Exit')

    play_menu = menu_bar.add_menu('&Play')
    play_action = play_menu.add_action(play_icon, 'Play')
    previous_action = play_menu.add_action(previous_icon, 'Previous')
    pause_action = play_menu.add_action(pause_icon, 'Pause')
    next_action = play_menu.add_action(next_icon, 'Next')
    stop_action = play_menu.add_action(stop_icon, 'Stop')

    exit_action.triggered.connect($qApp, :quit)

    tool_bar = add_tool_bar('')
    tool_bar.add_action(open_action)
    tool_bar.add_action(exit_action)
    tool_bar.add_action(play_action)
    tool_bar.add_action(previous_action)
    tool_bar.add_action(pause_action)
    tool_bar.add_action(next_action)
    tool_bar.add_action(stop_action)
  end
end

app = QApplication.new(ARGV)
window = MainWindow.new
window.show
app.exec
