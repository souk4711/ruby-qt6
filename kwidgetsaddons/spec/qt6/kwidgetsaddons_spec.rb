RSpec.describe RubyQt6::KWidgetsAddons do
  describe "Bindings" do
    qmod = Struct.new(:name).new("KWidgetsAddons")

    Dir.glob("ext/**/bando-k*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/k*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/kwidgetsaddons/kwidgetsaddons-rb.cpp"
      next if cppfile == "ext/qt6/kwidgetsaddons/kwidgetsaddonsversion-rb.cpp"
      next if cppfile == "ext/qt6/kwidgetsaddons/kmessagebox-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
