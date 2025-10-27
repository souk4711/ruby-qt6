RSpec.describe RubyQt6::QtDBus::QDBusVariant do
  it "#initialize" do
    o = described_class.new("hello")
    expect(o.variant.value).to eq("hello")

    o = described_class.new(RubyQt6::QtCore::QVariant.new(123))
    expect(o.variant.value).to eq(123)
  end
end
