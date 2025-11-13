# frozen_string_literal: true

class DetailsDialog < RubyQt6::Bando::QDialog
  q_object do
    slot 'verify()'
  end

  def initialize(title, parent = nil)
    super(parent)

    @order_items = []
    @items = []
    name_label = QLabel.new(tr('Name:'))
    address_label = QLabel.new(tr('Address:'))

    @name_edit = QLineEdit.new
    @address_edit = QTextEdit.new
    @address_edit.set_plain_text ''
    @offers_checkbox = QCheckBox.new(tr('Send offers:'))

    setup_items_table

    ok_button = QPushButton.new(tr('OK'))
    cancel_button = QPushButton.new(tr('Cancel'))
    ok_button.set_default true

    ok_button.clicked.connect(self, :verify)
    cancel_button.clicked.connect(self, :reject)

    details_layout = QGridLayout.new.tap do |d|
      d.add_widget(name_label, 0, 0)
      d.add_widget(@name_edit, 0, 1)
      d.add_widget(address_label, 1, 0)
      d.add_widget(@address_edit, 1, 1)
      d.add_widget(@items_table, 0, 2, 2, 2)
      d.add_widget(@offers_checkbox, 2, 1, 1, 4)
    end

    button_layout = QHBoxLayout.new.tap do |b|
      b.add_stretch(1)
      b.add_widget(ok_button)
      b.add_widget(cancel_button)
    end

    layout = QVBoxLayout.new.tap do |m|
      m.add_layout(details_layout)
      m.add_layout(button_layout)
    end
    set_layout(layout)

    set_window_title(title)
  end

  def setup_items_table
    @items << tr('T-shirt') << tr('Badge') << tr('Reference book') << tr('Coffee cup')
    @items_table = QTableWidget.new(@items.length, 2)

    (0...@items.length).each do |row|
      name = QTableWidgetItem.new(@items[row])
      name.set_flags Qt::ItemIsEnabled | Qt::ItemIsSelectable
      @items_table.set_item(row, 0, name)
      quantity = QTableWidgetItem.new('1')
      @items_table.set_item(row, 1, quantity)
    end
  end

  def order_items
    order_list = []
    (0...@items.length).each do |row|
      item = Array.new(2)
      item[0] = @items_table.item(row, 0).text
      quantity = @items_table.item(row, 1).data(Qt::DisplayRole).value.to_s.to_i
      item[1] = [0, quantity].max
      order_list.push(item)
    end
    order_list
  end

  def sender_name
    @name_edit.text
  end

  def sender_address
    @address_edit.to_plain_text
  end

  def send_offers
    @offers_checkbox.checked?
  end

  def verify
    if !@name_edit.text.empty? && !@address_edit.to_plain_text.empty?
      accept
      return
    end

    answer = QMessageBox.warning(self, tr('Incomplete Form'),
                                 tr("The form does not contain all the necessary information.\nDo you want to discard it?"), QMessageBox::Yes, QMessageBox::No)
    return unless answer == QMessageBox::Yes

    reject
  end
end
