# frozen_string_literal: true

# @!visibility private
module Kernel
  def rubyqt6_declare_enum_under(mod, enum)
    enum.constants.each { |const| mod.const_set(const, enum.const_get(const)) }
    enum.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i, str: to_s) }

    qmetatype = enum._qvariant_register_metatype
    RubyQt6::QtCore::QVariant.register(qmetatype, enum.method(:_qvariant_from_value), enum.method(:_qvariant_to_value), from: enum)
  end

  def rubyqt6_declare_qflags(flags, enum)
    enum.define_method(:to_qflags) { flags.new(self) }
    enum.define_method(:&) { |other| flags.new(self) & other }
    enum.define_method(:^) { |other| flags.new(self) ^ other }
    enum.define_method(:|) { |other| flags.new(self) | other }
    enum.define_method(:~) { ~flags.new(self) }

    flags.define_method(:to_qflags) { self }
    flags.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i) }
  end
end
