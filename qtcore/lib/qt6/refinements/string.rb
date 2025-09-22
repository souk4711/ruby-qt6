# frozen_string_literal: true

# @!visibility private
class ::String
  def to_qstr
    ::RubyQt6::QtCore::QString.new(self)
  end
end
