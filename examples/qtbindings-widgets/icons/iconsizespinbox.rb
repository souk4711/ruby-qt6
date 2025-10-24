# frozen_string_literal: true

class IconSizeSpinBox < RubyQt6::Bando::QSpinBox
  def initialize(parent = nil)
    super(parent)
  end

  def value_from_text(text)
    /(\\d+)(\\s*[xx]\\s*\\d+)?/.match(text)[1].to_i
  end

  def text_from_value(value)
    tr(format('%d x %d', value, value))
  end
end
