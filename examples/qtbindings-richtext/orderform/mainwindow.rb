# frozen_string_literal: true

require_relative 'detailsdialog'

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'open_dialog()'
    slot 'print_file()'
  end

  def initialize(parent = nil)
    super

    file_menu = QMenu.new(tr('&File'), self)
    new_action = file_menu.add_action(tr('&New...'))
    new_action.set_shortcut QKeySequence.new(tr('Ctrl+N'))
    @print_action = file_menu.add_action(tr('&Print...'))
    @print_action.set_shortcut QKeySequence.new(tr('Ctrl+P'))
    @print_action.set_enabled false
    quit_action = file_menu.add_action(tr('E&xit'))
    quit_action.set_shortcut QKeySequence.new(tr('Ctrl+Q'))
    menu_bar.add_menu(file_menu)

    @letters = QTabWidget.new

    new_action.triggered.connect(self, :open_dialog)
    @print_action.triggered.connect(self, :print_file)
    quit_action.triggered.connect(self, :close)

    set_central_widget @letters
    set_window_title tr('Order Form')
  end

  def create_letter(name, address, order_items, send_offers)
    editor = QTextEdit.new
    tabindex = @letters.add_tab(editor, name)
    @letters.set_current_index tabindex

    cursor = editor.text_cursor.dup
    cursor.move_position(QTextCursor::Start)
    top_frame = cursor.current_frame
    top_frame_format = top_frame.frame_format
    top_frame_format.set_padding 16
    top_frame.set_frame_format top_frame_format

    text_format = QTextCharFormat.new
    bold_format = QTextCharFormat.new
    bold_format.set_font_weight QFont::Bold

    referenceframe_format = QTextFrameFormat.new.tap do |r|
      r.set_border 1
      r.set_padding 8
      r.set_position QTextFrameFormat::FloatRight
      r.set_width QTextLength.new(QTextLength::PercentageLength, 40)
    end
    cursor.insert_frame(referenceframe_format)

    cursor.insert_text('A company', bold_format)
    cursor.insert_block
    cursor.insert_text('321 City Street')
    cursor.insert_block
    cursor.insert_text('Industry Park')
    cursor.insert_block
    cursor.insert_text('Another country')

    cursor.set_position top_frame.last_position

    cursor.insert_text(name, text_format)
    address.split("\n").each do |line|
      cursor.insert_block
      cursor.insert_text(line)
    end
    cursor.insert_block
    cursor.insert_block

    date = QDate.current_date
    cursor.insert_text(tr('Date: %s' % date.to_string('d MMMM yyyy')), text_format)
    cursor.insert_block

    bodyframe_format = QTextFrameFormat.new
    bodyframe_format.set_width(QTextLength.new(QTextLength::PercentageLength, 100))
    cursor.insert_frame(bodyframe_format)

    cursor.insert_text(tr('I would like to place an order for the following items:'), text_format)
    cursor.insert_block

    order_table_format = QTextTableFormat.new
    order_table_format.set_alignment Qt::AlignHCenter
    order_table = cursor.insert_table(1, 2, order_table_format)

    orderframe_format = cursor.current_frame.frame_format
    orderframe_format.set_border 1
    cursor.current_frame.set_frame_format orderframe_format

    cursor = order_table.cell_at(0, 0).first_cursor_position
    cursor.insert_text(tr('Product'), bold_format)
    cursor = order_table.cell_at(0, 1).first_cursor_position
    cursor.insert_text(tr('Quantity'), bold_format)

    (0...order_items.length).each do |i|
      item = order_items[i]
      row = order_table.rows

      order_table.insert_rows(row, 1)
      cursor = order_table.cell_at(row, 0).first_cursor_position
      cursor.insert_text(item[0], text_format)
      cursor = order_table.cell_at(row, 1).first_cursor_position
      cursor.insert_text('%s' % item[1], text_format)
    end

    cursor.set_position top_frame.last_position

    cursor.insert_text(tr('Please update my records to take account of the following privacy information:'))
    cursor.insert_block

    offers_table = cursor.insert_table(2, 2)

    cursor = offers_table.cell_at(0, 1).first_cursor_position
    cursor.insert_text(tr("I want to receive more information about your company's products and special offers."),
                       text_format)
    cursor = offers_table.cell_at(1, 1).first_cursor_position
    cursor.insert_text(tr('I do not want to receive any promotional information from your company.'), text_format)

    cursor = if send_offers
               offers_table.cell_at(0, 0).first_cursor_position
             else
               offers_table.cell_at(1, 0).first_cursor_position
             end

    cursor.insert_text('X', bold_format)

    cursor.set_position top_frame.last_position
    cursor.insert_block
    cursor.insert_text(tr('Sincerely,'), text_format)
    cursor.insert_block
    cursor.insert_block
    cursor.insert_block
    cursor.insert_text(name)

    @print_action.set_enabled true
  end

  def create_sample
    dialog = DetailsDialog.new('Dialog with default values', self)
    create_letter('Mr Smith', "12 High Street\nSmall Town\nThis country", dialog.order_items, true)
  end

  def open_dialog
    dialog = DetailsDialog.new(tr('Enter Customer Details'), self)
    return unless dialog.exec == QDialog::Accepted

    create_letter(dialog.sender_name, dialog.sender_address, dialog.order_items, dialog.send_offers)
  end

  def print_file
    editor = @letters.current_widget
    document = editor.document
    printer = QPrinter.new

    dialog = QPrintDialog.new(printer, self)
    return if dialog.exec != QDialog::Accepted

    document.print(printer)
  end
end
