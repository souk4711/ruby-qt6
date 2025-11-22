# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebengineprofile.html
    class QWebEngineProfile < RubyQt6::QtCore::QObject
      # @!parse class HttpCacheType              ; end
      # @!parse class PersistentCookiesPolicy    ; end
      # @!parse class PersistentPermissionsPolicy; end
      rubyqt6_declare_enum_under QWebEngineProfile, QWebEngineProfile::HttpCacheType
      rubyqt6_declare_enum_under QWebEngineProfile, QWebEngineProfile::PersistentCookiesPolicy
      rubyqt6_declare_enum_under QWebEngineProfile, QWebEngineProfile::PersistentPermissionsPolicy, alias: false

      # @!parse
      q_object do
        signal "clearHttpCacheCompleted()"
        signal "downloadRequested(QWebEngineDownloadRequest*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param name [String, QString]
      # @param parent [QObject]
      # @return [QWebEngineProfile]
      def initialize(name, parent = nil)
        _initialize(T.to_qstr(name), parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def set_notification_presenter(presenter)
        _gc_incref(presenter)
        _set_notification_presenter(presenter)
      end
    end
  end
end
