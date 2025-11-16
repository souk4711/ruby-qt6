# frozen_string_literal: true

# @!visibility private
class Symbol
  def to_qstr
    RubyQt6::T.to_qstr(to_s)
  end
end
