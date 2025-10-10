RSpec.describe RubyQt6::QtUiTools do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtUiTools")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtuitools/qtuitools-rb.cpp"
      next if cppfile == "ext/qt6/qtuitools/qtuitoolsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
