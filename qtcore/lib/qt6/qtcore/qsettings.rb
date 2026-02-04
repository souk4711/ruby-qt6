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
      # @return [QSettings]
      def initialize(organization, application)
        format = QSettings.default_format
        scope = QSettings::Scope::UserScope
        _initialize(format, scope, T.to_qstr(organization), T.to_qstr(application))
      end

      # @!visibility private
      def begin_group(prefix)
        _begin_group(T.to_qanystringview(prefix))
      end

      # @!visibility private
      def begin_read_array(prefix)
        _begin_read_array(T.to_qanystringview(prefix))
      end

      # @!visibility private
      def begin_write_array(prefix, size = -1)
        _begin_write_array(T.to_qanystringview(prefix), size)
      end

      # @!visibility private
      def contains(key)
        _contains(T.to_qanystringview(key))
      end

      # @!visibility private
      def remove(key)
        _remove(T.to_qanystringview(key))
      end

      # @!visibility private
      def set_value(key, value)
        qvariant = QVariant.new(value)
        _set_value(T.to_qanystringview(key), qvariant)
      end

      # @!visibility private
      def value(key, default = nil)
        qvariant = _value(T.to_qanystringview(key))
        return default unless qvariant.valid?

        case default
        when QStringList then QVariant.to_qstringlist(qvariant)
        else qvariant.value
        end
      end
    end
  end
end
