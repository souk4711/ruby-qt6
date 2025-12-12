RSpec.describe RubyQt6 do
  describe "._qmetaobject" do
    Support.self_and_descendants(QObject).each do |klass|
      it "._qmetaobject @ #{klass}" do
        next if [QDBusInterface].include?(klass)
        expect(klass._qmetaobject.class_name).to eq(klass.name.split("::").last)
      end
    end
  end

  describe "._rubyqt6_metaobject" do
    Support.self_and_descendants(QObject).each do |klass|
      it "._rubyqt6_metaobject @ #{klass}" do
        expect(klass._rubyqt6_metaobject.class_name).to eq(klass.name)
      end
    end
  end

  describe "ownership" do
    ownership_all = [QObject, QGraphicsItem, QStandardItem, QListWidgetItem, QTableWidgetItem, QTreeWidgetItem, QLayoutItem].flat_map { |klass| Support.self_and_descendants(klass) }
    ownership_rb_ = [QCoreApplication, QGuiApplication, QApplication, QFile, QSettings, QSplashScreen, QUiLoader]
    ownership_cpp = ownership_all - ownership_rb_

    ownership_all.each do |klass|
      _, lib, filename = klass.name.split("::").map(&:downcase)
      filename = File.expand_path("../../../#{lib}/lib/qt6/#{lib}/#{filename}.rb", __dir__)
      filedata = File.read(filename)
      next unless filedata.include?("def initialize")

      it "ownership @ #{klass}" do
        if ownership_rb_.include?(klass)
          expect(filedata.include?("_take_ownership_from_ruby")).to be(false)
        elsif ownership_cpp.include?(klass)
          expect(filedata.include?("_take_ownership_from_ruby(self)\n")).to be(true)
        else
          pending("unreachable")
        end
      end
    end
  end

  describe "rubyqt6-rice" do
    it "namespace" do
      expect(Rice4RubyQt6::Buffer≺char∗≻).to be_a(Class)
      expect(Rice4RubyQt6::Libc::File).to be_a(Class)
      expect(Rice4RubyQt6::Std::Vector≺QVariant≻).to be_a(Class)

      expect(::Object.const_defined?(:Rice)).to be(false)
      expect(::Object.const_defined?(:Libc)).to be(false)
      expect(::Object.const_defined?(:Std)).to be(false)
    end
  end
end
