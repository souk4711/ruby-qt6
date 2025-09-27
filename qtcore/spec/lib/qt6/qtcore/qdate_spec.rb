RSpec.describe RubyQt6::QtCore::QDate do
  it "#initialize" do
    o = described_class.new(2025, 9, 28)
    expect(o.year).to eq(2025)
    expect(o.month).to eq(9)
    expect(o.day).to eq(28)
  end

  it "#to_s" do
    o = described_class.new(2025, 9, 28)
    expect(o.to_s).to eq("28 Sep 2025")
  end

  it "#<=>" do
    expect(described_class.new(1777, 7, 7)).to be < described_class.new(1777, 7, 8)
    expect(described_class.new(1777, 7, 7)).to be > described_class.new(1777, 7, 6)
    expect(described_class.new(1777, 7, 7)).to be == described_class.new(1777, 7, 7)
    expect(described_class.new(1777, 7, 7) <=> 1777).to be_nil
    expect(described_class.new(1777, 7, 7) <=> nil).to be_nil
  end
end
