# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qfiledevice.html
    class QFileDevice < RubyQt6::QtCore::QIODevice
      # @!parse class FileError     ; end
      # @!parse class FileHandleFlag; end
      # @!parse class FileTime      ; end
      # @!parse class MemoryMapFlag ; end
      # @!parse class Permission    ; end
      rubyqt6_declare_enum_under QFileDevice, QFileDevice::FileError
      rubyqt6_declare_enum_under QFileDevice, QFileDevice::FileHandleFlag
      rubyqt6_declare_enum_under QFileDevice, QFileDevice::FileTime
      rubyqt6_declare_enum_under QFileDevice, QFileDevice::MemoryMapFlag
      rubyqt6_declare_enum_under QFileDevice, QFileDevice::Permission

      # @!parse class FileHandleFlags; end
      # @!parse class MemoryMapFlags ; end
      # @!parse class Permissions    ; end
      rubyqt6_declare_qflags QFileDevice::FileHandleFlags, QFileDevice::FileHandleFlag
      rubyqt6_declare_qflags QFileDevice::MemoryMapFlags, QFileDevice::MemoryMapFlag
      rubyqt6_declare_qflags QFileDevice::Permissions, QFileDevice::Permission

      # @!parse
      q_object do
      end
    end
  end
end
