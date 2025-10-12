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
      # @!parse class NumberOptions               ; end
      # @!parse class FloatingPointPrecisionOption; end
      # @!parse class TagSeparator                ; end
      # @!parse class CurrencySymbolFormat        ; end
      # @!parse class DataSizeFormat              ; end
      # @!parse class DataSizeFormats             ; end
      # @!parse class LanguageCodeType            ; end
      # @!parse class LanguageCodeTypes           ; end
      # @!parse class QuotationStyle              ; end
      rubyqt6_declare_enum_under QLocale, QLocale::Language
      rubyqt6_declare_enum_under QLocale, QLocale::Script
      rubyqt6_declare_enum_under QLocale, QLocale::Country
      rubyqt6_declare_enum_under QLocale, QLocale::MeasurementSystem
      rubyqt6_declare_enum_under QLocale, QLocale::FormatType
      rubyqt6_declare_enum_under QLocale, QLocale::NumberOption
      rubyqt6_declare_enum_under QLocale, QLocale::FloatingPointPrecisionOption
      rubyqt6_declare_enum_under QLocale, QLocale::TagSeparator
      rubyqt6_declare_enum_under QLocale, QLocale::CurrencySymbolFormat
      rubyqt6_declare_enum_under QLocale, QLocale::DataSizeFormat
      rubyqt6_declare_enum_under QLocale, QLocale::LanguageCodeType
      rubyqt6_declare_enum_under QLocale, QLocale::QuotationStyle
      rubyqt6_declare_qflags QLocale::NumberOptions, QLocale::NumberOption
      rubyqt6_declare_qflags QLocale::DataSizeFormats, QLocale::DataSizeFormat
      rubyqt6_declare_qflags QLocale::LanguageCodeTypes, QLocale::LanguageCodeType

      # @!visibility private
      def inspect
        T.q_inspect(self, name: name.to_s)
      end
    end
  end
end
