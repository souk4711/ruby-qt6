# frozen_string_literal: true

module RubyQt6
  module QtNetwork
    # @see https://doc.qt.io/qt-6/qnetworkreply.html
    class QNetworkReply < RubyQt6::QtCore::QIODevice
      # @!parse class NetworkError; end
      rubyqt6_declare_enum_under QNetworkReply, QNetworkReply::NetworkError

      # @!parse
      QtCore::QVariant.register(
        _qvariant_register_metatype,
        method(:_qvariant_from_value),
        method(:_qvariant_to_value),
        from: self
      )

      # @!parse
      q_object do
        signal "downloadProgress(qlonglong,qlonglong)"
        signal "encrypted()"
        signal "errorOccurred(QNetworkReply::NetworkError)"
        signal "finished()"
        signal "metaDataChanged()"
        signal "preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator*)"
        signal "redirectAllowed()"
        signal "redirected(QUrl)"
        signal "requestSent()"
        signal "socketStartedConnecting()"
        signal "sslErrors(QList<QSslError>)"
        signal "uploadProgress(qlonglong,qlonglong)"
        slot "abort()"
        slot "ignoreSslErrors()"
      end
    end
  end
end
