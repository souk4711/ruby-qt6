# frozen_string_literal: true

# @!visibility private
module Kernel
  def rubyqt6_declare_enum_under(mod, enum, **options)
    int2str = {}
    enum.constants.each do |name|
      const = enum.const_get(name)
      int2str[const.to_i] = name.to_s
      mod.const_set(name, const) if options.fetch(:alias, true)
    end

    enum.define_method(:to_s) { int2str[to_i] || "" }
    enum.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i, str: to_s) }

    enum.include(Comparable)
    enum.define_method(:to_int) { to_i }
    enum.define_method(:<=>) { |other| other.respond_to?(:to_int) ? to_int <=> other.to_int : nil }

    qmetatype_id = enum._qvariant_register_metatype
    RubyQt6::QtCore::QVariant.register(
      qmetatype_id,
      ->(value) { QVariant.from_int(value.to_int).tap { |qvariant| qvariant.convert(QMetaType.new(qmetatype_id)) } },
      ->(qvariant) { enum.from_int(QVariant.to_int(qvariant)) },
      from: enum
    )
  end

  def rubyqt6_declare_qflags(flags, enum)
    enum.define_method(:to_qflags) { flags.new(self) }
    enum.define_method(:~) { ~flags.new(self) }
    enum.define_method(:&) { |other| flags.new(self) & other }
    enum.define_method(:^) { |other| flags.new(self) ^ other }
    enum.define_method(:|) { |other| flags.new(self) | other }

    flags.define_singleton_method(:new) { |value = 0| flags.from_int(value.to_i) }
    flags.define_method(:inspect) { RubyQt6::T.inspect_struct_enum(self, int: to_i) }

    flags.include(Comparable)
    flags.define_method(:to_int) { to_i }
    flags.define_method(:<=>) { |other| other.respond_to?(:to_int) ? to_int <=> other.to_int : nil }

    flags.define_method(:to_qflags) { self }
    flags.define_method(:~) { flags.from_int(~to_i) }
    flags.define_method(:&) { |other| flags.from_int(to_i & other.to_i) }
    flags.define_method(:^) { |other| flags.from_int(to_i ^ other.to_i) }
    flags.define_method(:|) { |other| flags.from_int(to_i | other.to_i) }
  end

  def rubyqt6_declare_std_unique_ptr(ptr, **options)
    ptr.instance_exec do
      def_delegators :get, *options[:delegators]
    end
  end
end
