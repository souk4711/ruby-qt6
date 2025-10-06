RSpec.describe RubyQt6::QtCore::QSettings do
  it "#initialize" do
    o = described_class.new("souk4711", "RubyQt6")
    expect(o.format).to eq(described_class::Format::NativeFormat)
    expect(o.scope).to eq(described_class::Scope::UserScope)
    expect(o.organization_name).to eq("souk4711")
    expect(o.application_name).to eq("RubyQt6")
  end

  it "#set_value" do
    o = described_class.new("souk4711", "RubyQt6")
    o.set_value("interval", 30)
    expect(o.value("interval")).to eq(30)
  end

  it "#value" do
    o = described_class.new("souk4711", "RubyQt6")
    o.set_value("interval", 6.66)
    expect(o.value("interval")).to eq(6.66)
    expect(o.value("interval-no-value", 9.99)).to eq(9.99)
  end
end
