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
      return str if str.is_a?(QAnyStringView)
      return QAnyStringView.new(str) if str.is_a?(String) || str.is_a?(QString)
      raise ArgumentError, "Expected type QAnyStringView, but got #{str.class}"
    end

    def self.to_qbytearray(str)
      return str if str.is_a?(QByteArray)
      return QByteArray.new(str) if str.is_a?(String)
      raise ArgumentError, "Expected type QByteArray, but got #{str.class}"
    end

    def self.to_qstr(str)
      return str if str.is_a?(QString)
      return QString.new(str) if str.is_a?(String)
      raise ArgumentError, "Expected type QString, but got #{str.class}"
    end

    def self.to_qkeysequence(key)
      return key if key.is_a?(QKeySequence)
      return QKeySequence.new(key) if key.is_a?(String) || key.is_a?(QString) || key.is_a?(Integer) || key.is_a?(QKeySequence::StandardKey)
      raise ArgumentError, "Expected type QKeySequence, but got #{key.class}"
    end

    def self.to_qurl(url)
      return url if url.is_a?(QUrl)
      return QUrl.new(url) if url.is_a?(String) || url.is_a?(QString)
      raise ArgumentError, "Expected type QUrl, but got #{url.class}"
    end

    def self.to_qvariantlist(array)
      array.each_with_object(QVariantList.new) { |e, memo| memo << QVariant.new(e) }
    end

    def self.to_qvariantmap(hash)
      hash.each_with_object(QVariantMap.new) { |(k, v), memo| memo[k.to_qstr] = QVariant.new(v) }
    end

    def self.to_qflags(enum_or_flags)
      enum_or_flags.to_qflags
    end

    def self.bando_qobject_cast(object)
      b = object.class.name.start_with?("RubyQt6::Bando::")
      b ? object._ruby_value : object
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
