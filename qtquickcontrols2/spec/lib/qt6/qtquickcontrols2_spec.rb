RSpec.describe RubyQt6::QtQuickControls2 do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtQuickControls2")

    Dir.glob("ext/**/bando*.cpp").each do |cppfile|
      it "BandoFile: #{cppfile}" do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtquickcontrols2/qtquickcontrols2-rb.cpp"
      next if cppfile == "ext/qt6/qtquickcontrols2/qtquickcontrols2version-rb.cpp"

      it "QlassFile: #{cppfile}" do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
