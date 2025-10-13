# frozen_string_literal: true

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'change_precision(int)'
    slot 'set_format_string(QString)'
  end

  def initialize(parent = nil)
    super(parent)

    create_spin_boxes
    create_date_time_edits
    create_double_spin_boxes

    layout = QHBoxLayout.new
    layout.add_widget(@spin_boxes_group)
    layout.add_widget(@edits_group)
    layout.add_widget(@double_spin_boxes_group)
    set_layout(layout)

    set_window_title(tr('Spin Boxes'))
  end

  def create_spin_boxes
    @spin_boxes_group = QGroupBox.new(tr('Spinboxes'))

    integer_label = QLabel.new(tr(format('Enter a value between %d and %d:', -20, 20)))
    integer_spinbox = QSpinBox.new
    integer_spinbox.set_range(-20, 20)
    integer_spinbox.set_single_step(1)
    integer_spinbox.set_value(0)

    zoom_label = QLabel.new(tr(format('Enter a zoom value between %d and %d:', 0, 1000)))
    zoom_spin_box = QSpinBox.new
    zoom_spin_box.set_range(0, 1000)
    zoom_spin_box.set_single_step(10)
    zoom_spin_box.set_suffix('%')
    zoom_spin_box.set_special_value_text tr('Automatic')
    zoom_spin_box.set_value(100)

    price_label = QLabel.new(tr(format('Enter a price between %d and %d:', 0, 999)))
    @price_spin_box = QSpinBox.new
    @price_spin_box.set_range(0, 999)
    @price_spin_box.set_single_step(1)
    @price_spin_box.set_prefix('$')
    @price_spin_box.set_value(99)

    spinbox_layout = QVBoxLayout.new
    spinbox_layout.add_widget(integer_label)
    spinbox_layout.add_widget(integer_spinbox)
    spinbox_layout.add_widget(zoom_label)
    spinbox_layout.add_widget(zoom_spin_box)
    spinbox_layout.add_widget(price_label)
    spinbox_layout.add_widget(@price_spin_box)
    @spin_boxes_group.set_layout(spinbox_layout)
  end

  def create_date_time_edits
    @edits_group = QGroupBox.new(tr('Date and time spin boxes'))

    date_label = QLabel.new
    date_edit = QDateEdit.new(QDate.current_date)
    date_edit.set_date_range(QDate.new(2005, 1, 1), QDate.new(2010, 12, 31))
    date_label.set_text tr(format('Appointment date (between %s and %s:', date_edit.minimum_date.to_string(Qt::ISODate),
                                  date_edit.maximum_date.to_string(Qt::ISODate)))

    time_label = QLabel.new
    time_edit = QTimeEdit.new(QTime.current_time)
    time_edit.set_time_range(QTime.new(9, 0, 0), QTime.new(16, 30, 0))
    time_label.set_text tr(format('Appointment time (between %s and %s:', time_edit.minimum_time.to_string(Qt::ISODate),
                                  time_edit.maximum_time.to_string(Qt::ISODate)))

    @metting_label = QLabel.new
    @meeting_edit = QDateTimeEdit.new(QDateTime.current_date_time)

    format_label = QLabel.new(tr('Format string for the meeting date and time:'))
    format_combobox = QComboBox.new
    format_combobox.add_item('yyyy-MM-dd hh:mm:ss (zzz ms)')
    format_combobox.add_item('hh:mm:ss MM/dd/yyyy')
    format_combobox.add_item('hh:mm:ss dd/MM/yyyy')
    format_combobox.add_item('hh:mm:ss')
    format_combobox.add_item('hh:mm ap')
    format_combobox.current_text_changed.connect(self, :set_format_string)
    set_format_string(format_combobox.current_text)

    edits_layout = QVBoxLayout.new
    edits_layout.add_widget(date_label)
    edits_layout.add_widget(date_edit)
    edits_layout.add_widget(time_label)
    edits_layout.add_widget(time_edit)
    edits_layout.add_widget(@metting_label)
    edits_layout.add_widget(@meeting_edit)
    edits_layout.add_widget(format_label)
    edits_layout.add_widget(format_combobox)
    @edits_group.set_layout(edits_layout)
  end

  def set_format_string(format_string)
    @meeting_edit.set_display_format format_string
    if (@meeting_edit.displayed_sections & QDateTimeEdit::DateSections_Mask).nonzero?
      @meeting_edit.set_date_range(QDate.new(2004, 11, 1), QDate.new(2005, 11, 30))
      @metting_label.set_text tr(format('Meeting date (between %s and %s:',
                                        @meeting_edit.minimum_date.to_string(Qt::ISODate), @meeting_edit.maximum_date.to_string(Qt::ISODate)))
    else
      @meeting_edit.set_time_range(QTime.new(0, 7, 20), QTime.new(21, 0, 0))
      @metting_label.set_text tr(format('Meeting time (between %s and %s:',
                                        @meeting_edit.minimum_time.to_string(Qt::ISODate), @meeting_edit.maximum_time.to_string(Qt::ISODate)))
    end
  end

  def create_double_spin_boxes
    @double_spin_boxes_group = QGroupBox.new(tr('Double precision spinboxes'))

    precision_label = QLabel.new(tr('Number of decimal places to show:'))
    precision_spin_box = QSpinBox.new
    precision_spin_box.set_range(0, 14)
    precision_spin_box.set_value(2)
    precision_spin_box.value_changed.connect(self, :change_precision)

    double_label = QLabel.new(tr(format('Enter a value between %d and %d:', -20, 20)))
    @double_spin_box = QDoubleSpinBox.new
    @double_spin_box.set_range(-20.0, 20.0)
    @double_spin_box.set_single_step(1.0)
    @double_spin_box.set_value(0.0)

    scale_label = QLabel.new(tr(format('Enter a scale factor between %2f and %2f:', 0.0, 1000.0)))
    @scale_spin_box = QDoubleSpinBox.new
    @scale_spin_box.set_range(0.0, 1000.0)
    @scale_spin_box.set_single_step(10.0)
    @scale_spin_box.set_suffix('%')
    @scale_spin_box.set_special_value_text(tr('No scaling'))
    @scale_spin_box.set_value(100.0)

    price_label = QLabel.new(tr(format('Enter a price between %2f and %2f:', 0.0, 1000.0)))
    @price_spin_box = QDoubleSpinBox.new
    @price_spin_box.set_range(0.0, 1000.0)
    @price_spin_box.set_single_step(1.0)
    @price_spin_box.set_prefix('$')
    @price_spin_box.set_value(99.99)

    spinbox_layout = QVBoxLayout.new
    spinbox_layout.add_widget(precision_label)
    spinbox_layout.add_widget(precision_spin_box)
    spinbox_layout.add_widget(double_label)
    spinbox_layout.add_widget(@double_spin_box)
    spinbox_layout.add_widget(scale_label)
    spinbox_layout.add_widget(@scale_spin_box)
    spinbox_layout.add_widget(price_label)
    spinbox_layout.add_widget(@price_spin_box)
    @double_spin_boxes_group.set_layout(spinbox_layout)
  end

  def change_precision(decimals)
    @double_spin_box.set_decimals decimals
    @scale_spin_box.set_decimals decimals
    @price_spin_box.set_decimals decimals
  end
end
