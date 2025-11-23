# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.args_nth_delete_qobject(args, index)
      return unless args[index].is_a?(QtCore::QObject)
      args.delete_at(index)
    end

    def self.args_nth_delete_qwidget(args, index)
      return unless args[index].is_a?(QtWidgets::QWidget)
      args.delete_at(index)
    end

    def self.args_nth_delete_qgraphicsitem(args, index)
      return unless args[index].is_a?(QtWidgets::QGraphicsItem)
      args.delete_at(index)
    end

    def self.args_nth_to_qanystringview(args, index)
      return unless args[index].is_a?(String) || args[index].is_a?(QtCore::QString)
      args[index] = QtCore::QAnyStringView.new(args[index])
    end

    def self.args_nth_to_qstr(args, index)
      return unless args[index].is_a?(String)
      args[index] = QtCore::QString.new(args[index])
    end

    def self.to_qanystringview(str)
      return str unless str.is_a?(String) || str.is_a?(QtCore::QString)
      QtCore::QAnyStringView.new(str)
    end

    def self.to_qbytearray(str)
      return str unless str.is_a?(String)
      QtCore::QByteArray.new(str)
    end

    def self.to_qstr(str)
      return str unless str.is_a?(String)
      QtCore::QString.new(str)
    end

    def self.to_qkeysequence(key)
      return key unless key.is_a?(String) || key.is_a?(QtCore::QString) || key.is_a?(Integer) || key_is_a?(QtGui::QKeySequence::StandardKey)
      QtGui::QKeySequence.new(key)
    end

    def self.to_qvariantlist(array)
      array.each_with_object(QtCore::QVariantList.new) { |e, memo| memo << QtCore::QVariant.new(e) }
    end

    def self.to_qvariantmap(hash)
      hash.each_with_object(QtCore::QVariantMap.new) { |(k, v), memo| memo[k.to_qstr] = QtCore::QVariant.new(v) }
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
