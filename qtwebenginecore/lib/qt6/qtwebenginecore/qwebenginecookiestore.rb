# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginecookiestore.html
    class QWebEngineCookieStore < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "cookieAdded(QNetworkCookie)"
        signal "cookieRemoved(QNetworkCookie)"
      end
    end
  end
end
