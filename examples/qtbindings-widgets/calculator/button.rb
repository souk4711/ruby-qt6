# frozen_string_literal: true

class CalcButton < RubyQt6::Bando::QToolButton
  def initialize(text, _color, parent = nil)
    super(parent)

    set_size_policy(QSizePolicy::Expanding, QSizePolicy::Preferred)
    set_text(text)

    new_palette = palette
    new_palette.set_color(QPalette::Button, palette.color(QPalette::Button))
    set_palette(new_palette)
  end
end
