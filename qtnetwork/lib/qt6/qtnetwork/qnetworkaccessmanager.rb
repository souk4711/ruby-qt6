# frozen_string_literal: true

module RubyQt6
  module QtNetwork
    # @see https://doc.qt.io/qt-6/qnetworkaccessmanager.html
    class QNetworkAccessManager < RubyQt6::QtCore::QObject
      # @!parse class Operation; end
      rubyqt6_declare_enum_under QNetworkAccessManager, QNetworkAccessManager::Operation

      # @!parse
      q_object do
        signal "authenticationRequired(QNetworkReply*,QAuthenticator*)"
        signal "encrypted(QNetworkReply*)"
        signal "finished(QNetworkReply*)"
        signal "preSharedKeyAuthenticationRequired(QNetworkReply*,QSslPreSharedKeyAuthenticator*)"
        signal "proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)"
        signal "sslErrors(QNetworkReply*,QList<QSslError>)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QNetworkAccessManager]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
