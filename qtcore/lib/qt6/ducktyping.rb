# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.args_nth_to_qanystringview(args, index, *klass)
      args[index] = to_qanystringview(args[index]) if klass.include?(args[index].class)
    end

    def self.args_nth_to_qstr(args, index, *klass)
      args[index] = to_qstr(args[index]) if klass.include?(args[index].class)
    end

    def self.to_qanystringview(str)
      QtCore::QAnyStringView.new(str)
    end

    def self.to_qbytearray(str)
      QtCore::QByteArray.new(str)
    end

    def self.to_qstr(str)
      QtCore::QString.new(str)
    end

    def self.inspect_struct(object, **attributes)
      name = object.class.name.split("::").last + " "
      attributes = Array(attributes).map { |(name, value)| "#{name}=#{value.inspect}" }.join(", ")
      ["#<", name, attributes, ">"].join
    end

    def self.inspect_struct_enum(object, **attributes)
      name = object.class.name.split("::").last(2).join("::") + " "
      attributes = Array(attributes).map { |(name, value)| "#{name}=#{value.inspect}" }.join(", ")
      ["#<", name, attributes, ">"].join
    end
  end
end
