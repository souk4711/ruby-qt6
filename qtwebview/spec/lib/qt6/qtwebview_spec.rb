RSpec.describe RubyQt6::QtWebView do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtWebView")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtwebview/qtwebview-rb.cpp"
      next if cppfile == "ext/qt6/qtwebview/qtwebviewpreludes-rb.cpp"
      next if cppfile == "ext/qt6/qtwebview/qtwebviewversion-rb.cpp"
      next if cppfile == "ext/qt6/qtwebview/qtwebviewfunctions-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
