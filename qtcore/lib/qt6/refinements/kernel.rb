# frozen_string_literal: true

# @!visibility private
module Kernel
  def rubyqt6_declare_enum_under(mod, enum)
    enum.constants.each { |const| mod.const_set(const, enum.const_get(const)) }
    enum.define_method(:inspect) { RubyQt6::T.q_inspect_enum(self, int: to_i) }
  end

  def rubyqt6_declare_qflags(flags, enum)
    enum.define_method(:to_qflags) { flags.new(self) }
    enum.define_method(:|) { |other| flags.new(self).set_flag(other) }

    flags.define_method(:to_qflags) { self }
    flags.define_method(:zero?) { to_i.zero? }
    flags.define_method(:nonzero?) { to_i.nonzero? }
    flags.define_method(:inspect) { RubyQt6::T.q_inspect_enum(self, int: to_i) }
  end
end
