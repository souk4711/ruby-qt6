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

  def size_hint
    _size_hint.tap do |size|
      size.set_height size.height + 20
      size.set_width size.width > size.height ? size.width : size.height
    end
  end
end
