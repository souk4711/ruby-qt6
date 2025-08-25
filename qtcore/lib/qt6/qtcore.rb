# frozen_string_literal: true

require_relative "qtcore/qtcore"
require_relative "qtcore/qtcoreversion"
require_relative "qtcore/qt"

require_relative "qtcore/qanystringview"
require_relative "qtcore/qstring"
require_relative "qtcore/qurl"
require_relative "qtcore/qvariant"

require_relative "qtcore/qobject"
require_relative "qtcore/qmetaobject"
require_relative "qtcore/qcoreapplication"

require_relative "qtcore/version"

module RubyQt6
  def self.qt_modules
    constants.grep(/Qt[A-Z]/).map(&->(m) { const_get(m) })
  end
end
