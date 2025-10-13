# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'new_file()'
    slot 'open()'
    slot 'save()'
    slot 'print()'
    slot 'undo()'
    slot 'redo()'
    slot 'cut()'
    slot 'copy()'
    slot 'paste()'
    slot 'bold()'
    slot 'italic()'
    slot 'left_align()'
    slot 'right_align()'
    slot 'justify()'
    slot 'center()'
    slot 'set_line_spacing()'
    slot 'set_paragraph_spacing()'
    slot 'about()'
    slot 'about_qt()'
  end

  def initialize(parent = nil)
    super

    w = QWidget.new
    set_central_widget(w)

    top_filler = QWidget.new
    top_filler.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding)

    @info_label = QLabel.new(tr('<i>Choose a menu option, or right-click to invoke a context menu</i>'))
    @info_label.set_frame_style QFrame::StyledPanel.to_i | QFrame::Sunken
    @info_label.set_alignment Qt::AlignCenter

    bottomFiller = QWidget.new
    bottomFiller.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Expanding)

    vbox = QVBoxLayout.new
    vbox.set_contents_margins(5, 5, 5, 5)
    vbox.add_widget(top_filler)
    vbox.add_widget(@info_label)
    vbox.add_widget(bottomFiller)
    w.set_layout vbox

    create_actions
    create_menu
    status_bar.show_message(tr('A context menu is available by right-clicking'))

    set_window_title(tr('Menus'))
    set_minimum_size(160, 160)
    resize(480, 320)
  end

  def context_menu_event(event)
    menu = QMenu.new('', self)
    menu.add_action(@cut_action)
    menu.add_action(@copy_action)
    menu.add_action(@paste_action)
    menu.exec(event.global_pos)
  end

  def new_file
    @info_label.set_text tr('Invoked <b>File|New</b>')
  end

  def open
    @info_label.set_text tr('Invoked <b>File|Open</b>')
  end

  def save
    @info_label.set_text tr('Invoked <b>File|Save</b>')
  end

  def print
    @info_label.set_text tr('Invoked <b>File|Print</b>')
  end

  def undo
    @info_label.set_text tr('Invoked <b>Edit|Undo</b>')
  end

  def redo
    @info_label.set_text tr('Invoked <b>Edit|Redo</b>')
  end

  def cut
    @info_label.set_text tr('Invoked <b>Edit|Cut</b>')
  end

  def copy
    @info_label.set_text tr('Invoked <b>Edit|Copy</b>')
  end

  def paste
    @info_label.set_text tr('Invoked <b>Edit|Paste</b>')
  end

  def bold
    @info_label.set_text tr('Invoked <b>Edit|Format|Bold</b>')
  end

  def italic
    @info_label.set_text tr('Invoked <b>Edit|Format|Italic</b>')
  end

  def left_align
    @info_label.set_text tr('Invoked <b>Edit|Format|Left Align</b>')
  end

  def right_align
    @info_label.set_text tr('Invoked <b>Edit|Format|Right Align</b>')
  end

  def justify
    @info_label.set_text tr('Invoked <b>Edit|Format|Justify</b>')
  end

  def center
    @info_label.set_text tr('Invoked <b>Edit|Format|Center</b>')
  end

  def set_line_spacing
    @info_label.set_text tr('Invoked <b>Edit|Format|Set Line Spacing</b>')
  end

  def set_paragraph_spacing
    @info_label.set_text tr('Invoked <b>Edit|Format|Set Paragraph Spacing</b>')
  end

  def about
    @info_label.set_text tr('Invoked <b>Help|About</b>')
    QMessageBox.about(self, tr('About Menu'),
                      tr('The <b>Menu</b> example shows how to create menu-bar menus and context menus.'))
  end

  def about_qt
    @info_label.set_text tr('Invoked <b>Help|About Qt</b>')
  end

  def create_actions
    @new_action = QAction.new(QIcon.new, tr('&New'), self)
    @new_action.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @new_action.set_status_tip tr('Create a file.new')
    @new_action.triggered.connect(self, :new_file)

    @open_action = QAction.new(QIcon.new, tr('&Open...'), self)
    @open_action.set_shortcut QKeySequence.new(tr('Ctrl+O'))
    @open_action.set_status_tip tr('Open an existing file')
    @open_action.triggered.connect(self, :open)

    @save_action = QAction.new(QIcon.new, tr('&Save'), self)
    @save_action.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @save_action.set_status_tip tr('Save the document to disk')
    @save_action.triggered.connect(self, :save)

    @print_action = QAction.new(QIcon.new, tr('&Print...'), self)
    @print_action.set_shortcut QKeySequence.new(tr('Ctrl+P'))
    @print_action.set_status_tip tr('Print the document')
    @print_action.triggered.connect(self, :print)

    @exit_action = QAction.new(QIcon.new, tr('E&xit'), self)
    @exit_action.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @exit_action.set_status_tip tr('Exit the application')
    @exit_action.triggered.connect(self, :close)

    @undo_action = QAction.new(QIcon.new, tr('&Undo'), self)
    @undo_action.set_shortcut QKeySequence.new(tr('Ctrl+Z'))
    @undo_action.set_status_tip tr('Undo the last operation')
    @undo_action.triggered.connect(self, :undo)

    @redo_action = QAction.new(QIcon.new, tr('&Redo'), self)
    @redo_action.set_shortcut QKeySequence.new(tr('Ctrl+Y'))
    @redo_action.set_status_tip tr('Redo the last operation')
    @redo_action.triggered.connect(self, :redo)

    @cut_action = QAction.new(QIcon.new, tr('Cu&t'), self)
    @cut_action.set_shortcut QKeySequence.new(tr('Ctrl+X'))
    @cut_action.set_status_tip(tr("Cut the current selection's contents to the clipboard"))
    @cut_action.triggered.connect(self, :cut)

    @copy_action = QAction.new(QIcon.new, tr('&Copy'), self)
    @copy_action.set_shortcut QKeySequence.new(tr('Ctrl+C'))
    @copy_action.set_status_tip(tr("Copy the current selection's contents to the clipboard"))
    @copy_action.triggered.connect(self, :copy)

    @paste_action = QAction.new(QIcon.new, tr('&Paste'), self)
    @paste_action.set_shortcut QKeySequence.new(tr('Ctrl+V'))
    @paste_action.set_status_tip(tr("Paste the clipboard's contents into the current selection"))
    @paste_action.triggered.connect(self, :paste)

    @bold_action = QAction.new(QIcon.new, tr('&Bold'), self)
    @bold_action.set_checkable true
    @bold_action.set_shortcut QKeySequence.new(tr('Ctrl+B'))
    @bold_action.set_status_tip tr('Make the text bold')
    @bold_action.triggered.connect(self, :bold)

    bold_font = @bold_action.font
    bold_font.set_bold true
    @bold_action.set_font bold_font

    @italic_action = QAction.new(QIcon.new, tr('&Italic'), self)
    @italic_action.set_checkable true
    @italic_action.set_shortcut QKeySequence.new(tr('Ctrl+I'))
    @italic_action.set_status_tip tr('Make the text italic')
    @italic_action.triggered.connect(self, :italic)

    italic_font = @italic_action.font
    italic_font.set_italic true
    @italic_action.set_font italic_font

    @left_align_action = QAction.new(QIcon.new, tr('&Left Align'), self)
    @left_align_action.set_checkable true
    @left_align_action.set_shortcut QKeySequence.new(tr('Ctrl+L'))
    @left_align_action.set_status_tip tr('Left align the selected text')
    @left_align_action.triggered.connect(self, :left_align)

    @right_align_action = QAction.new(QIcon.new, tr('&Right Align'), self)
    @right_align_action.set_checkable true
    @right_align_action.set_shortcut QKeySequence.new(tr('Ctrl+R'))
    @right_align_action.set_status_tip tr('Right align the selected text')
    @right_align_action.triggered.connect(self, :right_align)

    @justify_action = QAction.new(QIcon.new, tr('&Justify'), self)
    @justify_action.set_checkable true
    @justify_action.set_shortcut QKeySequence.new(tr('Ctrl+J'))
    @justify_action.set_status_tip tr('Justify the selected text')
    @justify_action.triggered.connect(self, :justify)

    @center_action = QAction.new(QIcon.new, tr('&Center'), self)
    @center_action.set_checkable true
    @center_action.set_shortcut QKeySequence.new(tr('Ctrl+E'))
    @center_action.set_status_tip tr('Center the selected text')
    @center_action.triggered.connect(self, :center)

    @alignmentGroup = QActionGroup.new(self)
    @alignmentGroup.add_action(@left_align_action)
    @alignmentGroup.add_action(@right_align_action)
    @alignmentGroup.add_action(@justify_action)
    @alignmentGroup.add_action(@center_action)
    @left_align_action.set_checked true

    @set_line_spacing_action = QAction.new(QIcon.new, tr('Set &Line Spacing...'), self)
    @set_line_spacing_action.set_status_tip(tr('Change the gap between the lines of a paragraph'))
    @set_line_spacing_action.triggered.connect(self, :set_line_spacing)

    @set_paragraph_spacing_action = QAction.new(QIcon.new, tr('Set &Paragraph Spacing...'), self)
    @set_line_spacing_action.set_status_tip tr('Change the gap between paragraphs')
    @set_paragraph_spacing_action.triggered.connect(self, :set_paragraph_spacing)

    @about_action = QAction.new(QIcon.new, tr('&About'), self)
    @about_action.set_status_tip tr("Show the application's About box")
    @about_action.triggered.connect(self, :about)

    @about_qt_action = QAction.new(QIcon.new, tr('About &Qt'), self)
    @about_qt_action.set_status_tip tr("Show the Qt library's About box")
    @about_qt_action.triggered.connect($qApp, :about_qt)
    @about_qt_action.triggered.connect(self, :about_qt)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_action)
    @file_menu.add_action(@open_action)
    @file_menu.add_action(@save_action)
    @file_menu.add_action(@print_action)
    @file_menu.add_separator
    @file_menu.add_action(@exit_action)

    @edit_menu = menu_bar.add_menu(tr('&Edit'))
    @edit_menu.add_action(@undo_action)
    @edit_menu.add_action(@redo_action)
    @edit_menu.add_separator
    @edit_menu.add_action(@cut_action)
    @edit_menu.add_action(@copy_action)
    @edit_menu.add_action(@paste_action)
    @edit_menu.add_separator

    @format_menu = @edit_menu.add_menu(tr('&Format'))
    @format_menu.add_action(@bold_action)
    @format_menu.add_action(@italic_action)
    @format_menu.add_separator
    @format_menu.add_action(@left_align_action)
    @format_menu.add_action(@right_align_action)
    @format_menu.add_action(@justify_action)
    @format_menu.add_action(@center_action)
    @format_menu.add_separator
    @format_menu.add_action(@set_line_spacing_action)
    @format_menu.add_action(@set_paragraph_spacing_action)

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_action)
    @help_menu.add_action(@about_qt_action)
  end
end
