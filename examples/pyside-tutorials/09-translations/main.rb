# frozen_string_literal: true

require 'qt6/all'
require_relative 'rc_linguist'

class Window < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'selection_changed(QItemSelection,QItemSelection)'
  end

  def initialize
    super

    file_menu = menu_bar.add_menu(tr('&File'))
    quit_action = file_menu.add_action(tr('Quit'))
    quit_action.set_shortcut(QKeySequence.new(tr('CTRL+Q')))
    quit_action.triggered.connect(self, :close)

    help_menu = menu_bar.add_menu(tr('&Help'))
    about_qt_action = help_menu.add_action(tr('About Qt'))
    about_qt_action.triggered.connect($qApp, :aboutQt)

    @_list_widget = QListWidget.new
    @_list_widget.set_selection_mode(QAbstractItemView::SelectionMode::MultiSelection)
    @_list_widget.selection_model.selection_changed.connect(self, :selection_changed)
    @_list_widget.add_item('C++')
    @_list_widget.add_item('Java')
    @_list_widget.add_item('Python')
    set_central_widget(@_list_widget)
  end

  def selection_changed(_selected, _deselected)
    count = @_list_widget.selection_model.selected_rows.count
    message = tr('%n language(s) selected', '', count)
    status_bar.show_message(message)
  end
end

app = QApplication.new

translator_qt = QTranslator.new(app)
translator_custom = QTranslator.new(app)
translator_qt.load(QLocale.system, 'qtbase', '_', QLibraryInfo.path(QLibraryInfo::LibraryPath::TranslationsPath))
puts 'Launch with `LANG=de bundle exec ruby main.rb` to load example_de.qm' unless translator_custom.load(
  QLocale.system, 'example', '_', ':/translations'
)
QApplication.install_translator(translator_qt)
QApplication.install_translator(translator_custom)

window = Window.new
window.show
app.exec
