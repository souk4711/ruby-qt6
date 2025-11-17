# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginepermission.html
    class QWebEnginePermission
      # @!parse class PermissionType; end
      # @!parse class State         ; end
      rubyqt6_declare_enum_under QWebEnginePermission, QWebEnginePermission::PermissionType
      rubyqt6_declare_enum_under QWebEnginePermission, QWebEnginePermission::State
    end
  end
end
