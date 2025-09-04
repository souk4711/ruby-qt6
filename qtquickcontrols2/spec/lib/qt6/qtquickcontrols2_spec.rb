RSpec.describe RubyQt6::QtQuickControls2 do
  Dir.glob("ext/**/*.cpp").each do |f|
    contents = File.read(f)
    matched = contents.match(/define_constructor\(Constructor<(\w+)/)
    next unless matched

    it "redefine #initialize for #{matched[1]}" do
      contents = File.read("lib/qt6/qtquickcontrols2/#{matched[1].downcase}.rb")
      expect(contents.match("alias_method :_initialize, :initialize")).not_to be_nil
      expect(contents.match("def initialize")).not_to be_nil
    end
  end
end
