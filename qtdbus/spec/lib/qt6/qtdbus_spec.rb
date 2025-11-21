RSpec.describe RubyQt6::QtDBus do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtDBus")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtdbus/qtdbus-rb.cpp"
      next if cppfile == "ext/qt6/qtdbus/qtdbusversion-rb.cpp"
      next if cppfile == "ext/qt6/qtdbus/qdbus-rb-cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
