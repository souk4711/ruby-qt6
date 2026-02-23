RSpec.describe RubyQt6::QtTest do
  describe "Bindings" do
    qmod = Struct.new(:name).new("QtTest")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qttest/qttest-rb.cpp"
      next if cppfile == "ext/qt6/qttest/qttestpreludes-rb.cpp"
      next if cppfile == "ext/qt6/qttest/qttestversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
