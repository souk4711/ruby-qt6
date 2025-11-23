# frozen_string_literal: true

module RubyQt6
  module QtNetwork
    # @see https://doc.qt.io/qt-6/qnetworkproxyquery.html
    class QNetworkProxyQuery
      # @!parse class QueryType; end
      rubyqt6_declare_enum_under QNetworkProxyQuery, QNetworkProxyQuery::QueryType

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QNetworkProxyQuery]
      def initialize
        _initialize
      end
    end
  end
end
