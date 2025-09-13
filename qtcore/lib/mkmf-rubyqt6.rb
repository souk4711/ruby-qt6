# frozen_string_literal: true

QT6_INCLUDEDIR = [
  "/opt/local/include/qt6",
  "/usr/local/include/qt6",
  "/usr/include/qt6"
]

def find_qt6_includedir
  QT6_INCLUDEDIR.find do |path|
    find_header("QtCore/QtCore", path)
  end.to_s
end
