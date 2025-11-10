RSpec.describe RubyQt6::QtQuickControls2 do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtQuickControls2")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtquickcontrols2/qtquickcontrols2-rb.cpp"
      next if cppfile == "ext/qt6/qtquickcontrols2/qtquickcontrols2version-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
