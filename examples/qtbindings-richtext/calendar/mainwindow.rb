# frozen_string_literal: true

class MainWindow < RubyQt6::Bando::QMainWindow
  q_object do
    slot 'set_font_size(int)'
    slot 'set_month(int)'
    slot 'set_year(QDate)'
  end

  def initialize(parent = nil)
    super

    @selected_date = QDate.current_date
    @font_size = 10

    central_widget = QWidget.new

    date_label = QLabel.new(tr('Date:'))

    month_combo = QComboBox.new
    (1..12).each { |month| month_combo.add_item(month.to_s.rjust(2, '0')) }

    year_edit = QDateTimeEdit.new(QDateTime.new).tap do |y|
      y.set_display_format 'yyyy'
      y.set_date_range(QDate.new(1753, 1, 1), QDate.new(8000, 1, 1))
    end

    month_combo.set_current_index @selected_date.month - 1
    year_edit.set_date @selected_date

    font_size_label = QLabel.new(tr('Font size:'))

    font_size_spinbox = QSpinBox.new.tap do |f|
      f.set_range 1, 64
      f.set_value 10
    end

    @editor = QTextBrowser.new
    insert_calendar

    month_combo.activated.connect(self, :set_month)
    year_edit.date_changed.connect(self, :set_year)
    font_size_spinbox.value_changed.connect(self, :set_font_size)

    controls_layout = QHBoxLayout.new.tap do |c|
      c.add_widget(date_label)
      c.add_widget(month_combo)
      c.add_widget(year_edit)
      c.add_spacing(24)
      c.add_widget(font_size_label)
      c.add_widget(font_size_spinbox)
      c.add_stretch(1)
    end

    layout = QVBoxLayout.new.tap do |c|
      c.add_layout(controls_layout)
      c.add_widget(@editor, 1)
    end
    central_widget.set_layout(layout)

    set_central_widget central_widget
  end

  def insert_calendar
    @editor.clear

    cursor = @editor.text_cursor

    date = QDate.new(@selected_date.year, @selected_date.month, 1)

    table_format = QTextTableFormat.new.tap do |t|
      t.set_alignment Qt::AlignHCenter
      t.set_background QBrush.new(QColor.new('#e0e0e0'))
      t.set_cell_padding 2
      t.set_cell_spacing 4
    end

    table_format.set_column_width_constraints(
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14),
      QTextLength.new(QTextLength::PercentageLength, 14)
    )
    table = cursor.insert_table(1, 7, table_format)

    frame = cursor.current_frame
    frame_format = frame.frame_format
    frame_format.set_border 1
    frame.set_frame_format frame_format

    format = cursor.char_format
    format.set_font_point_size @font_size

    bold_format = QTextCharFormat.new
    bold_format.merge(format)
    bold_format.set_font_weight QFont::Bold

    highlighed_format = QTextCharFormat.new
    highlighed_format.merge(bold_format)
    highlighed_format.set_background QBrush.new(Qt::Yellow)

    (1..7).each do |week_day|
      cell = table.cell_at(0, week_day - 1)
      cell_cursor = cell.first_cursor_position
      cell_cursor.insert_text(week_day.to_s.rjust(2, '0'), bold_format)
    end

    table.insert_rows(table.rows, 1)

    while date.month == @selected_date.month
      week_day = date.day_of_week
      cell = table.cell_at(table.rows - 1, week_day - 1)
      cell_cursor = cell.first_cursor_position

      if date == QDate.current_date
        cell_cursor.insert_text('%s' % date.day, highlighed_format)
      else
        cell_cursor.insert_text('%s' % date.day, format)
      end

      date = date.add_days(1)
      table.insert_rows(table.rows, 1) if week_day == 7 && date.month == @selected_date.month
    end

    set_window_title(tr(format('Calendar for %s %s', @selected_date.to_string('MM'), @selected_date.year)))
  end

  def set_font_size(size)
    @font_size = size
    insert_calendar
  end

  def set_month(month)
    @selected_date = QDate.new(@selected_date.year, month + 1, @selected_date.day)
    insert_calendar
  end

  def set_year(date)
    @selected_date = QDate.new(date.year, @selected_date.month, @selected_date.day)
    insert_calendar
  end
end
