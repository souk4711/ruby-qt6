RSpec.describe RubyQt6 do
  describe "._rubyqt6_metaobject" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._rubyqt6_metaobject @ #{klass}" do
        expect(cls._rubyqt6_metaobject.class_name.split("::").last).to eq(klass.to_s)
      end
    end
  end

  describe "._qmetaobject" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._qmetaobject @ #{klass}" do
        expect(cls._qmetaobject.class_name).to eq(klass.to_s)
      end
    end
  end
end
