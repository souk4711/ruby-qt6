# frozen_string_literal: true

require "qt6/qtcore"

require_relative "qtnetwork/version"
require_relative "qtnetwork/qtnetwork"
require_relative "qtnetwork/qtnetworkversion"

require_relative "qtnetwork/qnetworkproxy"
require_relative "qtnetwork/qnetworkproxyquery"
require_relative "qtnetwork/qnetworkproxyfactory"
require_relative "qtnetwork/qnetworkrequest"

require_relative "qtnetwork/qnetworkaccessmanager"
require_relative "qtnetwork/qnetworkreply"

RubyQt6.initialize!(RubyQt6::QtNetwork)
