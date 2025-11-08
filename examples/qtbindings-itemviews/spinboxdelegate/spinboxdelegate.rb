# frozen_string_literal: true

class SpinBoxDelegate < RubyQt6::Bando::QItemDelegate
  def initialize(parent = nil)
    super(parent)
  end

  def create_editor(parent, _option, _index)
    editor = QSpinBox.new(parent)
    editor.set_minimum 0
    editor.set_maximum 100
    editor.install_event_filter(self)
    editor
  end

  def set_editor_data(editor, index)
    value = index.model.data(index, Qt::DisplayRole).value
    @spinbox = editor
    @spinbox.set_value value
  end

  def set_model_data(editor, model, index)
    @spinbox = editor
    @spinbox.interpret_text
    value = @spinbox.value
    model.set_data(index, QVariant.new(value))
  end

  def update_editor_geometry(editor, option, _index)
    editor.set_geometry option.rect
  end
end
