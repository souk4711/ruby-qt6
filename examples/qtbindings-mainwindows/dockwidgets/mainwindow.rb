# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'new_letter()'
    slot 'save()'
    slot 'print()'
    slot 'undo()'
    slot 'about()'
    slot 'insert_customer(QString)'
    slot 'add_paragraph(QString)'
  end

  def initialize
    super

    @text_tedit = QTextEdit.new
    set_central_widget(@text_tedit)

    create_actions
    create_menu
    create_tool_bars
    create_status_bar
    create_dock_windows

    set_window_title(tr('Dock Widgets'))
    new_letter
  end

  def new_letter
    @text_tedit.clear

    cursor = @text_tedit.text_cursor.dup
    cursor.move_position(QTextCursor::Start)
    top_frame = cursor.current_frame
    top_frrame_format = top_frame.frame_format
    top_frrame_format.set_padding 16
    top_frame.set_frame_format top_frrame_format

    text_format = QTextCharFormat.new
    bold_format = QTextCharFormat.new
    bold_format.set_font_weight QFont::Bold
    italic_format = QTextCharFormat.new
    italic_format.set_font_italic true

    table_format = QTextTableFormat.new
    table_format.set_border 1
    table_format.set_cell_padding 16
    table_format.set_alignment Qt::AlignRight
    cursor.insert_table(1, 1, table_format)
    cursor.insert_text('The Firm', bold_format)
    cursor.insert_block
    cursor.insert_text('321 City Street', text_format)
    cursor.insert_block
    cursor.insert_text('Industry Park')
    cursor.insert_block
    cursor.insert_text('Some Country')
    cursor.set_position top_frame.last_position
    cursor.insert_text(QDate.current_date.to_string('d MMMM yyyy'), text_format)
    cursor.insert_block
    cursor.insert_block
    cursor.insert_text('Dear ', text_format)
    cursor.insert_text('NAME', italic_format)
    cursor.insert_text(',', text_format)
    (0...3).each do |_|
      cursor.insert_block
    end
    cursor.insert_text(tr('Yours sincerely,'), text_format)
    (0...3).each do |_|
      cursor.insert_block
    end
    cursor.insert_text('The Boss', text_format)
    cursor.insert_block
    cursor.insert_text('ADDRESS', italic_format)
  end

  def print
    document = @text_tedit.document
    printer = QPrinter.new

    dlg = QPrintDialog.new(printer, self)
    return if dlg.exec != QDialog::Accepted.to_i

    document.print(printer)

    status_bar.show_message(tr('Ready'), 2000)
  end

  def save
    filename = QFileDialog.get_save_file_name(self, tr('Choose a file name'), '.', tr('HTML (*.html *.htm)'))
    return if (!filename) || filename.empty?

    file = QFile.new(filename)
    unless file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('Dock Widgets'), tr(format("Cannot write file %s:\n%s.", filename, error_string)))
      return
    end

    out = QTextStream.new(file)
    QApplication.set_override_cursor(QCursor.new(Qt::WaitCursor))
    out << @text_tedit.to_html
    QApplication.restore_override_cursor

    status_bar.show_message(tr("Saved '#{filename}'"), 2000)
  end

  def undo
    document = @text_tedit.document
    document.undo
  end

  def insert_customer(customer)
    return if customer.empty?

    @customer_list = customer.split(', ')
    document = @text_tedit.document
    cursor = document.find('NAME')
    return if cursor.nil?

    cursor.begin_edit_block
    cursor.insert_text(@customer_list.at(0))
    oldcursor = cursor
    cursor = document.find('ADDRESS')
    if !cursor.nil?
      (1...@customer_list.size).each do |i|
        cursor.insert_block
        cursor.insert_text(@customer_list.at(i))
      end
      cursor.end_edit_block
    else
      oldcursor.end_edit_block
    end
  end

  def add_paragraph(paragraph)
    return if paragraph.empty?

    document = @text_tedit.document
    cursor = document.find(tr('Yours sincerely,'))
    return if cursor.nil?

    cursor.begin_edit_block
    cursor.move_position(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 2)
    cursor.insert_block
    cursor.insert_text(paragraph)
    cursor.insert_block
    cursor.end_edit_block
  end

  def about
    QMessageBox.about(self, tr('About Dock Widgets'),
                      tr('The <b>Dock Widgets</b> example demonstrates how to ' \
                         "use Qt's dock widgets. You can enter your own text, " \
                         'click a customer to add a customer name and ' \
                         'address, and click standard paragraphs to add them.'))
  end

  def create_actions
    @new_letter_act = QAction.new(QIcon.new('images/new.png'), tr('&New Letter'), self)
    @new_letter_act.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @new_letter_act.set_status_tip tr('Create a form.new letter')
    @new_letter_act.triggered.connect(self, :new_letter)

    @save_act = QAction.new(QIcon.new('images/save.png'), tr('&Save...'), self)
    @save_act.set_shortcut QKeySequence.new(tr('Ctrl+S'))
    @save_act.set_status_tip tr('Save the current form letter')
    @save_act.triggered.connect(self, :save)

    @print_act = QAction.new(QIcon.new('images/print.png'), tr('&Print...'), self)
    @print_act.set_shortcut QKeySequence.new(tr('Ctrl+P'))
    @print_act.set_status_tip tr('Print the current form letter')
    @print_act.triggered.connect(self, :print)

    @undo_act = QAction.new(QIcon.new('images/undo.png'), tr('&Undo'), self)
    @undo_act.set_shortcut QKeySequence.new(tr('Ctrl+Z'))
    @undo_act.set_status_tip tr('Undo the last editing action')
    @undo_act.triggered.connect(self, :undo)

    @quit_act = QAction.new(tr('&Quit'), self)
    @quit_act.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    @quit_act.set_status_tip tr('Quit the application')
    @quit_act.triggered.connect(self, :close)

    @about_act = QAction.new(tr('&About'), self)
    @about_act.set_status_tip tr("Show the application's About box")
    @about_act.triggered.connect(self, :about)

    @about_qt_act = QAction.new(tr('About &Qt'), self)
    @about_qt_act.set_status_tip tr("Show the Qt library's About box")
    @about_qt_act.triggered.connect($qApp, :about_qt)
  end

  def create_menu
    @file_menu = menu_bar.add_menu(tr('&File'))
    @file_menu.add_action(@new_letter_act)
    @file_menu.add_action(@save_act)
    @file_menu.add_action(@print_act)
    @file_menu.add_separator
    @file_menu.add_action(@quit_act)

    @edit_menu = menu_bar.add_menu(tr('&Edit'))
    @edit_menu.add_action(@undo_act)

    menu_bar.add_separator

    @help_menu = menu_bar.add_menu(tr('&Help'))
    @help_menu.add_action(@about_act)
    @help_menu.add_action(@about_qt_act)
  end

  def create_tool_bars
    @file_tool_bar = add_tool_bar(tr('File'))
    @file_tool_bar.add_action(@new_letter_act)
    @file_tool_bar.add_action(@save_act)
    @file_tool_bar.add_action(@print_act)

    @edit_tool_bar = add_tool_bar(tr('Edit'))
    @edit_tool_bar.add_action(@undo_act)
  end

  def create_status_bar
    status_bar.show_message(tr('Ready'))
  end

  def create_dock_windows
    dock = QDockWidget.new(tr('Customers'), self)
    dock.set_allowed_areas Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea
    @customer_list = QListWidget.new(dock)
    @customer_list.add_items(QStringList.new <<
           'John Doe, Harmony Enterprises, 12 Lakeside, Ambleton' \
           'Jane Doe, Memorabilia, 23 Watersedge, Beaton' \
           'Tammy Shea, Tiblanka, 38 Sea Views, Carlton' \
           'Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal' \
           'Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston' \
           'Sally Hobart, Tiroli Tea, 67 Long River, Fedula')
    dock.set_widget @customer_list
    add_dock_widget(Qt::RightDockWidgetArea, dock)

    dock = QDockWidget.new(tr('Paragraphs'), self)
    @paragraphcs_list = QListWidget.new(dock)
    @paragraphcs_list.add_items(QStringList.new <<
              'Thank you for your payment which we have received today.' \
              'Your order has been dispatched and should be with you ' \
              'within 28 days.' \
              'We have dispatched those items that were in stock. The ' \
              'rest of your order will be dispatched once all the ' \
              'remaining items have arrived at our warehouse. No ' \
              'additional shipping charges will be made.' \
              'You made a small overpayment (less than $5) which we ' \
              'will keep on account for you, or return at your request.' \
              'You made a small underpayment (less than $1), but we have ' \
              "sent your order anyway. We'll add self underpayment to " \
              'your next bill.' \
              'Unfortunately you did not send enough money. Please remit ' \
              'an additional $. Your order will be dispatched as soon as ' \
              'the complete amount has been received.' \
              'You made an overpayment (more than $5). Do you wish to ' \
              'buy more items, or should we return the excess to you?')
    dock.set_widget @paragraphcs_list
    add_dock_widget(Qt::RightDockWidgetArea, dock)

    @customer_list.current_text_changed.connect(self, :insert_customer)
    @paragraphcs_list.current_text_changed.connect(self, :add_paragraph)
  end
end
