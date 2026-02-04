# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.args_nth_delete_qobject(args, index)
      return unless args[index].is_a?(QObject)
      args.delete_at(index)
    end

    def self.args_nth_delete_qwidget(args, index)
      return unless args[index].is_a?(QWidget)
      args.delete_at(index)
    end

    def self.args_nth_delete_qgraphicsitem(args, index)
      return unless args[index].is_a?(QGraphicsItem)
      args.delete_at(index)
    end

    def self.args_nth_to_qanystringview(args, index)
      return unless args[index].is_a?(String) || args[index].is_a?(QString)
      args[index] = QAnyStringView.new(args[index])
    end

    def self.args_nth_to_qstr(args, index)
      return unless args[index].is_a?(String)
      args[index] = QString.new(args[index])
    end

    def self.to_qanystringview(str)
      return str unless str.is_a?(String) || str.is_a?(QString)
      QAnyStringView.new(str)
    end

    def self.to_qbytearray(str)
      return str unless str.is_a?(String)
      QByteArray.new(str)
    end

    def self.to_qstr(str)
      return str unless str.is_a?(String)
      QString.new(str)
    end

    def self.to_qkeysequence(key)
      return key unless key.is_a?(String) || key.is_a?(QString) || key.is_a?(Integer) || key.is_a?(QKeySequence::StandardKey)
      QKeySequence.new(key)
    end

    def self.to_qvariantlist(array)
      array.each_with_object(QVariantList.new) { |e, memo| memo << QVariant.new(e) }
    end

    def self.to_qvariantmap(hash)
      hash.each_with_object(QVariantMap.new) { |(k, v), memo| memo[k.to_qstr] = QVariant.new(v) }
    end

    def self.to_qflags(enum_or_flags)
      return enum_or_flags unless enum_or_flags.respond_to?(:to_qflags)
      enum_or_flags.to_qflags
    end

    def self.bando_qobject_cast(object)
      return object unless object.class.name.start_with?("RubyQt6::Bando::")
      object._ruby_value
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
