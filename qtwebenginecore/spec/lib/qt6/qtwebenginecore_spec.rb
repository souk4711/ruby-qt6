RSpec.describe RubyQt6::QtWebEngineCore do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtWebEngineCore")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtwebenginecore/qtwebenginecore-rb.cpp"
      next if cppfile == "ext/qt6/qtwebenginecore/qtwebenginecorepreludes-rb.cpp"
      next if cppfile == "ext/qt6/qtwebenginecore/qtwebenginecoreversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
