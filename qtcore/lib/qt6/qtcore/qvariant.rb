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
        T.inspect_struct(self, type: type_name, value:)
      end

      private

      # @!visibility private
      def self.to_qobject(qvariant)
        T.bando_qobject_cast(_to_qobject(qvariant))
      end
      private_class_method :to_qobject

      # @!parse
      register(QMetaType::Type::Bool, method(:from_bool), method(:to_bool), from: [TrueClass, FalseClass])
      register(QMetaType::Type::Int, method(:from_int), method(:to_int), from: Integer)
      register(QMetaType::Type::Double, method(:from_double), method(:to_double), from: Float)
      register(QMetaType::Type::QString, method(:from_qstring), method(:to_qstring), from: [String, QString])
      register(QMetaType::Type::QByteArray, method(:from_qbytearray), method(:to_qbytearray), from: QByteArray)
      register(QMetaType::Type::QDateTime, method(:from_qdatetime), method(:to_qdatetime), from: QDateTime)
      register(QMetaType::Type::QDate, method(:from_qdate), method(:to_qdate), from: QDate)
      register(QMetaType::Type::QTime, method(:from_qtime), method(:to_qtime), from: QTime)
      register(QMetaType::Type::QLine, method(:from_qline), method(:to_qline), from: QLine)
      register(QMetaType::Type::QLineF, method(:from_qlinef), method(:to_qlinef), from: QLineF)
      register(QMetaType::Type::QPoint, method(:from_qpoint), method(:to_qpoint), from: QPoint)
      register(QMetaType::Type::QPointF, method(:from_qpointf), method(:to_qpointf), from: QPointF)
      register(QMetaType::Type::QRect, method(:from_qrect), method(:to_qrect), from: QRect)
      register(QMetaType::Type::QRectF, method(:from_qrectf), method(:to_qrectf), from: QRectF)
      register(QMetaType::Type::QSize, method(:from_qsize), method(:to_qsize), from: QSize)
      register(QMetaType::Type::QSizeF, method(:from_qsizef), method(:to_qsizef), from: QSizeF)
      register(QMetaType::Type::QStringList, method(:from_qstringlist), method(:to_qstringlist), from: QStringList)
      register(QMetaType::Type::QObjectStar, method(:from_qobject), method(:to_qobject), from: QObject)
    end
  end
end
