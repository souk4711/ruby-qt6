RSpec.describe RubyQt6::QtCore::Qt do
  it "#to_qflags" do
    expect(described_class::AlignLeft.to_qflags).to eq(0x0001)
    expect(described_class::AlignLeft.to_qflags).to eq(described_class::Alignment.from_int(0x0001))
    expect(described_class::AlignLeft | described_class::AlignTop).to eq(described_class::Alignment.from_int(0x0001 + 0x0020))
  end
end
