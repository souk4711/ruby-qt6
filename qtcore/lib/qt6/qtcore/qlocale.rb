# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qlocale.html
    class QLocale
      # @!parse class Language                    ; end
      # @!parse class Script                      ; end
      # @!parse class Country                     ; end
      # @!parse class MeasurementSystem           ; end
      # @!parse class FormatType                  ; end
      # @!parse class NumberOption                ; end
      # @!parse class FloatingPointPrecisionOption; end
      # @!parse class TagSeparator                ; end
      # @!parse class CurrencySymbolFormat        ; end
      # @!parse class DataSizeFormat              ; end
      # @!parse class LanguageCodeType            ; end
      # @!parse class QuotationStyle              ; end
      rubyqt6_include_constants QLocale, QLocale::Language
      rubyqt6_include_constants QLocale, QLocale::Script
      rubyqt6_include_constants QLocale, QLocale::Country
      rubyqt6_include_constants QLocale, QLocale::MeasurementSystem
      rubyqt6_include_constants QLocale, QLocale::FormatType
      rubyqt6_include_constants QLocale, QLocale::NumberOption
      rubyqt6_include_constants QLocale, QLocale::FloatingPointPrecisionOption
      rubyqt6_include_constants QLocale, QLocale::TagSeparator
      rubyqt6_include_constants QLocale, QLocale::CurrencySymbolFormat
      rubyqt6_include_constants QLocale, QLocale::DataSizeFormat
      rubyqt6_include_constants QLocale, QLocale::LanguageCodeType
      rubyqt6_include_constants QLocale, QLocale::QuotationStyle
    end
  end
end
