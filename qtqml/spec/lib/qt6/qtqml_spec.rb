RSpec.describe RubyQt6::QtQml do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtQml")

    Dir.glob("ext/**/bando*.cpp").each do |cppfile|
      it "BandoFile: #{cppfile}" do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtqml/qtqml-rb.cpp"
      next if cppfile == "ext/qt6/qtqml/qtqmlversion-rb.cpp"

      it "QlassFile: #{cppfile}" do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
