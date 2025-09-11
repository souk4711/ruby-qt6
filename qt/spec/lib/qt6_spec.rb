RSpec.describe RubyQt6 do
  describe "._static_meta_object" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._static_meta_object @ #{klass}" do
        expect(cls._static_meta_object.class_name).to eq(klass.to_s)
      end
    end
  end

  describe ".__qmetaobject__" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject) && cls != RubyQt6::QtCore::QObject

      it "define .__qmetaobject__ @ #{klass}" do
        expect(cls.__qmetaobject__).to be_a(RubyQt6::Internal::MetaObject)
      end
    end
  end
end
