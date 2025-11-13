# frozen_string_literal: true

require_relative 'highlighter'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'new_file()'
    slot 'open_file()'
    slot 'open_file(QString)'
  end

  def initialize(parent = nil)
    super(parent)

    @highlighter = Highlighter.new
    setup_file_menu
    setup_editor

    set_central_widget(@editor)
    set_window_title(tr('Syntax Highlighter'))
  end

  def new_file
    @editor.clear
  end

  def open_file(path = nil)
    file_name = path
    if file_name.nil?
      file_name = QFileDialog.get_open_file_name(self, tr('Open File'), '',
                                                 'qmake Files (*.pro *.prf *.pri)')
    end
    return if file_name.nil?

    file = QFile.new(file_name)
    return unless file.open(QFile::ReadOnly | QFile::Text)

    @editor.set_plain_text file.read_all.to_s
  end

  def setup_editor
    variable_format = QTextCharFormat.new
    variable_format.set_font_weight QFont::Bold
    variable_format.set_foreground QBrush.new(Qt::Blue)
    @highlighter.add_mapping('\b[A-Z_]+\b', variable_format)

    single_line_comment_format = QTextCharFormat.new
    single_line_comment_format.set_background QBrush.new(QColor.new('#77ff77'))
    @highlighter.add_mapping('#[^\n]*', single_line_comment_format)

    quotation_format = QTextCharFormat.new
    quotation_format.set_background QBrush.new(Qt::Cyan)
    quotation_format.set_foreground QBrush.new(Qt::Blue)
    @highlighter.add_mapping('\".*\"', quotation_format)

    function_format = QTextCharFormat.new
    function_format.set_font_italic true
    function_format.set_foreground QBrush.new(Qt::Blue)
    @highlighter.add_mapping('\b[a-z0-9_]+\(.*\)', function_format)

    font = QFont.new
    font.set_family 'Courier'
    font.set_fixed_pitch true
    font.set_point_size 10

    @editor = QTextEdit.new
    @editor.set_font font
    @highlighter.add_to_document(@editor.document)
  end

  def setup_file_menu
    file_menu = QMenu.new(tr('&File'), self)
    menu_bar.add_menu(file_menu)

    file_menu.add_action(tr('&New...'), QKeySequence.new(tr('Ctrl+N', 'File|New'))).triggered.connect(self, :new_file)
    file_menu.add_action(tr('&Open...'), QKeySequence.new(tr('Ctrl+O', 'File|Open'))).triggered.connect(self,
                                                                                                        :open_file)
    file_menu.add_action(tr('E&xit'), QKeySequence.new(tr('Ctrl+Q', 'File|Exit'))).triggered.connect($qApp, :quit)
  end
end
