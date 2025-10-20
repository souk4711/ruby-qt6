# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qvariant.html
    class QVariant
      # @!visibility private
      def self.from_object_methods
        @from_object_methods ||= {}
      end

      # @!visibility private
      def self.from_object(o, qmetatype)
        meth = from_object_methods[qmetatype.id]
        meth ? meth.call(o) : raise("Unsupported qmetatype '#{qmetatype.name}'")
      end

      # @!visibility private
      def self.to_object_methods
        @to_object_methods ||= {}
      end

      # @!visibility private
      def self.to_object(v)
        meth = to_object_methods[v.type_id]
        meth ? meth.call(v) : raise("Unsupported qmetatype '#{v.type_name}'")
      end

      # @!visibility private
      def self.register(id, from_object_method, to_object_method, from: [])
        id = id.to_i
        raise "QVariant with id already registered: #{id}" if from_object_methods.key?(id)

        from_object_methods[id] = from_object_method
        to_object_methods[id] = to_object_method

        qmetatype = QtCore::QMetaType.new(id)
        Array(from).each do |klass|
          klass.define_singleton_method(:default_qmetatype) do
            qmetatype
          end
        end
      end

      # @!visibility private
      def self.to_qobject(qvariant)
        T.bando_qobject_cast(_to_qobject(qvariant))
      end

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
      register(QtCore::QMetaType::Type::QObjectStar, method(:from_qobject), method(:to_qobject))
    end
  end
end
