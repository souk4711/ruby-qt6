# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qiodevicebase.html
    class QIODeviceBase
      # @!parse class OpenModeFlag; end
      rubyqt6_declare_enum_under QIODeviceBase, QIODeviceBase::OpenModeFlag

      # @!parse class OpenMode; end
      rubyqt6_declare_qflags QIODeviceBase::OpenMode, QIODeviceBase::OpenModeFlag
    end
  end
end
