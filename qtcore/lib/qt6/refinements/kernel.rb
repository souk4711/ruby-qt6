# frozen_string_literal: true

# @!visibility private
module Kernel
  def rubyqt6_declare_enum_under(mod, enum)
    int2str = {}
    enum.constants.each do |name|
      const = enum.const_get(name)
      int2str[const.to_i] = name.to_s
      mod.const_set(name, const)
    end

    enum.define_method(:to_s) { int2str[to_i] || "" }
    enum.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i, str: to_s) }

    enum.include(Comparable)
    enum.define_method(:<=>) { |other| other.respond_to?(:to_i) ? to_i <=> other.to_i : nil }

    qmetatype = enum._qvariant_register_metatype
    RubyQt6::QtCore::QVariant.register(qmetatype, enum.method(:_qvariant_from_value), enum.method(:_qvariant_to_value), from: enum)
  end

  def rubyqt6_declare_qflags(flags, enum)
    enum.define_method(:to_qflags) { flags.new(self) }
    enum.define_method(:~) { ~flags.new(self) }
    enum.define_method(:&) { |other| flags.new(self) & other }
    enum.define_method(:^) { |other| flags.new(self) ^ other }
    enum.define_method(:|) { |other| flags.new(self) | other }

    flags.define_method(:to_qflags) { self }
    flags.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i) }

    flags.include(Comparable)
    flags.define_method(:<=>) { |other| other.respond_to?(:to_i) ? to_i <=> other.to_i : nil }
  end
end
