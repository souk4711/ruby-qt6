RSpec.describe RubyQt6::QtWebEngineWidgets do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtWebEngineWidgets")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtwebenginewidgets/qtwebenginewidgets-rb.cpp"
      next if cppfile == "ext/qt6/qtwebenginewidgets/qtwebenginewidgetspreludes-rb.cpp"
      next if cppfile == "ext/qt6/qtwebenginewidgets/qtwebenginewidgetsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
