# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginenewwindowrequest.html
    class QWebEngineNewWindowRequest < RubyQt6::QtCore::QObject
      # @!parse class DestinationType; end
      rubyqt6_declare_enum_under QWebEngineNewWindowRequest, QWebEngineNewWindowRequest::DestinationType

      # @!parse
      q_object do
      end
    end
  end
end
