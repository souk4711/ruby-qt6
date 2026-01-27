# frozen_string_literal: true

module RubyQt6
  module QtNetwork
    # @see https://doc.qt.io/qt-6/qnetworkrequest.html
    class QNetworkRequest
      # @!parse class Attribute              ; end
      # @!parse class CacheLoadControl       ; end
      # @!parse class KnownHeaders           ; end
      # @!parse class LoadControl            ; end
      # @!parse class Priority               ; end
      # @!parse class RedirectPolicy         ; end
      # @!parse class TransferTimeoutConstant; end
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::Attribute
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::CacheLoadControl
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::KnownHeaders
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::LoadControl
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::Priority
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::RedirectPolicy
      rubyqt6_declare_enum_under QNetworkRequest, QNetworkRequest::TransferTimeoutConstant

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QNetworkRequest]
      #
      # @overload initialize
      #
      # @overload initialize(url)
      #   @param url [QUrl]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
