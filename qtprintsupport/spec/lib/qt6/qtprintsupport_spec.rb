RSpec.describe RubyQt6::QtPrintSupport do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtPrintSupport")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtprintsupport/qtprintsupport-rb.cpp"
      next if cppfile == "ext/qt6/qtprintsupport/qtprintsupportversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
