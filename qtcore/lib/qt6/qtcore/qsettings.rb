# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qsettings.html
    class QSettings < RubyQt6::QtCore::QObject
      # @!parse class Format; end
      # @!parse class Scope ; end
      # @!parse class Status; end
      rubyqt6_declare_enum_under QSettings, QSettings::Format
      rubyqt6_declare_enum_under QSettings, QSettings::Scope
      rubyqt6_declare_enum_under QSettings, QSettings::Status

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param organization [QString]
      # @param application [QString]
      # @param parent [QObject]
      # @return [QSettings]
      def initialize(organization, application, parent = nil)
        format = QtCore::QSettings.default_format
        scope = QtCore::QSettings::Scope::UserScope
        _initialize(format, scope, T.to_qstr(organization), T.to_qstr(application), parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_value(key, value)
        qmetatype = QtCore::QMetaType.from_klass(value.class)
        qvariant = QtCore::QVariant.from_object(value, qmetatype)
        _set_value(T.to_qanystringview(key), qvariant)
      end

      # @!visibility private
      def value(key, default = nil)
        qvariant = _value(T.to_qanystringview(key))
        qvariant.valid? ? QtCore::QVariant.to_object(qvariant) : default
      end
    end
  end
end
