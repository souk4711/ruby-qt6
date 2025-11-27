RSpec.describe RubyQt6::QtTest::QSignalSpy do
  it "#initialize" do
    obj = RubyQt6::QtCore::QObject.new
    spy = described_class.new(obj, "objectNameChanged(QString)")
    expect(spy.count).to eq(0)

    obj.set_object_name("name123")
    expect(spy.count).to eq(1)
    expect(spy[0][0].value).to eq("name123")
  end
end
