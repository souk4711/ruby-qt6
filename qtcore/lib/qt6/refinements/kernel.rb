# frozen_string_literal: true

# @!visibility private
module ::Kernel
  def rubyqt6_declare_enum_under(mod, enum)
    enum.constants.each do |const|
      mod.const_set(const, enum.const_get(const))
    end
    enum.define_method(:inspect) do
      ::RubyQt6::T.q_inspect_enum(self, int: to_i)
    end
  end

  def rubyqt6_declare_qflags(flags, enum)
    enum.define_method(:to_qflags) do
      flags.new(self)
    end
    enum.define_method(:|) do |other|
      flags.new(self).set_flag(other)
    end

    flags.define_method(:inspect) do
      ::RubyQt6::T.q_inspect_enum(self, int: to_i)
    end
  end
end
