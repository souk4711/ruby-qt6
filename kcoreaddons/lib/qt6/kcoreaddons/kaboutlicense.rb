# frozen_string_literal: true

module RubyQt6
  module KCoreAddons
    # @see https://api.kde.org/kaboutlicense.html
    class KAboutLicense
      # @!parse class LicenseKey        ; end
      # @!parse class NameFormat        ; end
      # @!parse class VersionRestriction; end
      rubyqt6_declare_enum_under KAboutLicense, KAboutLicense::LicenseKey
      rubyqt6_declare_enum_under KAboutLicense, KAboutLicense::NameFormat
      rubyqt6_declare_enum_under KAboutLicense, KAboutLicense::VersionRestriction

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [KAboutLicense]
      def initialize
        _initialize
      end
    end
  end
end
