# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpagedpaintdevice.html
    class QPagedPaintDevice < RubyQt6::QtGui::QPaintDevice
      # @!parse class PdfVersion; end
      rubyqt6_declare_enum_under QPagedPaintDevice, QPagedPaintDevice::PdfVersion
    end
  end
end
