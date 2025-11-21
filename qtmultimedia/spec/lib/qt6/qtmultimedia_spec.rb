RSpec.describe RubyQt6::QtMultimedia do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtMultimedia")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtmultimedia/qtmultimedia-rb.cpp"
      next if cppfile == "ext/qt6/qtmultimedia/qtmultimediaversion-rb.cpp"
      next if cppfile == "ext/qt6/qtmultimedia/qtaudio-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
