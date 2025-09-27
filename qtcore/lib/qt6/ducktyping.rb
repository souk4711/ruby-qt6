# frozen_string_literal: true

module RubyQt6
  # @!visibility private
  module T
    def self.to_qanystringview(str)
      QtCore::QAnyStringView.new(str)
    end

    def self.to_qbytearray(str)
      QtCore::QByteArray.new(str)
    end

    def self.to_qstr(str)
      QtCore::QString.new(str)
    end

    def self.q_inspect(object, **attributes)
      name = object.class.name.split("::").last + " "
      attributes = Array(attributes).map { |(name, value)| "#{name}=#{value.inspect}" }.join(", ")
      ["#<", name, attributes, ">"].join
    end
  end
end
