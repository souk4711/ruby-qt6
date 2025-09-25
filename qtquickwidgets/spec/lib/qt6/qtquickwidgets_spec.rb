RSpec.describe RubyQt6::QtQuickWidgets do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtQuickWidgets")

    Dir.glob("ext/**/bando*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtquickwidgets/qtquickwidgets-rb.cpp"
      next if cppfile == "ext/qt6/qtquickwidgets/qtquickwidgetsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
