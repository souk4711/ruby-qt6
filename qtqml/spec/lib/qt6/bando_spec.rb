RSpec.describe RubyQt6::Bando do
  [
    [RubyQt6::Bando::QJSEngine, RubyQt6::QtQml::QJSEngine],
    [RubyQt6::Bando::QQmlEngine, RubyQt6::QtQml::QQmlEngine],
    [RubyQt6::Bando::QQmlApplicationEngine, RubyQt6::QtQml::QQmlApplicationEngine]
  ].each do |bando_qlass, qlass|
    it "#{bando_qlass} should behave like #{qlass}" do
      expect(bando_qlass._rubyqt6_metaobject).to eq(qlass._rubyqt6_metaobject)
      expect(bando_qlass._qmetaobject).to eq(qlass._qmetaobject)
    end
  end
end
