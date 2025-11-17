# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginesettings.html
    class QWebEngineSettings
      # @!parse class FontFamily            ; end
      # @!parse class FontSize              ; end
      # @!parse class ImageAnimationPolicy  ; end
      # @!parse class UnknownUrlSchemePolicy; end
      # @!parse class WebAttribute          ; end
      rubyqt6_declare_enum_under QWebEngineSettings, QWebEngineSettings::FontFamily
      rubyqt6_declare_enum_under QWebEngineSettings, QWebEngineSettings::FontSize
      rubyqt6_declare_enum_under QWebEngineSettings, QWebEngineSettings::ImageAnimationPolicy
      rubyqt6_declare_enum_under QWebEngineSettings, QWebEngineSettings::UnknownUrlSchemePolicy
      rubyqt6_declare_enum_under QWebEngineSettings, QWebEngineSettings::WebAttribute
    end
  end
end
