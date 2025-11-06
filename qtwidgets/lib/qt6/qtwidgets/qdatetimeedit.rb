# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdatetimeedit.html
    class QDateTimeEdit < RubyQt6::QtWidgets::QAbstractSpinBox
      # @!parse class Section ; end
      # @!parse class Sections; end
      rubyqt6_declare_enum_under QDateTimeEdit, QDateTimeEdit::Section
      rubyqt6_declare_qflags QDateTimeEdit::Sections, QDateTimeEdit::Section

      # @!parse
      q_object do
        signal "dateChanged(QDate)"
        signal "dateTimeChanged(QDateTime)"
        signal "timeChanged(QTime)"
        slot "setDate(QDate)"
        slot "setDateTime(QDateTime)"
        slot "setTime(QTime)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param datetime [QDateTime]
      # @param parent [QWidget]
      # @return [QDateTimeEdit]
      def initialize(datetime, parent = nil)
        _initialize(datetime, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
