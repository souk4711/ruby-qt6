# frozen_string_literal: true

class ImageDelegate < RubyQt6::Bando::QItemDelegate
  q_object do
    slot 'emit_commit_data()'
  end

  def initialize(parent = nil)
    super(parent)
  end

  def create_editor(parent, _option, index)
    combo_box = QComboBox.new(parent)
    if index.column == 1
      combo_box.add_item(tr('Normal'))
      combo_box.add_item(tr('Active'))
      combo_box.add_item(tr('Disabled'))
    elsif index.column == 2
      combo_box.add_item(tr('Off'))
      combo_box.add_item(tr('On'))
    end

    combo_box.activated.connect(self, :emit_commit_data)
    combo_box
  end

  def set_editor_data(editor, index)
    combo_box = editor
    return if combo_box.nil?

    pos = combo_box.find_text(index.model.data(index).value)
    combo_box.set_current_index pos
  end

  def set_model_data(editor, model, index)
    combo_box = editor
    return if combo_box.nil?

    model.set_data(index, QVariant.new(combo_box.current_text), Qt::EditRole)
  end

  def emit_commit_data
    commit_data.emit(sender)
  end
end
