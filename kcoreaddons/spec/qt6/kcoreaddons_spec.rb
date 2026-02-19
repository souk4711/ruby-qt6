RSpec.describe RubyQt6::KCoreAddons do
  describe "Bindings" do
    qmod = Struct.new(:name).new("KCoreAddons")

    Dir.glob("ext/**/bando-k*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/k*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/kcoreaddons/kcoreaddons-rb.cpp"
      next if cppfile == "ext/qt6/kcoreaddons/kcoreaddonsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end
end
