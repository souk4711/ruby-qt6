RSpec.describe RubyQt6::QtGui do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtGui")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtgui/qtgui-rb.cpp"
      next if cppfile == "ext/qt6/qtgui/qtguipreludes-rb.cpp"
      next if cppfile == "ext/qt6/qtgui/qtguiversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
