RSpec.describe QSettings do
  it "#initialize" do
    o = described_class.new("souk4711-dev", "RubyQt6")
    expect(o.format).to eq(described_class::NativeFormat)
    expect(o.scope).to eq(described_class::UserScope)
    expect(o.organization_name).to eq("souk4711-dev")
    expect(o.application_name).to eq("RubyQt6")
  end

  it "#set_value" do
    o = described_class.new("souk4711-dev", "RubyQt6")
    o.set_value("interval", 30)
    expect(o.value("interval", 0)).to eq(30)
  end

  it "#value" do
    o = described_class.new("souk4711-dev", "RubyQt6")
    o.set_value("interval", 6.66)
    expect(o.value("interval", 0)).to eq(6.66)
    expect(o.value("interval-undefined", 9.99)).to eq(9.99)
  end
end
