RSpec.describe RubyQt6::QtCore do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtCore")

    Dir.glob("ext/**/bando*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtcore/qtcore-rb.cpp"
      next if cppfile == "ext/qt6/qtcore/qtcoreversion-rb.cpp"
      next if cppfile == "ext/qt6/qtcore/qt-enum-rb.cpp"
      next if cppfile == "ext/qt6/qtcore/qt-flags-rb.cpp"
      next if cppfile == "ext/qt6/qtcore/qstringlist-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
