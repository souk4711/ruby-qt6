# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      def self.new(object, qmetatype = nil)
        return object if object.is_a?(self)
        from_object(object, qmetatype)
      end

      # @!visibility private
      def value
        self.class.__send__(:to_object, self)
      end

      # @!visibility private
      def inspect
        str = value.to_s
        T.inspect_struct(self, type: type_name, str:)
      rescue => e
        T.inspect_struct(self, type: type_name, str: e)
      end

      private

      # @!visibility private
      def self.to_qobject(qvariant)
        T.bando_qobject_cast(_to_qobject(qvariant))
      end
      private_class_method :to_qobject

      # @!parse
      register(QtCore::QMetaType::Type::Bool, method(:from_bool), method(:to_bool), from: [TrueClass, FalseClass])
      register(QtCore::QMetaType::Type::Int, method(:from_int), method(:to_int), from: Integer)
      register(QtCore::QMetaType::Type::Double, method(:from_double), method(:to_double), from: Float)
      register(QtCore::QMetaType::Type::QString, method(:from_qstring), method(:to_qstring), from: [String, QtCore::QString])
      register(QtCore::QMetaType::Type::QDateTime, method(:from_qdatetime), method(:to_qdatetime), from: QtCore::QDateTime)
      register(QtCore::QMetaType::Type::QDate, method(:from_qdate), method(:to_qdate), from: QtCore::QDate)
      register(QtCore::QMetaType::Type::QTime, method(:from_qtime), method(:to_qtime), from: QtCore::QTime)
      register(QtCore::QMetaType::Type::QLine, method(:from_qline), method(:to_qline), from: QtCore::QLine)
      register(QtCore::QMetaType::Type::QLineF, method(:from_qlinef), method(:to_qlinef), from: QtCore::QLineF)
      register(QtCore::QMetaType::Type::QPoint, method(:from_qpoint), method(:to_qpoint), from: QtCore::QPoint)
      register(QtCore::QMetaType::Type::QPointF, method(:from_qpointf), method(:to_qpointf), from: QtCore::QPointF)
      register(QtCore::QMetaType::Type::QRect, method(:from_qrect), method(:to_qrect), from: QtCore::QRect)
      register(QtCore::QMetaType::Type::QRectF, method(:from_qrectf), method(:to_qrectf), from: QtCore::QRectF)
      register(QtCore::QMetaType::Type::QSize, method(:from_qsize), method(:to_qsize), from: QtCore::QSize)
      register(QtCore::QMetaType::Type::QSizeF, method(:from_qsizef), method(:to_qsizef), from: QtCore::QSizeF)
      register(QtCore::QMetaType::Type::QStringList, method(:from_qstringlist), method(:to_qstringlist), from: QtCore::QStringList)
      register(QtCore::QMetaType::Type::QObjectStar, method(:from_qobject), method(:to_qobject), from: QtCore::QObject)
    end
  end
end
