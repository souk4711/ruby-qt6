# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginenavigationrequest.html
    class QWebEngineNavigationRequest < RubyQt6::QtCore::QObject
      # @!parse class NavigationRequestAction; end
      # @!parse class NavigationType         ; end
      rubyqt6_declare_enum_under QWebEngineNavigationRequest, QWebEngineNavigationRequest::NavigationRequestAction
      rubyqt6_declare_enum_under QWebEngineNavigationRequest, QWebEngineNavigationRequest::NavigationType

      # @!parse
      q_object do
      end
    end
  end
end
