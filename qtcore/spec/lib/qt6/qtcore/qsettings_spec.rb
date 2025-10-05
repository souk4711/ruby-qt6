RSpec.describe RubyQt6::QtCore::QSettings do
  it "#initialize" do
    o = described_class.new("souk4711", "RubyQt6")
    expect(o.format).to eq(described_class::Format::NativeFormat)
    expect(o.scope).to eq(described_class::Scope::UserScope)
    expect(o.organization_name).to eq("souk4711")
    expect(o.application_name).to eq("RubyQt6")
  end
end
