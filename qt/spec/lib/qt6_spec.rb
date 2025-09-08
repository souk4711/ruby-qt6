RSpec.describe RubyQt6 do
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
