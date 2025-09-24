# frozen_string_literal: true

# @!visibility private
class ::String
  def to_qstr
    ::RubyQt6::T.to_qstr(self)
  end
end
