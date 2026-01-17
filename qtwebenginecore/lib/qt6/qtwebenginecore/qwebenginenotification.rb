# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginenotification.html
    class QWebEngineNotification < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "closed()"
        slot "click()"
        slot "close()"
        slot "show()"
      end
    end

    rubyqt6_declare_std_unique_ptr(
      ::Rice4RubyQt6::Std::UniquePtr≺QWebEngineNotification≻, delegators: [:closed]
    )
  end
end
