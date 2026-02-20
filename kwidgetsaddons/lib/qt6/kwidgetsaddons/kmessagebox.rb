# frozen_string_literal: true

module RubyQt6
  module KWidgetsAddons
    # @see https://api.kde.org/kmessagebox.html
    module KMessageBox
      # @!parse class ButtonCode; end
      # @!parse class DialogType; end
      # @!parse class Option    ; end
      # @!parse class Options   ; end
      rubyqt6_declare_enum_under KMessageBox, KMessageBox::ButtonCode
      rubyqt6_declare_enum_under KMessageBox, KMessageBox::DialogType
      rubyqt6_declare_enum_under KMessageBox, KMessageBox::Option
      rubyqt6_declare_qflags KMessageBox::Options, KMessageBox::Option
    end
  end
end
