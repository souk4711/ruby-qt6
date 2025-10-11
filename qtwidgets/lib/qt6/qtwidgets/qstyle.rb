# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstyle.html
    class QStyle < RubyQt6::QtCore::QObject
      # @!parse class StateFlag                ; end
      # @!parse class PrimitiveElement         ; end
      # @!parse class ControlElement           ; end
      # @!parse class SubElement               ; end
      # @!parse class ComplexControl           ; end
      # @!parse class SubControl               ; end
      # @!parse class PixelMetric              ; end
      # @!parse class ContentsType             ; end
      # @!parse class RequestSoftwareInputPanel; end
      # @!parse class StyleHint                ; end
      # @!parse class StandardPixmap           ; end
      rubyqt6_declare_enum_under QStyle, QStyle::StateFlag
      rubyqt6_declare_enum_under QStyle, QStyle::PrimitiveElement
      rubyqt6_declare_enum_under QStyle, QStyle::ControlElement
      rubyqt6_declare_enum_under QStyle, QStyle::SubElement
      rubyqt6_declare_enum_under QStyle, QStyle::ComplexControl
      rubyqt6_declare_enum_under QStyle, QStyle::SubControl
      rubyqt6_declare_enum_under QStyle, QStyle::PixelMetric
      rubyqt6_declare_enum_under QStyle, QStyle::ContentsType
      rubyqt6_declare_enum_under QStyle, QStyle::RequestSoftwareInputPanel
      rubyqt6_declare_enum_under QStyle, QStyle::StyleHint
      rubyqt6_declare_enum_under QStyle, QStyle::StandardPixmap

      # @!parse
      q_object do
      end
    end
  end
end
