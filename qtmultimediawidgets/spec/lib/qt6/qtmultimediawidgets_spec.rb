RSpec.describe RubyQt6::QtMultimediaWidgets do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtMultimediaWidgets")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtmultimediawidgets/qtmultimediawidgets-rb.cpp"
      next if cppfile == "ext/qt6/qtmultimediawidgets/qtmultimediawidgetspreludes-rb.cpp"
      next if cppfile == "ext/qt6/qtmultimediawidgets/qtmultimediawidgetsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
