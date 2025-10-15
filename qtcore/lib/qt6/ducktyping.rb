# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.args_nth_delete_qobject(args, index)
      return unless [QtCore::QObject].include?(args[index].class)
      args.delete_at(index)
    end

    def self.args_nth_to_qanystringview_checked(args, index)
      return unless [String, QtCore::QString].include?(args[index].class)
      args[index] = to_qanystringview(args[index])
    end

    def self.args_nth_to_qstr_checked(args, index)
      return unless [String].include?(args[index].class)
      args[index] = to_qstr(args[index])
    end

    def self.to_qanystringview(str)
      QtCore::QAnyStringView.new(str)
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
