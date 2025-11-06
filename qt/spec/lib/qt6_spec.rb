RSpec.describe RubyQt6 do
  qobject_subclasses =
    Object.constants.grep(/^Q/).each_with_object([]) do |name, memo|
      klass = Object.const_get(name)
      memo << klass if klass < RubyQt6::QtCore::QObject
    end.sort_by(&:name).freeze

  describe "._qmetaobject" do
    qobject_subclasses.each do |klass|
      it "._qmetaobject @ #{klass}" do
        next if [RubyQt6::QtDBus::QDBusInterface].include?(klass)
        expect(klass._qmetaobject.class_name).to eq(klass.name.split("::").last)
      end
    end
  end

  describe "._rubyqt6_metaobject" do
    qobject_subclasses.each do |klass|
      it "._rubyqt6_metaobject @ #{klass}" do
        expect(klass._rubyqt6_metaobject.class_name).to eq(klass.name)
      end
    end
  end

  describe "ownership" do
    ownership_ruby = [QCoreApplication, QGuiApplication, QApplication, QSplashScreen]
    ownership_cpp_ = qobject_subclasses - ownership_ruby

    qobject_subclasses.each do |klass|
      _, lib, filename = klass.name.split("::").map(&:downcase)
      filename = File.expand_path("../../../#{lib}/lib/qt6/#{lib}/#{filename}.rb", __dir__)
      filedata = File.read(filename)
      next unless filedata.include?("def initialize")

      it "ownership @ #{klass}" do
        if ownership_ruby.include?(klass)
          expect(filedata.include?("_take_ownership_from_ruby")).to be(false)
        elsif ownership_cpp_.include?(klass)
          expect(filedata.include?("_take_ownership_from_ruby(self)\n")).to be(true)
        else
          pending("unreachable")
        end
      end
    end
  end
end
